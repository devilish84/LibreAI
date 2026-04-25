#include "AnthropicClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>

static const QStringList CLAUDE_MODELS = {
    "claude-opus-4-7",
    "claude-sonnet-4-6",
    "claude-haiku-4-5-20251001",
};

AnthropicClient::AnthropicClient(const QString& apiKey, QObject* parent)
    : AIClient(parent), m_apiKey(apiKey) {}

void AnthropicClient::fetchModels() {
    emit modelsReady(CLAUDE_MODELS);
}

void AnthropicClient::sendChat(const QString& model,
                                const QVector<Message>& history,
                                const QString& prompt) {
    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{
        {"model", model},
        {"max_tokens", 4096},
        {"messages", messages}
    };

    QNetworkRequest req(QUrl("https://api.anthropic.com/v1/messages"));
    req.setRawHeader("x-api-key", m_apiKey.toUtf8());
    req.setRawHeader("anthropic-version", "2023-06-01");
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, QJsonDocument(body).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString()); return;
        }
        auto content = QJsonDocument::fromJson(reply->readAll())
                           .object()["content"].toArray()
                           .first().toObject()["text"].toString();
        emit responseReady(content);
    });
}
