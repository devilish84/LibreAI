"""
OXT bundle structure tests.

Validates that the packaged .oxt contains everything required for each
platform — particularly the Qt platform plugins that must be present for
windows to appear at all.

Usage:
    pytest tests/integration/test_oxt_bundle.py --oxt=libreai_macos_arm64.oxt -v

The --oxt option is required; the test collection is skipped when omitted.
"""
import sys
import zipfile
import subprocess
from pathlib import Path

import pytest


@pytest.fixture(scope="session")
def oxt_path(request):
    p = request.config.getoption("--oxt")
    if not p:
        pytest.skip("--oxt not provided")
    path = Path(p)
    if not path.exists():
        pytest.fail(f"OXT not found: {path}")
    return path


@pytest.fixture(scope="session")
def oxt_names(oxt_path):
    """Return the set of all zip entry names in the OXT."""
    with zipfile.ZipFile(oxt_path) as z:
        return set(z.namelist())


# ── Common (all platforms) ────────────────────────────────────────────────────

def test_meta_inf_manifest(oxt_names):
    assert "META-INF/manifest.xml" in oxt_names, \
        "META-INF/manifest.xml missing — OXT will not be recognised by LibreOffice"


def test_description_xml(oxt_names):
    assert "description.xml" in oxt_names


def test_addons_xcu(oxt_names):
    assert "Addons.xcu" in oxt_names, "Addons.xcu missing — menu entries will not appear"


def test_jobs_xcu(oxt_names):
    assert "Jobs.xcu" in oxt_names


# ── macOS-specific ────────────────────────────────────────────────────────────

@pytest.fixture(scope="session")
def is_macos_oxt(oxt_path):
    return "macos" in oxt_path.name.lower() or "mac" in oxt_path.name.lower()


def test_macos_dylib_present(oxt_names, oxt_path, is_macos_oxt):
    """Main shared library must be present in the OXT root."""
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    dylibs = [n for n in oxt_names if n.endswith(".dylib") and "/" not in n]
    assert dylibs, "No .dylib found in OXT root — extension will not load"


def test_macos_manifest_declares_dylib(oxt_path, is_macos_oxt):
    """manifest.xml must declare libreai.dylib as a native UNO component for macOS.

    Without a MacOSX platform file-entry, LibreOffice never even attempts to
    load the component on macOS — the menu appears (from Addons.xcu) but every
    item silently does nothing because the backing service was never
    registered. This is distinct from the dylib being present in the zip.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    with zipfile.ZipFile(oxt_path) as z:
        manifest = z.read("META-INF/manifest.xml").decode()
    assert "libreai.dylib" in manifest, (
        "META-INF/manifest.xml does not reference libreai.dylib — LibreOffice "
        "will not load the component on macOS (menu items do nothing)."
    )
    assert "platform=MacOSX" in manifest, (
        "manifest.xml has no MacOSX platform file-entry. Add e.g.\n"
        '  <manifest:file-entry\n'
        '    manifest:media-type="application/vnd.sun.star.uno-component;'
        'type=native;platform=MacOSX_aarch64"\n'
        '    manifest:full-path="libreai.dylib"/>'
    )


def test_macos_no_urelib_placeholder(oxt_names, oxt_path, is_macos_oxt):
    """libreai.dylib must not keep the unresolved @__…URELIB UNO install names.

    The UNO libs are linked with a placeholder install name
    (@__…URELIB/libuno_*.dylib.3) that is never patched and does not resolve at
    runtime, so LibreOffice reports "loading component library failed". They
    must be rewritten (e.g. to @executable_path/../Frameworks) during bundling.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    if sys.platform != "darwin":
        pytest.skip("otool only available on macOS")
    dylibs = [n for n in oxt_names if n.endswith(".dylib") and "/" not in n
              and "libreai" in n]
    if not dylibs:
        pytest.skip("libreai.dylib not found in OXT root")

    import tempfile, os
    with zipfile.ZipFile(oxt_path) as z:
        data = z.read(dylibs[0])
    with tempfile.NamedTemporaryFile(suffix=".dylib", delete=False) as f:
        f.write(data)
        tmp = f.name
    try:
        result = subprocess.run(["otool", "-L", tmp], capture_output=True, text=True)
        if result.returncode != 0:
            pytest.skip("otool not available on this runner")
        urelib = [line.strip() for line in result.stdout.splitlines()
                  if "URELIB" in line]
        assert not urelib, (
            "libreai.dylib still references the unpatched @__…URELIB placeholder "
            "for UNO libs — it will fail to load in LibreOffice on macOS:\n"
            + "\n".join(urelib)
        )
    finally:
        os.unlink(tmp)


def test_macos_cocoa_platform_plugin(oxt_names, is_macos_oxt):
    """platforms/libqcocoa.dylib must be bundled.

    Without this file Qt cannot create any native window on macOS.
    show() silently does nothing, which looks exactly like menus working
    but no window ever appearing (the symptom in issue #2).
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    assert "platforms/libqcocoa.dylib" in oxt_names, (
        "platforms/libqcocoa.dylib is missing from the OXT.\n"
        "Qt requires this plugin to create windows on macOS.\n"
        "Fix: copy $Qt6_DIR/plugins/platforms/libqcocoa.dylib into pkg/platforms/ "
        "during the bundle step."
    )


def test_macos_qt_conf(oxt_names, oxt_path, is_macos_oxt):
    """qt.conf must tell Qt to look for plugins in the OXT directory.

    Qt reads qt.conf relative to the loaded dylib; setting Plugins=. means
    it searches for a platforms/ folder next to libreai.dylib.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    assert "qt.conf" in oxt_names, (
        "qt.conf is missing — Qt will not find the bundled platform plugin at runtime"
    )
    with zipfile.ZipFile(oxt_path) as z:
        content = z.read("qt.conf").decode()
    assert "Plugins" in content, \
        f"qt.conf does not set Plugins path:\n{content}"


def test_macos_cocoa_no_rpath_qt_deps(oxt_names, oxt_path, is_macos_oxt):
    """libqcocoa.dylib must not have unresolved @rpath Qt references.

    All Qt framework deps inside the plugin must be rewritten to
    @loader_path/<dylib> so they resolve to the bundled Qt dylibs in the
    OXT root — not to a developer's local Qt installation.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    if "platforms/libqcocoa.dylib" not in oxt_names:
        pytest.skip("libqcocoa.dylib not present (caught by earlier test)")

    import tempfile, os
    with zipfile.ZipFile(oxt_path) as z:
        data = z.read("platforms/libqcocoa.dylib")

    with tempfile.NamedTemporaryFile(suffix=".dylib", delete=False) as f:
        f.write(data)
        tmp = f.name

    try:
        result = subprocess.run(
            ["otool", "-L", tmp], capture_output=True, text=True
        )
        if result.returncode != 0:
            pytest.skip("otool not available on this runner")
        rpath_qt = [
            line.strip() for line in result.stdout.splitlines()
            if "@rpath" in line and "Qt" in line
        ]
        assert not rpath_qt, (
            "libqcocoa.dylib still has @rpath Qt references — "
            "run install_name_tool to rewrite them to @loader_path:\n"
            + "\n".join(rpath_qt)
        )
    finally:
        os.unlink(tmp)


def test_macos_plugin_loader_path_deps_resolve(oxt_path, oxt_names, is_macos_oxt):
    """Each @loader_path Qt dep of a bundled plugin must resolve to a real file.

    The plugins live in platforms/, but the Qt dylibs live in the OXT root, so
    the plugin's deps must be @loader_path/../QtFoo. If they are written as
    @loader_path/QtFoo (pointing inside platforms/), the file does not exist —
    the cocoa plugin fails to load and Qt aborts at QApplication construction,
    i.e. every menu click crashes LibreOffice (the v1.0.11 macOS regression).

    Resolve each @loader_path/... dependency of every plugin against the
    extracted tree and assert the target exists.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    if sys.platform != "darwin":
        pytest.skip("otool only available on macOS")
    plugins = [n for n in oxt_names if n.startswith("platforms/") and n.endswith(".dylib")]
    if not plugins:
        pytest.skip("no bundled plugins")

    import tempfile, os
    with tempfile.TemporaryDirectory() as td:
        with zipfile.ZipFile(oxt_path) as z:
            z.extractall(td)
        failures = []
        for plugin in plugins:
            plugin_path = os.path.join(td, plugin)
            plugin_dir = os.path.dirname(plugin_path)
            result = subprocess.run(["otool", "-L", plugin_path],
                                    capture_output=True, text=True)
            if result.returncode != 0:
                pytest.skip("otool not available on this runner")
            for line in result.stdout.splitlines()[1:]:
                dep = line.strip().split(" ")[0]
                if not dep.startswith("@loader_path/"):
                    continue
                rel = dep[len("@loader_path/"):]
                resolved = os.path.normpath(os.path.join(plugin_dir, rel))
                if not os.path.exists(resolved):
                    failures.append(f"{plugin}: {dep} -> missing {os.path.relpath(resolved, td)}")

    assert not failures, (
        "Bundled plugin has @loader_path deps that do not resolve to a file in "
        "the OXT — the plugin will fail to load and crash QApplication init. "
        "Plugins in platforms/ must reference root Qt dylibs as "
        "@loader_path/../QtFoo:\n" + "\n".join(failures)
    )


def test_macos_main_dylib_no_rpath_qt_deps(oxt_names, oxt_path, is_macos_oxt):
    """libreai.dylib must not have unresolved @rpath Qt references."""
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    dylibs = [n for n in oxt_names if n.endswith(".dylib") and "/" not in n
              and "libreai" in n]
    if not dylibs:
        pytest.skip("libreai.dylib not found in OXT root")

    import tempfile, os
    with zipfile.ZipFile(oxt_path) as z:
        data = z.read(dylibs[0])

    with tempfile.NamedTemporaryFile(suffix=".dylib", delete=False) as f:
        f.write(data)
        tmp = f.name

    try:
        result = subprocess.run(
            ["otool", "-L", tmp], capture_output=True, text=True
        )
        if result.returncode != 0:
            pytest.skip("otool not available on this runner")
        rpath_qt = [
            line.strip() for line in result.stdout.splitlines()
            if "@rpath" in line and "Qt" in line
        ]
        assert not rpath_qt, (
            "libreai.dylib still has @rpath Qt references — "
            "bundled Qt dylibs will not be found at runtime:\n"
            + "\n".join(rpath_qt)
        )
    finally:
        os.unlink(tmp)


# ── macOS code-signature validity (issue #2 root cause) ───────────────────────
#
# Bundling copies the inner binary out of each Qt .framework (e.g.
# QtWidgets.framework/Versions/A/QtWidgets) so it can sit flat in the OXT.
# That binary's original code signature was sealed against the framework's
# Info.plist. Once install_name_tool rewrites its load commands (to point
# @loader_path at the bundled copies) and it's copied out on its own, the
# signature is left invalid unless every touched binary is explicitly
# re-signed (`codesign --force -s -`) afterward.
#
# On Apple Silicon, dyld/AMFI refuse to map any image with an invalid
# signature — even with library validation disabled, which only relaxes the
# same-team requirement, not signature well-formedness. The process is
# SIGKILLed the moment the bad binary is loaded. Since LibreOffice loads
# LibreAIJob via dlopen when a menu item is first dispatched, and swallows
# the failure, this reproduces exactly as "menu items visible, nothing
# happens when clicked" (issue #2) with zero console output.


def _macho_entries(oxt_names, oxt_path):
    """Return zip entry names whose contents are Mach-O binaries (by magic)."""
    magics = {b"\xcf\xfa\xed\xfe", b"\xce\xfa\xed\xfe", b"\xca\xfe\xba\xbe", b"\xbe\xba\xfe\xca"}
    macho = []
    with zipfile.ZipFile(oxt_path) as z:
        for n in oxt_names:
            if n.endswith("/"):
                continue
            head = z.read(n)[:4]
            if head in magics:
                macho.append(n)
    return macho


def test_macos_bundled_binaries_have_valid_signature(oxt_names, oxt_path, is_macos_oxt):
    """Every bundled Mach-O must carry a valid, self-contained code signature.

    This is the actual root cause of issue #2: QtWidgets/QtCore/etc. end up
    with a broken signature after being extracted from their .framework and
    patched with install_name_tool, and macOS silently kills the process
    that tries to load them — no crash log a user would think to check,
    no stderr output, just "nothing happens."
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    if sys.platform != "darwin":
        pytest.skip("codesign only available on macOS")

    import tempfile, os
    macho_names = _macho_entries(oxt_names, oxt_path)
    assert macho_names, "no Mach-O binaries found in OXT — did packaging fail?"

    with zipfile.ZipFile(oxt_path) as z:
        failures = []
        for name in macho_names:
            data = z.read(name)
            with tempfile.NamedTemporaryFile(suffix=".dylib", delete=False) as f:
                f.write(data)
                tmp = f.name
            try:
                result = subprocess.run(
                    ["codesign", "--verify", "--strict", tmp],
                    capture_output=True, text=True,
                )
                if result.returncode != 0:
                    failures.append(f"{name}: {result.stderr.strip()}")
            finally:
                os.unlink(tmp)

    assert not failures, (
        "Bundled binaries have invalid code signatures — macOS will refuse "
        "to load them (Apple Silicon requires every loaded image to carry a "
        "valid signature, even ad-hoc). Fix: run "
        "`codesign --force --sign - <file>` on every binary in pkg/ after "
        "install_name_tool, before zipping the .oxt:\n" + "\n".join(failures)
    )


def test_macos_libreai_dylib_loads_without_crashing(oxt_path, is_macos_oxt, tmp_path):
    """dlopen() the packaged libreai.dylib and assert the process isn't killed.

    Reproduces the real-world symptom without needing LibreOffice open at
    all: extract the OXT (preserving layout so @loader_path resolves), then
    dlopen libreai.dylib in a throwaway subprocess. A SIGKILL here (negative
    returncode) means the signature/bundling is broken and every menu item
    will silently no-op inside LibreOffice. A clean OSError about UNO/URE
    symbols is expected and fine — those only resolve inside a running
    LibreOffice process.
    """
    if not is_macos_oxt:
        pytest.skip("not a macOS OXT")
    if sys.platform != "darwin":
        pytest.skip("only applicable on macOS")

    extract_dir = tmp_path / "oxt"
    with zipfile.ZipFile(oxt_path) as z:
        z.extractall(extract_dir)

    dylib = extract_dir / "libreai.dylib"
    assert dylib.exists(), "libreai.dylib missing from extracted OXT"

    proc = subprocess.run(
        [sys.executable, "-c",
         f"import ctypes; ctypes.CDLL('{dylib}')"],
        capture_output=True, text=True,
    )

    assert proc.returncode >= 0, (
        f"loading libreai.dylib killed the process with signal "
        f"{-proc.returncode} (likely SIGKILL from an invalid code "
        f"signature — see test_macos_bundled_binaries_have_valid_signature)."
        f"\nstderr:\n{proc.stderr}"
    )


# ── Windows-specific ──────────────────────────────────────────────────────────

@pytest.fixture(scope="session")
def is_windows_oxt(oxt_path):
    return "windows" in oxt_path.name.lower() or "win" in oxt_path.name.lower()


def test_windows_dll_present(oxt_names, is_windows_oxt):
    if not is_windows_oxt:
        pytest.skip("not a Windows OXT")
    dlls = [n for n in oxt_names if n.lower().endswith(".dll") and "libreai" in n.lower()]
    assert dlls, "libreai DLL missing from Windows OXT"


def test_windows_qwindows_plugin(oxt_names, is_windows_oxt):
    """platforms/qwindows.dll must be present in Windows OXT."""
    if not is_windows_oxt:
        pytest.skip("not a Windows OXT")
    assert "platforms/qwindows.dll" in oxt_names, \
        "platforms/qwindows.dll missing from Windows OXT"
