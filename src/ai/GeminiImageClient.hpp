#pragma once
#include "ImageClient.hpp"
#include <QNetworkAccessManager>

class GeminiImageClient : public ImageClient {
    Q_OBJECT
public:
    explicit GeminiImageClient(const QString& apiKey,
                              const QString& baseUrl = QStringLiteral("https://generativelanguage.googleapis.com/v1beta"),
                              QObject* parent = nullptr);
    void fetchImageModels() override;
    void generateImage(const QString& model,
                       const QString& prompt,
                       const QString& size) override;

private:
    QString m_apiKey;
    QString m_baseUrl;
    QNetworkAccessManager m_nam;

    // Routes to the right endpoint based on model family
    void generateViaPredict(const QString& model,
                            const QString& prompt,
                            const QString& size);
    void generateViaContent(const QString& model,
                            const QString& prompt);
};
