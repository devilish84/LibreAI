# AI Provider Integration

## Abstract Base — `AIClient`

**File:** `src/ai/AIClient.hpp`  
**Base:** `QObject`

All provider clients inherit `AIClient` and implement two pure virtual methods:

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
    QString timestamp;  // ISO 8601, e.g. "2026-04-28T14:32:01"
    QString provider;   // "ollama" | "openai" | "claude" | "grok" | "gemini"
    QString model;      // e.g. "gpt-4o"
};
```

The last three fields are optional — two-field aggregate init (`{"user", prompt}`) still compiles.

All HTTP requests use `QNetworkAccessManager` — fully async, never blocks the UNO thread.

---

## Ollama (local)

**Class:** `OllamaClient` (`src/ai/OllamaClient.cpp`)  
**Default URL:** `http://localhost:11434`

### Authentication modes

Configured via `OllamaAuthConfig` (read from `Config`):

| Mode | Description |
|------|-------------|
| None | No headers added (default for local Ollama) |
| Basic | `Authorization: Basic <base64(user:pass)>` |
| ApiKey | `<custom-header>: <value>` (configurable header name and value) |

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | `GET` | `/api/tags` | Returns `models[].name` |
| Chat | `POST` | `/api/chat` | Body: `{model, messages, stream: false}` |

Message format:
```json
{ "role": "user"|"assistant", "content": "..." }
```

Response field: `message.content`

---

## OpenAI (and compatible endpoints)

**Class:** `OpenAIClient` (`src/ai/OpenAIClient.cpp`)  
**Default URL:** `https://api.openai.com/v1`  
**Auth:** `Authorization: Bearer <openai_key>`

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | `GET` | `/models` | Filters to IDs containing `"gpt"` |
| Chat | `POST` | `/chat/completions` | Body: `{model, messages, stream: false}` |

The configurable base URL means any OpenAI-compatible API (LocalAI, LM Studio, Azure OpenAI, etc.) works by pointing `openai_url` at the right host.

Response field: `choices[0].message.content`

---

## Anthropic Claude

**Class:** `AnthropicClient` (`src/ai/AnthropicClient.cpp`)  
**URL:** `https://api.anthropic.com` (hard-coded)  
**Auth:** `x-api-key: <claude_key>`, `anthropic-version: 2023-06-01`

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | — | — | No public endpoint; list is **hard-coded** |
| Chat | `POST` | `/v1/messages` | Body: `{model, messages, max_tokens: 4096}` |

**Hard-coded model list** (update in `AnthropicClient.cpp` when new models release):
```
claude-opus-4-7
claude-sonnet-4-6
claude-haiku-4-5-20251001
claude-opus-4-5
claude-sonnet-4-5
claude-haiku-3-5
```

Response field: `content[0].text`

---

## Grok (xAI)

**Class:** `GrokClient` (`src/ai/GrokClient.cpp`)  
**URL:** `https://api.x.ai/v1` (hard-coded)  
**Auth:** `Authorization: Bearer <grok_key>`

OpenAI-compatible wire format. Excludes embed/image/audio/vision models from the model list.

| Operation | Method | Endpoint |
|-----------|--------|----------|
| List models | `GET` | `/models` |
| Chat | `POST` | `/chat/completions` |

Response field: `choices[0].message.content`

---

## Gemini (Google)

**Class:** `GeminiClient` (`src/ai/GeminiClient.cpp`)  
**Base URL:** `https://generativelanguage.googleapis.com/v1beta`  
**Auth:** `?key=<gemini_key>` query parameter

Gemini uses its own request/response structure — not OpenAI-compatible.

| Operation | Method | Endpoint |
|-----------|--------|----------|
| List models | `GET` | `/models?key=…` |
| Chat | `POST` | `/models/<model>:generateContent?key=…` |

Request body:
```json
{
  "contents": [
    { "role": "user"|"model", "parts": [{ "text": "..." }] }
  ]
}
```

`"assistant"` history role is mapped to `"model"` for Gemini.  
`parseModels` strips the `"models/"` prefix from each name and excludes embedding/aqa/attribution/retrieval/vision models.

Response field: `candidates[0].content.parts[0].text`

---

## Adding a New Provider

1. Create `src/ai/MyProviderClient.hpp` / `.cpp` inheriting `AIClient`.
2. Implement `fetchModels()` and `sendChat()` emitting the three standard signals.
3. Add a new `Provider::MyProvider` enum value in `src/core/Config.hpp`.
4. Add load/save logic in `Config.cpp` (JSON key + `currentModel()` / `isConfigured()` switch).
5. Store the API key via `CredentialStore::store("libreai/myprovider_key", ...)`.
6. Add the provider to the `QComboBox` in `ConfigDialog` and handle field visibility.
7. Instantiate it in `ChatWindow::buildClient()`.
8. Add `src/ai/MyProviderClient.cpp` to `SOURCES` in `CMakeLists.txt`.
