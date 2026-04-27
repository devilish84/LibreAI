#pragma once
#ifdef HAVE_MACOS_KEYCHAIN
#include "CredentialStore.hpp"

// macOS: Security.framework Keychain Services
class CredentialBackendMacOS : public ICredentialBackend {
public:
    bool    isAvailable() const override;
    bool    store(const QString& key, const QString& value) override;
    QString retrieve(const QString& key) override;
    void    remove(const QString& key) override;
    QString backendName() const override { return QStringLiteral("macOS Keychain"); }
};
#endif
