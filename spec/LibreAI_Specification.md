# LibreAI — Technical Specification

**Version:** 1.0.8  
**Branch:** `development` (release by tagging `v*`)

---

## 1. Overview

LibreAI is a LibreOffice extension that provides an AI writing assistant through a floating Qt6 chat window. It connects to locally-running Ollama models or cloud AI providers (OpenAI, Anthropic Claude, xAI Grok, Google Gemini) and enables in-document text selection, chat, rewriting, Markdown-rendered responses, and applying AI-formatted output directly to Writer documents.

The extension is implemented in **C++17 with Qt6** as a native UNO component (shared library), avoiding any Java dependency.

---

## 2. Goals

| Goal | Description |
|------|-------------|
| Native C++ component | No Java required; loads on any LO 7.x+ Linux/macOS/Windows installation |
| Multi-provider | Ollama, OpenAI, Claude, Grok, Gemini in one UI |
| Writer integration | Grab selected text, rewrite it, apply formatted response back to document |
| Rich text apply | Headings, bold, italic, code, and lists transferred as native Writer formatting |
| Right-click access | "Ask from AI" context-menu item pre-loads selected text |
| Secure credentials | Platform keychain (Linux Qt6Keychain / macOS Security.framework / Windows DPAPI) |
| Persistent config | Provider, URL, model survive restarts (`~/.config/libreai/config.json`) |
| Markdown rendering | AI responses rendered with headers, code blocks, bold, lists in the chat panel |
| Async networking | All AI HTTP calls are non-blocking (`QNetworkAccessManager`) |
| Dark theme | VS Code-inspired dark UI: `#1E1E1E` background, `#0E639C` accent |

---

## 3. Architecture

### 3.1 Directory Layout

```
libreai/
├── src/
│   ├── uno/                    UNO glue layer
│   │   ├── component.cpp       UNO entry points
│   │   ├── LibreAIJob.*        XJobExecutor
│   │   ├── LibreAIStarter.*    XJob (startup + interceptor install)
│   │   ├── CMInterceptor.*     XContextMenuInterceptor
│   │   └── UnoHelper.*         getSelectedText / applyText / applyRichText
│   ├── core/
│   │   ├── Config.*            JSON config singleton
│   │   ├── CredentialStore.*   Backend factory + ICredentialBackend interface
│   │   ├── CredentialBackendKeychain.*   Linux Qt6Keychain
│   │   ├── CredentialBackendMacOS.*      macOS Security.framework
│   │   ├── CredentialBackendDPAPI.*      Windows DPAPI
│   │   ├── CredentialBackendMemory.*     In-memory fallback
│   │   └── Logger.*            Qt file logger
│   ├── ai/
│   │   ├── AIClient.hpp        Abstract base + Message struct
│   │   ├── OllamaClient.*
│   │   ├── OpenAIClient.*
│   │   ├── AnthropicClient.*
│   │   ├── GrokClient.*
│   │   └── GeminiClient.*
│   └── ui/
│       ├── ChatWindow.*
│       └── ConfigDialog.*
├── include/                    UNO SDK generated headers
├── translations/               .ts / .qm + .qrc
├── tests/unit/                 Google Test suites
├── tests/integration/          pytest + python-uno
├── spec/                       This documentation
├── .github/workflows/          CI (Linux, Windows, macOS, tests)
├── META-INF/manifest.xml
├── Addons.xcu
├── Jobs.xcu
├── description.xml
├── CMakeLists.txt
└── build.sh
```

### 3.2 UNO Services

| Service | Class | Triggered by |
|---------|-------|--------------|
| `org.libreai.job` | `LibreAIJob` | Menu, toolbar, right-click `service:` URL |
| `org.libreai.starter` | `LibreAIStarter` | `Jobs.xcu`: `onStartApp`, `onNew`, `onLoad` |

### 3.3 Startup Sequence

```
LO starts → Jobs.xcu fires org.libreai.starter
  → LibreAIStarter::execute()
      → installInterceptors() — iterate all open frames
      → attachDocumentListener() — XDocumentEventBroadcaster, once only
      → (first call) QApplication created
      → Config::applyLanguage()
      → isConfigured() ? ChatWindow::instance() : ConfigDialog::instance()
```

### 3.4 Trigger Arguments

| Argument | Action |
|----------|--------|
| `"open"` | Show ChatWindow (or ConfigDialog if unconfigured) |
| `"config"` | Show ConfigDialog |
| `"open_with_sel"` | Show ChatWindow with current selection pre-filled |

---

## 4. AI Providers

### 4.1 AIClient Base

```cpp
struct Message {
    QString role;       // "user" | "assistant"
    QString content;
    QString timestamp;  // ISO 8601
    QString provider;   // "ollama"|"openai"|"claude"|"grok"|"gemini"
    QString model;
};

class AIClient : public QObject {
signals:
    void modelsReady(QStringList models);
    void responseReady(QString text);
    void errorOccurred(QString error);
public:
    virtual void fetchModels() = 0;
    virtual void sendChat(const QString& model,
                          const QVector<Message>& history,
                          const QString& prompt) = 0;
};
```

### 4.2 Provider Summary

| Provider | Class | Base URL | Auth | List Models |
|----------|-------|----------|------|-------------|
| Ollama | `OllamaClient` | configurable | None / Basic / API Key header | `GET /api/tags` |
| OpenAI | `OpenAIClient` | configurable | `Authorization: Bearer` | `GET /models` |
| Claude | `AnthropicClient` | `api.anthropic.com` | `x-api-key` | Hard-coded list |
| Grok | `GrokClient` | `api.x.ai/v1` | `Authorization: Bearer` | `GET /models` |
| Gemini | `GeminiClient` | `generativelanguage.googleapis.com/v1beta` | `?key=` query param | `GET /models` |

---

## 5. Configuration

### 5.1 Config Struct (key fields)

```cpp
enum class Provider { Ollama, OpenAI, Claude, Grok, Gemini };

struct Config {
    Provider provider;
    QString  ollamaUrl, openaiUrl;
    OllamaAuthConfig::Mode ollamaAuthMode;
    QString  ollamaAuthUser, ollamaAuthKeyHeader;
    QString  ollamaModel, openaiModel, claudeModel, grokModel, geminiModel;
    QString  language;
    bool     loggingEnabled;
    int      logLevel, logMaxSizeMB;
    // Runtime keys from CredentialStore — not persisted to JSON:
    QString  openaiKey, claudeKey, grokKey, geminiKey;
};
```

### 5.2 JSON Schema (`~/.config/libreai/config.json`)

Non-sensitive settings only. API keys are stored in the platform credential backend.

```json
{
  "provider": "OLLAMA",
  "ollama_url": "http://localhost:11434",
  "ollama_auth_mode": 0,
  "openai_url": "https://api.openai.com/v1",
  "ollama_model": "", "openai_model": "", "claude_model": "",
  "grok_model": "",   "gemini_model": "",
  "language": "en",
  "logging_enabled": false,
  "log_level": 1,
  "log_max_size_mb": 10
}
```

### 5.3 Credential Storage

| Platform | Backend | Compile flag |
|----------|---------|--------------|
| Linux + Qt6Keychain | `CredentialBackendKeychain` | `HAVE_KEYCHAIN` |
| macOS | `CredentialBackendMacOS` (Security.framework) | `HAVE_MACOS_KEYCHAIN` |
| Windows | `CredentialBackendDPAPI` | `HAVE_DPAPI` |
| Fallback | `CredentialBackendMemory` | (none) |

All credential values are **never logged**. Keys are logged at Debug level only.

---

## 6. Chat Window

### 6.1 Widget Layout

| Widget | Type |
|--------|------|
| Header | `QLabel` |
| Grab Selection | `QPushButton` |
| Selected text | `QPlainTextEdit` (80 px, editable) |
| Instruction | `QPlainTextEdit` (80 px) |
| Rewrite / Send / Clear History | `QPushButton` row |
| History toggle | `QPushButton` (checkable) |
| History list | `QListWidget` (160 px, hidden by default) |
| Response | `QTextEdit` (read-only, Markdown) |
| Apply to Document | `QPushButton` |
| Status bar | `QLabel` |

### 6.2 Markdown Rendering

`QTextEdit::setMarkdown()` renders AI responses natively. A `QTextDocument::setDefaultStyleSheet()` provides dark-theme styling for headings, code blocks, blockquotes, and links.

### 6.3 Apply to Document — Rich Text

`UnoHelper::applyRichText(doc)` walks `QTextBlock`/`QTextFragment` and:
- Maps heading level → LO paragraph style (`"Heading 1"` … `"Heading 6"`)
- Sets `CharWeight` (bold), `CharPosture` (italic), `CharFontName` (monospace) via `XPropertySet`
- Prepends list markers (`"• "`, `"N. "`) for `QTextList` items
- Falls back to plain text for Impress / Calc
- Uses live view cursor if no selection was grabbed beforehand

---

## 7. Config Dialog

### 7.1 Tab 1 — Model Selection

Five-provider combo with conditional field visibility:
- **Ollama**: URL + auth mode (None / Basic / API Key) + model
- **OpenAI**: base URL + API key + model
- **Claude**: API key + model (hard-coded list)
- **Grok**: API key + model
- **Gemini**: API key + model

### 7.2 Tab 2 — General Settings

Language selector, logging enable/disable, log level, log max size.

### 7.3 Save Behaviour

1. Write fields to `Config`
2. Store keys in `CredentialStore`
3. `Config::save()` — writes `config.json`
4. `initLogging()` — applies log settings immediately
5. Language changed → `applyLanguage()` + `resetInstance()` on both singletons

---

## 8. UnoHelper

| Function | Description |
|----------|-------------|
| `setContext(ctx)` | Stores `XComponentContext` |
| `getCurrentFrame()` | Desktop → `getCurrentFrame()` |
| `getSelectedText()` | Detects Writer/Impress/Calc; returns selected string; remembers cursor/target |
| `applyText(text)` | Plain-text apply using remembered or live cursor |
| `applyRichText(doc)` | Rich-text apply for Writer; plain-text fallback for Impress/Calc |

Supported document types detected from controller service name:

| App | Detection | Selection | Apply |
|-----|-----------|-----------|-------|
| Writer | `text.TextDocumentView` | `XTextViewCursorSupplier` | `XText` + `XPropertySet` |
| Impress | `presentation.PresentationController` / `XDrawView` | `XSelectionSupplier` → shape | `XText::setString` |
| Calc | `sheet.SpreadsheetViewSettings` | `XSelectionSupplier` → cell | `XTextRange::setString` |

---

## 9. Build & Release

### 9.1 Quick Build

```bash
bash build.sh            # → libreai.oxt
bash build.sh --install  # → installs into LO
```

### 9.2 CI Pipelines

| Pipeline | Trigger | Platform |
|----------|---------|----------|
| `release.yml` | `v*` tag | Linux (Ubuntu 22.04 + 24.04) |
| `release-windows.yml` | `workflow_dispatch` | Windows x86_64 |
| `release-macos.yml` | `workflow_dispatch` | macOS ARM64 (Apple Silicon) |
| `test.yml` | push / PR | Linux — unit + integration tests |

### 9.3 Unit Tests

Three Google Test executables: `test_config`, `test_logger`, `test_ai_parsing`.

```bash
cmake -S . -B build -DBUILD_TESTS=ON -Wno-dev
cmake --build build --parallel $(nproc)
ctest --test-dir build --output-on-failure
```

---

## 10. Known Limitations

| Limitation | Details |
|------------|---------|
| Anthropic model list | Hard-coded in `AnthropicClient.cpp` — no public list-models endpoint |
| Chat history | In-memory only; lost on LibreOffice restart |
| Writer only for rich text | `applyRichText` applies formatting only in Writer; Impress/Calc receive plain text |
| Qt event loop | Runs on LO's main thread; keep Qt operations lightweight |
| Menu bar i18n | Follows LibreOffice's own UI language, not LibreAI's language setting |

---

## 11. Extension Identity

| Field | Value |
|-------|-------|
| Extension ID | `org.libreai` |
| Version | `1.0.8` |
| Implementation (job) | `org.libreai.job` |
| Implementation (starter) | `org.libreai.starter` |
| Native library (Linux) | `libreai.so` |
| Native library (macOS) | `libreai.dylib` |
| Native library (Windows) | `libreai.dll` |
