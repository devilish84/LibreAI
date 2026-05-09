#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

// Google Gemini — REST API at https://generativelanguage.googleapis.com/v1beta
class GeminiClient : public AIClient {
    Q_OBJECT
public:
    explicit GeminiClient(const QString& apiKey,
                         const QString& baseUrl = QStringLiteral("https://generativelanguage.googleapis.com/v1beta"),
                         QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;

    static QStringList parseModels(const QByteArray& json);
    static QString     parseResponse(const QByteArray& json);
private:
    QString               m_apiKey;
    QString               m_baseUrl;
    QNetworkAccessManager m_nam;
    QString modelEndpoint(const QString& model) const;
};
