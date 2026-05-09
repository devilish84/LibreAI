#pragma once
#include "ImageClient.hpp"
#include "OllamaClient.hpp"
#include <QNetworkAccessManager>

class OllamaImageClient : public ImageClient {
    Q_OBJECT
public:
    explicit OllamaImageClient(const QString& baseUrl,
                               const OllamaAuthConfig& auth = {},
                               QObject* parent = nullptr);
    void fetchImageModels() override;
    void generateImage(const QString& model,
                       const QString& prompt,
                       const QString& size) override;

private:
    void applyAuth(QNetworkRequest& req) const;

    QString               m_baseUrl;
    OllamaAuthConfig      m_auth;
    QNetworkAccessManager m_nam;
};
