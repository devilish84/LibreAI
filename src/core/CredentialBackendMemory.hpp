#pragma once
#include "CredentialStore.hpp"
#include <QHash>

// Fallback: in-memory only. isAvailable() returns false so callers can warn
// the user. Used in CI environments and any platform without a real keychain.
class CredentialBackendMemory : public ICredentialBackend {
public:
    bool    isAvailable() const override { return false; }
    bool    store(const QString& key, const QString& value) override;
    QString retrieve(const QString& key) override;
    void    remove(const QString& key) override;
    QString backendName() const override { return QStringLiteral("In-Memory (no persistence)"); }

private:
    QHash<QString, QString> m_store;
};
