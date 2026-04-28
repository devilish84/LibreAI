# LibreAI

An AI writing assistant extension for **LibreOffice Writer, Impress, and Calc**, implemented as a native C++/Qt6 UNO component — no Java required.

Connects to locally-running [Ollama](https://ollama.com) models or cloud AI providers (OpenAI, Anthropic Claude, xAI Grok, Google Gemini). Grab selected text from your document, send it to an AI model with an instruction, and apply the formatted response back — all from a floating chat window or the right-click context menu. AI responses are rendered with full Markdown formatting and applied to Writer with native heading styles, bold, italic, and list formatting preserved.

---

## Features

- **5 AI providers** — Ollama (local), OpenAI, Anthropic Claude, xAI Grok, Google Gemini
- **Markdown rendering** — AI responses display with formatted headers, bold, italic, code blocks, and bullet lists in the chat panel
- **Rich text apply** — "Apply to Document" transfers heading styles, bold/italic, and lists as native LibreOffice Writer formatting (not plain text)
- **Writer / Impress / Calc** — grab selection and apply response in any of the three apps
- **Right-click shortcut** — "Ask from AI" context menu item pre-loads selected text into the chat
- **Conversation history** — multi-turn chat with a collapsible history panel; "Clear History" resets context
- **Secure credential storage** — API keys stored in the OS keychain (Qt6Keychain on Linux, Security.framework on macOS, DPAPI on Windows) — never written to disk as plaintext
- **Ollama remote auth** — None, HTTP Basic Auth, or API-key header for Ollama behind a reverse proxy
- **Configurable logging** — activity log at `~/.config/libreai/libreai.log` with level and size controls
- **i18n** — UI in English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português
- **Processing animation** — braille spinner shown while waiting for the model
- **Dark theme** — VS Code-inspired dark UI
- **Async networking** — UI never blocks while waiting for AI responses

---

## Supported Models

### Ollama (local)

Any model pulled locally via `ollama pull`. The model list is fetched live from your Ollama instance. Popular choices:

| Model | Description |
|-------|-------------|
| `llama3.3` | Meta Llama 3.3 — strong general-purpose model |
| `mistral` | Mistral 7B — fast and capable |
| `gemma3` | Google Gemma 3 |
| `qwen3` | Alibaba Qwen 3 |
| `phi4` | Microsoft Phi-4 — efficient small model |
| `deepseek-r1` | DeepSeek R1 — strong reasoning |

### OpenAI

Model list fetched live from the API. Common models:

| Model | Description |
|-------|-------------|
| `gpt-4o` | Most capable GPT-4 model, multimodal |
| `gpt-4o-mini` | Fast, cost-efficient GPT-4 class |
| `gpt-4-turbo` | GPT-4 Turbo with 128k context |
| `gpt-3.5-turbo` | Fast, low-cost option |

Any OpenAI-compatible endpoint works (LocalAI, LM Studio, Azure OpenAI) — point the Base URL at your server.

### Anthropic Claude

| Model | Description |
|-------|-------------|
| `claude-opus-4-7` | Most capable Claude model |
| `claude-sonnet-4-6` | Best balance of intelligence and speed |
| `claude-haiku-4-5-20251001` | Fastest Claude model |
| `claude-opus-4-5` | Previous generation Opus |
| `claude-sonnet-4-5` | Previous generation Sonnet |
| `claude-haiku-3-5` | Previous generation Haiku |

### xAI Grok

Model list fetched live from the API.

| Model | Description |
|-------|-------------|
| `grok-3` | xAI's most capable model |
| `grok-3-mini` | Fast, efficient Grok model |
| `grok-2` | Previous generation Grok |

### Google Gemini

Model list fetched live from the API.

| Model | Description |
|-------|-------------|
| `gemini-2.5-pro` | Most capable Gemini model |
| `gemini-2.0-flash` | Fast multimodal model |
| `gemini-1.5-pro` | Long context (1M tokens) |
| `gemini-1.5-flash` | Fast and efficient |

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
| OpenAI API key *(optional)* | For GPT models |
| Anthropic API key *(optional)* | For Claude models |
| xAI API key *(optional)* | For Grok models |
| Google AI API key *(optional)* | For Gemini models |

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

### Model Selection tab

Select a provider; only the relevant fields are shown:

**Ollama**

| Setting | Description |
|---------|-------------|
| Base URL | Ollama server URL (default `http://localhost:11434`) |
| Auth | None / Basic Auth / API Key |
| Username / Password | Shown when Basic Auth is selected |
| Header / API Key | Shown when API Key is selected |
| Model | Click **↺** to fetch available models, then select one |

**OpenAI**

| Setting | Description |
|---------|-------------|
| Base URL | API endpoint (default `https://api.openai.com/v1`) |
| API Key | Your OpenAI secret key |
| Model | Click **↺** to fetch available models, then select one |

**Claude**

| Setting | Description |
|---------|-------------|
| API Key | Your Anthropic API key |
| Model | Select from the built-in model list |

**Grok**

| Setting | Description |
|---------|-------------|
| API Key | Your xAI API key |
| Model | Click **↺** to fetch available models |

**Gemini**

| Setting | Description |
|---------|-------------|
| API Key | Your Google AI Studio API key |
| Model | Click **↺** to fetch available models |

Credentials are stored in the OS keychain — never written to `config.json`. If the keychain is unavailable, credentials must be re-entered on next start.

### General Settings tab

| Setting | Description |
|---------|-------------|
| Language | UI language for all LibreAI windows |
| Enable logging | Write activity to `~/.config/libreai/libreai.log` |
| Log level | Debug / Info / Error |
| Max log size | File size cap in MB (default 10) |

Supported languages: English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português.

---

## Usage

1. LibreOffice opens → the LibreAI chat window appears automatically.
2. If not yet configured, the Configuration dialog opens first — select a provider, enter credentials, refresh and pick a model, then click **OK**.
3. In the chat window:
   - Type a question or instruction in **INSTRUCTION / CHAT** and click **Send** for a pure chat message.
   - Select text in your document and click **Grab Selection** (or right-click → **Ask from AI**) to load it into the **SELECTED TEXT** area, then add an instruction and click **Send** or **Rewrite**.
   - The AI response appears with Markdown formatting — headings, bold, code blocks, lists.
   - Click **Apply to Document** to insert the response at the cursor / replace the selection. In Writer, formatting (headings, bold, italic, lists) is transferred as native document styles.
4. Use **▶ History** to browse past exchanges. **Clear History** resets the conversation context sent to the model.

---

## Project Structure

```
LibreAI/
├── src/
│   ├── ai/
│   │   ├── AIClient.hpp               Abstract AI provider base (QObject + signals)
│   │   ├── OllamaClient.hpp/cpp       Ollama REST client (with auth support)
│   │   ├── OpenAIClient.hpp/cpp       OpenAI-compatible REST client
│   │   ├── AnthropicClient.hpp/cpp    Anthropic Claude REST client
│   │   ├── GrokClient.hpp/cpp         xAI Grok REST client
│   │   └── GeminiClient.hpp/cpp       Google Gemini REST client
│   ├── core/
│   │   ├── Config.hpp/cpp             JSON config singleton + language loader
│   │   ├── CredentialStore.hpp/cpp    Credential façade + ICredentialBackend interface
│   │   ├── CredentialBackendKeychain  Linux Qt6Keychain backend
│   │   ├── CredentialBackendMacOS     macOS Security.framework backend
│   │   ├── CredentialBackendDPAPI     Windows DPAPI backend
│   │   ├── CredentialBackendMemory    In-memory fallback
│   │   └── Logger.hpp/cpp             Qt message handler + file logging
│   ├── ui/
│   │   ├── ChatWindow.hpp/cpp         Qt6 chat window (singleton)
│   │   └── ConfigDialog.hpp/cpp       Qt6 configuration dialog (singleton)
│   └── uno/
│       ├── component.cpp              UNO entry points
│       ├── LibreAIJob.hpp/cpp         XJobExecutor — menu/toolbar/right-click handler
│       ├── LibreAIStarter.hpp/cpp     XJob — startup; opens window, installs interceptor
│       ├── CMInterceptor.hpp/cpp      XContextMenuInterceptor — right-click menu item
│       └── UnoHelper.hpp/cpp          LO UNO utilities (selection, applyText, applyRichText)
├── translations/                      Qt .ts / .qm files + .qrc
├── tests/
│   ├── unit/                          Google Test unit tests
│   └── integration/                   pytest headless integration tests
├── spec/                              Technical specification documents
├── META-INF/manifest.xml
├── Addons.xcu                         Menu bar + toolbar registration
├── Jobs.xcu                           Startup job bindings
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
