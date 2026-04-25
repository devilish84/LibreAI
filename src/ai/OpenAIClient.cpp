#include "OpenAIClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcOpenAI, "libreai.openai")

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
        auto arr = QJsonDocument::fromJson(body).object()["data"].toArray();
        static const QStringList kExclude = {
            "embed", "dall-e", "tts", "whisper", "transcri",
            "search", "similarity", "moderat", "instruct",
            "audio", "realtime", "codex", "image", "computer"
        };
        QStringList names;
        for (auto v : arr) {
            QString id = v.toObject()["id"].toString();
            bool skip = false;
            for (const QString& kw : kExclude)
                if (id.contains(kw, Qt::CaseInsensitive)) { skip = true; break; }
            if (!skip) names << id;
        }
        names.sort();
        qCInfo(lcOpenAI) << "fetchModels ready, count=" << names.size();
        emit modelsReady(names);
    });
}

void OpenAIClient::sendChat(const QString& model,
                             const QVector<Message>& history,
                             const QString& prompt) {
    qCDebug(lcOpenAI) << "sendChat, model=" << model
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
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOpenAI) << "sendChat error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcOpenAI) << "sendChat response body:" << respBody;
        auto content = QJsonDocument::fromJson(respBody)
                           .object()["choices"].toArray()
                           .first().toObject()["message"]
                           .toObject()["content"].toString();
        qCInfo(lcOpenAI) << "sendChat response received, length=" << content.length();
        emit responseReady(content);
    });
}
