#include "OpenAIClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>

OpenAIClient::OpenAIClient(const QString& baseUrl, const QString& apiKey,
                            QObject* parent)
    : AIClient(parent), m_baseUrl(baseUrl), m_apiKey(apiKey) {}

QNetworkRequest OpenAIClient::makeRequest(const QString& path) const {
    QNetworkRequest req(QUrl(m_baseUrl + path));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return req;
}

void OpenAIClient::fetchModels() {
    QNetworkRequest req(QUrl(m_baseUrl + "/models"));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        auto arr = QJsonDocument::fromJson(reply->readAll())
                       .object()["data"].toArray();
        QStringList names;
        for (auto v : arr)
            names << v.toObject()["id"].toString();
        names.sort();
        emit modelsReady(names);
    });
}

void OpenAIClient::sendChat(const QString& model,
                             const QVector<Message>& history,
                             const QString& prompt) {
    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{{"model", model}, {"messages", messages}};

    auto* reply = m_nam.post(makeRequest("/chat/completions"),
                             QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        auto content = QJsonDocument::fromJson(reply->readAll())
                           .object()["choices"].toArray()
                           .first().toObject()["message"]
                           .toObject()["content"].toString();
        emit responseReady(content);
    });
}
