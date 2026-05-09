#include "GeminiImageClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QNetworkReply>
#include <QNetworkRequest>

Q_LOGGING_CATEGORY(lcGeminiImg, "libreai.gemini.image")

GeminiImageClient::GeminiImageClient(const QString& apiKey, const QString& baseUrl, QObject* parent)
    : ImageClient(parent), m_apiKey(apiKey), m_baseUrl(baseUrl)
{
    qCDebug(lcGeminiImg) << "GeminiImageClient constructed, baseUrl=" << baseUrl;
}

void GeminiImageClient::fetchImageModels() {
    qCDebug(lcGeminiImg) << "fetchImageModels (hardcoded)";
    emit imageModelsReady({
        "imagen-3.0-generate-002",
        "imagen-3.0-fast-generate-001",
        "gemini-2.0-flash-exp-image-generation"
    });
}

void GeminiImageClient::generateImage(const QString& model,
                                      const QString& prompt,
                                      const QString& size) {
    if (model.startsWith("imagen", Qt::CaseInsensitive))
        generateViaPredict(model, prompt, size);
    else
        generateViaContent(model, prompt);
}

void GeminiImageClient::generateViaPredict(const QString& model,
                                           const QString& prompt,
                                           const QString& size) {
    qCDebug(lcGeminiImg) << "generateViaPredict model=" << model;

    // Map WxH size string to Imagen aspect ratio
    QString aspect = "1:1";
    if (size == "1792x1024") aspect = "16:9";
    else if (size == "1024x1792") aspect = "9:16";

    QJsonObject body{
        {"instances", QJsonArray{QJsonObject{{"prompt", prompt}}}},
        {"parameters", QJsonObject{
            {"sampleCount", 1},
            {"aspectRatio", aspect}
        }}
    };
    QByteArray bodyBytes = QJsonDocument(body).toJson();

    QUrl url(m_baseUrl + "/models/" + model + ":predict?key=" + m_apiKey);
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGeminiImg) << "generateViaPredict error:" << reply->errorString();
            emit errorOccurred(reply->errorString());
            return;
        }
        QByteArray respBody = reply->readAll();
        QString b64 = QJsonDocument::fromJson(respBody)
            .object()["predictions"].toArray()
            .first().toObject()["bytesBase64Encoded"].toString();
        if (b64.isEmpty()) {
            QString apiErr = QJsonDocument::fromJson(respBody)
                .object()["error"].toObject()["message"].toString();
            emit errorOccurred(apiErr.isEmpty() ? tr("No image data in response") : apiErr);
            return;
        }
        QByteArray png = QByteArray::fromBase64(b64.toUtf8());
        qCInfo(lcGeminiImg) << "generateViaPredict success, bytes=" << png.size();
        emit imageReady(png);
    });
}

void GeminiImageClient::generateViaContent(const QString& model,
                                           const QString& prompt) {
    qCDebug(lcGeminiImg) << "generateViaContent model=" << model;

    QJsonObject body{
        {"contents", QJsonArray{
            QJsonObject{
                {"role", "user"},
                {"parts", QJsonArray{QJsonObject{{"text", prompt}}}}
            }
        }},
        {"generationConfig", QJsonObject{
            {"responseModalities", QJsonArray{"IMAGE", "TEXT"}}
        }}
    };
    QByteArray bodyBytes = QJsonDocument(body).toJson();

    QUrl url(m_baseUrl + "/models/" + model + ":generateContent?key=" + m_apiKey);
    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcGeminiImg) << "generateViaContent error:" << reply->errorString();
            emit errorOccurred(reply->errorString());
            return;
        }
        QByteArray respBody = reply->readAll();
        auto parts = QJsonDocument::fromJson(respBody)
            .object()["candidates"].toArray()
            .first().toObject()["content"]
            .toObject()["parts"].toArray();

        for (auto v : parts) {
            auto inlineData = v.toObject()["inlineData"].toObject();
            if (!inlineData.isEmpty()) {
                QByteArray png = QByteArray::fromBase64(
                    inlineData["data"].toString().toUtf8());
                if (!png.isEmpty()) {
                    qCInfo(lcGeminiImg) << "generateViaContent success, bytes=" << png.size();
                    emit imageReady(png);
                    return;
                }
            }
        }
        emit errorOccurred(tr("No image data in response"));
    });
}
