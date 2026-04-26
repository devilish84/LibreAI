#pragma once
#include "AIClient.hpp"
#include <QNetworkAccessManager>

class OpenAIClient : public AIClient {
    Q_OBJECT
public:
    explicit OpenAIClient(const QString& baseUrl, const QString& apiKey,
                          QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;

    static QStringList parseModels(const QByteArray& json);
    static QString     parseResponse(const QByteArray& json);
private:
    QString               m_baseUrl;
    QString               m_apiKey;
    QNetworkAccessManager m_nam;
    QNetworkRequest       makeRequest(const QString& path) const;
};
