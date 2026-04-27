#include "CredentialStore.hpp"
#include "CredentialBackendMemory.hpp"
#include <QLoggingCategory>
#include <memory>

#if defined(HAVE_KEYCHAIN)
#  include "CredentialBackendKeychain.hpp"
#elif defined(HAVE_MACOS_KEYCHAIN)
#  include "CredentialBackendMacOS.hpp"
#elif defined(HAVE_DPAPI)
#  include "CredentialBackendDPAPI.hpp"
#endif

Q_LOGGING_CATEGORY(lcCredStore, "libreai.credentials")

namespace CredentialStore {

ICredentialBackend& backend()
{
    static std::unique_ptr<ICredentialBackend> s_backend = []()
        -> std::unique_ptr<ICredentialBackend>
    {
#if defined(HAVE_KEYCHAIN)
        auto b = std::make_unique<CredentialBackendKeychain>();
#elif defined(HAVE_MACOS_KEYCHAIN)
        auto b = std::make_unique<CredentialBackendMacOS>();
#elif defined(HAVE_DPAPI)
        auto b = std::make_unique<CredentialBackendDPAPI>();
#else
        auto b = std::make_unique<CredentialBackendMemory>();
#endif
        qCInfo(lcCredStore) << "Credential backend:" << b->backendName()
                            << "| available:" << b->isAvailable();
        return b;
    }();
    return *s_backend;
}

bool isAvailable()
{
    return backend().isAvailable();
}

bool store(const QString& key, const QString& value)
{
    return backend().store(key, value);
}

QString retrieve(const QString& key)
{
    return backend().retrieve(key);
}

void remove(const QString& key)
{
    backend().remove(key);
}

} // namespace CredentialStore
