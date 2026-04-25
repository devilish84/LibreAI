#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

class OllamaClient : public AIClient {
    Q_OBJECT
public:
    explicit OllamaClient(const QString& baseUrl, QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;
private:
    QString              m_baseUrl;
    QNetworkAccessManager m_nam;
};
