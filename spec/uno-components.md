# UNO Components

## LibreAIJob

**File:** `src/uno/LibreAIJob.hpp` / `src/uno/LibreAIJob.cpp`  
**UNO interface:** `XJobExecutor`  
**Service name:** `org.libreai.job`

Entry point for all user-initiated actions (menu, toolbar, right-click).

### trigger(args) dispatch table

| Argument | Action | Available in |
|----------|--------|-------------|
| `"open"` | `Config::isConfigured()` ? show `ChatWindow` : show `ConfigDialog` | All |
| `"config"` | Show `ConfigDialog` | All |
| `"open_with_sel"` | Show `ChatWindow`; pre-fill Selected Text from current document selection | All |
| `"batch_rewrite"` | Show `BatchRewriteDialog` | Writer only (`Context` in Addons.xcu) |
| `"generate_image"` | Show `ImageGenDialog`; pass selected text as context hint | Writer, Impress (`Context` in Addons.xcu) |

On the very first call, `QApplication` is created (if not already) and `Config::applyLanguage()` is called.

On **Windows**, the Qt plugin path is resolved from the DLL's own location before `QApplication` construction:

```cpp
GetModuleFileNameW(libreai_module_handle(), path, MAX_PATH);
// strip filename, set QCoreApplication::addLibraryPath(dir + "/plugins")
```

---

## LibreAIStarter

**File:** `src/uno/LibreAIStarter.hpp` / `src/uno/LibreAIStarter.cpp`  
**UNO interface:** `XJob`  
**Service name:** `org.libreai.starter`  
**Triggered by:** `Jobs.xcu` events `onStartApp`, `onNew`, `onLoad`

Responsible for:
- Creating `QApplication` and showing the first window on startup.
- Installing `CMInterceptor` on every open frame.
- Attaching the `XDocumentEventBroadcaster` listener for `OnViewCreated` / `OnNew` / `OnLoad` (once only, guarded by `s_listenerAttached`).

`OnViewCreated` is the key event — it fires after the frame controller is fully initialised, which is when `registerContextMenuInterceptor` reliably works.

---

## CMInterceptor

**File:** `src/uno/CMInterceptor.hpp` / `src/uno/CMInterceptor.cpp`  
**UNO interface:** `XContextMenuInterceptor`

A single static instance registered on each frame controller via `XContextMenuInterception::registerContextMenuInterceptor`.

### What it injects

Appended to every right-click context menu:

1. `com.sun.star.ui.ActionTriggerSeparator`
2. `com.sun.star.ui.ActionTrigger`
   - `Text` = `"Ask from AI"` (translated via `QCoreApplication::translate`)
   - `CommandURL` = `"service:org.libreai.job?open_with_sel"`

Returns `CONTINUE_MODIFIED`.

### De-duplication

`s_intercepted` (`std::set<sal_IntPtr>`) holds frame pointers of successfully registered frames. A frame is added **only after** `registerContextMenuInterceptor` returns without throwing. If the controller is not ready yet the frame stays out of the set and will be retried on the next `OnViewCreated` / `OnNew` event.

---

## UnoHelper

**File:** `src/uno/UnoHelper.hpp` / `src/uno/UnoHelper.cpp`  
**Scope:** free functions in the `UnoHelper` namespace

| Function | Description |
|----------|-------------|
| `setContext(ctx)` | Stores `XComponentContext` for session-wide use |
| `getCurrentFrame()` | `XDesktop::getCurrentFrame()` |
| `getSelectedText()` | Detects Writer/Impress/Calc; returns selected text; remembers cursor/target for Apply |
| `applyText(text)` | Plain-text insert using remembered or live cursor |
| `applyRichText(doc)` | Rich-text insert for Writer; falls back to `applyText` for Impress/Calc |
| `insertImage(pngData)` | Insert PNG image into Writer (AS_CHARACTER anchor, 12 cm × 9 cm) or Impress (graphic shape on current slide) |

### insertImage Detail

1. Saves `pngData` to `/tmp/libreai_img.png` and converts to a `file://` URL.
2. **Writer:** creates a `TextGraphicObject` via `XMultiServiceFactory`, sets `GraphicURL`, `AnchorType = AS_CHARACTER`, and a 12 cm × 9 cm size; inserts after the current text cursor.
3. **Impress:** creates a `GraphicObjectShape` on the current draw page, sets `GraphicURL` and position/size via `XPropertySet`.

### Supported Document Types

Detection is based on the controller's UNO service name:

| App | Detection service |
|-----|------------------|
| Writer | `com.sun.star.text.TextDocumentView` |
| Impress | `com.sun.star.presentation.PresentationController` or `XDrawView` |
| Calc | `com.sun.star.sheet.SpreadsheetViewSettings` |

### applyRichText Detail

Walks `QTextDocument` blocks and fragments:

1. Deletes the current selection via `XText::insertString(range, "", true)`
2. For each `QTextBlock`:
   - Sets `ParaStyleName` (`"Heading 1"`–`"Heading 6"`, `"Preformatted Text"`, or `"Default Paragraph Style"`) via `XPropertySet`
   - Detects `QTextList` membership and prepends `"• "` / `"N. "` / `"a. "` as plain text
3. For each `QTextFragment`:
   - Sets `CharWeight` (bold), `CharPosture` (italic), `CharFontName` (monospace → `"Courier New"`) via `XPropertySet`
   - Inserts fragment text via `XText::insertString`
4. If no remembered cursor (no prior Grab Selection), gets the live `XTextViewCursor` from the current frame

---

## XCU Registration Files

### Addons.xcu

Registers the LibreAI menu and toolbar entry under LibreOffice's `OfficeMenuBar` and `OfficeToolBar` extension points.

- **Menu:** `Tools → LibreAI → Open chat` (`service:org.libreai.job?open`) and `Settings` (`service:org.libreai.job?config`)
- **Toolbar:** single button triggering `open`
- Menu item labels use `xml:lang` attributes and follow **LibreOffice's own UI language**, not LibreAI's language setting.

### Jobs.xcu

Binds `org.libreai.starter` (`XJob`) to three LO lifecycle events:

| Event | When |
|-------|------|
| `onStartApp` | LibreOffice application launches |
| `onNew` | New document created |
| `onLoad` | Existing document opened |

This triple binding ensures the interceptor is installed even when LO is already running and a new document is opened.

---

## component.cpp

**File:** `src/uno/component.cpp`

Implements the two mandatory UNO shared-library entry points:

```cpp
extern "C" void* component_getFactory(const char* implName, void* sm, void* key);
extern "C" void  component_writeInfo(void* sm, void* key);
```

`component_getFactory` returns an `XSingleComponentFactory` for `LibreAIJob` or `LibreAIStarter` based on `implName`.
