# Feature — Image Generation

## Overview

Allows users to generate images from a text prompt using any configured image provider and insert the result directly into the active Writer or Impress document.

Accessible via **LibreAI → Generate Image…** menu item.  
Only visible in **Writer** and **Impress** (hidden in Calc and other apps via the `Context` property in `Addons.xcu`).

---

## Entry Point

`LibreAIJob::trigger("generate_image")`:

1. Reads the current document selection via `UnoHelper::getSelectedText()`.
2. Creates an `ImageGenDialog` (non-modal `QWidget` window).
3. Calls `dialog->setContextHint(selectedText)` — shows the selection as context for the user.
4. Shows the dialog.

---

## ImageGenDialog

**File:** `src/ui/ImageGenDialog.hpp` / `src/ui/ImageGenDialog.cpp`  
**Base:** `QWidget` with `Qt::Window` flag  
**Minimum size:** 520 × 600

### Layout

| Control | Purpose |
|---------|---------|
| Context label + value | Shows selected text (hidden when empty) |
| Prompt (`QPlainTextEdit`) | User's image description |
| Size (`QComboBox`) | 1024×1024 / 1792×1024 / 1024×1792 / 512×512 |
| Generate button | Calls the active `ImageClient` |
| Status label | Shows progress / error / "Image ready." |
| Preview (`QScrollArea` + `QLabel`) | Displays scaled generated image |
| Insert into Document button | Calls `UnoHelper::insertImage()` then closes |
| Close button | Closes without inserting |

### Flow

1. User enters prompt, selects size, clicks **Generate**.
2. `buildClient()` creates the appropriate `ImageClient` from `Config::get()`.
3. `ImageClient::generateImage(model, prompt, size)` is called asynchronously.
4. On `imageReady(pngData)`: preview is shown scaled to fit, Insert button enabled.
5. On `errorOccurred(error)`: error shown in red status label.
6. On **Insert**: `UnoHelper::insertImage(m_lastPng)` inserts the PNG, dialog closes.

---

## ImageClient Hierarchy

See [ai-providers.md](ai-providers.md) — Image Generation section.

| Provider | Class | Models |
|----------|-------|--------|
| Ollama | `OllamaImageClient` | Fetched from `/api/tags`, filtered by image keywords |
| OpenAI | `OpenAIImageClient` | `dall-e-3`, `dall-e-2` |
| Grok | `GrokImageClient` | `aurora` |
| Gemini | `GeminiImageClient` | `imagen-3.0-generate-002`, `imagen-3.0-fast-generate-001`, `gemini-2.0-flash-exp-image-generation` |

---

## Model Selection

Image provider and model are configured separately from text generation:

- **Config fields:** `imageProvider`, `ollamaImageModel`, `openaiImageModel`, `grokImageModel`, `geminiImageModel`
- **Config tab:** Image Generation tab in ConfigDialog
- **Ollama models** are classified by the user in the Providers tab using the **Image Generation Models** `DualListWidget`; classifications persist in `config.json` as `ollama_image_models`

---

## Image Insertion

See `UnoHelper::insertImage()` in [uno-components.md](uno-components.md).

- **Writer:** inserted as `TextGraphicObject` with `AS_CHARACTER` anchor after the cursor position, 12 cm × 9 cm default size.
- **Impress:** inserted as `GraphicObjectShape` on the current slide.

---

## Menu Visibility

```xml
<prop oor:name="Context" oor:type="xs:string">
  <value>com.sun.star.text.TextDocument;com.sun.star.presentation.PresentationDocument</value>
</prop>
```

The item does not appear in Calc or other LibreOffice applications.
