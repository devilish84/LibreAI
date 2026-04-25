# Config Dialog

**Class:** `ConfigDialog` (`src/ConfigDialog.hpp` / `src/ConfigDialog.cpp`)  
**Base:** `QWidget` with `Qt::Window` flag  
**Lifetime:** singleton via `ConfigDialog::instance()` / `ConfigDialog::resetInstance()`

Opens automatically on first launch when `Config::isConfigured()` returns false.  
Also opened explicitly by `LibreAIJob::trigger("config")`.

---

## Tabs

### Tab 1 — AI Provider

| Control | Type | Purpose |
|---------|------|---------|
| Provider | `QComboBox` | Ollama / OpenAI / Claude |
| Ollama URL | `QLineEdit` | Base URL for local Ollama instance (default: `http://localhost:11434`) |
| OpenAI URL | `QLineEdit` | Base URL for OpenAI-compatible endpoint (default: `https://api.openai.com/v1`) |
| OpenAI Key | `QLineEdit` (password) | API key for OpenAI |
| Claude Key | `QLineEdit` (password) | API key for Anthropic Claude |
| Model | `QComboBox` | Selected model — populated by Refresh |
| Refresh Models | `QPushButton` | Fetches model list from active provider |
| Status | `QLabel` | Connection feedback |

Fields shown/hidden based on the selected provider (Ollama shows URL only; OpenAI shows URL + key; Claude shows key only).

### Tab 1 — General Settings

| Control | Type | Purpose |
|---------|------|---------|
| Language | `QComboBox` | UI language selector |
| Enable logging | `QCheckBox` | Enables writing log output to file (default: off) |
| Level | `QComboBox` | Minimum log level: Debug / Info / Error (default: Info) |

The Level combo and its label are disabled when the checkbox is unchecked.  
Log file path: `~/.config/libreai/libreai.log` (fixed, not user-configurable).

Language choices are defined in `kLanguages[]` in `ConfigDialog.cpp`:

```cpp
static const std::pair<const char*, const char*> kLanguages[] = {
    {"en", "English"}, {"fi", "Suomi"}, {"sv", "Svenska"},
    {"da", "Dansk"},   {"nb", "Norsk"}, {"es", "Español"},
    {"de", "Deutsch"}, {"pt", "Português"},
};
```

---

## Save Behaviour

On **Save**:
1. Write all fields to `Config` and call `Config::save()`.
2. If language changed: call `Config::applyLanguage()`, then `ChatWindow::resetInstance()` and `ConfigDialog::resetInstance()` — both singletons are destroyed and will be recreated in the new locale on next open.
3. Close the dialog.

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

Tab labels, button text, and placeholder text all go through `tr()` so they update instantly when the translator is swapped.
