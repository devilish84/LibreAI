#pragma once
#include <QString>

enum class Provider  { Ollama, OpenAI, Claude };
enum class OllamaAuth { None, Basic, ApiKey };

struct Config {
    Provider   provider  = Provider::Ollama;

    // URLs
    QString  ollamaUrl  = "http://localhost:11434";
    QString  openaiUrl  = "https://api.openai.com/v1";

    // Per-provider selected models
    QString  ollamaModel;
    QString  openaiModel;
    QString  claudeModel;

    // Ollama auth (non-secret parts)
    OllamaAuth ollamaAuth            = OllamaAuth::None;
    QString    ollamaBasicUser;
    QString    ollamaApiKeyHeader    = "Authorization";

    // Credentials — held in memory, stored in OS keychain (not JSON)
    QString  openaiKey;
    QString  claudeKey;
    QString  ollamaBasicPass;
    QString  ollamaApiKeyValue;

    // UI / misc
    QString  language        = "en";
    bool     loggingEnabled  = false;
    int      logLevel        = 1;   // 0=Debug  1=Info  2=Error

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();

    // Convenience: model for currently active provider
    const QString& currentModel() const;
    void           setCurrentModel(const QString& m);

private:
    Config();
};
