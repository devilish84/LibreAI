# Changelog

All notable changes to LibreAI are documented here.

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
