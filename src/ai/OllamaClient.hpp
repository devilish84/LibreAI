#pragma once
#include "AIClient.hpp"
#include "../core/Config.hpp"
#include <QNetworkAccessManager>

struct OllamaAuthConfig {
    OllamaAuth type            = OllamaAuth::None;
    QString    basicUser;
    QString    basicPass;
    QString    apiKeyHeader    = "Authorization";
    QString    apiKeyValue;

    static OllamaAuthConfig fromConfig();
};

class OllamaClient : public AIClient {
    Q_OBJECT
public:
    explicit OllamaClient(const QString& baseUrl,
                          const OllamaAuthConfig& auth = {},
                          QObject* parent = nullptr);
    void fetchModels() override;
    void sendChat(const QString& model, const QVector<Message>& history,
                  const QString& prompt) override;
private:
    void applyAuth(QNetworkRequest& req) const;

    QString              m_baseUrl;
    OllamaAuthConfig     m_auth;
    QNetworkAccessManager m_nam;
};
