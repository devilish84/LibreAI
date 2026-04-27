#ifdef HAVE_MACOS_KEYCHAIN
#include "CredentialBackendMacOS.hpp"
#include <Security/Security.h>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcMacKeychain, "libreai.credentials.macos")

static CFDictionaryRef makeBaseQuery(const QString& key)
{
    CFStringRef cfKey = CFStringCreateWithCString(
        nullptr, key.toUtf8().constData(), kCFStringEncodingUTF8);
    const void* ks[] = { kSecClass,                kSecAttrService,    kSecAttrAccount };
    const void* vs[] = { kSecClassGenericPassword,  CFSTR("libreai"),   cfKey          };
    CFDictionaryRef q = CFDictionaryCreate(nullptr, ks, vs, 3,
        &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFRelease(cfKey);
    return q;
}

bool CredentialBackendMacOS::isAvailable() const
{
    return true;
}

bool CredentialBackendMacOS::store(const QString& key, const QString& value)
{
    qCDebug(lcMacKeychain) << "Storing key:" << key;
    remove(key);  // SecItemUpdate is fiddly; delete-then-add is simpler
    if (value.isEmpty()) return true;

    QByteArray utf8 = value.toUtf8();  // value bytes are never logged
    CFDataRef data = CFDataCreate(nullptr,
        reinterpret_cast<const UInt8*>(utf8.constData()), utf8.size());

    CFDictionaryRef base = makeBaseQuery(key);
    CFMutableDictionaryRef item = CFDictionaryCreateMutableCopy(nullptr, 0, base);
    CFDictionarySetValue(item, kSecValueData, data);
    CFRelease(data);
    CFRelease(base);

    OSStatus status = SecItemAdd(item, nullptr);
    CFRelease(item);

    if (status != errSecSuccess)
        qCWarning(lcMacKeychain) << "Store failed for key:" << key
                                 << "| OSStatus:" << status;
    else
        qCDebug(lcMacKeychain) << "Stored key:" << key;
    return status == errSecSuccess;
}

QString CredentialBackendMacOS::retrieve(const QString& key)
{
    qCDebug(lcMacKeychain) << "Retrieving key:" << key;
    CFDictionaryRef base = makeBaseQuery(key);
    CFMutableDictionaryRef q = CFDictionaryCreateMutableCopy(nullptr, 0, base);
    CFRelease(base);
    CFDictionarySetValue(q, kSecReturnData,  kCFBooleanTrue);
    CFDictionarySetValue(q, kSecMatchLimit,  kSecMatchLimitOne);

    CFTypeRef result = nullptr;
    OSStatus status  = SecItemCopyMatching(q, &result);
    CFRelease(q);

    if (status != errSecSuccess || !result) {
        qCDebug(lcMacKeychain) << "No value found for key:" << key
                               << "| OSStatus:" << status;
        return {};
    }
    // result bytes are never logged — they are secret
    CFDataRef data = static_cast<CFDataRef>(result);
    QString val = QString::fromUtf8(
        reinterpret_cast<const char*>(CFDataGetBytePtr(data)),
        static_cast<int>(CFDataGetLength(data)));
    CFRelease(result);
    qCDebug(lcMacKeychain) << "Retrieved key:" << key;
    return val;
}

void CredentialBackendMacOS::remove(const QString& key)
{
    qCDebug(lcMacKeychain) << "Removing key:" << key;
    CFDictionaryRef q = makeBaseQuery(key);
    OSStatus status = SecItemDelete(q);
    CFRelease(q);

    if (status != errSecSuccess && status != errSecItemNotFound)
        qCWarning(lcMacKeychain) << "Remove failed for key:" << key
                                 << "| OSStatus:" << status;
    else
        qCDebug(lcMacKeychain) << "Removed key:" << key;
}
#endif
