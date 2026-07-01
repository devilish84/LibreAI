# LibreAI — Claude Code Guide

LibreAI is a native **C++17 / Qt6** LibreOffice extension providing an AI writing assistant. Supports Ollama (local), OpenAI, Anthropic Claude, xAI Grok, and Google Gemini.

**Current version:** 1.0.11 | **Branch strategy:** develop on `development`, release by tagging `v*`

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
gh workflow run release-macos.yml   --ref development --field tag=v1.0.X
```

---

## Documentation (spec/)

| File | Contents |
|------|----------|
| [architecture.md](spec/architecture.md) | Class map, startup sequence, singleton pattern, Qt-in-LO constraints |
| [uno-components.md](spec/uno-components.md) | LibreAIJob, LibreAIStarter, CMInterceptor, UnoHelper, XCU files |
| [ui-chat-window.md](spec/ui-chat-window.md) | ChatWindow layout, Markdown rendering, rich text apply, theme palette |
| [ui-config-dialog.md](spec/ui-config-dialog.md) | ConfigDialog tabs, save behaviour, singleton lifecycle |
| [ai-providers.md](spec/ai-providers.md) | AIClient base API, all 5 providers, adding a provider |
| [config.md](spec/config.md) | Config singleton, JSON schema, isConfigured(), applyLanguage() |
| [i18n.md](spec/i18n.md) | Supported languages, Qt conventions, adding a new language |
| [build-release.md](spec/build-release.md) | CMake options, build.sh, CI pipelines (Linux/Windows/macOS), release workflow |
| [testing.md](spec/testing.md) | Manual checklist, Google Test unit tests, pytest integration tests |
| [LibreAI_Specification.md](spec/LibreAI_Specification.md) | Formal technical specification |
| [feature-batch-rewrite.md](spec/feature-batch-rewrite.md) | Batch Rewrite mode — DocumentParser, BatchProcessor, BatchRewriteDialog |
| [feature-image-generation.md](spec/feature-image-generation.md) | Image Generation — ImageClient hierarchy, ImageGenDialog, UnoHelper::insertImage |
| [feature-prompt-library.md](spec/feature-prompt-library.md) | Prompt Library & Templates — saved instructions, variable substitution |

## Plans

| File | Contents |
|------|----------|
| [libreai-architecture-overview.md](plans/libreai-architecture-overview.md) | High-level runtime composition, data flow diagram, execution constraints |

---

## Known Limitations

| Limitation | Detail |
|------------|--------|
| Anthropic model list | Hard-coded in `AnthropicClient.cpp` — no public list-models endpoint |
| Chat history | In-memory only; lost on LibreOffice restart |
| Rich text apply | Writer only — Impress and Calc receive plain text |
| Batch rewrite | Writer only — DocumentParser uses `XTextViewCursorSupplier` |
| Menu bar i18n | Follows LibreOffice's own UI language, not LibreAI's language setting |
| Qt event loop | Runs on LO's main thread; keep Qt operations lightweight |
