# LibreAI

An AI writing assistant extension for **LibreOffice Writer, Impress, and Calc**, implemented as a native C++/Qt6 UNO component — no Java required.

Connects to locally-running [Ollama](https://ollama.com) models or cloud AI providers (OpenAI, Anthropic Claude, xAI Grok, Google Gemini). Grab selected text from your document, send it to an AI model with an instruction, and apply the formatted response back — all from a floating chat window or the right-click context menu. Generate images from a text prompt and insert them directly into Writer or Impress.

---

## Features

- **5 AI providers** — Ollama (local), OpenAI, Anthropic Claude, xAI Grok, Google Gemini
- **Image generation** — Generate images with DALL-E, Grok Aurora, Gemini Imagen, or Ollama flux models and insert directly into Writer or Impress
- **Batch Rewrite** — Process every section of a Writer document through an AI instruction in one pass
- **Markdown rendering** — AI responses display with formatted headers, bold, italic, code blocks, and bullet lists in the chat panel
- **Rich text apply** — "Apply to Document" transfers heading styles, bold/italic, and lists as native LibreOffice Writer formatting (not plain text)
- **Writer / Impress / Calc** — grab selection and apply response in any of the three apps
- **Right-click shortcut** — "Ask from AI" context menu item pre-loads selected text into the chat
- **Conversation history** — multi-turn chat with a collapsible history panel; "Clear History" resets context
- **Secure credential storage** — API keys stored in the OS keychain (Qt6Keychain on Linux, Security.framework on macOS, DPAPI on Windows) — never written to disk as plaintext
- **Ollama remote auth** — None, HTTP Basic Auth, or API-key header for Ollama behind a reverse proxy
- **Configurable base URLs** — all providers support a custom base URL for compatible endpoints or proxies
- **Configurable logging** — activity log at `~/.config/libreai/libreai.log` with level and size controls
- **i18n** — UI in English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português
- **Dark theme** — VS Code-inspired dark UI
- **Async networking** — UI never blocks while waiting for AI responses

---

## Supported Models

### Ollama (local)

Any model pulled locally via `ollama pull`. Text and image models are listed and **classified separately** in the Providers tab — assign each model to Text Generation or Image Generation (or both). Popular choices:

**Text generation**

| Model | Description |
|-------|-------------|
| `llama3.3` | Meta Llama 3.3 — strong general-purpose model |
| `mistral` | Mistral 7B — fast and capable |
| `gemma3` | Google Gemma 3 |
| `qwen3` | Alibaba Qwen 3 |
| `phi4` | Microsoft Phi-4 — efficient small model |
| `deepseek-r1` | DeepSeek R1 — strong reasoning |

**Image generation**

| Model | Description |
|-------|-------------|
| `x/flux2-klein` | FLUX.1 Schnell — fast local image generation |

### OpenAI

**Text:** model list fetched live. Common models: `gpt-4o`, `gpt-4o-mini`, `gpt-4-turbo`, `gpt-3.5-turbo`.

**Images:** `dall-e-3`, `dall-e-2`.

Any OpenAI-compatible endpoint works (LocalAI, LM Studio, Azure OpenAI) — set a custom Base URL.

### Anthropic Claude

| Model | Description |
|-------|-------------|
| `claude-opus-4-7` | Most capable Claude model |
| `claude-sonnet-4-6` | Best balance of intelligence and speed |
| `claude-haiku-4-5-20251001` | Fastest Claude model |

### xAI Grok

**Text:** model list fetched live (`grok-3`, `grok-3-mini`, `grok-2`, …).

**Images:** `aurora`.

### Google Gemini

**Text:** model list fetched live (`gemini-2.5-pro`, `gemini-2.0-flash`, `gemini-1.5-pro`, …).

**Images:** `imagen-3.0-generate-002`, `imagen-3.0-fast-generate-001`, `gemini-2.0-flash-exp-image-generation`.

---

## Requirements

| Dependency | Version | Notes |
|------------|---------|-------|
| LibreOffice | 7.x+ | Tested on 7.3.7 and 24.x |
| CMake | 3.16+ | |
| GCC / Clang | C++17 | |
| Qt 6 | Core, Widgets, Network | `qt6-base-dev` |
| LO SDK headers | — | `libreoffice-dev` |
| lrelease | Qt 6 | `linguist-qt6` (for building translations) |
| Qt6Keychain | Qt 6 | `qtkeychain-qt6-dev` (Linux, optional — fallback to in-memory) |

**Runtime:**

| Package | Notes |
|---------|-------|
| `libqt6widgets6` | Qt 6 runtime |
| `libqt6network6` | Qt 6 network |
| `libqt6keychain1` | Secure credential storage (Linux) |
| Ollama *(optional)* | Running at `http://localhost:11434` |
| OpenAI API key *(optional)* | For GPT / DALL-E models |
| Anthropic API key *(optional)* | For Claude models |
| xAI API key *(optional)* | For Grok / Aurora models |
| Google AI API key *(optional)* | For Gemini / Imagen models |

---

## Installation

### Option A — Install the pre-built `.oxt`

Download the latest `.oxt` for your platform from [Releases](../../releases) and install via LibreOffice Extension Manager (**Tools → Extension Manager → Add**) or from the command line:

```bash
unopkg add libreai_ubuntu2404_x86_64.oxt
```

Restart LibreOffice to activate.

### Option B — Build from source

#### 1. Install build dependencies

```bash
sudo apt-get install \
    build-essential cmake \
    qt6-base-dev \
    libreoffice-dev \
    linguist-qt6 \
    qtkeychain-qt6-dev
```

#### 2. Generate UNO headers

```bash
cd /path/to/LibreAI
mkdir -p include
cppumaker -O include \
    /usr/lib/libreoffice/program/types.rdb \
    /usr/lib/libreoffice/program/types/offapi.rdb
```

#### 3. Build and install the extension

```bash
bash build.sh --install
```

Or build only (produces `libreai.oxt`):

```bash
bash build.sh
unopkg remove org.libreai 2>/dev/null || true
unopkg add -f libreai.oxt
```

Restart LibreOffice to activate.

---

## Configuration

On first launch LibreOffice will open the **Configuration** dialog automatically. You can also reach it at any time via **LibreAI → Configuration**.

The dialog has four tabs.

### General Settings

| Setting | Description |
|---------|-------------|
| Language | UI language for all LibreAI windows |
| Enable logging | Write activity to `~/.config/libreai/libreai.log` |
| Log level | Debug / Info / Error |
| Max log size | File size cap in MB |

### Providers

Select a provider from the dropdown to configure it. Ollama models are fetched automatically when the tab opens.

**Ollama**

| Setting | Description |
|---------|-------------|
| Base URL | Ollama server URL (default `http://localhost:11434`) |
| Auth | None / Basic Auth / API Key |
| Username / Password | Shown when Basic Auth is selected |
| Header / API Key | Shown when API Key auth is selected |
| Text Generation Models | Dual-list — assign models available for text generation |
| Image Generation Models | Dual-list — assign models available for image generation |

Model classifications are saved in `config.json` and restored on next launch.

**OpenAI / Claude / Grok / Gemini**

| Setting | Description |
|---------|-------------|
| Base URL | API endpoint (customisable for compatible endpoints) |
| API Key | Your API key (stored in OS keychain, never on disk) |

### Text Generation

Select the provider and model to use for the chat window and Rewrite/Apply operations.

### Image Generation

Select the provider and model to use for **LibreAI → Generate Image…**.

---

## Usage

### Chat and Rewrite

1. LibreOffice opens → the LibreAI chat window appears automatically.
2. If not yet configured, the Configuration dialog opens first.
3. In the chat window:
   - Type a question or instruction and click **Send** for a pure chat message.
   - Select text in your document and click **Grab Selection** (or right-click → **Ask from AI**) to load it, then add an instruction and click **Send** or **Rewrite**.
   - The AI response appears with Markdown formatting.
   - Click **Apply to Document** to insert the response at the cursor / replace the selection.
4. Use **▶ History** to browse past exchanges. **Clear History** resets the context.

### Generate Image (Writer and Impress only)

1. Optionally select text in your document to use as context.
2. Click **LibreAI → Generate Image…**
3. Enter a prompt, choose a size, and click **Generate**.
4. The generated image appears in the preview area.
5. Click **Insert into Document** to place it after the cursor in Writer, or on the current slide in Impress.

### Batch Rewrite (Writer only)

1. Click **LibreAI → Batch Rewrite…**
2. Enter an instruction to apply to every section of the document.
3. LibreAI processes each section sequentially and replaces the content.

---

## Project Structure

```
LibreAI/
├── src/
│   ├── ai/
│   │   ├── AIClient.hpp/cpp               Abstract text provider base
│   │   ├── OllamaClient.hpp/cpp           Ollama text client (auth support, fetchAllModels)
│   │   ├── OpenAIClient.hpp/cpp           OpenAI-compatible text client
│   │   ├── AnthropicClient.hpp/cpp        Anthropic Claude text client
│   │   ├── GrokClient.hpp/cpp             xAI Grok text client
│   │   ├── GeminiClient.hpp/cpp           Google Gemini text client
│   │   ├── ImageClient.hpp/cpp            Abstract image provider base
│   │   ├── OllamaImageClient.hpp/cpp      Ollama image client (/api/generate)
│   │   ├── OpenAIImageClient.hpp/cpp      DALL-E image client
│   │   ├── GrokImageClient.hpp/cpp        Grok Aurora image client
│   │   └── GeminiImageClient.hpp/cpp      Gemini Imagen client
│   ├── core/
│   │   ├── Config.hpp/cpp                 JSON config singleton + language loader
│   │   ├── CredentialStore.hpp/cpp        Credential façade + ICredentialBackend interface
│   │   ├── CredentialBackendKeychain      Linux Qt6Keychain backend
│   │   ├── CredentialBackendMacOS         macOS Security.framework backend
│   │   ├── CredentialBackendDPAPI         Windows DPAPI backend
│   │   ├── CredentialBackendMemory        In-memory fallback
│   │   ├── BatchProcessor.hpp/cpp         Batch section rewrite engine
│   │   └── Logger.hpp/cpp                 Qt message handler + file logging
│   ├── ui/
│   │   ├── ChatWindow.hpp/cpp             Qt6 chat window (singleton)
│   │   ├── ConfigDialog.hpp/cpp           Qt6 configuration dialog (singleton)
│   │   ├── DualListWidget.hpp/cpp         Two-pane list with transfer buttons
│   │   ├── ImageGenDialog.hpp/cpp         Image generation dialog
│   │   └── BatchRewriteDialog.hpp/cpp     Batch rewrite dialog
│   └── uno/
│       ├── component.cpp                  UNO entry points
│       ├── LibreAIJob.hpp/cpp             XJobExecutor — menu/toolbar/right-click handler
│       ├── LibreAIStarter.hpp/cpp         XJob — startup; opens window, installs interceptor
│       ├── CMInterceptor.hpp/cpp          XContextMenuInterceptor — right-click menu item
│       ├── DocumentParser.hpp/cpp         Writer document section parser
│       └── UnoHelper.hpp/cpp              LO UNO utilities (selection, apply, insertImage)
├── translations/                          Qt .ts / .qm files + .qrc
├── tests/
│   ├── unit/                              Google Test unit tests
│   └── integration/                       pytest headless integration tests
├── spec/                                  Technical specification documents
├── META-INF/manifest.xml
├── Addons.xcu                             Menu bar + toolbar registration
├── Jobs.xcu                               Startup job bindings
├── CMakeLists.txt
└── build.sh
```

---

## Adding a New Language

1. Copy `translations/libreai_fi.ts` to `translations/libreai_XX.ts` (BCP 47 language code).
2. Translate all `<translation>` entries.
3. Add the language to `kLanguages[]` in `src/ui/ConfigDialog.cpp`.
4. Add the compiled `.qm` filename to `translations/libreai_translations.qrc`.
5. Add localized `<value xml:lang="XX">` entries in `Addons.xcu`.
6. Run `lrelease translations/libreai_XX.ts` then `bash build.sh --install`.

---

## License

MIT
