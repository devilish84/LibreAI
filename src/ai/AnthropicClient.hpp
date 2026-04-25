#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

class AnthropicClient : public AIClient {
    Q_OBJECT
public:
    explicit AnthropicClient(const QString& apiKey, QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;
private:
    QString               m_apiKey;
    QNetworkAccessManager m_nam;
};
