#include "OpenAIClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QLoggingCategory>
#include <QAtomicInteger>

Q_LOGGING_CATEGORY(lcOpenAI, "libreai.openai")

static QAtomicInteger<int> s_openaiReqId{0};

OpenAIClient::OpenAIClient(const QString& baseUrl, const QString& apiKey,
                            QObject* parent)
    : AIClient(parent), m_baseUrl(baseUrl), m_apiKey(apiKey)
{
    qCDebug(lcOpenAI) << "OpenAIClient constructed, baseUrl=" << baseUrl;
}

QNetworkRequest OpenAIClient::makeRequest(const QString& path) const {
    qCDebug(lcOpenAI) << "makeRequest, path=" << path;
    QNetworkRequest req(QUrl(m_baseUrl + path));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return req;
}

QStringList OpenAIClient::parseModels(const QByteArray& json) {
    static const QStringList kExclude = {
        "embed", "dall-e", "tts", "whisper", "transcri",
        "search", "similarity", "moderat", "instruct",
        "audio", "realtime", "codex", "image", "computer"
    };
    auto arr = QJsonDocument::fromJson(json).object()["data"].toArray();
    QStringList names;
    for (auto v : arr) {
        QString id = v.toObject()["id"].toString();
        bool skip = false;
        for (const QString& kw : kExclude)
            if (id.contains(kw, Qt::CaseInsensitive)) { skip = true; break; }
        if (!skip) names << id;
    }
    names.sort();
    return names;
}

QString OpenAIClient::parseResponse(const QByteArray& json) {
    return QJsonDocument::fromJson(json)
               .object()["choices"].toArray()
               .first().toObject()["message"]
               .toObject()["content"].toString();
}

void OpenAIClient::fetchModels() {
    qCDebug(lcOpenAI) << "fetchModels, url=" << (m_baseUrl + "/models");
    QNetworkRequest req(QUrl(m_baseUrl + "/models"));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOpenAI) << "fetchModels error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcOpenAI) << "fetchModels response body:" << body;
        QStringList names = parseModels(body);
        qCInfo(lcOpenAI) << "fetchModels ready, count=" << names.size();
        emit modelsReady(names);
    });
}

void OpenAIClient::sendChat(const QString& model,
                             const QVector<Message>& history,
                             const QString& prompt) {
    int reqId = s_openaiReqId.fetchAndAddRelaxed(1);
    qCDebug(lcOpenAI) << "sendChat reqId=" << reqId
                      << "model=" << model
                      << "historySize=" << history.size()
                      << "promptLength=" << prompt.length();

    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{{"model", model}, {"messages", messages}};
    QByteArray bodyBytes = QJsonDocument(body).toJson();
    qCDebug(lcOpenAI) << "sendChat request body:" << bodyBytes;

    auto* reply = m_nam.post(makeRequest("/chat/completions"), bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply, reqId, model] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOpenAI) << "sendChat reqId=" << reqId << "error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcOpenAI) << "sendChat reqId=" << reqId << "response body:" << respBody;
        QString content = parseResponse(respBody);
        qCInfo(lcOpenAI) << "sendChat reqId=" << reqId << "model=" << model
                         << "response length=" << content.length();
        emit responseReady(content);
    });
}
