#include "OllamaImageClient.hpp"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QNetworkReply>
#include <QNetworkRequest>

Q_LOGGING_CATEGORY(lcOllamaImg, "libreai.ollama.image")

// Keywords that identify Ollama models capable of image generation
static const QStringList kImageKeywords = {
    "flux", "stable-diffusion", "sdxl", "dall", "wuerstchen",
    "kandinsky", "dreamshaper", "playground", "juggernaut"
};

OllamaImageClient::OllamaImageClient(const QString& baseUrl,
                                     const OllamaAuthConfig& auth,
                                     QObject* parent)
    : ImageClient(parent), m_baseUrl(baseUrl), m_auth(auth)
{
    qCDebug(lcOllamaImg) << "OllamaImageClient constructed, baseUrl=" << baseUrl;
}

void OllamaImageClient::applyAuth(QNetworkRequest& req) const {
    switch (m_auth.type) {
        case OllamaAuth::None: break;
        case OllamaAuth::Basic: {
            QByteArray creds = (m_auth.basicUser + ":" + m_auth.basicPass).toUtf8().toBase64();
            req.setRawHeader("Authorization", "Basic " + creds);
            break;
        }
        case OllamaAuth::ApiKey:
            req.setRawHeader(m_auth.apiKeyHeader.toUtf8(), m_auth.apiKeyValue.toUtf8());
            break;
    }
}

void OllamaImageClient::fetchImageModels() {
    qCDebug(lcOllamaImg) << "fetchImageModels";
    QNetworkRequest req(QUrl(m_baseUrl + "/api/tags"));
    applyAuth(req);
    auto* reply = m_nam.get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOllamaImg) << "fetchImageModels error:" << reply->errorString();
            emit errorOccurred(reply->errorString());
            return;
        }
        QByteArray body = reply->readAll();
        auto arr = QJsonDocument::fromJson(body).object()["models"].toArray();
        QStringList names;
        for (auto v : arr) {
            QString name = v.toObject()["name"].toString();
            for (const QString& kw : kImageKeywords) {
                if (name.contains(kw, Qt::CaseInsensitive)) {
                    names << name;
                    break;
                }
            }
        }
        qCInfo(lcOllamaImg) << "fetchImageModels ready, count=" << names.size();
        emit imageModelsReady(names);
    });
}

void OllamaImageClient::generateImage(const QString& model,
                                      const QString& prompt,
                                      const QString& /*size*/) {
    qCDebug(lcOllamaImg) << "generateImage model=" << model
                         << "promptLength=" << prompt.length();

    QJsonObject body{{"model", model}, {"prompt", prompt}, {"stream", false}};
    QByteArray bodyBytes = QJsonDocument(body).toJson();

    QNetworkRequest req(QUrl(m_baseUrl + "/api/generate"));
    req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    applyAuth(req);

    auto* reply = m_nam.post(req, bodyBytes);
    connect(reply, &QNetworkReply::finished, this, [this, reply] {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(lcOllamaImg) << "generateImage error:" << reply->errorString();
            emit errorOccurred(reply->errorString());
            return;
        }
        QByteArray respBody = reply->readAll();
        qCDebug(lcOllamaImg) << "generateImage response size=" << respBody.size();

        auto obj = QJsonDocument::fromJson(respBody).object();

        // Ollama image models return {"images": ["<base64>"]}
        auto imagesArr = obj["images"].toArray();
        if (!imagesArr.isEmpty()) {
            QByteArray png = QByteArray::fromBase64(
                imagesArr.first().toString().toUtf8());
            if (!png.isEmpty()) {
                qCInfo(lcOllamaImg) << "generateImage success, bytes=" << png.size();
                emit imageReady(png);
                return;
            }
        }
        // Some models embed a single "image" key
        QString singleImg = obj["image"].toString();
        if (!singleImg.isEmpty()) {
            QByteArray png = QByteArray::fromBase64(singleImg.toUtf8());
            if (!png.isEmpty()) {
                emit imageReady(png);
                return;
            }
        }
        emit errorOccurred(tr("No image data in response"));
    });
}
