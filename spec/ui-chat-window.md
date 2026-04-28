# Chat Window

**Class:** `ChatWindow` (`src/ui/ChatWindow.hpp` / `src/ui/ChatWindow.cpp`)  
**Base:** `QWidget` with `Qt::Window` flag (floats above LibreOffice, never blocks the UNO thread)  
**Minimum size:** 320 × 560 px, default 380 × 640 px  
**Lifetime:** singleton via `ChatWindow::instance()` / `ChatWindow::resetInstance()`

---

## Widget Layout (top → bottom)

| Widget | Type | Purpose |
|--------|------|---------|
| Header label | `QLabel` | "≡ LibreAI" |
| Grab Selection | `QPushButton` (btn2) | Reads current Writer/Impress/Calc selection via `UnoHelper::getSelectedText()` |
| SELECTED TEXT | `QLabel` | Section label |
| Selected text | `QPlainTextEdit` (80 px) | Editable; pre-filled from document selection |
| INSTRUCTION / CHAT | `QLabel` | Section label |
| Instruction | `QPlainTextEdit` (80 px) | User prompt / instruction text |
| Rewrite / Send / Clear History | `QPushButton` row | Primary actions |
| ▶ History (N) | `QPushButton` (checkable, btn2) | Toggles conversation history list |
| History list | `QListWidget` (160 px, hidden by default) | Shows past user/AI exchanges |
| RESPONSE | `QLabel` | Section label |
| Response area | `QTextEdit` (read-only, expands) | AI response — rendered as **Markdown** |
| Apply to Document | `QPushButton` | Transfers formatted response to Writer |
| Status bar | `QLabel` | Connection state, errors, "Sending…", "Done" |

---

## Markdown Rendering

The response area uses `QTextEdit::setMarkdown()` so AI responses render natively:

- `# Heading` → Heading 1 paragraph style (styled orange `#CE9178`)
- `**bold**` / `*italic*` — character weight / slant
- `` `code` `` / ` ```code block``` ` — monospace, dark background `#2d2d2d`, blue text `#9CDCFE`
- `> blockquote` — left border, muted colour
- `[link](url)` — teal `#4EC9B0`

Styling is applied via `QTextDocument::setDefaultStyleSheet()` on the response document.

The spinner animation during requests uses `QPlainTextEdit::setPlainText()` (which works on `QTextEdit`) and is overwritten when the response arrives.

---

## Apply to Document — Rich Text

`onApply()` calls `UnoHelper::applyRichText(m_respEdit->document())` which:

1. Walks each `QTextBlock` in the `QTextDocument`.
2. Maps heading level → LibreOffice paragraph style (`"Heading 1"` … `"Heading 6"`), fixed-pitch blocks → `"Preformatted Text"`, others → `"Default Paragraph Style"`.
3. For each `QTextFragment`, sets `CharWeight` (bold), `CharPosture` (italic), and `CharFontName` (monospace → `"Courier New"`) via `XPropertySet`.
4. Detects list items via `QTextBlock::textList()` and prepends `"• "` (unordered), `"N. "` (decimal), or `"a. "` (alpha) as plain text.
5. Falls back to plain text for Impress and Calc targets.
6. Uses the live Writer view cursor if no selection was grabbed beforehand.

---

## Conversation History

`m_history` is a `QVector<Message>` (role, content, timestamp, provider, model).  
After each successful `sendChat`, two messages are appended (user + assistant).  
The history panel (`QListWidget`) shows truncated previews — user entries in `C_TEXT`, AI entries in `C_SUCCESS`.  
"Clear History" clears `m_history` and the list widget.

---

## Busy State / Spinner

`setBusy(true)` disables Send / Rewrite / Apply and starts a `QTimer` at 80 ms intervals cycling through Braille spinner frames (`⠋⠙⠹⠸⠼⠴⠦⠧⠇⠏`). `QApplication::setOverrideCursor(Qt::WaitCursor)` is set for the duration. `setBusy(false)` restores everything and stops the timer.

---

## Supported Document Types

`UnoHelper` detects the active app from the controller's service name:

| App | Selection | Apply |
|-----|-----------|-------|
| Writer | `XTextViewCursorSupplier` | Rich text via `XText` / `XTextCursor` + `XPropertySet` |
| Impress | `XSelectionSupplier` → shape `XText` | Plain text via `XText::setString` |
| Calc | `XSelectionSupplier` → `XCellRange` | Plain text via `XTextRange::setString` |

---

## Theme

Dark VS Code-inspired palette applied via `setStyleSheet()`:

| Token | Hex | Use |
|-------|-----|-----|
| `C_BG` | `#1E1E1E` | Window background |
| `C_SURFACE` | `#252526` | Input / textarea background |
| `C_TEXT` | `#D4D4D4` | Primary text |
| `C_MUTED` | `#858585` | Labels, status, placeholders |
| `C_BTN` | `#0E639C` | Primary buttons (Send, Apply, Rewrite) |
| `C_BTN2` | `#3C3C3C` | Secondary buttons (Grab, Clear, History toggle) |
| `C_SUCCESS` | `#4EC9B0` | Success status / AI history entries |
| `C_ERROR` | `#F44747` | Error status text |
| `C_BORDER` | `#3C3C3C` | Input borders |

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
