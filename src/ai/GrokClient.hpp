#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

// xAI Grok — OpenAI-compatible API at https://api.x.ai/v1
class GrokClient : public AIClient {
    Q_OBJECT
public:
    explicit GrokClient(const QString& apiKey,
                       const QString& baseUrl = QStringLiteral("https://api.x.ai/v1"),
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
    QNetworkRequest       makeRequest(const QString& path) const;
};
