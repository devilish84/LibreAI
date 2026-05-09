#include "OpenAIImageClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QNetworkReply>

Q_LOGGING_CATEGORY(lcOpenAIImg, "libreai.openai.image")

OpenAIImageClient::OpenAIImageClient(const QString& baseUrl,
                                     const QString& apiKey,
                                     QObject* parent)
    : ImageClient(parent), m_baseUrl(baseUrl), m_apiKey(apiKey)
{
    qCDebug(lcOpenAIImg) << "OpenAIImageClient constructed";
}

QNetworkRequest OpenAIImageClient::makeRequest(const QString& path) const {
    QNetworkRequest req(QUrl(m_baseUrl + path));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return req;
}

void OpenAIImageClient::fetchImageModels() {
    // DALL-E models are not returned by /models with chat filters removed;
    // return hardcoded list immediately.
    qCDebug(lcOpenAIImg) << "fetchImageModels (hardcoded)";
    emit imageModelsReady({"dall-e-3", "dall-e-2"});
}

void OpenAIImageClient::generateImage(const QString& model,
                                      const QString& prompt,
                                      const QString& size) {
    qCDebug(lcOpenAIImg) << "generateImage model=" << model << "size=" << size;

    QJsonObject body{
        {"model",           model},
        {"prompt",          prompt},
        {"n",               1},
        {"size",            size},
        {"response_format", QStringLiteral("b64_json")}
    };
    QByteArray bodyBytes = QJsonDocument(body).toJson();

    auto* reply = m_nam.post(makeRequest("/images/generations"), bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOpenAIImg) << "generateImage error:" << reply->errorString();
            // Try to parse error detail from response body
            QByteArray errBody = reply->readAll();
            QString detail = QJsonDocument::fromJson(errBody)
                .object()["error"].toObject()["message"].toString();
            emit errorOccurred(detail.isEmpty() ? reply->errorString() : detail);
            return;
        }
        QByteArray respBody = reply->readAll();
        QString b64 = QJsonDocument::fromJson(respBody)
            .object()["data"].toArray()
            .first().toObject()["b64_json"].toString();
        if (b64.isEmpty()) {
            emit errorOccurred(tr("No image data in response"));
            return;
        }
        QByteArray png = QByteArray::fromBase64(b64.toUtf8());
        qCInfo(lcOpenAIImg) << "generateImage success, bytes=" << png.size();
        emit imageReady(png);
    });
}
