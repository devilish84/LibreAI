#include "Logger.hpp"
#include "Config.hpp"

#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QLoggingCategory>
#include <QMutex>
#include <QStandardPaths>
#include <QtMessageHandler>

Q_LOGGING_CATEGORY(lcLogger, "libreai.logger")

static QFile*  s_logFile  = nullptr;
static int     s_minLevel = 1;   // 0=Debug 1=Info 2=Error
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

    // At debug level, suppress Qt-internal categories to reduce noise
    if (type == QtDebugMsg && ctx.category
            && qstrncmp(ctx.category, "libreai", 7) != 0) return;

    QMutexLocker lock(&s_mutex);
    if (!s_logFile || !s_logFile->isOpen()) return;

    // Show the part after "libreai." for brevity
    QString cat;
    if (ctx.category && qstrncmp(ctx.category, "libreai.", 8) == 0)
        cat = QLatin1String(ctx.category + 8);
    else if (ctx.category)
        cat = QLatin1String(ctx.category);

    QString line = QString("[%1] [%2] [%3] %4\n")
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz"))
        .arg(QLatin1String(levelName(type)))
        .arg(cat)
        .arg(msg);

    s_logFile->write(line.toUtf8());
    s_logFile->flush();
}

void initLogging() {
    QMutexLocker lock(&s_mutex);

    // Always close previous handler first
    if (s_logFile) {
        s_logFile->close();
        delete s_logFile;
        s_logFile = nullptr;
        qInstallMessageHandler(nullptr);
    }

    const Config& cfg = Config::get();

    // Log file is ALWAYS written.
    // loggingEnabled=false  → Info level (warnings + events, no debug detail)
    // loggingEnabled=true   → honour logLevel: 0=Debug, 1=Info, 2=Error
    s_minLevel = cfg.loggingEnabled ? cfg.logLevel : 1;

    // Enable libreai.* categories according to the effective level
    QString rules;
    if (s_minLevel == 0)
        rules = "libreai.*=true";
    else if (s_minLevel == 1)
        rules = "libreai.*=true\nlibreai.*.debug=false";
    else
        rules = "libreai.*=false\nlibreai.*.warning=true\nlibreai.*.critical=true";
    QLoggingCategory::setFilterRules(rules);

    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir().mkpath(dir);
    QString path = dir + "/libreai.log";

    s_logFile = new QFile(path);
    if (!s_logFile->open(QIODevice::Append | QIODevice::Text)) {
        delete s_logFile;
        s_logFile = nullptr;
        return;
    }

    qInstallMessageHandler(messageHandler);
    lock.unlock();
    qInfo(lcLogger) << "LibreAI logging started — level" << s_minLevel
                    << "(loggingEnabled=" << cfg.loggingEnabled << ")"
                    << "— file:" << path;
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
