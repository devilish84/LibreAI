# Config Dialog

**Class:** `ConfigDialog` (`src/ui/ConfigDialog.hpp` / `src/ui/ConfigDialog.cpp`)  
**Base:** `QWidget` with `Qt::Window` flag  
**Minimum size:** 760 × 600 (resizes to 820 × 660)  
**Lifetime:** singleton via `ConfigDialog::instance()` / `ConfigDialog::resetInstance()`

Opens automatically on first launch when `Config::isConfigured()` returns false.  
Also opened explicitly by `LibreAIJob::trigger("config")`.

---

## Tabs

### Tab 1 — General Settings

| Control | Type | Purpose |
|---------|------|---------|
| Language | `QComboBox` | UI language |
| Enable logging | `QCheckBox` | Write log file (default: off) |
| Log level | `QComboBox` | Debug / Info / Error (disabled when logging off) |
| Max log size | `QSpinBox` | MB cap for log file (default: 5) |

Log file path: `~/.config/libreai/libreai.log` (fixed, shown as read-only label).

Language choices defined in `kLanguages[]` in `ConfigDialog.cpp`:

```cpp
static const struct { const char* code; const char* name; } kLanguages[] = {
    {"en", "English"}, {"fi", "Suomi"},  {"sv", "Svenska"},
    {"da", "Dansk"},   {"nb", "Norsk"},  {"es", "Español"},
    {"de", "Deutsch"}, {"pt", "Português"},
};
```

---

### Tab 2 — Providers

A `QComboBox` at the top selects the active provider. A `QStackedWidget` below shows the configuration page for that provider.

When the **Ollama** provider is selected (or the tab is opened with Ollama active), models are **fetched automatically** from the Ollama server.

#### Ollama page

| Control | Type | Visibility |
|---------|------|------------|
| Base URL | `QLineEdit` | Always |
| Auth | `QComboBox` | Always — None / Basic Auth / API Key |
| Username | `QLineEdit` | Basic Auth only |
| Password | `QLineEdit` (password) | Basic Auth only |
| Header | `QLineEdit` | API Key only |
| API Key | `QLineEdit` (password) | API Key only |
| Fetch Models | `QPushButton` | Always (also triggered automatically) |
| Text Generation Models | `DualListWidget` | Always |
| Image Generation Models | `DualListWidget` | Always |

The `DualListWidget` has two panes (available / selected) and `>>` `>` `<` `<<` transfer buttons. Model classifications are persisted to `config.json` as `ollama_text_models` and `ollama_image_models` arrays.

#### OpenAI page

| Control | Type |
|---------|------|
| Base URL | `QLineEdit` (default: `https://api.openai.com/v1`) |
| API Key | `QLineEdit` (password) |

#### Claude page

| Control | Type |
|---------|------|
| Base URL | `QLineEdit` (default: `https://api.anthropic.com/v1`) |
| API Key | `QLineEdit` (password) |

#### Grok page

| Control | Type |
|---------|------|
| Base URL | `QLineEdit` (default: `https://api.x.ai/v1`) |
| API Key | `QLineEdit` (password) |

#### Gemini page

| Control | Type |
|---------|------|
| Base URL | `QLineEdit` (default: `https://generativelanguage.googleapis.com/v1beta`) |
| API Key | `QLineEdit` (password) |

A **Keychain hint** is shown at the bottom of the tab when `CredentialStore::isAvailable()` returns false, warning that credentials will not persist between sessions.

---

### Tab 3 — Text Generation

| Control | Type | Purpose |
|---------|------|---------|
| Provider | `QComboBox` | Ollama / OpenAI / Claude / Grok / Gemini |
| Model | `QComboBox` + `↺` button | Select active text generation model |

For **Ollama**: model list is populated from `m_ollamaTextList->selectedModels()` (live from the Providers tab — no save needed). A hint is shown when no models are assigned.

For other providers: `↺` calls `AIClient::fetchModels()` asynchronously using the credentials currently entered in the Providers tab.

---

### Tab 4 — Image Generation

| Control | Type | Purpose |
|---------|------|---------|
| Provider | `QComboBox` | Ollama / OpenAI / Grok / Gemini |
| Model | `QComboBox` + `↺` button | Select active image generation model |

For **Ollama**: model list is populated from `m_ollamaImgList->selectedModels()` (live from the Providers tab). A hint is shown when no models are assigned.

For other providers: `↺` calls `ImageClient::fetchImageModels()` asynchronously.

---

## Save Behaviour (`onOk`)

1. Write all UI fields to `Config` (URLs, auth, model selections, language, logging).
2. Store API keys in `CredentialStore` (one call per provider key).
3. Save Ollama model whitelists: `cfg.ollamaTextModels = m_ollamaTextList->selectedModels()`.
4. Call `Config::save()` — persists all non-sensitive fields to `config.json`.
5. Call `initLogging()` to apply any log setting changes immediately.
6. If language changed: call `Config::applyLanguage()`, then `ChatWindow::resetInstance()` and `ConfigDialog::resetInstance()` — both singletons are destroyed and recreated in the new locale on next open.
7. Close the dialog.

---

## Tab-switch Auto-refresh

| Tab switch to | Action |
|--------------|--------|
| Providers (idx 1), Ollama selected | `onFetchOllamaModels()` |
| Text Generation (idx 2) | `onTxtProviderChanged(currentIndex)` |
| Image Generation (idx 3) | `onImgProviderChanged(currentIndex)` |
| Providers combo → Ollama (idx 0) | `onFetchOllamaModels()` |

---

## DualListWidget

**File:** `src/ui/DualListWidget.hpp` / `src/ui/DualListWidget.cpp`  
**Base:** `QWidget`

Reusable two-pane list for assigning Ollama models to a category.

```cpp
void        setModels(const QStringList& all, const QStringList& selected);
QStringList selectedModels() const;
void        setTitle(const QString& title);
```

- Left pane: unassigned models.
- Right pane: assigned (selected) models.
- Transfer buttons: `>>` (all right), `>` (selected right), `<` (selected left), `<<` (all left).

---

## Credential Security

API key fields use `QLineEdit::setEchoMode(QLineEdit::Password)`. Keys are never written to `config.json`. On load, `Config()` retrieves them from `CredentialStore::retrieve()`. On save, `CredentialStore::store()` writes them to the platform backend.

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
Tab labels, button text, and all visible strings go through `tr()`.
