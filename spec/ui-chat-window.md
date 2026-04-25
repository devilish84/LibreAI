# Chat Window

**Class:** `ChatWindow` (`src/ChatWindow.hpp` / `src/ChatWindow.cpp`)  
**Base:** `QWidget` with `Qt::Window` flag (floats above LibreOffice, never blocks the UNO thread)  
**Lifetime:** singleton via `ChatWindow::instance()` / `ChatWindow::resetInstance()`

---

## Widget Layout (top → bottom)

| Widget | Type | Purpose |
|--------|------|---------|
| Provider | `QComboBox` | Select Ollama / OpenAI / Claude |
| Connection | `QLineEdit` | Base URL (Ollama, OpenAI) or API key label area (Claude) |
| Model | `QComboBox` | Populated asynchronously from provider |
| Refresh Models | `QPushButton` | Triggers `AIClient::fetchModels()` |
| Selected Text | `QTextEdit` | Editable; pre-filled from Writer selection when triggered via `open_with_sel` |
| Grab Selection | `QPushButton` | Re-reads current Writer selection via `UnoHelper::getSelectedText()` |
| Instruction | `QTextEdit` | User prompt sent to AI |
| Send | `QPushButton` | Calls `AIClient::sendChat()` |
| Response | `QTextEdit` (read-only) | Streams AI response tokens |
| Apply to Document | `QPushButton` | Calls `UnoHelper::applyText()` to replace Writer selection |
| Status bar | `QLabel` | Shows connection state, errors, "Sending…" feedback |

---

## Theme

Dark VS Code-inspired palette applied via `setStyleSheet()`:

| Token | Hex | Use |
|-------|-----|-----|
| `C_BG` | `#1E1E1E` | Window background |
| `C_SURFACE` | `#252526` | Input / textarea background |
| `C_TEXT` | `#D4D4D4` | Primary text |
| `C_MUTED` | `#858585` | Labels, status, placeholders |
| `C_BTN` | `#0E639C` | Primary buttons (Send, Apply) |
| `C_BTN2` | `#3C3C3C` | Secondary buttons (Refresh, Grab) |
| `C_SUCCESS` | `#4EC9B0` | Success status text |
| `C_ERROR` | `#F44747` | Error status text |
| `C_BORDER` | `#3C3C3C` | Input borders |

---

## Networking

All AI requests go through the active `AIClient` subclass (`OllamaClient`, `OpenAIClient`, or `AnthropicClient`). Responses arrive via Qt signals:

```cpp
void responseReady(QString text);   // full response text
void errorOccurred(QString error);  // human-readable error
```

`QNetworkAccessManager` is used throughout — no blocking calls on any thread.

---

## Singleton Lifecycle

```cpp
ChatWindow* ChatWindow::instance();       // create-if-absent, show, raise
void        ChatWindow::resetInstance();  // close + delete (called on language change)
```

`resetInstance()` is called by `ConfigDialog` when the user saves a new language setting. The next call to `instance()` creates a fresh window translated into the new locale.

---

## i18n

`ChatWindow` is a `Q_OBJECT` class — use `tr("...")` for all user-visible strings.  
`retranslateUi()` is called from `changeEvent(QEvent::LanguageChange)` so labels update immediately when the translator is swapped without reopening the window.
