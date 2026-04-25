# UNO Components

## LibreAIJob

**File:** `src/LibreAIJob.hpp` / `src/LibreAIJob.cpp`  
**UNO interface:** `XJobExecutor`  
**Service name:** `org.libreai.job`

Entry point for all user-initiated actions (menu, toolbar, right-click).

### trigger(args) dispatch table

| Argument | Action |
|----------|--------|
| `"open"` | `Config::isConfigured()` ? show `ChatWindow` : show `ConfigDialog` |
| `"config"` | Show `ConfigDialog` |
| `"open_with_sel"` | Show `ChatWindow`; pre-fill Selected Text from current Writer selection |

On the very first call this is also where `QApplication` is created (if not already) and `Config::applyLanguage()` is called.

On **Windows**, the Qt plugin path is resolved from the DLL's own location before `QApplication` construction:

```cpp
GetModuleFileNameW(libreai_module_handle(), path, MAX_PATH);
// strip filename, set QCoreApplication::addLibraryPath(dir + "/plugins")
```

---

## LibreAIStarter

**File:** `src/LibreAIStarter.hpp` / `src/LibreAIStarter.cpp`  
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

**File:** `src/CMInterceptor.hpp` / `src/CMInterceptor.cpp`  
**UNO interface:** `XContextMenuInterceptor`

A single static instance registered on each Writer frame controller via `XContextMenuInterception::registerContextMenuInterceptor`.

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

**File:** `src/UnoHelper.hpp` / `src/UnoHelper.cpp`  
**Scope:** free functions in the `UnoHelper` namespace

| Function | Description |
|----------|-------------|
| `setContext(ctx)` | Stores `XComponentContext` for session-wide use |
| `getCurrentFrame()` | `XDesktop::getCurrentFrame()` |
| `getSelectedText()` | Frame → Controller → `XTextViewCursorSupplier` → cursor → `getString()` |
| `applyText(text)` | Frame → Controller → cursor → `setString(text)` |

Writer-only: `XTextViewCursorSupplier` is not available in Calc or Impress. Calling these functions outside a Writer document will throw or return empty.

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

**File:** `src/component.cpp`

Implements the two mandatory UNO shared-library entry points:

```cpp
extern "C" void* component_getFactory(const char* implName, void* sm, void* key);
extern "C" void  component_writeInfo(void* sm, void* key);
```

`component_getFactory` returns an `XSingleComponentFactory` for `LibreAIJob` or `LibreAIStarter` based on `implName`.
