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
- **i18n** — UI available in English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português; language selectable from Configuration
- **Processing animation** — braille spinner shown in the response area while waiting for the model
- **Persistent config** — all settings saved to `~/.config/libreai/config.json`
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

**Runtime:**

| Package | Notes |
|---------|-------|
| `libqt6widgets6` | Qt 6 runtime |
| `libqt6network6` | Qt 6 network |
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
    linguist-qt6
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

Supported languages: English, Suomi, Svenska, Dansk, Norsk, Español, Deutsch, Português.

### Model Selection tab

| Setting | Description |
|---------|-------------|
| Provider | Ollama / OpenAI / Claude |
| Base URL / API Key | Connection details for the selected provider |
| Model | Click **↺** to fetch available models, then select one |

Settings are saved to `~/.config/libreai/config.json`:

```json
{
  "provider": "OLLAMA",
  "ollama_url": "http://localhost:11434",
  "openai_url": "https://api.openai.com/v1",
  "openai_key": "",
  "claude_key": "",
  "model": "",
  "language": "en"
}
```

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
│   ├── component.cpp              UNO entry points
│   ├── LibreAIJob.hpp/cpp         XJobExecutor — menu/toolbar/right-click handler
│   ├── LibreAIStarter.hpp/cpp     XJob — startup; opens window, installs interceptor
│   ├── CMInterceptor.hpp/cpp      XContextMenuInterceptor — right-click menu item
│   ├── ChatWindow.hpp/cpp         Qt6 chat window (singleton)
│   ├── ConfigDialog.hpp/cpp       Qt6 configuration dialog with tabs (singleton)
│   ├── AIClient.hpp               Abstract AI provider base (QObject + signals)
│   ├── OllamaClient.hpp/cpp       Ollama REST client
│   ├── OpenAIClient.hpp/cpp       OpenAI REST client
│   ├── AnthropicClient.hpp/cpp    Anthropic Claude REST client
│   ├── Config.hpp/cpp             JSON config singleton + language loader
│   └── UnoHelper.hpp/cpp          LO UNO utilities (selection, apply text)
├── translations/
│   ├── libreai_fi.ts / .qm        Finnish
│   ├── libreai_sv.ts / .qm        Swedish
│   ├── libreai_da.ts / .qm        Danish
│   ├── libreai_nb.ts / .qm        Norwegian
│   ├── libreai_es.ts / .qm        Spanish
│   ├── libreai_de.ts / .qm        German
│   ├── libreai_pt.ts / .qm        Portuguese
│   └── libreai_translations.qrc   Qt resource file embedding all .qm files
├── META-INF/manifest.xml          Extension manifest
├── Addons.xcu                     Menu bar + toolbar registration (with i18n)
├── Jobs.xcu                       Startup job bindings
├── CMakeLists.txt                 CMake build definition
├── build.sh                       Build + package + install script
└── spec/
    └── LibreAI_Specification.md   Full technical specification
```

---

## Adding a New Language

1. Copy an existing `translations/libreai_fi.ts` to `translations/libreai_XX.ts` (using the BCP 47 language code).
2. Translate all `<translation>` entries.
3. Add the language to `kLanguages[]` in `src/ConfigDialog.cpp`.
4. Add the compiled `.qm` filename to `translations/libreai_translations.qrc`.
5. Add localized `<value xml:lang="XX">` entries in `Addons.xcu` for the menu items.
6. Run `lrelease translations/libreai_XX.ts` then `bash build.sh --install`.

---

## License

MIT
