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

    static Config& get();
    void save() const;
    bool isConfigured() const;
    static void applyLanguage();

private:
    Config();
};
