#include "Logger.hpp"
#include "Config.hpp"

#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QMutex>
#include <QStandardPaths>
#include <QtMessageHandler>

static QFile*  s_logFile   = nullptr;
static int     s_minLevel  = 1;   // mirrors Config::logLevel
static QMutex  s_mutex;

static const char* levelName(QtMsgType type) {
    switch (type) {
        case QtDebugMsg:    return "DEBUG";
        case QtInfoMsg:     return "INFO ";
        case QtWarningMsg:  return "WARN ";
        case QtCriticalMsg: return "ERROR";
        case QtFatalMsg:    return "FATAL";
    }
    return "?    ";
}

static int msgTypeToInt(QtMsgType type) {
    switch (type) {
        case QtDebugMsg:    return 0;
        case QtInfoMsg:     return 1;
        case QtWarningMsg:  return 2;
        case QtCriticalMsg: return 2;
        case QtFatalMsg:    return 2;
    }
    return 0;
}

static void messageHandler(QtMsgType type,
                            const QMessageLogContext& ctx,
                            const QString& msg)
{
    if (msgTypeToInt(type) < s_minLevel) return;

    QMutexLocker lock(&s_mutex);
    if (!s_logFile || !s_logFile->isOpen()) return;

    QString line = QString("[%1] [%2] %3: %4\n")
        .arg(QDateTime::currentDateTime().toString(Qt::ISODate))
        .arg(QLatin1String(levelName(type)))
        .arg(ctx.function ? QLatin1String(ctx.function) : QLatin1String(""))
        .arg(msg);

    s_logFile->write(line.toUtf8());
    s_logFile->flush();
}

void initLogging() {
    QMutexLocker lock(&s_mutex);

    // Always close any existing log first
    if (s_logFile) {
        s_logFile->close();
        delete s_logFile;
        s_logFile = nullptr;
        qInstallMessageHandler(nullptr);
    }

    const Config& cfg = Config::get();
    if (!cfg.loggingEnabled) return;

    // logLevel: 0=Debug → QtDebugMsg, 1=Info → QtInfoMsg, 2=Error → QtCriticalMsg
    s_minLevel = cfg.logLevel;

    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);

    s_logFile = new QFile(dir + "/libreai.log");
    if (!s_logFile->open(QIODevice::Append | QIODevice::Text)) {
        delete s_logFile;
        s_logFile = nullptr;
        return;
    }

    qInstallMessageHandler(messageHandler);
    // Log the startup message outside the lock — messageHandler re-acquires it
    lock.unlock();
    qInfo() << "LibreAI logging started — level" << cfg.logLevel;
}

void closeLogging() {
    QMutexLocker lock(&s_mutex);
    qInstallMessageHandler(nullptr);
    if (s_logFile) {
        s_logFile->close();
        delete s_logFile;
        s_logFile = nullptr;
    }
}
