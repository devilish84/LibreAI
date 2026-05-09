#pragma once
#include <QString>
#include <QStringList>

enum class Provider  { Ollama, OpenAI, Claude, Grok, Gemini };
enum class OllamaAuth { None, Basic, ApiKey };

struct Config {
    Provider   provider  = Provider::Ollama;

    // URLs
    QString  ollamaUrl  = "http://localhost:11434";
    QString  openaiUrl  = "https://api.openai.com/v1";
    QString  claudeUrl  = "https://api.anthropic.com/v1";
    QString  grokUrl    = "https://api.x.ai/v1";
    QString  geminiUrl  = "https://generativelanguage.googleapis.com/v1beta";

    // Per-provider selected models (text generation)
    QString  ollamaModel;
    QString  openaiModel;
    QString  claudeModel;
    QString  grokModel;
    QString  geminiModel;

    // Ollama model whitelists (empty = all models allowed)
    QStringList ollamaTextModels;
    QStringList ollamaImageModels;

    // Image generation
    Provider imageProvider = Provider::OpenAI;
    QString  ollamaImageModel;
    QString  openaiImageModel = "dall-e-3";
    QString  grokImageModel   = "aurora";
    QString  geminiImageModel = "imagen-3.0-generate-002";

    // Ollama auth (non-secret parts)
    OllamaAuth ollamaAuth            = OllamaAuth::None;
    QString    ollamaBasicUser;
    QString    ollamaApiKeyHeader    = "Authorization";

    // Credentials — held in memory, stored in OS keychain (not JSON)
    QString  openaiKey;
    QString  claudeKey;
    QString  grokKey;
    QString  geminiKey;
    QString  ollamaBasicPass;
    QString  ollamaApiKeyValue;

    // Batch processing
    int  batchDelayMs         = 500;
    int  batchTimeoutSec      = 60;
    bool batchStopOnError     = false;

    // UI / misc
    QString  language        = "en";
    bool     loggingEnabled  = false;
    int      logLevel        = 1;   // 0=Debug  1=Info  2=Error
    int      maxLogSizeMb    = 5;   // rotate when log exceeds this size

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();

    // Convenience: model for currently active text provider
    const QString& currentModel() const;
    void           setCurrentModel(const QString& m);

    // Convenience: image model for currently active image provider
    const QString& currentImageModel() const;
    void           setCurrentImageModel(const QString& m);

private:
    Config();
};
