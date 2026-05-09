# Configuration

## Config Singleton

**File:** `src/core/Config.hpp` / `src/core/Config.cpp`

`Config` is a lazy-loaded singleton accessed via `Config::get()`. It reads `~/.config/libreai/config.json` once on first access and writes it on every explicit `save()` call.

API keys are **not** stored in `config.json` — they are managed by `CredentialStore` using the platform's secure storage.

```cpp
enum class Provider   { Ollama, OpenAI, Claude, Grok, Gemini };
enum class OllamaAuth { None, Basic, ApiKey };

struct Config {
    Provider   provider  = Provider::Ollama;

    // URLs (all configurable)
    QString  ollamaUrl  = "http://localhost:11434";
    QString  openaiUrl  = "https://api.openai.com/v1";
    QString  claudeUrl  = "https://api.anthropic.com/v1";
    QString  grokUrl    = "https://api.x.ai/v1";
    QString  geminiUrl  = "https://generativelanguage.googleapis.com/v1beta";

    // Per-provider selected models (text generation)
    QString  ollamaModel;
    QString  openaiModel;
    QString  claudeModel;
    QString  grokModel;
    QString  geminiModel;

    // Ollama model whitelists (classified by user in Providers tab)
    QStringList ollamaTextModels;   // models available for text generation
    QStringList ollamaImageModels;  // models available for image generation

    // Image generation
    Provider imageProvider       = Provider::OpenAI;
    QString  ollamaImageModel;
    QString  openaiImageModel    = "dall-e-3";
    QString  grokImageModel      = "aurora";
    QString  geminiImageModel    = "imagen-3.0-generate-002";

    // Ollama auth (non-secret parts)
    OllamaAuth ollamaAuth            = OllamaAuth::None;
    QString    ollamaBasicUser;
    QString    ollamaApiKeyHeader    = "Authorization";

    // Credentials — runtime only, stored in OS keychain (never in JSON)
    QString  openaiKey;
    QString  claudeKey;
    QString  grokKey;
    QString  geminiKey;
    QString  ollamaBasicPass;
    QString  ollamaApiKeyValue;

    // Batch processing
    int  batchDelayMs     = 500;
    int  batchTimeoutSec  = 60;
    bool batchStopOnError = false;

    // UI / misc
    QString  language       = "en";
    bool     loggingEnabled = false;
    int      logLevel       = 1;   // 0=Debug  1=Info  2=Error
    int      maxLogSizeMb   = 5;

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();

    const QString& currentModel() const;
    void           setCurrentModel(const QString& m);
    const QString& currentImageModel() const;
    void           setCurrentImageModel(const QString& m);
private:
    Config();
};
```

---

## JSON Schema

File path: `~/.config/libreai/config.json`  
Created automatically by `QStandardPaths::AppConfigLocation` on first save.

```json
{
  "provider":              "OLLAMA",
  "ollama_url":            "http://localhost:11434",
  "openai_url":            "https://api.openai.com/v1",
  "claude_url":            "https://api.anthropic.com/v1",
  "grok_url":              "https://api.x.ai/v1",
  "gemini_url":            "https://generativelanguage.googleapis.com/v1beta",
  "ollama_model":          "",
  "openai_model":          "",
  "claude_model":          "",
  "grok_model":            "",
  "gemini_model":          "",
  "ollama_text_models":    ["phi:latest", "qwen3-coder:30b"],
  "ollama_image_models":   ["x/flux2-klein:latest"],
  "image_provider":        "OPENAI",
  "ollama_image_model":    "",
  "openai_image_model":    "dall-e-3",
  "grok_image_model":      "aurora",
  "gemini_image_model":    "imagen-3.0-generate-002",
  "ollama_auth":           "NONE",
  "ollama_basic_user":     "",
  "ollama_api_key_header": "Authorization",
  "batch_delay_ms":        500,
  "batch_timeout_s":       60,
  "batch_stop_on_error":   false,
  "language":              "en",
  "logging_enabled":       false,
  "log_level":             1,
  "max_log_size_mb":       5
}
```

API keys are **never written to this file**. They are stored in the platform credential backend:

| Provider | Credential key |
|----------|---------------|
| Ollama (basic) | `libreai/ollama_basic_pass` |
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
| Ollama | `!ollamaUrl.isEmpty()` |
| OpenAI | `!openaiKey.isEmpty()` |
| Claude | `!claudeKey.isEmpty()` |
| Grok | `!grokKey.isEmpty()` |
| Gemini | `!geminiKey.isEmpty()` |

---

## currentModel() / currentImageModel()

Returns the model string for the active provider. `setCurrentModel()` / `setCurrentImageModel()` write back to the appropriate per-provider field.

---

## applyLanguage()

Installs a `QTranslator` loaded from `:/i18n/libreai_<lang>.qm` (embedded resource).  
English (`"en"`) skips the translator entirely — the source strings are English.  
The previous translator is removed and deleted before installing the new one.

Called on startup by `LibreAIStarter` and on save by `ConfigDialog` when the language changes.

---

## initLogging() / closeLogging()

Defined in `src/core/Logger.hpp` / `src/core/Logger.cpp`. Installs a custom `QtMessageHandler` that writes timestamped lines to `~/.config/libreai/libreai.log` when `loggingEnabled` is true. Messages below `logLevel` are silently dropped. Thread-safe via `QMutex`. Re-calling `initLogging()` after a settings change takes effect immediately.

Log size is capped at `maxLogSizeMb` megabytes — if the file exceeds this on open, it is truncated.
