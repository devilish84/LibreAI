#pragma once
#ifdef HAVE_DPAPI
#include "CredentialStore.hpp"

// Windows: DPAPI (CryptProtectData) with JSON file storage
class CredentialBackendDPAPI : public ICredentialBackend {
public:
    bool    isAvailable() const override;
    bool    store(const QString& key, const QString& value) override;
    QString retrieve(const QString& key) override;
    void    remove(const QString& key) override;
    QString backendName() const override { return QStringLiteral("Windows DPAPI"); }

private:
    static QString credsPath();
    static QJsonObject readBlob();
    static void        writeBlob(const QJsonObject& obj);
};
#endif
