#include "Config.hpp"
#include "CredentialStore.hpp"
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QStandardPaths>
#include <QTranslator>

Q_LOGGING_CATEGORY(lcConfig, "libreai.config")

static QString configPath() {
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);
    return dir + "/config.json";
}

Config::Config() {
    qCDebug(lcConfig) << "Config loading from" << configPath();
    QFile f(configPath());
    if (!f.open(QIODevice::ReadOnly)) {
        qCInfo(lcConfig) << "No config file found, using defaults";
        return;
    }
    auto obj = QJsonDocument::fromJson(f.readAll()).object();

    QString p = obj["provider"].toString("OLLAMA");
    if      (p == "OPENAI") provider = Provider::OpenAI;
    else if (p == "CLAUDE") provider = Provider::Claude;
    else if (p == "GROK")   provider = Provider::Grok;
    else if (p == "GEMINI") provider = Provider::Gemini;
    else                    provider = Provider::Ollama;

    ollamaUrl = obj["ollama_url"].toString(ollamaUrl);
    openaiUrl = obj["openai_url"].toString(openaiUrl);

    ollamaModel  = obj["ollama_model"].toString();
    openaiModel  = obj["openai_model"].toString();
    claudeModel  = obj["claude_model"].toString();
    grokModel    = obj["grok_model"].toString();
    geminiModel  = obj["gemini_model"].toString();

    // Migrate legacy single "model" field
    if (ollamaModel.isEmpty() && openaiModel.isEmpty() && claudeModel.isEmpty()) {
        QString legacy = obj["model"].toString();
        if (!legacy.isEmpty()) {
            qCInfo(lcConfig) << "Migrating legacy model field:" << legacy;
            setCurrentModel(legacy);
        }
    }

    QString auth = obj["ollama_auth"].toString("NONE");
    if      (auth == "BASIC")  ollamaAuth = OllamaAuth::Basic;
    else if (auth == "APIKEY") ollamaAuth = OllamaAuth::ApiKey;
    else                       ollamaAuth = OllamaAuth::None;

    ollamaBasicUser      = obj["ollama_basic_user"].toString();
    ollamaApiKeyHeader   = obj["ollama_api_key_header"].toString(ollamaApiKeyHeader);

    language        = obj["language"].toString("en");
    loggingEnabled  = obj["logging_enabled"].toBool(false);
    logLevel        = obj["log_level"].toInt(1);
    maxLogSizeMb    = obj["max_log_size_mb"].toInt(5);

    qCDebug(lcConfig) << "Config loaded: provider=" << p
                      << "ollamaUrl=" << ollamaUrl
                      << "language=" << language
                      << "loggingEnabled=" << loggingEnabled;

    // Load credentials from OS keychain (never from JSON).
    // Call isAvailable() first so subsequent calls use the cached result.
    CredentialStore::isAvailable();
    openaiKey        = CredentialStore::retrieve("libreai/openai_key");
    claudeKey        = CredentialStore::retrieve("libreai/claude_key");
    grokKey          = CredentialStore::retrieve("libreai/grok_key");
    geminiKey        = CredentialStore::retrieve("libreai/gemini_key");
    ollamaBasicPass  = CredentialStore::retrieve("libreai/ollama_basic_pass");
    ollamaApiKeyValue= CredentialStore::retrieve("libreai/ollama_api_key");

    qCDebug(lcConfig) << "Credentials loaded from keychain:"
                      << "openaiKey=" << (!openaiKey.isEmpty() ? "set" : "empty")
                      << "claudeKey=" << (!claudeKey.isEmpty() ? "set" : "empty")
                      << "grokKey="   << (!grokKey.isEmpty()   ? "set" : "empty")
                      << "geminiKey=" << (!geminiKey.isEmpty() ? "set" : "empty");
}

Config& Config::get() {
    static Config instance;
    return instance;
}

void Config::save() const {
    qCInfo(lcConfig) << "Saving configuration, provider="
                     << (provider == Provider::OpenAI ? "OPENAI"
                        : provider == Provider::Claude  ? "CLAUDE"
                        : provider == Provider::Grok    ? "GROK"
                        : provider == Provider::Gemini  ? "GEMINI" : "OLLAMA");

    QJsonObject obj;
    obj["provider"]   = provider == Provider::OpenAI ? "OPENAI"
                      : provider == Provider::Claude  ? "CLAUDE"
                      : provider == Provider::Grok    ? "GROK"
                      : provider == Provider::Gemini  ? "GEMINI" : "OLLAMA";
    obj["ollama_url"] = ollamaUrl;
    obj["openai_url"] = openaiUrl;

    obj["ollama_model"]  = ollamaModel;
    obj["openai_model"]  = openaiModel;
    obj["claude_model"]  = claudeModel;
    obj["grok_model"]    = grokModel;
    obj["gemini_model"]  = geminiModel;

    obj["ollama_auth"] = ollamaAuth == OllamaAuth::Basic  ? "BASIC"
                       : ollamaAuth == OllamaAuth::ApiKey ? "APIKEY" : "NONE";
    obj["ollama_basic_user"]     = ollamaBasicUser;
    obj["ollama_api_key_header"] = ollamaApiKeyHeader;

    obj["language"]        = language;
    obj["logging_enabled"] = loggingEnabled;
    obj["log_level"]       = logLevel;
    obj["max_log_size_mb"] = maxLogSizeMb;

    CredentialStore::store("libreai/openai_key",        openaiKey);
    CredentialStore::store("libreai/claude_key",        claudeKey);
    CredentialStore::store("libreai/grok_key",          grokKey);
    CredentialStore::store("libreai/gemini_key",        geminiKey);
    CredentialStore::store("libreai/ollama_basic_pass", ollamaBasicPass);
    CredentialStore::store("libreai/ollama_api_key",    ollamaApiKeyValue);

    QFile f(configPath());
    if (f.open(QIODevice::WriteOnly)) {
        f.write(QJsonDocument(obj).toJson());
        qCInfo(lcConfig) << "Configuration saved to" << configPath();
    } else {
        qCWarning(lcConfig) << "Failed to open config file for writing:" << configPath();
    }
}

bool Config::isConfigured() const {
    qCDebug(lcConfig) << "isConfigured check, provider="
                      << static_cast<int>(provider);
    switch (provider) {
        case Provider::Ollama:  return !ollamaUrl.isEmpty();
        case Provider::OpenAI:  return !openaiKey.isEmpty();
        case Provider::Claude:  return !claudeKey.isEmpty();
        case Provider::Grok:    return !grokKey.isEmpty();
        case Provider::Gemini:  return !geminiKey.isEmpty();
    }
    return false;
}

const QString& Config::currentModel() const {
    qCDebug(lcConfig) << "currentModel";
    switch (provider) {
        case Provider::Ollama: return ollamaModel;
        case Provider::OpenAI: return openaiModel;
        case Provider::Claude: return claudeModel;
        case Provider::Grok:   return grokModel;
        case Provider::Gemini: return geminiModel;
    }
    return ollamaModel;
}

void Config::setCurrentModel(const QString& m) {
    qCDebug(lcConfig) << "setCurrentModel" << m;
    switch (provider) {
        case Provider::Ollama: ollamaModel  = m; return;
        case Provider::OpenAI: openaiModel  = m; return;
        case Provider::Claude: claudeModel  = m; return;
        case Provider::Grok:   grokModel    = m; return;
        case Provider::Gemini: geminiModel  = m; return;
    }
}

void Config::applyLanguage() {
    qCDebug(lcConfig) << "applyLanguage, lang=" << Config::get().language;
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
        qCWarning(lcConfig) << "Failed to load translation for" << lang;
        delete s_translator;
        s_translator = nullptr;
    } else {
        QApplication::installTranslator(s_translator);
        qCInfo(lcConfig) << "Language applied:" << lang;
    }
}
