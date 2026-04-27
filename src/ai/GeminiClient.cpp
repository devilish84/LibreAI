#include "GeminiClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QLoggingCategory>
#include <QAtomicInteger>

Q_LOGGING_CATEGORY(lcGemini, "libreai.gemini")

static const QString kBaseUrl = QStringLiteral("https://generativelanguage.googleapis.com/v1beta");
static QAtomicInteger<int> s_geminiReqId{0};

GeminiClient::GeminiClient(const QString& apiKey, QObject* parent)
    : AIClient(parent), m_apiKey(apiKey)
{
    qCDebug(lcGemini) << "GeminiClient constructed";
}

QString GeminiClient::modelEndpoint(const QString& model) const
{
    // e.g. kBaseUrl + "/models/gemini-1.5-pro:generateContent?key=..."
    return kBaseUrl + "/models/" + model + ":generateContent?key=" + m_apiKey;
}

QStringList GeminiClient::parseModels(const QByteArray& json)
{
    // GET /v1beta/models returns { "models": [ { "name": "models/gemini-1.5-pro", ... } ] }
    static const QStringList kExclude = {
        "embedding", "aqa", "attribution", "retrieval", "vision"
    };
    auto arr = QJsonDocument::fromJson(json).object()["models"].toArray();
    QStringList names;
    for (auto v : arr) {
        QString name = v.toObject()["name"].toString(); // "models/gemini-1.5-pro"
        QString id   = name.section('/', -1);           // "gemini-1.5-pro"
        bool skip = false;
        for (const QString& kw : kExclude)
            if (id.contains(kw, Qt::CaseInsensitive)) { skip = true; break; }
        if (!skip && !id.isEmpty()) names << id;
    }
    names.sort();
    return names;
}

QString GeminiClient::parseResponse(const QByteArray& json)
{
    // { "candidates": [ { "content": { "parts": [ { "text": "..." } ] } } ] }
    return QJsonDocument::fromJson(json)
               .object()["candidates"].toArray()
               .first().toObject()["content"]
               .toObject()["parts"].toArray()
               .first().toObject()["text"].toString();
}

void GeminiClient::fetchModels()
{
    QUrl url(kBaseUrl + "/models?key=" + m_apiKey);
    qCDebug(lcGemini) << "fetchModels";
    QNetworkRequest req(url);
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGemini) << "fetchModels error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcGemini) << "fetchModels response:" << body;
        QStringList names = parseModels(body);
        qCInfo(lcGemini) << "fetchModels ready, count=" << names.size();
        emit modelsReady(names);
    });
}

void GeminiClient::sendChat(const QString& model,
                              const QVector<Message>& history,
                              const QString& prompt)
{
    int reqId = s_geminiReqId.fetchAndAddRelaxed(1);
    qCDebug(lcGemini) << "sendChat reqId=" << reqId
                      << "model=" << model
                      << "historySize=" << history.size()
                      << "promptLength=" << prompt.length();

    // Gemini uses "contents" with "role" (user/model) and "parts":[{"text":"..."}]
    // Anthropic-style: map "assistant" -> "model" for Gemini's role field.
    QJsonArray contents;
    for (auto& m : history) {
        QString role = (m.role == "assistant") ? "model" : "user";
        contents.append(QJsonObject{
            {"role", role},
            {"parts", QJsonArray{QJsonObject{{"text", m.content}}}}
        });
    }
    contents.append(QJsonObject{
        {"role", "user"},
        {"parts", QJsonArray{QJsonObject{{"text", prompt}}}}
    });

    QByteArray bodyBytes = QJsonDocument(QJsonObject{{"contents", contents}}).toJson();

    QNetworkRequest req(QUrl(modelEndpoint(model)));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply, reqId, model] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGemini) << "sendChat reqId=" << reqId << "error:" << reply->errorString();
            emit errorOccurred(reply->errorString()); return;
        }
        QByteArray body = reply->readAll();
        qCDebug(lcGemini) << "sendChat reqId=" << reqId << "response:" << body;
        QString content = parseResponse(body);
        qCInfo(lcGemini) << "sendChat reqId=" << reqId << "model=" << model
                         << "responseLength=" << content.length();
        emit responseReady(content);
    });
}
