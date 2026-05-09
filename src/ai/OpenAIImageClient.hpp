#pragma once
#include "ImageClient.hpp"
#include <QNetworkAccessManager>

class OpenAIImageClient : public ImageClient {
    Q_OBJECT
public:
    explicit OpenAIImageClient(const QString& baseUrl,
                               const QString& apiKey,
                               QObject* parent = nullptr);
    void fetchImageModels() override;
    void generateImage(const QString& model,
                       const QString& prompt,
                       const QString& size) override;

private:
    QNetworkRequest makeRequest(const QString& path) const;

    QString               m_baseUrl;
    QString               m_apiKey;
    QNetworkAccessManager m_nam;
};
