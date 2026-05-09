#include "GrokImageClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QNetworkReply>

Q_LOGGING_CATEGORY(lcGrokImg, "libreai.grok.image")

GrokImageClient::GrokImageClient(const QString& apiKey, const QString& baseUrl, QObject* parent)
    : ImageClient(parent), m_apiKey(apiKey), m_baseUrl(baseUrl)
{
    qCDebug(lcGrokImg) << "GrokImageClient constructed, baseUrl=" << baseUrl;
}

QNetworkRequest GrokImageClient::makeRequest(const QString& path) const {
    QNetworkRequest req(QUrl(m_baseUrl + path));
    req.setRawHeader("Authorization", ("Bearer " + m_apiKey).toUtf8());
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    return req;
}

void GrokImageClient::fetchImageModels() {
    // Aurora is the only xAI image model available via the public API.
    qCDebug(lcGrokImg) << "fetchImageModels (hardcoded)";
    emit imageModelsReady({"aurora"});
}

void GrokImageClient::generateImage(const QString& model,
                                    const QString& prompt,
                                    const QString& /*size*/) {
    // Aurora does not accept a size parameter yet; omit it.
    qCDebug(lcGrokImg) << "generateImage model=" << model;

    QJsonObject body{
        {"model",           model},
        {"prompt",          prompt},
        {"n",               1},
        {"response_format", QStringLiteral("b64_json")}
    };
    QByteArray bodyBytes = QJsonDocument(body).toJson();

    auto* reply = m_nam.post(makeRequest("/images/generations"), bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGrokImg) << "generateImage error:" << reply->errorString();
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
        qCInfo(lcGrokImg) << "generateImage success, bytes=" << png.size();
        emit imageReady(png);
    });
}
