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
