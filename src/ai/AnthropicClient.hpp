#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

class AnthropicClient : public AIClient {
    Q_OBJECT
public:
    explicit AnthropicClient(const QString& apiKey,
                             const QString& baseUrl = "https://api.anthropic.com/v1",
                             QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;

    static QStringList hardcodedModels();
    static QString     parseResponse(const QByteArray& json);
private:
    QString               m_apiKey;
    QString               m_baseUrl;
    QNetworkAccessManager m_nam;
};
