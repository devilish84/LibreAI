#include "Config.hpp"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

static QString configPath() {
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);
    return dir + "/config.json";
}

Config::Config() {
    QFile f(configPath());
    if (!f.open(QIODevice::ReadOnly)) return;
    auto obj = QJsonDocument::fromJson(f.readAll()).object();

    QString p = obj["provider"].toString("OLLAMA");
    if      (p == "OPENAI") provider = Provider::OpenAI;
    else if (p == "CLAUDE") provider = Provider::Claude;
    else                    provider = Provider::Ollama;

    ollamaUrl = obj["ollama_url"].toString(ollamaUrl);
    openaiUrl = obj["openai_url"].toString(openaiUrl);
    openaiKey = obj["openai_key"].toString();
    claudeKey = obj["claude_key"].toString();
    model     = obj["model"].toString();
}

Config& Config::get() {
    static Config instance;
    return instance;
}

void Config::save() const {
    QJsonObject obj;
    obj["provider"]   = provider == Provider::OpenAI ? "OPENAI"
                      : provider == Provider::Claude  ? "CLAUDE" : "OLLAMA";
    obj["ollama_url"] = ollamaUrl;
    obj["openai_url"] = openaiUrl;
    obj["openai_key"] = openaiKey;
    obj["claude_key"] = claudeKey;
    obj["model"]      = model;

    QFile f(configPath());
    if (f.open(QIODevice::WriteOnly))
        f.write(QJsonDocument(obj).toJson());
}
