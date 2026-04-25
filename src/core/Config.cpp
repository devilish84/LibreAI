#include "Config.hpp"
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QTranslator>

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
    language       = obj["language"].toString("en");
    loggingEnabled = obj["logging_enabled"].toBool(false);
    logLevel       = obj["log_level"].toInt(1);
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
    obj["language"]        = language;
    obj["logging_enabled"] = loggingEnabled;
    obj["log_level"]       = logLevel;

    QFile f(configPath());
    if (f.open(QIODevice::WriteOnly))
        f.write(QJsonDocument(obj).toJson());
}

bool Config::isConfigured() const {
    if (model.isEmpty()) return false;
    switch (provider) {
        case Provider::Ollama: return !ollamaUrl.isEmpty();
        case Provider::OpenAI: return !openaiKey.isEmpty();
        case Provider::Claude: return !claudeKey.isEmpty();
    }
    return false;
}

void Config::applyLanguage() {
    static QTranslator* s_translator = nullptr;
    if (s_translator) {
        QApplication::removeTranslator(s_translator);
        delete s_translator;
        s_translator = nullptr;
    }
    const QString& lang = Config::get().language;
    if (lang == "en") return;
    s_translator = new QTranslator();
    if (!s_translator->load(":/i18n/libreai_" + lang + ".qm")) {
        delete s_translator;
        s_translator = nullptr;
    } else {
        QApplication::installTranslator(s_translator);
    }
}
