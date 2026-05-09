#include "GrokClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QLoggingCategory>
#include <QAtomicInteger>

Q_LOGGING_CATEGORY(lcGrok, "libreai.grok")

static QAtomicInteger<int> s_grokReqId{0};

GrokClient::GrokClient(const QString& apiKey, const QString& baseUrl, QObject* parent)
    : AIClient(parent), m_apiKey(apiKey), m_baseUrl(baseUrl)
{
    qCDebug(lcGrok) << "GrokClient constructed, baseUrl=" << baseUrl;
}

QNetworkRequest GrokClient::makeRequest(const QString& path) const
{
    QNetworkRequest req(QUrl(m_baseUrl + path));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return req;
}

QStringList GrokClient::parseModels(const QByteArray& json)
{
    static const QStringList kExclude = { "embed", "image", "audio", "vision" };
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

QString GrokClient::parseResponse(const QByteArray& json)
{
    // xAI uses the same OpenAI chat completions response shape
    return QJsonDocument::fromJson(json)
               .object()["choices"].toArray()
               .first().toObject()["message"]
               .toObject()["content"].toString();
}

void GrokClient::fetchModels()
{
    qCDebug(lcGrok) << "fetchModels";
    auto* reply = m_nam.get(makeRequest("/models"));
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGrok) << "fetchModels error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcGrok) << "fetchModels response:" << body;
        QStringList names = parseModels(body);
        qCInfo(lcGrok) << "fetchModels ready, count=" << names.size();
        emit modelsReady(names);
    });
}

void GrokClient::sendChat(const QString& model,
                           const QVector<Message>& history,
                           const QString& prompt)
{
    int reqId = s_grokReqId.fetchAndAddRelaxed(1);
    qCDebug(lcGrok) << "sendChat reqId=" << reqId
                    << "model=" << model
                    << "historySize=" << history.size()
                    << "promptLength=" << prompt.length();

    QJsonArray messages;
    for (auto& m : history)
        messages.append(QJsonObject{{"role", m.role}, {"content", m.content}});
    messages.append(QJsonObject{{"role", "user"}, {"content", prompt}});

    QByteArray bodyBytes = QJsonDocument(
        QJsonObject{{"model", model}, {"messages", messages}}
    ).toJson();

    auto* reply = m_nam.post(makeRequest("/chat/completions"), bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply, reqId, model] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGrok) << "sendChat reqId=" << reqId << "error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcGrok) << "sendChat reqId=" << reqId << "response:" << body;
        QString content = parseResponse(body);
        qCInfo(lcGrok) << "sendChat reqId=" << reqId << "model=" << model
                       << "responseLength=" << content.length();
        emit responseReady(content);
    });
}
