# AI Provider Integration

## Abstract Base — `AIClient`

**File:** `src/AIClient.hpp`  
**Base:** `QObject`

All provider clients inherit `AIClient` and implement two pure virtual methods:

```cpp
virtual void fetchModels() = 0;
virtual void sendChat(const QString& model,
                      const QList<QPair<QString,QString>>& history,
                      const QString& prompt) = 0;
```

Results are delivered via Qt signals (connect in `ChatWindow`):

```cpp
signals:
    void modelsReady(QStringList models);
    void responseReady(QString text);
    void errorOccurred(QString error);
```

All HTTP requests use `QNetworkAccessManager` — fully async, never blocks the UNO thread.  
Connect/read timeout: **30 s** (`QNetworkRequest::setTransferTimeout`).

---

## Ollama (local)

**Class:** `OllamaClient` (`src/OllamaClient.cpp`)  
**Default URL:** `http://localhost:11434`  
**Auth:** None

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | `GET` | `/api/tags` | Returns `models[].name` |
| Chat | `POST` | `/api/chat` | Body: `{model, messages, stream: false}` |

Message format:
```json
{ "role": "user"|"assistant", "content": "..." }
```

Response field: `response.message.content`

To use a self-hosted or remote Ollama instance change the URL in ConfigDialog → AI Provider tab.

---

## OpenAI (and compatible endpoints)

**Class:** `OpenAIClient` (`src/OpenAIClient.cpp`)  
**Default URL:** `https://api.openai.com/v1`  
**Auth:** `Authorization: Bearer <openai_key>`

| Operation | Method | Endpoint | Notes |
|-----------|--------|----------|-------|
| List models | `GET` | `/models` | Filters to `id` values containing `"gpt"` |
| Chat | `POST` | `/chat/completions` | Body: `{model, messages, stream: false}` |

The configurable base URL means any OpenAI-compatible API (e.g. LocalAI, LM Studio, Azure OpenAI) works by pointing `openai_url` at the right host.

Response field: `choices[0].message.content`

---

## Anthropic Claude

**Class:** `AnthropicClient` (`src/AnthropicClient.cpp`)  
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

## Adding a New Provider

1. Create `src/MyProviderClient.hpp` / `.cpp` inheriting `AIClient`.
2. Implement `fetchModels()` and `sendChat()` emitting the three standard signals.
3. Add a new `Provider::MyProvider` enum value in `Config.hpp`.
4. Add it to the provider `QComboBox` in `ConfigDialog` and handle its credential field visibility.
5. Instantiate it in `ChatWindow` when the provider changes.
6. Add the JSON key to `Config::save()` / `Config()` constructor.
