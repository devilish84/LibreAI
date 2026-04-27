#pragma once
#include <QString>
#include <memory>

// Abstract credential backend — one concrete implementation per platform.
class ICredentialBackend {
public:
    virtual ~ICredentialBackend() = default;

    // Returns false if the underlying OS keychain is unavailable.
    virtual bool isAvailable() const = 0;

    // Stores value under key. Passing an empty value removes the entry.
    virtual bool store(const QString& key, const QString& value) = 0;

    // Returns the stored value, or an empty string if not found.
    virtual QString retrieve(const QString& key) = 0;

    // Deletes the entry for key (no-op if absent).
    virtual void remove(const QString& key) = 0;

    // Human-readable name for logging.
    virtual QString backendName() const = 0;
};

// Free-function façade — delegates to the platform backend singleton.
namespace CredentialStore {
    ICredentialBackend& backend();
    bool    isAvailable();
    bool    store(const QString& key, const QString& value);
    QString retrieve(const QString& key);
    void    remove(const QString& key);
}
