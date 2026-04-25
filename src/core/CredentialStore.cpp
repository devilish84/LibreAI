#include "CredentialStore.hpp"

// ── Linux: QtKeychain (Secret Service / KWallet) ─────────────────────────────
#if defined(HAVE_KEYCHAIN)
#include <qt6keychain/keychain.h>
#include <QEventLoop>

namespace CredentialStore {

bool isAvailable() {
    static int s_cached = -1;  // -1 = unknown, 0 = no, 1 = yes
    if (s_cached >= 0) return s_cached == 1;
    QKeychain::ReadPasswordJob job("libreai");
    job.setAutoDelete(false);
    job.setKey("libreai/__probe__");
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
    bool ok = job.error() != QKeychain::NoBackendAvailable
           && job.error() != QKeychain::OtherError;
    s_cached = ok ? 1 : 0;
    return ok;
}

bool store(const QString& key, const QString& value) {
    if (value.isEmpty()) { remove(key); return true; }
    QKeychain::WritePasswordJob job("libreai");
    job.setAutoDelete(false);
    job.setKey(key);
    job.setTextData(value);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
    return job.error() == QKeychain::NoError;
}

QString retrieve(const QString& key) {
    QKeychain::ReadPasswordJob job("libreai");
    job.setAutoDelete(false);
    job.setKey(key);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
    return job.error() == QKeychain::NoError ? job.textData() : QString{};
}

void remove(const QString& key) {
    QKeychain::DeletePasswordJob job("libreai");
    job.setAutoDelete(false);
    job.setKey(key);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();
}

} // namespace CredentialStore

// ── Windows: DPAPI (CryptProtectData) ────────────────────────────────────────
#elif defined(HAVE_DPAPI)
#include <windows.h>
#include <dpapi.h>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

static QString credsPath() {
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);
    return dir + "/creds.dat";
}

static QJsonObject readBlob() {
    QFile f(credsPath());
    if (!f.open(QIODevice::ReadOnly)) return {};
    QByteArray enc = f.readAll();

    DATA_BLOB in{}, out{};
    in.pbData = reinterpret_cast<BYTE*>(enc.data());
    in.cbData = static_cast<DWORD>(enc.size());
    if (!CryptUnprotectData(&in, nullptr, nullptr, nullptr, nullptr, 0, &out))
        return {};
    QByteArray plain(reinterpret_cast<char*>(out.pbData), out.cbData);
    LocalFree(out.pbData);
    return QJsonDocument::fromJson(plain).object();
}

static void writeBlob(const QJsonObject& obj) {
    QByteArray plain = QJsonDocument(obj).toJson(QJsonDocument::Compact);
    DATA_BLOB in{}, out{};
    in.pbData = reinterpret_cast<BYTE*>(plain.data());
    in.cbData = static_cast<DWORD>(plain.size());
    if (!CryptProtectData(&in, nullptr, nullptr, nullptr, nullptr, 0, &out)) return;
    QByteArray enc(reinterpret_cast<char*>(out.pbData), out.cbData);
    LocalFree(out.pbData);
    QFile f(credsPath());
    if (f.open(QIODevice::WriteOnly)) f.write(enc);
}

namespace CredentialStore {

bool isAvailable() { return true; }

bool store(const QString& key, const QString& value) {
    auto obj = readBlob();
    if (value.isEmpty()) obj.remove(key);
    else obj[key] = value;
    writeBlob(obj);
    return true;
}

QString retrieve(const QString& key) {
    return readBlob()[key].toString();
}

void remove(const QString& key) {
    auto obj = readBlob();
    obj.remove(key);
    writeBlob(obj);
}

} // namespace CredentialStore

// ── Fallback: in-memory only (CI / no keychain daemon) ───────────────────────
#else
#include <QHash>

namespace CredentialStore {

static QHash<QString, QString> s_store;

bool isAvailable() { return false; }

bool store(const QString& key, const QString& value) {
    if (value.isEmpty()) s_store.remove(key);
    else s_store[key] = value;
    return true;
}

QString retrieve(const QString& key) {
    return s_store.value(key);
}

void remove(const QString& key) {
    s_store.remove(key);
}

} // namespace CredentialStore
#endif
