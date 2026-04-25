#pragma once
#include <QString>

enum class Provider { Ollama, OpenAI, Claude };

struct Config {
    Provider provider   = Provider::Ollama;
    QString  ollamaUrl  = "http://localhost:11434";
    QString  openaiUrl  = "https://api.openai.com/v1";
    QString  openaiKey;
    QString  claudeKey;
    QString  model;
    QString  language   = "en";
    bool     loggingEnabled = false;
    int      logLevel       = 1;   // 0=Debug  1=Info  2=Error

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();

private:
    Config();
};
