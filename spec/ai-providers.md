# AI Provider Integration

## Text Generation

### Abstract Base — `AIClient`

**File:** `src/ai/AIClient.hpp`  
**Base:** `QObject`

All text provider clients inherit `AIClient` and implement two pure virtual methods:

```cpp
virtual void fetchModels() = 0;
virtual void sendChat(const QString& model,
                      const QVector<Message>& history,
                      const QString& prompt) = 0;
```

Results are delivered via Qt signals:

```cpp
signals:
    void modelsReady(QStringList models);
    void responseReady(QString text);
    void errorOccurred(QString error);
```

### Message Struct

```cpp
struct Message {
    QString role;       // "user" | "assistant"
    QString content;
    QString timestamp;  // ISO 8601
    QString provider;   // "ollama" | "openai" | "claude" | "grok" | "gemini"
    QString model;
};
```

All HTTP requests use `QNetworkAccessManager` — fully async, never blocks the UNO thread.

---

### Ollama

**Class:** `OllamaClient` (`src/ai/OllamaClient.cpp`)  
**Default URL:** `http://localhost:11434` (configurable)

#### Authentication modes

| Mode | Header |
|------|--------|
| None | No headers added |
| Basic | `Authorization: Basic <base64(user:pass)>` |
| ApiKey | `<custom-header>: <value>` |

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models (filtered) | `GET` | `/api/tags` | `fetchModels()` — returns image-keyword models only |
| List models (all) | `GET` | `/api/tags` | `fetchAllModels()` — returns all models for Providers tab |
| Chat | `POST` | `/api/chat` | Body: `{model, messages, stream: false}` |

Response field: `message.content`

---

### OpenAI (and compatible endpoints)

**Class:** `OpenAIClient` (`src/ai/OpenAIClient.cpp`)  
**Default URL:** `https://api.openai.com/v1` (configurable)  
**Auth:** `Authorization: Bearer <openai_key>`

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | `GET` | `/models` | Filters to IDs containing `"gpt"` |
| Chat | `POST` | `/chat/completions` | Body: `{model, messages, stream: false}` |

Response field: `choices[0].message.content`

---

### Anthropic Claude

**Class:** `AnthropicClient` (`src/ai/AnthropicClient.cpp`)  
**Default URL:** `https://api.anthropic.com/v1` (configurable)  
**Auth:** `x-api-key: <claude_key>`, `anthropic-version: 2023-06-01`

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | — | — | No public endpoint; list is **hard-coded** |
| Chat | `POST` | `<baseUrl>/messages` | Body: `{model, messages, max_tokens: 4096}` |

**Hard-coded model list** (update in `AnthropicClient::hardcodedModels()` when new models release):
```
claude-opus-4-7
claude-sonnet-4-6
claude-haiku-4-5-20251001
```

Response field: `content[0].text`

---

### Grok (xAI)

**Class:** `GrokClient` (`src/ai/GrokClient.cpp`)  
**Default URL:** `https://api.x.ai/v1` (configurable)  
**Auth:** `Authorization: Bearer <grok_key>`

OpenAI-compatible wire format. Excludes embed/image/audio/vision models from the model list.

| Operation | Method | Endpoint |
|-----------|--------|----------|
| List models | `GET` | `/models` |
| Chat | `POST` | `/chat/completions` |

Response field: `choices[0].message.content`

---

### Gemini (Google)

**Class:** `GeminiClient` (`src/ai/GeminiClient.cpp`)  
**Default URL:** `https://generativelanguage.googleapis.com/v1beta` (configurable)  
**Auth:** `?key=<gemini_key>` query parameter

| Operation | Method | Endpoint |
|-----------|--------|----------|
| List models | `GET` | `/models?key=…` |
| Chat | `POST` | `/models/<model>:generateContent?key=…` |

`"assistant"` history role is mapped to `"model"` for Gemini.  
`parseModels` strips the `"models/"` prefix and excludes embedding/aqa/attribution/retrieval/vision models.

Response field: `candidates[0].content.parts[0].text`

---

## Image Generation

### Abstract Base — `ImageClient`

**File:** `src/ai/ImageClient.hpp` / `src/ai/ImageClient.cpp`  
**Base:** `QObject`

Separate hierarchy from `AIClient` — different interface (no chat history, returns binary PNG).

```cpp
virtual void fetchImageModels() = 0;
virtual void generateImage(const QString& model,
                           const QString& prompt,
                           const QString& size) = 0;
signals:
    void imageModelsReady(QStringList models);
    void imageReady(QByteArray pngData);
    void errorOccurred(QString error);
```

The out-of-line destructor in `ImageClient.cpp` anchors the vtable/typeinfo (required for shared library linking).

---

### Ollama Image

**Class:** `OllamaImageClient` (`src/ai/OllamaImageClient.cpp`)  
**Endpoint:** `POST /api/generate`  
**Auth:** same `OllamaAuthConfig` as text client

`fetchImageModels()` fetches all Ollama models and returns only those matching image keywords: `flux`, `stable-diffusion`, `sdxl`, `dall`, `wuerstchen`, `kandinsky`, `dreamshaper`, `playground`, `juggernaut`.

Response: `{"images": ["<base64>"]}` or `{"image": "<base64>"}` — decoded to PNG bytes.

---

### OpenAI Image (DALL-E)

**Class:** `OpenAIImageClient` (`src/ai/OpenAIImageClient.cpp`)  
**Default URL:** `https://api.openai.com/v1` (configurable)  
**Auth:** `Authorization: Bearer <openai_key>`  
**Hard-coded models:** `dall-e-3`, `dall-e-2`

`POST /images/generations` with `response_format: b64_json`.  
Response: `data[0].b64_json` decoded to PNG bytes.

---

### Grok Image (Aurora)

**Class:** `GrokImageClient` (`src/ai/GrokImageClient.cpp`)  
**Default URL:** `https://api.x.ai/v1` (configurable)  
**Auth:** `Authorization: Bearer <grok_key>`  
**Hard-coded models:** `aurora`

OpenAI-compatible image endpoint. Size parameter omitted for Aurora.

---

### Gemini Image (Imagen)

**Class:** `GeminiImageClient` (`src/ai/GeminiImageClient.cpp`)  
**Default URL:** `https://generativelanguage.googleapis.com/v1beta` (configurable)  
**Hard-coded models:** `imagen-3.0-generate-002`, `imagen-3.0-fast-generate-001`, `gemini-2.0-flash-exp-image-generation`

Routes by model name:
- `imagen*` → `POST /models/<model>:predict` — response: `predictions[0].bytesBase64Encoded`
- `gemini*` → `POST /models/<model>:generateContent` with `responseModalities: ["IMAGE"]` — response: first `inlineData.data` part

---

## Adding a New Text Provider

1. Create `src/ai/MyProviderClient.hpp` / `.cpp` inheriting `AIClient`.
2. Implement `fetchModels()` and `sendChat()` emitting the three standard signals.
3. Add a new `Provider::MyProvider` enum value in `src/core/Config.hpp`.
4. Add `myProviderUrl` and `myProviderModel` fields to `Config`; update load/save in `Config.cpp`.
5. Store the API key via `CredentialStore::store("libreai/myprovider_key", ...)`.
6. Add the provider to the `QComboBox` in `ConfigDialog::buildProvidersTab()` and add a stack page.
7. Instantiate in `ChatWindow::buildClient()` and `BatchProcessor`.
8. Add `src/ai/MyProviderClient.cpp` to `SOURCES` in `CMakeLists.txt`.

## Adding a New Image Provider

Same steps as above but inherit `ImageClient`, implement `fetchImageModels()` and `generateImage()`.  
Add to `ConfigDialog::buildImageGenTab()` and `ImageGenDialog::buildClient()`.
