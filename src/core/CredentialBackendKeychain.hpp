#pragma once
#ifdef HAVE_KEYCHAIN
#include "CredentialStore.hpp"

// Linux: QtKeychain (Secret Service / KWallet)
class CredentialBackendKeychain : public ICredentialBackend {
public:
    bool    isAvailable() const override;
    bool    store(const QString& key, const QString& value) override;
    QString retrieve(const QString& key) override;
    void    remove(const QString& key) override;
    QString backendName() const override { return QStringLiteral("QtKeychain"); }
};
#endif
