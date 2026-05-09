#include "OllamaClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QLoggingCategory>
#include <QAtomicInteger>

Q_LOGGING_CATEGORY(lcOllama, "libreai.ollama")

static QAtomicInteger<int> s_ollamaReqId{0};

OllamaAuthConfig OllamaAuthConfig::fromConfig() {
    qCDebug(lcOllama) << "OllamaAuthConfig::fromConfig";
    const Config& c = Config::get();
    return { c.ollamaAuth, c.ollamaBasicUser, c.ollamaBasicPass,
             c.ollamaApiKeyHeader, c.ollamaApiKeyValue };
}

OllamaClient::OllamaClient(const QString& baseUrl,
                             const OllamaAuthConfig& auth,
                             QObject* parent)
    : AIClient(parent), m_baseUrl(baseUrl), m_auth(auth)
{
    qCDebug(lcOllama) << "OllamaClient constructed, baseUrl=" << baseUrl;
}

void OllamaClient::applyAuth(QNetworkRequest& req) const {
    qCDebug(lcOllama) << "applyAuth, type=" << static_cast<int>(m_auth.type);
    switch (m_auth.type) {
        case OllamaAuth::None:
            break;
        case OllamaAuth::Basic: {
            QByteArray creds = (m_auth.basicUser + ":" + m_auth.basicPass).toUtf8().toBase64();
            req.setRawHeader("Authorization", "Basic " + creds);
            break;
        }
        case OllamaAuth::ApiKey:
            req.setRawHeader(m_auth.apiKeyHeader.toUtf8(), m_auth.apiKeyValue.toUtf8());
            break;
    }
}

QStringList OllamaClient::parseAllModels(const QByteArray& json) {
    auto arr = QJsonDocument::fromJson(json).object()["models"].toArray();
    QStringList names;
    for (auto v : arr)
        names << v.toObject()["name"].toString();
    return names;
}

QStringList OllamaClient::parseModels(const QByteArray& json) {
    static const QStringList kExclude = {
        "llava", "stable-diffusion", "sdxl", "dall",
        "whisper", "speech", "audio",
        "codellama", "codegemma", "starcoder", "deepseek-coder", "coder"
    };
    auto arr = QJsonDocument::fromJson(json).object()["models"].toArray();
    QStringList names;
    for (auto v : arr) {
        QString name = v.toObject()["name"].toString();
        bool skip = false;
        for (const QString& kw : kExclude)
            if (name.contains(kw, Qt::CaseInsensitive)) { skip = true; break; }
        if (!skip) names << name;
    }
    return names;
}

QString OllamaClient::parseResponse(const QByteArray& json) {
    return QJsonDocument::fromJson(json)
               .object()["message"].toObject()["content"].toString();
}

void OllamaClient::fetchAllModels() {
    qCDebug(lcOllama) << "fetchAllModels, url=" << (m_baseUrl + "/api/tags");
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    applyAuth(req);
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        emit modelsReady(parseAllModels(reply->readAll()));
    });
}

void OllamaClient::fetchModels() {
    qCDebug(lcOllama) << "fetchModels, url=" << (m_baseUrl + "/api/tags");
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    applyAuth(req);
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOllama) << "fetchModels error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcOllama) << "fetchModels response body:" << body;
        QStringList names = parseModels(body);
        qCInfo(lcOllama) << "fetchModels ready, count=" << names.size();
        emit modelsReady(names);
    });
}

void OllamaClient::sendChat(const QString& model,
                             const QVector<Message>& history,
                             const QString& prompt) {
    int reqId = s_ollamaReqId.fetchAndAddRelaxed(1);
    qCDebug(lcOllama) << "sendChat reqId=" << reqId
                      << "model=" << model
                      << "historySize=" << history.size()
                      << "promptLength=" << prompt.length();

    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{{"model", model}, {"messages", messages}, {"stream", false}};
    QByteArray bodyBytes = QJsonDocument(body).toJson();
    qCDebug(lcOllama) << "sendChat request body:" << bodyBytes;

    QNetworkRequest req(QUrl(m_baseUrl + "/api/chat"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    applyAuth(req);
    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply, reqId, model] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOllama) << "sendChat reqId=" << reqId << "error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcOllama) << "sendChat reqId=" << reqId << "response body:" << respBody;
        QString content = parseResponse(respBody);
        qCInfo(lcOllama) << "sendChat reqId=" << reqId << "model=" << model
                         << "response length=" << content.length();
        emit responseReady(content);
    });
}
