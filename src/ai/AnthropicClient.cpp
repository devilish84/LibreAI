#include "AnthropicClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcAnthropic, "libreai.anthropic")

static const QStringList CLAUDE_MODELS = {
    "claude-opus-4-7",
    "claude-sonnet-4-6",
    "claude-haiku-4-5-20251001",
};

AnthropicClient::AnthropicClient(const QString& apiKey, QObject* parent)
    : AIClient(parent), m_apiKey(apiKey)
{
    qCDebug(lcAnthropic) << "AnthropicClient constructed";
}

void AnthropicClient::fetchModels() {
    qCDebug(lcAnthropic) << "fetchModels, returning" << CLAUDE_MODELS.size() << "hardcoded models";
    emit modelsReady(CLAUDE_MODELS);
}

void AnthropicClient::sendChat(const QString& model,
                                const QVector<Message>& history,
                                const QString& prompt) {
    qCDebug(lcAnthropic) << "sendChat, model=" << model
                         << "historySize=" << history.size()
                         << "promptLength=" << prompt.length();

    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QJsonObject body{
        {"model", model},
        {"max_tokens", 4096},
        {"messages", messages}
    };
    QByteArray bodyBytes = QJsonDocument(body).toJson();
    qCDebug(lcAnthropic) << "sendChat request body:" << bodyBytes;

    QNetworkRequest req(QUrl("https://api.anthropic.com/v1/messages"));
    req.setRawHeader("x-api-key", m_apiKey.toUtf8());
    req.setRawHeader("anthropic-version", "2023-06-01");
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcAnthropic) << "sendChat error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcAnthropic) << "sendChat response body:" << respBody;
        auto content = QJsonDocument::fromJson(respBody)
                           .object()["content"].toArray()
                           .first().toObject()["text"].toString();
        qCInfo(lcAnthropic) << "sendChat response received, length=" << content.length();
        emit responseReady(content);
    });
}
