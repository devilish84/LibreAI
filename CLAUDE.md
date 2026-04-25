# LibreAI — Claude Code Guide

LibreAI is a native **C++17 / Qt6** LibreOffice Writer extension providing an AI writing assistant. Supports Ollama (local), OpenAI, and Anthropic Claude.

**Current version:** 1.0.5 | **Branch strategy:** develop on `development`, release by tagging `v*`

---

## Quick Reference

### Build & Install

```bash
bash build.sh            # configure + compile + package → libreai.oxt
bash build.sh --install  # also installs into LibreOffice via unopkg
pkill -x soffice.bin; pkill -x soffice   # always kill LO before installing
```

### Unit Tests

```bash
cmake -S . -B build -DBUILD_TESTS=ON -Wno-dev
cmake --build build --parallel $(nproc)
ctest --test-dir build --output-on-failure
```

### Integration Tests (headless)

```bash
xvfb-run -a pytest tests/integration/ -v --timeout=60
```

### Release

```bash
git tag v1.0.X && git push origin v1.0.X   # triggers Linux CI
gh workflow run release-windows.yml --ref development --field tag=v1.0.X
```

---

## Documentation (spec/)

| File | Contents |
|------|----------|
| [architecture.md](spec/architecture.md) | Class map, startup sequence, singleton pattern, Qt-in-LO constraints |
| [uno-components.md](spec/uno-components.md) | LibreAIJob, LibreAIStarter, CMInterceptor, UnoHelper, XCU files |
| [ui-chat-window.md](spec/ui-chat-window.md) | ChatWindow layout, widgets, theme palette |
| [ui-config-dialog.md](spec/ui-config-dialog.md) | ConfigDialog tabs, save behaviour, singleton lifecycle |
| [ai-providers.md](spec/ai-providers.md) | AIClient base API, Ollama / OpenAI / Anthropic details, adding a provider |
| [config.md](spec/config.md) | Config singleton, JSON schema, isConfigured(), applyLanguage() |
| [i18n.md](spec/i18n.md) | Supported languages, Qt conventions, adding a new language |
| [build-release.md](spec/build-release.md) | CMake options, build.sh, CI pipelines, release workflow |
| [testing.md](spec/testing.md) | Manual checklist, Google Test unit tests, pytest integration tests |
| [LibreAI_Specification.md](spec/LibreAI_Specification.md) | Formal technical specification |

---

## Known Limitations

| Limitation | Detail |
|------------|--------|
| Anthropic model list | Hard-coded in `AnthropicClient.cpp` — no public list-models endpoint |
| Chat history | In-memory only; lost on LibreOffice restart |
| Writer only | `UnoHelper` uses `XTextViewCursorSupplier` — Writer-specific |
| Menu bar i18n | Follows LibreOffice's own UI language, not LibreAI's language setting |
| Qt event loop | Runs on LO's main thread; keep Qt operations lightweight |
