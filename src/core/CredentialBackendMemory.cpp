#include "CredentialBackendMemory.hpp"
#include <QHash>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcMemory, "libreai.credentials.memory")

bool CredentialBackendMemory::store(const QString& key, const QString& value)
{
    qCDebug(lcMemory) << "Storing key:" << key << "(in-memory, not persisted)";
    if (value.isEmpty())
        m_store.remove(key);
    else
        m_store[key] = value;  // value is not logged
    return true;
}

QString CredentialBackendMemory::retrieve(const QString& key)
{
    qCDebug(lcMemory) << "Retrieving key:" << key;
    return m_store.value(key);  // value is not logged
}

void CredentialBackendMemory::remove(const QString& key)
{
    qCDebug(lcMemory) << "Removing key:" << key;
    m_store.remove(key);
}
