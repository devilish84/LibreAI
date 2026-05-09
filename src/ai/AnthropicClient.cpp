#include "AnthropicClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QLoggingCategory>
#include <QAtomicInteger>

Q_LOGGING_CATEGORY(lcAnthropic, "libreai.anthropic")

static QAtomicInteger<int> s_anthropicReqId{0};

AnthropicClient::AnthropicClient(const QString& apiKey, const QString& baseUrl, QObject* parent)
    : AIClient(parent), m_apiKey(apiKey), m_baseUrl(baseUrl)
{
    qCDebug(lcAnthropic) << "AnthropicClient constructed";
}

QStringList AnthropicClient::hardcodedModels() {
    return {
        "claude-opus-4-7",
        "claude-sonnet-4-6",
        "claude-haiku-4-5-20251001",
    };
}

QString AnthropicClient::parseResponse(const QByteArray& json) {
    return QJsonDocument::fromJson(json)
               .object()["content"].toArray()
               .first().toObject()["text"].toString();
}

void AnthropicClient::fetchModels() {
    QStringList models = hardcodedModels();
    qCDebug(lcAnthropic) << "fetchModels, returning" << models.size() << "hardcoded models";
    emit modelsReady(models);
}

void AnthropicClient::sendChat(const QString& model,
                                const QVector<Message>& history,
                                const QString& prompt) {
    int reqId = s_anthropicReqId.fetchAndAddRelaxed(1);
    qCDebug(lcAnthropic) << "sendChat reqId=" << reqId
                         << "model=" << model
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

    QUrl url(m_baseUrl + "/messages");
    QNetworkRequest req(url);
    req.setRawHeader("x-api-key", m_apiKey.toUtf8());
    req.setRawHeader("anthropic-version", "2023-06-01");
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply, reqId, model] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcAnthropic) << "sendChat reqId=" << reqId << "error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcAnthropic) << "sendChat reqId=" << reqId << "response body:" << respBody;
        QString content = parseResponse(respBody);
        qCInfo(lcAnthropic) << "sendChat reqId=" << reqId << "model=" << model
                            << "response length=" << content.length();
        emit responseReady(content);
    });
}
