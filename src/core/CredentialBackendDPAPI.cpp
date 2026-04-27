#ifdef HAVE_DPAPI
#include "CredentialBackendDPAPI.hpp"
#include <windows.h>
#include <dpapi.h>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLoggingCategory>
#include <QStandardPaths>

Q_LOGGING_CATEGORY(lcDPAPI, "libreai.credentials.dpapi")

QString CredentialBackendDPAPI::credsPath()
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);
    return dir + QStringLiteral("/creds.dat");
}

QJsonObject CredentialBackendDPAPI::readBlob()
{
    QFile f(credsPath());
    if (!f.open(QIODevice::ReadOnly)) {
        qCDebug(lcDPAPI) << "No credential file found at" << credsPath();
        return {};
    }
    QByteArray enc = f.readAll();

    DATA_BLOB in{}, out{};
    in.pbData = reinterpret_cast<BYTE*>(enc.data());
    in.cbData = static_cast<DWORD>(enc.size());
    if (!CryptUnprotectData(&in, nullptr, nullptr, nullptr, nullptr, 0, &out)) {
        qCWarning(lcDPAPI) << "CryptUnprotectData failed — corrupt or wrong user?";
        return {};
    }
    // Decrypted bytes are never logged — they contain secrets
    QByteArray plain(reinterpret_cast<char*>(out.pbData), out.cbData);
    LocalFree(out.pbData);
    return QJsonDocument::fromJson(plain).object();
}

void CredentialBackendDPAPI::writeBlob(const QJsonObject& obj)
{
    // JSON keys (credential names) are logged at debug; values are never logged
    qCDebug(lcDPAPI) << "Writing blob with" << obj.size() << "entries";
    QByteArray plain = QJsonDocument(obj).toJson(QJsonDocument::Compact);

    DATA_BLOB in{}, out{};
    in.pbData = reinterpret_cast<BYTE*>(plain.data());
    in.cbData = static_cast<DWORD>(plain.size());
    if (!CryptProtectData(&in, nullptr, nullptr, nullptr, nullptr, 0, &out)) {
        qCWarning(lcDPAPI) << "CryptProtectData failed";
        return;
    }
    QByteArray enc(reinterpret_cast<char*>(out.pbData), out.cbData);
    LocalFree(out.pbData);

    QFile f(credsPath());
    if (!f.open(QIODevice::WriteOnly))
        qCWarning(lcDPAPI) << "Cannot write credential file:" << credsPath();
    else
        f.write(enc);
}

bool CredentialBackendDPAPI::isAvailable() const
{
    return true;
}

bool CredentialBackendDPAPI::store(const QString& key, const QString& value)
{
    qCDebug(lcDPAPI) << "Storing key:" << key;
    auto obj = readBlob();
    if (value.isEmpty())
        obj.remove(key);
    else
        obj[key] = value;  // value is not logged
    writeBlob(obj);
    qCDebug(lcDPAPI) << "Stored key:" << key;
    return true;
}

QString CredentialBackendDPAPI::retrieve(const QString& key)
{
    qCDebug(lcDPAPI) << "Retrieving key:" << key;
    QString val = readBlob()[key].toString();
    qCDebug(lcDPAPI) << "Retrieved key:" << key << "| found:" << !val.isEmpty();
    return val;  // value is not logged
}

void CredentialBackendDPAPI::remove(const QString& key)
{
    qCDebug(lcDPAPI) << "Removing key:" << key;
    auto obj = readBlob();
    obj.remove(key);
    writeBlob(obj);
    qCDebug(lcDPAPI) << "Removed key:" << key;
}
#endif
