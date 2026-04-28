# Build & Release

## Quick Start

```bash
bash build.sh            # configure + compile + package → libreai.oxt
bash build.sh --install  # also installs into LibreOffice via unopkg
```

Always kill LibreOffice before installing:

```bash
pkill -x soffice.bin; pkill -x soffice
```

---

## Build Dependencies

### Linux

```bash
sudo apt-get install build-essential cmake qt6-base-dev libreoffice-dev linguist-qt6
# Optional — for secure credential storage:
sudo apt-get install libqt6keychain-dev
```

UNO headers must be pre-generated into `include/` once:

```bash
cppumaker -O include \
    /usr/lib/libreoffice/program/types.rdb \
    /usr/lib/libreoffice/program/types/offapi.rdb
```

### macOS

- Xcode Command Line Tools
- CMake (`brew install cmake`)
- Qt6 (`brew install qt`)
- LibreOffice SDK DMG (from the LibreOffice download site)

```bash
cmake -S . -B build \
    -DLO_INCLUDE=$HOME/lo_sdk/include \
    -DLO_SDK_LIB=$HOME/uno_stubs
```

### Windows

- Visual Studio 2022 (C++17)
- Qt6 (MSVC build from qt.io)
- LibreOffice SDK installed at `%PROGRAMFILES%\LibreOffice_25.8_SDK`
- Build script: `build.ps1`

---

## CMake Options

| Option | Default | Description |
|--------|---------|-------------|
| `CMAKE_BUILD_TYPE` | `Release` | `Debug` for test builds |
| `BUILD_TESTS` | `OFF` | Enable Google Test unit tests |
| `LO_INCLUDE` | Platform default | Path to LO UNO headers |
| `LO_SDK_LIB` | Platform default | Path to `libuno_*.so/dylib/lib` |

**Important:** CMake `set()` overrides `-D` flags for normal variables. All platform defaults use `if(NOT VAR)` guards so `-DVAR=...` takes effect.

---

## What build.sh Does

1. `cmake -S . -B build` — configure with Qt6 and LO SDK headers
2. `cmake --build build` — compile `libreai.so` and `.qm` translation files
3. Collect Qt6 runtime `.so` libs
4. `zip` everything into `libreai.oxt`:
   - `libreai.so`
   - Qt6 runtime libs
   - `META-INF/manifest.xml`, `Addons.xcu`, `Jobs.xcu`, `description.xml`, `icons/`
   - Compiled `.qm` translation files (via embedded `.qrc`)
5. (with `--install`) `unopkg add --force libreai.oxt`

---

## CI Pipelines

| Workflow | File | Trigger | Builds |
|----------|------|---------|--------|
| Release (Linux) | `.github/workflows/release.yml` | `v*` tag push | Ubuntu 22.04 + 24.04 |
| Release (Windows) | `.github/workflows/release-windows.yml` | `workflow_dispatch` with `tag` input | Windows x86_64 |
| Release (macOS) | `.github/workflows/release-macos.yml` | `workflow_dispatch` with `tag` input | macOS ARM64 (Apple Silicon) |
| Tests | `.github/workflows/test.yml` | push / PR to `development` or `main` | Unit + integration |

### macOS CI Notes

- Runs on `macos-14` (Apple Silicon / ARM64)
- Installs Qt6 via `jurplel/install-qt-action@v3`
- Downloads LO SDK DMG from funet mirror; detects version from app bundle plist (3-part)
- Copies SDK directory directly (flat layout — no `.pkg` installer)
- Creates `$HOME/uno_stubs/` with unversioned symlinks to versioned UNO dylibs (`libuno_cppu.dylib.3` → `libuno_cppu.dylib`)
- Uses a custom `copy_qt_dep()` shell function (otool + install_name_tool) to bundle Qt frameworks — `dylibbundler` is not used because LO's `@__URELIB` rpath causes it to hang

---

## Release Workflow

```bash
# 1. Commit everything to development
git push origin development

# 2. Tag and push — triggers Linux CI
git tag v1.0.X
git push origin v1.0.X

# 3. Trigger Windows CI manually
gh workflow run release-windows.yml \
    --ref development --field tag=v1.0.X

# 4. Trigger macOS CI manually
gh workflow run release-macos.yml \
    --ref development --field tag=v1.0.X
```

### Moving a tag (e.g. after a hotfix)

```bash
git push origin v1.0.X --delete
git tag -f v1.0.X
git push origin v1.0.X
gh workflow run release-windows.yml --ref development --field tag=v1.0.X
gh workflow run release-macos.yml   --ref development --field tag=v1.0.X
```

---

## Platform Notes

### Linux — Credential Storage

Qt6Keychain is detected automatically. If found, `HAVE_KEYCHAIN` is defined and `CredentialBackendKeychain` is compiled in. Otherwise keys are stored in memory only (lost on restart).

### macOS — Credential Storage

`Security.framework` is always linked (`HAVE_MACOS_KEYCHAIN`). Keys are stored in the macOS Keychain via `SecKeychainAdd/FindGenericPassword`.

### Windows — Credential Storage

`Crypt32` is always linked (`HAVE_DPAPI`). Keys are encrypted with DPAPI and stored in a JSON file at `%APPDATA%\libreai\credentials.json`.

### Windows — Qt Plugin Path

Must be set from `GetModuleFileNameW(libreai_module_handle(), ...)` before `QApplication` is constructed (see `src/uno/LibreAIJob.cpp`).

### All Platforms — sal_Unicode

`sal_Unicode*` vs `const ushort*` are distinct on MSVC. Always use `reinterpret_cast<const sal_Unicode*>(qstring.utf16())` when passing Qt strings to `rtl::OUString`.
