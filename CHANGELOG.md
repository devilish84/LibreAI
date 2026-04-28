# Changelog

All notable changes to LibreAI are documented here.

---

## [1.0.8] — 2026-04-28

### Added

- **Grok (xAI) provider** — new `GrokClient` using the xAI API (`api.x.ai/v1`); OpenAI-compatible wire format; model list fetched live with embed/image/audio/vision models excluded.
- **Gemini (Google) provider** — new `GeminiClient` using the Gemini `generateContent` API; `"assistant"` history role mapped to `"model"`; model list fetched live with embedding/aqa/retrieval/vision models excluded.
- **Markdown rendering** — response area upgraded from `QPlainTextEdit` to `QTextEdit` with `setMarkdown()`; headers, bold, italic, inline code, code blocks, blockquotes, and links rendered natively with a dark-theme stylesheet.
- **Rich text apply** — "Apply to Document" now transfers Markdown formatting as native LibreOffice Writer styles: headings become Heading 1–6 paragraph styles, bold/italic set via `CharWeight`/`CharPosture`, code spans use Courier New, bullet and numbered list items are prefixed automatically; falls back to plain text for Impress and Calc.
- **Platform credential backends** — `ICredentialBackend` interface extracted; per-platform implementations: `CredentialBackendKeychain` (Linux Qt6Keychain), `CredentialBackendMacOS` (macOS Security.framework), `CredentialBackendDPAPI` (Windows DPAPI), `CredentialBackendMemory` (in-memory fallback). Backend selected at compile time via preprocessor flags.
- **macOS release pipeline** — new `.github/workflows/release-macos.yml` targeting `macos-14` (Apple Silicon); Qt6 installed via `jurplel/install-qt-action`; LO SDK downloaded from funet mirror; Qt frameworks bundled with a custom `copy_qt_dep()` shell function using `otool` + `install_name_tool`.

### Changed

- **Provider list extended to 5** — `Provider` enum now includes `Ollama`, `OpenAI`, `Claude`, `Grok`, `Gemini`; ConfigDialog, Config, ChatWindow, and unit tests all updated.
- **Per-provider model fields** — `Config` now has `grokModel` and `geminiModel` alongside the existing per-provider fields; `currentModel()` and `isConfigured()` cover all five providers.
- **Credential keys** — Grok stored as `libreai/grok_key`, Gemini as `libreai/gemini_key`.
- **`applyRichText` works without prior Grab Selection** — falls back to the live Writer view cursor so Apply works even when no text was grabbed beforehand.
- **CMake `if(NOT VAR)` guards** — platform default paths now use `if(NOT LO_INCLUDE)` / `if(NOT LO_SDK_LIB)` guards so `-D` flags from CI override them correctly.
- **Release workflow body** — Linux release workflow updated to include macOS row in the Downloads table and updated description.

### Fixed

- **`CredentialBackendDPAPI.hpp` missing `#include <QJsonObject>`** — MSVC requires explicit includes; GCC/Clang accepted it via transitive includes. Caused Windows CI build failure.
- **`GeminiClient` most-vexing-parse** — `QNetworkRequest req(QUrl(url))` was parsed as a function declaration by MSVC; fixed by splitting into two statements.
- **`applyRichText` bullet points lost** — Qt does not include list marker characters in `QTextFragment` text; detected via `QTextBlock::textList()` and prefixed manually.

---

## [1.0.7] — 2026-04-26

### Added

- **Chat history pane** — collapsible "▶ History (N)" panel in the chat window lists all exchanges for the current session; user messages shown in light text, AI responses in teal; scrolls to the latest entry automatically.
- **Clear History button** — clears the in-memory conversation context mid-session so the AI starts fresh without restarting LibreOffice.
- **Message metadata** — each history entry now carries a timestamp (ISO 8601), provider name, and model name for improved log diagnostics.
- **Log rotation** — `libreai.log` is rotated to `.log.1` / `.log.2` when it exceeds the configured max size (default 5 MB); configurable via a new "MAX SIZE" spinbox in General Settings.
- **Log file path display** — General Settings tab now shows the exact path of the log file as a read-only, selectable label.
- **Unit tests for Logger** — 8 new GTest cases covering log file creation, close behaviour, level filtering, and log rotation.
- **Unit tests for AI client JSON parsing** — 17 new GTest cases covering model list parsing (exclusion filters, sorting, empty/malformed input) and response extraction for all three providers (Ollama, OpenAI, Anthropic).

### Changed

- **AI client JSON parsing extracted** — `parseModels()` and `parseResponse()` are now public static methods on each client class, making them independently testable without network calls.
- **Request IDs in logs** — each `sendChat` call is tagged with an incrementing `reqId` so request and response log lines can be correlated even when calls interleave.
- **`Config`** — new fields: `maxLogSizeMb` (default 5), persisted as `max_log_size_mb`.
- **Test CMakeLists** — refactored with a shared `libreai_test` macro; added `test_logger` and `test_ai_parsing` executables.

### Fixed

- **Log path wrong on first launch** — `LibreAIJob::trigger` called `Config::applyLanguage()` (which initialises the Config singleton) before `QCoreApplication::setApplicationName("libreai")` was set, causing the log to be written to `~/.config/libreai.log` instead of `~/.config/libreai/libreai.log`. Fixed by setting the application name at the top of `trigger()`.

---

## [1.0.6] — 2026-04-25

### Added

- **Per-provider model persistence** — each provider (Ollama, OpenAI, Claude) now remembers its own selected model independently; switching providers no longer loses the previous selection.
- **Ollama remote authentication** — Ollama can now be used behind a reverse proxy requiring HTTP Basic Auth or an API-key header. Auth mode (None / Basic / API Key) is configurable in the Configuration dialog.
- **Secure credential storage** — API keys and passwords are now stored in the OS keychain (QtKeychain on Linux, DPAPI on Windows) and are never written to `config.json`. If the keychain is unavailable a warning is shown in the dialog.
- **Comprehensive file logging** — all activity is written to `~/.config/libreai/libreai.log`. Every method logs at least a debug-level entry on entry. HTTP request/response bodies are logged at debug level when verbose logging is enabled; auth headers are never logged.
- **Configurable log verbosity** — new "Enable verbose logging" checkbox and log-level selector in Configuration → General Settings. The log file is always written regardless of this setting (at Info level when disabled).
- **CredentialStore** (`src/core/CredentialStore.hpp/cpp`) — new platform-abstracted credential backend with QtKeychain (Linux), DPAPI (Windows), and in-memory fallback.

### Changed

- **ConfigDialog — flat form layout** — the Model Selection tab now uses a single flat `QFormLayout` with rows shown/hidden per provider, replacing nested `QWidget` section containers that caused black rendering in the Qt-inside-LibreOffice embedding context.
- **ConfigDialog — provider fields shown/hidden dynamically** — only the fields relevant to the selected provider are visible. Ollama auth sub-fields (user/pass or header/key) appear/disappear based on the auth mode selection.
- **`isConfigured()` no longer requires a model** — previously the extension required both credentials *and* a model to be selected before the chat window would open. Now only connectivity credentials (URL for Ollama, API key for OpenAI/Claude) are required; model can be selected later.
- **`config.json` schema updated** — new fields: `ollama_auth`, `ollama_basic_user`, `ollama_api_key_header`, `ollama_model`, `openai_model`, `claude_model`, `logging_enabled`, `log_level`. Legacy `model` field is migrated to the correct per-provider field on first load.
- **`QCoreApplication::applicationName`** set to `"libreai"` immediately after QApplication creation, fixing `QStandardPaths::AppConfigLocation` returning the wrong path (and thus the log file not being created).
- **OllamaClient** updated to accept `OllamaAuthConfig` and inject auth headers into all requests.
- **CI pipelines** — added `qtkeychain-qt6-dev` to all Ubuntu install steps.

### Fixed

- Log file written to `~/.config/libreai/libreai.log` (was `~/.config/libreai.log` due to empty application name).
- Logging was completely disabled when `loggingEnabled=false` — now always active at Info level.
- ConfigDialog rendered black after the per-provider section refactor — fixed by flattening the widget hierarchy.
- Extension failed to load with `undefined symbol: CredentialStore::isAvailable` — `CredentialStore.cpp` was missing from CMakeLists SOURCES.
- Qt6Keychain `find_package` failed on systems without `qt6-dbus-dev` — added manual `find_library` fallback.

---

## [1.0.5] — 2026-03-xx

- Configuration dialog with tabs (General Settings, Model Selection)
- i18n support (8 languages); language selectable from Configuration
- Auto-open on startup: chat window if configured, Configuration dialog otherwise
- Qt file logging foundation

## [1.0.4] and earlier

See git log for earlier history.
