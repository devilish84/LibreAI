# Configuration

## Config Singleton

**File:** `src/core/Config.hpp` / `src/core/Config.cpp`

`Config` is a lazy-loaded singleton accessed via `Config::get()`. It reads `~/.config/libreai/config.json` once on first access and writes it on every explicit `save()` call.

API keys are **not** stored in `config.json` — they are managed by `CredentialStore` using the platform's secure storage.

```cpp
enum class Provider { Ollama, OpenAI, Claude, Grok, Gemini };

struct OllamaAuthConfig {
    enum class Mode { None, Basic, ApiKey };
    Mode    mode;
    QString user, password;
    QString keyHeader, keyValue;
    static OllamaAuthConfig fromConfig();
};

struct Config {
    Provider provider       = Provider::Ollama;
    QString  ollamaUrl      = "http://localhost:11434";
    OllamaAuthConfig::Mode ollamaAuthMode = OllamaAuthConfig::Mode::None;
    QString  ollamaAuthUser;
    QString  ollamaAuthKeyHeader;
    QString  openaiUrl      = "https://api.openai.com/v1";
    QString  ollamaModel;
    QString  openaiModel;
    QString  claudeModel;
    QString  grokModel;
    QString  geminiModel;
    QString  language       = "en";
    bool     loggingEnabled = false;
    int      logLevel       = 1;   // 0=Debug  1=Info  2=Error
    int      logMaxSizeMB   = 10;

    // Runtime-only (not persisted)
    QString  openaiKey;
    QString  claudeKey;
    QString  grokKey;
    QString  geminiKey;

    static Config& get();
    void save() const;
    bool isConfigured() const;
    QString currentModel() const;
    static void applyLanguage();
private:
    Config();  // reads from disk + loads keys from CredentialStore
};
```

---

## JSON Schema

File path: `~/.config/libreai/config.json`  
Created automatically by `QStandardPaths::AppConfigLocation` on first save.

```json
{
  "provider":           "OLLAMA",
  "ollama_url":         "http://localhost:11434",
  "ollama_auth_mode":   0,
  "ollama_auth_user":   "",
  "ollama_auth_key_header": "",
  "openai_url":         "https://api.openai.com/v1",
  "ollama_model":       "",
  "openai_model":       "",
  "claude_model":       "",
  "grok_model":         "",
  "gemini_model":       "",
  "language":           "en",
  "logging_enabled":    false,
  "log_level":          1,
  "log_max_size_mb":    10
}
```

API keys are **never written to this file**. They are stored in the platform credential backend under the keys:

| Provider | Credential key |
|----------|---------------|
| Ollama (basic) | `libreai/ollama_password` |
| Ollama (API key) | `libreai/ollama_api_key` |
| OpenAI | `libreai/openai_key` |
| Claude | `libreai/claude_key` |
| Grok | `libreai/grok_key` |
| Gemini | `libreai/gemini_key` |

---

## isConfigured()

Gates the ChatWindow — if false, ConfigDialog opens instead.

| Provider | Condition |
|----------|-----------|
| Ollama | `!ollamaModel.isEmpty() && !ollamaUrl.isEmpty()` |
| OpenAI | `!openaiModel.isEmpty() && !openaiKey.isEmpty()` |
| Claude | `!claudeModel.isEmpty() && !claudeKey.isEmpty()` |
| Grok | `!grokModel.isEmpty() && !grokKey.isEmpty()` |
| Gemini | `!geminiModel.isEmpty() && !geminiKey.isEmpty()` |

---

## currentModel()

Returns the model string for the active provider:

```cpp
QString Config::currentModel() const {
    switch (provider) {
        case Provider::Ollama:  return ollamaModel;
        case Provider::OpenAI:  return openaiModel;
        case Provider::Claude:  return claudeModel;
        case Provider::Grok:    return grokModel;
        case Provider::Gemini:  return geminiModel;
    }
}
```

---

## applyLanguage()

Installs a `QTranslator` loaded from `:/i18n/libreai_<lang>.qm` (embedded resource).  
English (`"en"`) skips the translator entirely — the source strings are English.  
The previous translator is removed and deleted before installing the new one.

Called on startup by `LibreAIStarter` and on save by `ConfigDialog` when the language changes.

---

## initLogging() / closeLogging()

Defined in `src/core/Logger.hpp` / `src/core/Logger.cpp`. Installs a custom `QtMessageHandler` that writes timestamped lines to `~/.config/libreai/libreai.log` when `loggingEnabled` is true. Messages below `logLevel` are silently dropped. Thread-safe via `QMutex`. Re-calling `initLogging()` after a settings change takes effect immediately.

Log size is capped at `logMaxSizeMB` megabytes — if the file exceeds this on open, it is truncated.
