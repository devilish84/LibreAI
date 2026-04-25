#pragma once
#include <QString>

namespace CredentialStore {
    bool    isAvailable();
    bool    store(const QString& key, const QString& value);
    QString retrieve(const QString& key);
    void    remove(const QString& key);
}
