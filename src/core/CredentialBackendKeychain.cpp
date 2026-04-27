#ifdef HAVE_KEYCHAIN
#include "CredentialBackendKeychain.hpp"
#include <qt6keychain/keychain.h>
#include <QEventLoop>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcKeychain, "libreai.credentials.keychain")

bool CredentialBackendKeychain::isAvailable() const
{
    static int s_cached = -1;
    if (s_cached >= 0) return s_cached == 1;

    qCDebug(lcKeychain) << "Probing QtKeychain availability";
    QKeychain::ReadPasswordJob job(QStringLiteral("libreai"));
    job.setAutoDelete(false);
    job.setKey(QStringLiteral("libreai/__probe__"));
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();

    bool ok = job.error() != QKeychain::NoBackendAvailable
           && job.error() != QKeychain::OtherError;
    s_cached = ok ? 1 : 0;
    qCInfo(lcKeychain) << "Backend available:" << ok
                       << "| error code:" << job.error();
    return ok;
}

bool CredentialBackendKeychain::store(const QString& key, const QString& value)
{
    if (value.isEmpty()) {
        remove(key);
        return true;
    }
    qCDebug(lcKeychain) << "Storing key:" << key;
    QKeychain::WritePasswordJob job(QStringLiteral("libreai"));
    job.setAutoDelete(false);
    job.setKey(key);
    job.setTextData(value);  // value is never logged
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();

    bool ok = job.error() == QKeychain::NoError;
    if (!ok)
        qCWarning(lcKeychain) << "Store failed for key:" << key
                              << "| error:" << job.errorString();
    else
        qCDebug(lcKeychain) << "Stored key:" << key;
    return ok;
}

QString CredentialBackendKeychain::retrieve(const QString& key)
{
    qCDebug(lcKeychain) << "Retrieving key:" << key;
    QKeychain::ReadPasswordJob job(QStringLiteral("libreai"));
    job.setAutoDelete(false);
    job.setKey(key);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();

    bool ok = job.error() == QKeychain::NoError;
    if (!ok)
        qCDebug(lcKeychain) << "Retrieve returned no value for key:" << key
                            << "| error:" << job.errorString();
    else
        qCDebug(lcKeychain) << "Retrieved key:" << key;
    // textData() is not logged — it contains a secret
    return ok ? job.textData() : QString{};
}

void CredentialBackendKeychain::remove(const QString& key)
{
    qCDebug(lcKeychain) << "Removing key:" << key;
    QKeychain::DeletePasswordJob job(QStringLiteral("libreai"));
    job.setAutoDelete(false);
    job.setKey(key);
    QEventLoop loop;
    QObject::connect(&job, &QKeychain::Job::finished, &loop, &QEventLoop::quit);
    job.start();
    loop.exec();

    if (job.error() != QKeychain::NoError && job.error() != QKeychain::EntryNotFound)
        qCWarning(lcKeychain) << "Remove failed for key:" << key
                              << "| error:" << job.errorString();
    else
        qCDebug(lcKeychain) << "Removed key:" << key;
}
#endif
