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

## Build Dependencies (Linux)

```bash
sudo apt-get install build-essential cmake qt6-base-dev libreoffice-dev linguist-qt6
```

UNO headers must be pre-generated into `include/` once:

```bash
cppumaker -O include \
    /usr/lib/libreoffice/program/types.rdb \
    /usr/lib/libreoffice/program/types/offapi.rdb
```

---

## CMake Options

| Option | Default | Description |
|--------|---------|-------------|
| `CMAKE_BUILD_TYPE` | `Release` | `Debug` for test builds |
| `BUILD_TESTS` | `OFF` | Enable Google Test unit tests (`tests/unit/`) |
| `CMAKE_EXPORT_COMPILE_COMMANDS` | `OFF` | Generate `compile_commands.json` for clang-tidy |

---

## What build.sh Does

1. `cmake -S . -B build` — configure with Qt6 and LO SDK headers
2. `cmake --build build` — compile `libreai.so` and `.qm` translation files
3. Collect Qt6 runtime `.so` libs via `ldd`
4. `zip` everything into `libreai.oxt`:
   - `libreai.so`
   - Qt6 runtime libs
   - `META-INF/manifest.xml`
   - `Addons.xcu`, `Jobs.xcu`, `description.xml`, `icons/`
5. (with `--install`) `unopkg add --force libreai.oxt`

---

## CI Pipelines

| Workflow | File | Trigger | Builds |
|----------|------|---------|--------|
| Release (Linux) | `.github/workflows/release.yml` | `v*` tag push | Ubuntu 22.04 + 24.04 |
| Release (Windows) | `.github/workflows/release-windows.yml` | `workflow_dispatch` with `tag` input | Windows x86_64 |
| Tests | `.github/workflows/test.yml` | push / PR to `development` or `main` | Unit + integration |

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
```

### Moving a tag (e.g. after a hotfix)

```bash
git push origin v1.0.X --delete
git tag -f v1.0.X
git push origin v1.0.X
gh workflow run release-windows.yml --ref development --field tag=v1.0.X
```

---

## Windows Build Notes

- Requires LibreOffice SDK installed at `%PROGRAMFILES%\LibreOffice_25.8_SDK`
- Qt plugin path must be set from `GetModuleFileNameW` before `QApplication` construction (see `src/LibreAIJob.cpp`)
- `sal_Unicode*` vs `const ushort*` are distinct on MSVC — always cast via `reinterpret_cast<const sal_Unicode*>(qstring.utf16())`
- Build script: `build.ps1`
