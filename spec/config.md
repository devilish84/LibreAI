# Configuration

## Config Singleton

**File:** `src/Config.hpp` / `src/Config.cpp`

`Config` is a lazy-loaded singleton accessed via `Config::get()`. It reads `~/.config/libreai/config.json` once on first access and writes it on every explicit `save()` call.

```cpp
struct Config {
    Provider provider   = Provider::Ollama;
    QString  ollamaUrl  = "http://localhost:11434";
    QString  openaiUrl  = "https://api.openai.com/v1";
    QString  openaiKey;
    QString  claudeKey;
    QString  model;
    QString  language   = "en";
    bool     loggingEnabled = false;
    int      logLevel       = 1;   // 0=Debug  1=Info  2=Error

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();
private:
    Config();  // reads from disk
};
```

---

## JSON Schema

File path: `~/.config/libreai/config.json`  
Created automatically by `QStandardPaths::AppConfigLocation` on first save.

```json
{
  "provider":    "OLLAMA",
  "ollama_url":  "http://localhost:11434",
  "openai_url":  "https://api.openai.com/v1",
  "openai_key":  "",
  "claude_key":  "",
  "model":       "",
  "language":        "en",
  "logging_enabled": false,
  "log_level":       1
}
```

| Key | Type | Values |
|-----|------|--------|
| `provider` | string | `"OLLAMA"` \| `"OPENAI"` \| `"CLAUDE"` |
| `ollama_url` | string | Any HTTP URL |
| `openai_url` | string | Any OpenAI-compatible base URL |
| `openai_key` | string | OpenAI API key (empty = unauthenticated) |
| `claude_key` | string | Anthropic API key |
| `model` | string | Model identifier string |
| `language` | string | Two-letter language code (see [i18n.md](i18n.md)) |
| `logging_enabled` | bool | `true` = write log file, default `false` |
| `log_level` | int | `0`=Debug `1`=Info `2`=Error, default `1` |

---

## isConfigured()

Gates the ChatWindow — if false, ConfigDialog opens instead.

| Provider | Condition |
|----------|-----------|
| Ollama | `!model.isEmpty() && !ollamaUrl.isEmpty()` |
| OpenAI | `!model.isEmpty() && !openaiKey.isEmpty()` |
| Claude | `!model.isEmpty() && !claudeKey.isEmpty()` |

---

## applyLanguage()

Installs a `QTranslator` loaded from `:/i18n/libreai_<lang>.qm` (embedded resource).  
English (`"en"`) skips the translator entirely — the source strings are English.  
The previous translator is removed and deleted before installing the new one.

Called on startup by `LibreAIStarter` and on save by `ConfigDialog` when the language changes.

---

## initLogging() / closeLogging()

Defined in `src/Logger.hpp` / `src/Logger.cpp`. Installs a custom `QtMessageHandler` that writes timestamped lines to `~/.config/libreai/libreai.log` when `loggingEnabled` is true. Messages below `logLevel` are silently dropped. Thread-safe via `QMutex`. Re-calling `initLogging()` after a settings change takes effect immediately.
