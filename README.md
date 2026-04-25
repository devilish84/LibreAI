# LibreAI

An AI writing assistant extension for **LibreOffice Writer**, implemented as a native C++/Qt6 UNO component — no Java required.

Connects to locally-running [Ollama](https://ollama.com) models or cloud providers (OpenAI, Anthropic Claude). Lets you grab selected text from your document, send it to an AI model, and apply the response back — all from a floating chat window or the right-click context menu.

---

## Features

- **Multi-provider** — Ollama (local), OpenAI, and Anthropic Claude
- **Writer integration** — grab selected text, rewrite it, apply response back to document
- **Right-click shortcut** — "Grab Selection to LibreAI" context menu item pre-loads selected text
- **Auto-open on startup** — chat window (or Configuration dialog) opens automatically when LibreOffice starts
- **Separate Configuration dialog** — provider, connection, and model selection in a dedicated dialog (LibreAI → Configuration)
- **Per-provider settings** — each provider remembers its own model and connection settings independently
- **Ollama remote auth** — supports None, HTTP Basic Auth, and API-key header authentication for Ollama behind a reverse proxy
- **Secure credential storage** — API keys and passwords stored in the OS keychain (QtKeychain on Linux, DPAPI on Windows) — never written to disk as plaintext
- **Comprehensive logging** — all activity written to `~/.config/libreai/libreai.log`; verbose HTTP debug logging optional
- **i18n** — UI available in English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português; language selectable from Configuration
- **Processing animation** — braille spinner shown in the response area while waiting for the model
- **Dark theme** — VS Code-inspired dark UI
- **Async networking** — UI never blocks while waiting for AI responses

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
| QtKeychain | Qt 6 | `qtkeychain-qt6-dev` (Linux, optional — fallback to in-memory) |

**Runtime:**

| Package | Notes |
|---------|-------|
| `libqt6widgets6` | Qt 6 runtime |
| `libqt6network6` | Qt 6 network |
| `libqt6keychain1` | Secure credential storage (Linux) |
| Ollama *(optional)* | Running at `http://localhost:11434` |
| OpenAI API key *(optional)* | For GPT models |
| Anthropic API key *(optional)* | For Claude models |

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
# Build, package, and install directly into your LO user profile
bash build.sh --install
```

Or build only (produces `libreai.oxt`):

```bash
bash build.sh
```

Then install manually:

```bash
unopkg remove org.libreai 2>/dev/null || true
unopkg add -f libreai.oxt
```

Restart LibreOffice to activate.

---

## Configuration

On first launch LibreOffice will open the **Configuration** dialog automatically. You can also reach it at any time via **LibreAI → Configuration**.

### General Settings tab

| Setting | Description |
|---------|-------------|
| Language | UI language for all LibreAI windows |
| Enable verbose logging | Write debug-level entries including HTTP request/response bodies to the log file |
| Log level | Minimum severity when verbose logging is enabled (Debug / Info / Error) |

Supported languages: English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português.

### Model Selection tab

Select a provider; only the relevant fields are shown:

**Ollama**

| Setting | Description |
|---------|-------------|
| Base URL | Ollama server URL (default `http://localhost:11434`) |
| Auth | None / Basic Auth / API Key |
| Username / Password | Shown when Basic Auth is selected |
| Header / API Key | Shown when API Key is selected (default header: `Authorization`) |
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

Credentials (API keys, passwords) are stored in the OS keychain — never written to `config.json`. If the keychain is unavailable a warning is shown and you will need to re-enter credentials on next start.

Settings are saved to `~/.config/libreai/config.json`:

```json
{
  "provider": "OLLAMA",
  "ollama_url": "http://localhost:11434",
  "ollama_auth": "NONE",
  "ollama_basic_user": "",
  "ollama_api_key_header": "Authorization",
  "openai_url": "https://api.openai.com/v1",
  "ollama_model": "",
  "openai_model": "",
  "claude_model": "",
  "language": "en",
  "logging_enabled": false,
  "log_level": 1
}
```

---

## Logging

LibreAI always writes a log file at:

```
~/.config/libreai/libreai.log
```

By default only Info-level entries are written. Enable **verbose logging** in Configuration → General Settings to also capture HTTP request/response bodies (useful for debugging AI provider issues). API keys and auth headers are never included in the log.

---

## Usage

1. LibreOffice Writer opens → the LibreAI chat window appears automatically.
2. If not yet configured, the Configuration dialog opens first — select a provider, enter credentials, refresh and pick a model, then click **OK**.
3. In the chat window:
   - Type a question or instruction in **INSTRUCTION / CHAT** and click **Send** for a pure chat message.
   - Select text in your document and click **Grab Selection** (or right-click → **Grab Selection to LibreAI**) to load it into the **SELECTED TEXT** area, then add an instruction and click **Send** or **Rewrite**.
   - Click **Apply to Document** to replace the selected text with the AI response.
4. A spinner animation plays in the response area while the model is processing.

---

## Project Structure

```
LibreAI/
├── src/
│   ├── ai/
│   │   ├── AIClient.hpp               Abstract AI provider base (QObject + signals)
│   │   ├── OllamaClient.hpp/cpp       Ollama REST client (with auth support)
│   │   ├── OpenAIClient.hpp/cpp       OpenAI REST client
│   │   └── AnthropicClient.hpp/cpp    Anthropic Claude REST client
│   ├── core/
│   │   ├── Config.hpp/cpp             JSON config singleton + language loader
│   │   ├── CredentialStore.hpp/cpp    OS keychain / DPAPI credential storage
│   │   └── Logger.hpp/cpp             Qt message handler + file logging
│   ├── ui/
│   │   ├── ChatWindow.hpp/cpp         Qt6 chat window (singleton)
│   │   └── ConfigDialog.hpp/cpp       Qt6 configuration dialog with tabs (singleton)
│   └── uno/
│       ├── component.cpp              UNO entry points
│       ├── LibreAIJob.hpp/cpp         XJobExecutor — menu/toolbar/right-click handler
│       ├── LibreAIStarter.hpp/cpp     XJob — startup; opens window, installs interceptor
│       ├── CMInterceptor.hpp/cpp      XContextMenuInterceptor — right-click menu item
│       └── UnoHelper.hpp/cpp          LO UNO utilities (selection, apply text)
├── translations/
│   ├── libreai_fi.ts / .qm            Finnish
│   ├── libreai_sv.ts / .qm            Swedish
│   ├── libreai_da.ts / .qm            Danish
│   ├── libreai_nb.ts / .qm            Norwegian
│   ├── libreai_es.ts / .qm            Spanish
│   ├── libreai_de.ts / .qm            German
│   ├── libreai_pt.ts / .qm            Portuguese
│   └── libreai_translations.qrc       Qt resource file embedding all .qm files
├── tests/
│   ├── unit/                          Google Test unit tests
│   └── integration/                   pytest headless integration tests
├── META-INF/manifest.xml              Extension manifest
├── Addons.xcu                         Menu bar + toolbar registration (with i18n)
├── Jobs.xcu                           Startup job bindings
├── CMakeLists.txt                     CMake build definition
├── build.sh                           Build + package + install script
└── spec/
    └── *.md                           Technical specification documents
```

---

## Adding a New Language

1. Copy an existing `translations/libreai_fi.ts` to `translations/libreai_XX.ts` (using the BCP 47 language code).
2. Translate all `<translation>` entries.
3. Add the language to `kLanguages[]` in `src/ui/ConfigDialog.cpp`.
4. Add the compiled `.qm` filename to `translations/libreai_translations.qrc`.
5. Add localized `<value xml:lang="XX">` entries in `Addons.xcu` for the menu items.
6. Run `lrelease translations/libreai_XX.ts` then `bash build.sh --install`.

---

## License

MIT
