#include "OllamaClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>

OllamaClient::OllamaClient(const QString& baseUrl, QObject* parent)
    : AIClient(parent), m_baseUrl(baseUrl) {}

void OllamaClient::fetchModels() {
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        auto arr = QJsonDocument::fromJson(reply->readAll())
                       .object()["models"].toArray();
        QStringList names;
        for (auto v : arr)
            names << v.toObject()["name"].toString();
        emit modelsReady(names);
    });
}

void OllamaClient::sendChat(const QString& model,
                             const QVector<Message>& history,
                             const QString& prompt) {
    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{{"model", model}, {"messages", messages}, {"stream", false}};

    QNetworkRequest req(QUrl(m_baseUrl + "/api/chat"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    auto* reply = m_nam.post(req, QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        auto content = QJsonDocument::fromJson(reply->readAll())
                           .object()["message"].toObject()["content"].toString();
        emit responseReady(content);
    });
}
