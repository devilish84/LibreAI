#pragma once
#include "ImageClient.hpp"
#include <QNetworkAccessManager>

class GrokImageClient : public ImageClient {
    Q_OBJECT
public:
    explicit GrokImageClient(const QString& apiKey,
                            const QString& baseUrl = QStringLiteral("https://api.x.ai/v1"),
                            QObject* parent = nullptr);
    void fetchImageModels() override;
    void generateImage(const QString& model,
                       const QString& prompt,
                       const QString& size) override;

private:
    QNetworkRequest makeRequest(const QString& path) const;

    QString               m_apiKey;
    QString               m_baseUrl;
    QNetworkAccessManager m_nam;
};
