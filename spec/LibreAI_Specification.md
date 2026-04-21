# LibreAI — Technical Specification

## 1. Overview

LibreAI is a LibreOffice Writer extension that provides an AI writing assistant
through a floating Qt6 chat window. It connects to locally-running Ollama models
or cloud AI providers (OpenAI, Anthropic Claude) and enables in-document text
selection, chat, rewriting, and applying AI responses directly to the document.

The extension is implemented in **C++17 with Qt 6** as a native UNO component
(shared library `.so`), avoiding any Java dependency.

---

## 2. Goals

| Goal | Description |
|------|-------------|
| Native C++ component | No Java required; loads reliably on any LO 7.x Linux installation |
| Multi-provider | Ollama (local), OpenAI, and Anthropic Claude in one UI |
| Writer integration | Grab selected text, rewrite it, apply response back to document |
| Right-click access | "Ask from AI" context-menu item pre-loads selected text |
| Cold-start context menu | Interceptor installed at startup via `XDocumentEventBroadcaster` |
| Persistent config | Provider, URL/key, and model survive restarts (`~/.config/libreai/config.json`) |
| Dark theme | VS Code-inspired dark UI: `#1E1E1E` background, `#0E639C` accent |
| Async networking | All AI HTTP calls are non-blocking (`QNetworkAccessManager`) |

---

## 2. Architecture

```
libreai/
├── src/
│   ├── component.cpp          UNO entry points (component_getFactory, component_writeInfo)
│   ├── LibreAIJob.hpp/cpp     XJobExecutor — handles menu/toolbar/right-click trigger
│   ├── LibreAIStarter.hpp/cpp XJob — runs at LO startup; installs context-menu interceptor
│   ├── CMInterceptor.hpp/cpp  XContextMenuInterceptor — injects "Ask from AI" into right-click
│   ├── ChatWindow.hpp/cpp     Qt6 floating chat window (singleton)
│   ├── AIClient.hpp           Abstract base for AI provider clients
│   ├── OllamaClient.hpp/cpp   Ollama REST API client
│   ├── OpenAIClient.hpp/cpp   OpenAI-compatible REST API client
│   ├── AnthropicClient.hpp/cpp Anthropic Claude REST API client
│   ├── Config.hpp/cpp         JSON config singleton (~/.config/libreai/config.json)
│   └── UnoHelper.hpp/cpp      LO UNO utilities (get selection, apply text, current frame)
├── META-INF/manifest.xml      Extension manifest
├── Addons.xcu                 Menu bar + toolbar item registration
├── Jobs.xcu                   Startup job binding (onStartApp / onNew / onLoad)
├── description.xml            Extension metadata
├── CMakeLists.txt             CMake build (Qt6 + LO SDK headers)
└── build.sh                   Configure + build + package → libreai.oxt [+ --install]
```

### 2.1 Service Names

| Service | Implementation class | Triggered by |
|---------|---------------------|--------------|
| `org.libreai.job` | `LibreAIJob` | Menu, toolbar, right-click `service:` URL |
| `org.libreai.starter` | `LibreAIStarter` | Jobs.xcu events: `onStartApp`, `onNew`, `onLoad` |

### 2.2 Startup Sequence

```
LO starts
  → Jobs.xcu fires org.libreai.starter (onStartApp / onNew / onLoad)
      → LibreAIStarter::execute()
          → installInterceptors()
              → XDesktop → XFramesSupplier → iterate all open frames
              → tryInstallInterceptor(frame) for each
          → attachDocumentListener()
              → XDocumentEventBroadcaster singleton (getValueByName)
              → DocListener registered for OnViewCreated / OnNew / OnLoad / OnFocus
```

### 2.3 Chat Window Activation

```
User clicks "Open chat" menu item (or toolbar button)
  → LibreAIJob::trigger("open")
      → QApplication created once if not yet running
      → ChatWindow::instance() shown
      → tryInstallInterceptor(currentFrame) called as side-effect
```

### 2.4 Right-Click Flow

```
User right-clicks in Writer
  → CMInterceptor::notifyContextMenuExecute()
      → Appends separator + ActionTrigger "Ask from AI"
        (CommandURL = "service:org.libreai.job?open_with_sel")
      → Returns CONTINUE_MODIFIED
User clicks "Ask from AI"
  → LibreAIJob::trigger("open_with_sel")
      → ChatWindow shown with selected text pre-filled
```

---

## 3. Component Specifications

### 3.1 ChatWindow (Qt6 UI)

**Technology:** `QWidget` singleton with `Qt::Tool` window flag (stays above LO).

**Layout** (top → bottom):

| Widget | Type | Purpose |
|--------|------|---------|
| Provider | `QComboBox` | Ollama / OpenAI / Claude |
| Connection | `QLineEdit` | Base URL (Ollama/OpenAI) or API key (Claude) |
| Model | `QComboBox` | Populated from provider on Refresh |
| Refresh Models | `QPushButton` | Fetches model list asynchronously |
| Selected Text | `QTextEdit` | Editable; pre-filled from Writer selection |
| Grab Selection | `QPushButton` | Re-grabs current Writer selection |
| Instruction | `QTextEdit` | User prompt / instruction |
| Send | `QPushButton` | Sends request to AI provider |
| Response | `QTextEdit` (read-only) | AI response |
| Apply to Document | `QPushButton` | Replaces Writer selection with response text |

**Color palette:**

| Token | Hex | Use |
|-------|-----|-----|
| `C_BG` | `#1E1E1E` | Window background |
| `C_SURFACE` | `#2D2D2D` | Input / textarea background |
| `C_TEXT` | `#D4D4D4` | Primary text |
| `C_BTN` | `#0E639C` | Primary buttons (Send, Apply) |
| `C_BTN2` | `#3C3C3C` | Secondary buttons (Refresh, Grab) |

**Networking:** All provider calls use `QNetworkAccessManager` with signals/slots
(`finished`). No blocking calls are made on any thread.

### 3.2 Config

**File:** `~/.config/libreai/config.json`

```json
{
  "provider": "OLLAMA",
  "ollama_url": "http://localhost:11434",
  "openai_url": "https://api.openai.com/v1",
  "openai_key": "",
  "claude_key": "",
  "model": ""
}
```

Loaded and saved via `Config::get()` singleton (Qt JSON). Written on every change.

### 3.3 AI Provider Clients

All extend `AIClient : QObject` with signals:

```cpp
signals:
    void modelsReady(QStringList models);
    void responseReady(QString text);
    void errorOccurred(QString error);
```

Pure virtuals:

```cpp
virtual void fetchModels() = 0;
virtual void sendChat(const QString& model,
                      const QList<QPair<QString,QString>>& history,
                      const QString& prompt) = 0;
```

| Provider | List models | Chat endpoint | Auth |
|----------|------------|---------------|------|
| Ollama | `GET /api/tags` | `POST /api/chat` (`stream: false`) | None |
| OpenAI | `GET /v1/models` | `POST /v1/chat/completions` | `Authorization: Bearer <key>` |
| Anthropic | Hard-coded list | `POST /v1/messages` | `x-api-key: <key>` |

Connect/read timeout: 30 s (`QNetworkRequest::setTransferTimeout`).

### 3.4 UnoHelper

Namespace-scoped utilities (no class):

| Function | Description |
|----------|-------------|
| `setContext(ctx)` | Stores `XComponentContext` for later use |
| `getCurrentFrame()` | Desktop → `getCurrentFrame()` |
| `getSelectedText()` | Frame → Controller → `XTextViewCursorSupplier` → `getString()` |
| `applyText(text)` | Frame → Controller → cursor → `setString(text)` |

### 3.5 CMInterceptor

Singleton instance (static in `LibreAIStarter.cpp`). Registered on each
`XController` that supports `XContextMenuInterception`. De-duplication tracked
via `std::set<sal_IntPtr> s_intercepted` keyed on controller pointer.

Appends to every context menu:
1. `com.sun.star.ui.ActionTriggerSeparator`
2. `com.sun.star.ui.ActionTrigger` with `Text = "Ask from AI"` and
   `CommandURL = "service:org.libreai.job?open_with_sel"`

---

## 4. Configuration Files

### 4.1 Addons.xcu
Registers:
- **OfficeMenuBar** → `LibreAI` top-level menu → "Open chat"
- **OfficeToolBar** → toolbar button

### 4.2 Jobs.xcu
Binds `org.libreai.starter` (XJob) to:
- `onStartApp` — LO application launch
- `onNew` — new document created
- `onLoad` — existing document opened

---

## 5. Build & Distribution

### Build requirements

| Dependency | Package / Notes |
|------------|----------------|
| CMake 3.16+ | `cmake` |
| GCC / Clang (C++17) | `build-essential` |
| Qt 6 (Core, Widgets, Network) | `qt6-base-dev` |
| LO SDK headers | `/usr/include/libreoffice` (from `libreoffice-dev`) |
| LO SDK libs | `/usr/lib/libreoffice/sdk/lib` (`libuno_*.so`) |

### Build steps

```bash
cd /home/devilish/projects/libreai
bash build.sh            # CMake configure + build + zip → libreai.oxt
bash build.sh --install  # also installs via unopkg into LO user profile
```

### Output

`libreai.oxt` — ZIP archive containing:
- `libreai.so` (compiled native component, `Linux_X86_64` platform)
- `META-INF/manifest.xml`
- `Addons.xcu`, `Jobs.xcu`, `description.xml`

### Runtime requirements

| Requirement | Notes |
|-------------|-------|
| LibreOffice 7.x | Tested on LO 7.3.7 (Ubuntu) |
| Qt 6 runtime | `libqt6widgets6`, `libqt6network6` |
| Ollama (optional) | Running at `http://localhost:11434` |
| OpenAI API key (optional) | For GPT models |
| Anthropic API key (optional) | For Claude models |

---

## 6. Known Limitations

| Limitation | Details |
|------------|---------|
| Context menu cold-start | Interceptor registration via `XDocumentEventBroadcaster` may lag one event cycle on first launch |
| Chat history is in-memory | Clears when LO restarts |
| Anthropic model list is hard-coded | Anthropic has no public list-models REST endpoint |
| Qt event loop inside LO | `QApplication` runs within LO's main thread; heavy Qt operations could affect LO responsiveness |
| Writer only | `UnoHelper` uses `XTextViewCursorSupplier` which is Writer-specific |

---

## 7. Extension Identity

| Field | Value |
|-------|-------|
| Extension ID | `org.libreai` |
| Version | `1.0.0` |
| Implementation (job) | `org.libreai.job` |
| Implementation (starter) | `org.libreai.starter` |
| Native library | `libreai.so` (Linux_X86_64) |
