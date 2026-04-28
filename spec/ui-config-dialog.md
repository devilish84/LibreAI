# Config Dialog

**Class:** `ConfigDialog` (`src/ui/ConfigDialog.hpp` / `src/ui/ConfigDialog.cpp`)  
**Base:** `QWidget` with `Qt::Window` flag  
**Lifetime:** singleton via `ConfigDialog::instance()` / `ConfigDialog::resetInstance()`

Opens automatically on first launch when `Config::isConfigured()` returns false.  
Also opened explicitly by `LibreAIJob::trigger("config")`.

---

## Tabs

### Tab 1 — Model Selection

Single flat `QFormLayout` with fields shown/hidden per provider.

**Provider selector**

`QComboBox` with five entries: Ollama / OpenAI / Claude (Anthropic) / Grok (xAI) / Gemini (Google).

**Ollama fields**

| Control | Type | Visibility |
|---------|------|------------|
| Server URL | `QLineEdit` | Always (Ollama) |
| Authentication | `QComboBox` | Always (Ollama) — None / Basic / API Key |
| Username | `QLineEdit` | Basic auth only |
| Password | `QLineEdit` (password) | Basic auth only |
| Key Header | `QLineEdit` | API Key auth only |
| Key Value | `QLineEdit` (password) | API Key auth only |

**OpenAI fields**

| Control | Type |
|---------|------|
| Base URL | `QLineEdit` (default: `https://api.openai.com/v1`) |
| API Key | `QLineEdit` (password) |

**Claude fields**

| Control | Type |
|---------|------|
| API Key | `QLineEdit` (password) |

**Grok fields**

| Control | Type |
|---------|------|
| API Key | `QLineEdit` (password) |

**Gemini fields**

| Control | Type |
|---------|------|
| API Key | `QLineEdit` (password) |

**Model row (shared)**

| Control | Type | Purpose |
|---------|------|---------|
| Model | `QComboBox` | Populated by Refresh from the active provider |
| Refresh Models | `QPushButton` | Calls `AIClient::fetchModels()` asynchronously |

**Keychain hint** — `QLabel` below model row; shows which credential backend is active (e.g., "Keys stored in system keychain").

---

### Tab 2 — General Settings

| Control | Type | Purpose |
|---------|------|---------|
| Language | `QComboBox` | UI language |
| Enable logging | `QCheckBox` | Write log file (default: off) |
| Log level | `QComboBox` | Debug / Info / Error (disabled when logging off) |
| Max log size | `QSpinBox` | MB cap for log file (default: 10) |

Log file path: `~/.config/libreai/libreai.log` (fixed, shown as read-only label).

Language choices defined in `kLanguages[]` in `ConfigDialog.cpp`:

```cpp
static const std::pair<const char*, const char*> kLanguages[] = {
    {"en", "English"}, {"fi", "Suomi"}, {"sv", "Svenska"},
    {"da", "Dansk"},   {"nb", "Norsk"}, {"es", "Español"},
    {"de", "Deutsch"}, {"pt", "Português"},
};
```

---

## Save Behaviour (`onOk`)

1. Write all UI fields to `Config`.
2. Store API keys in `CredentialStore` (one call per provider key).
3. Call `Config::save()` — persists non-sensitive fields to `config.json`.
4. Call `initLogging()` to apply any log setting changes immediately.
5. If language changed: call `Config::applyLanguage()`, then `ChatWindow::resetInstance()` and `ConfigDialog::resetInstance()` — both singletons are destroyed and recreated in the new locale on next open.
6. Close the dialog.

---

## Credential Security

API key fields use `QLineEdit::setEchoMode(QLineEdit::Password)`. Keys are never written to `config.json`. On load, `Config()` retrieves them from `CredentialStore::retrieve()`. On save, `CredentialStore::store()` writes them to the platform backend. If the backend is `CredentialBackendMemory` (no secure storage), a warning hint is shown.

---

## Singleton Lifecycle

```cpp
ConfigDialog* ConfigDialog::instance();       // create-if-absent, show, raise
void          ConfigDialog::resetInstance();  // close + delete (called on language change)
```

---

## i18n

`ConfigDialog` is a `Q_OBJECT` class — use `tr("...")` for all strings.  
`retranslateUi()` is called from `changeEvent(QEvent::LanguageChange)`.  
Tab labels, button text, and placeholder text all go through `tr()`.
