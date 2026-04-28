# Architecture

## Overview

LibreAI is a native **C++17 / Qt6** LibreOffice UNO component (shared library `.so` / `.dylib` / `.dll`). It has no Java dependency. The extension registers two UNO services:

| Service | Implementation | Triggered by |
|---------|---------------|--------------|
| `org.libreai.job` | `LibreAIJob` | Menu, toolbar, right-click `service:` URL |
| `org.libreai.starter` | `LibreAIStarter` | `Jobs.xcu` events: `onStartApp`, `onNew`, `onLoad` |

---

## Class Map

| Class / Namespace | File | Role |
|-------------------|------|------|
| `LibreAIJob` | `src/uno/LibreAIJob.cpp` | `XJobExecutor` — dispatches `open`, `config`, `open_with_sel` |
| `LibreAIStarter` | `src/uno/LibreAIStarter.cpp` | `XJob` — runs at LO startup; creates `QApplication`, opens first window, installs interceptors |
| `CMInterceptor` | `src/uno/CMInterceptor.cpp` | `XContextMenuInterceptor` — injects "Ask from AI" right-click item |
| `UnoHelper` | `src/uno/UnoHelper.cpp` | Free functions: `getSelectedText()`, `applyText()`, `applyRichText()`, `getCurrentFrame()` |
| `ChatWindow` | `src/ui/ChatWindow.cpp` | Qt6 singleton chat panel (`QWidget`, `Qt::Window`) |
| `ConfigDialog` | `src/ui/ConfigDialog.cpp` | Qt6 singleton config dialog (two tabs) |
| `Config` | `src/core/Config.cpp` | JSON config singleton (`~/.config/libreai/config.json`) |
| `CredentialStore` | `src/core/CredentialStore.cpp` | Credential façade — selects platform backend at compile time |
| `ICredentialBackend` | `src/core/CredentialStore.hpp` | Abstract credential backend interface |
| `CredentialBackendKeychain` | `src/core/CredentialBackendKeychain.cpp` | Linux Qt6Keychain backend (`HAVE_KEYCHAIN`) |
| `CredentialBackendMacOS` | `src/core/CredentialBackendMacOS.cpp` | macOS Security.framework backend (`HAVE_MACOS_KEYCHAIN`) |
| `CredentialBackendDPAPI` | `src/core/CredentialBackendDPAPI.cpp` | Windows DPAPI backend (`HAVE_DPAPI`) |
| `CredentialBackendMemory` | `src/core/CredentialBackendMemory.cpp` | In-memory fallback (no persistence) |
| `Logger` | `src/core/Logger.cpp` | Qt message handler — file logging with level filtering |
| `AIClient` | `src/ai/AIClient.hpp` | Abstract Qt base for all provider clients |
| `OllamaClient` | `src/ai/OllamaClient.cpp` | Ollama REST client |
| `OpenAIClient` | `src/ai/OpenAIClient.cpp` | OpenAI-compatible REST client |
| `AnthropicClient` | `src/ai/AnthropicClient.cpp` | Anthropic Claude REST client |
| `GrokClient` | `src/ai/GrokClient.cpp` | xAI Grok REST client (OpenAI-compatible) |
| `GeminiClient` | `src/ai/GeminiClient.cpp` | Google Gemini REST client |

---

## Startup Sequence

```
LibreOffice starts
  → Jobs.xcu fires org.libreai.starter
      → LibreAIStarter::execute()
          → installInterceptors()
              iterate all open frames → tryInstallInterceptor(frame)
          → attachDocumentListener()   [once only]
              registers DocListener for OnViewCreated / OnNew / OnLoad
          → (first call only)
              QApplication created
              Config::applyLanguage()
              Config::isConfigured() ? ChatWindow::instance() : ConfigDialog::instance()
```

`OnViewCreated` is the critical event — the frame controller is fully ready at that point, so `registerContextMenuInterceptor` reliably succeeds there.

---

## Trigger Arguments

`LibreAIJob::trigger(args)` dispatches on the string argument:

| Argument | Action |
|----------|--------|
| `"open"` | Show `ChatWindow` (or `ConfigDialog` if not configured) |
| `"config"` | Show `ConfigDialog` |
| `"open_with_sel"` | Show `ChatWindow` with current Writer selection pre-filled |

---

## Singleton Pattern

Both `ChatWindow` and `ConfigDialog` use a static `s_instance` pointer with `instance()` / `resetInstance()`. `resetInstance()` closes and deletes the window — called on language change so the window is recreated with the new locale.

---

## Credential Backend Selection

The credential backend is chosen at **compile time** via preprocessor flags:

```
HAVE_KEYCHAIN       → CredentialBackendKeychain   (Linux + Qt6Keychain)
HAVE_MACOS_KEYCHAIN → CredentialBackendMacOS      (macOS Security.framework)
HAVE_DPAPI          → CredentialBackendDPAPI       (Windows DPAPI)
(fallback)          → CredentialBackendMemory      (in-memory, not persistent)
```

The factory lives in `CredentialStore::backend()` as a `static std::unique_ptr<ICredentialBackend>`. All credential keys are logged at Debug level; **values are never logged**.

---

## Interceptor De-duplication

`s_intercepted` (`std::set<sal_IntPtr>`) tracks frame pointers. A frame is added to the set only **after** `registerContextMenuInterceptor` succeeds. If the controller is not ready yet the frame is left out so it will be retried on the next document event.

---

## Qt Inside LibreOffice — Constraints

- **`QApplication` is created once** and never destroyed. It lives for the LO session.
- **All Qt windows use `Qt::Window` flag** — never `QDialog::exec()`, which blocks the UNO thread and triggers LO's "not responding" watchdog.
- **All AI HTTP calls are async** via `QNetworkAccessManager`. Never block the UNO thread with `QEventLoop` or similar.
- On **Windows**, Qt plugin path must be set from `GetModuleFileNameW(libreai_module_handle(), ...)` before `QApplication` is constructed.
- **`sal_Unicode*` vs `const ushort*`**: on MSVC these are unrelated pointer types. Always use `reinterpret_cast<const sal_Unicode*>(qstring.utf16())` when passing Qt strings to `rtl::OUString`.

---

## Directory Layout

```
libreai/
├── src/
│   ├── uno/                    UNO glue layer
│   │   ├── component.cpp       component_getFactory / component_writeInfo
│   │   ├── LibreAIJob.*        XJobExecutor
│   │   ├── LibreAIStarter.*    XJob (startup)
│   │   ├── CMInterceptor.*     XContextMenuInterceptor
│   │   └── UnoHelper.*         getSelectedText / applyText / applyRichText
│   ├── core/                   Platform-independent core
│   │   ├── Config.*            JSON config singleton
│   │   ├── CredentialStore.*   Backend factory + interface
│   │   ├── CredentialBackend*  Per-platform implementations
│   │   └── Logger.*            Qt file logger
│   ├── ai/                     AI provider clients
│   │   ├── AIClient.hpp        Abstract base + Message struct
│   │   ├── OllamaClient.*
│   │   ├── OpenAIClient.*
│   │   ├── AnthropicClient.*
│   │   ├── GrokClient.*
│   │   └── GeminiClient.*
│   └── ui/                     Qt widgets
│       ├── ChatWindow.*
│       └── ConfigDialog.*
├── include/                    UNO SDK headers (generated by cppumaker)
├── translations/               Qt .ts / .qm files + .qrc
├── tests/
│   ├── unit/                   Google Test suites
│   └── integration/            pytest + python-uno tests
├── spec/                       This documentation
├── .github/workflows/          CI pipelines
├── META-INF/manifest.xml
├── Addons.xcu
├── Jobs.xcu
├── description.xml
├── CMakeLists.txt
└── build.sh
```
