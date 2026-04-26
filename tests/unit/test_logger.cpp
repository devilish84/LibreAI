#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QLoggingCategory>
#include <QStandardPaths>
#include "Config.hpp"
#include "Logger.hpp"

Q_LOGGING_CATEGORY(lcLogTest, "libreai.logtest")

static QString logPath() {
    return QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
           + "/libreai.log";
}

TEST(Logger, InitCreatesLogFile) {
    QFile::remove(logPath());
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1;
    initLogging();
    EXPECT_TRUE(QFile::exists(logPath()));
    closeLogging();
}

TEST(Logger, CloseLoggingClosesFile) {
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1;
    initLogging();
    closeLogging();
    // After close, writing a message should not crash or append to the file
    qint64 sizeBefore = QFile(logPath()).size();
    qCInfo(lcLogTest) << "this should not be written";
    qint64 sizeAfter = QFile(logPath()).size();
    EXPECT_EQ(sizeBefore, sizeAfter);
}

TEST(Logger, InfoLevelWritesInfoMessages) {
    QFile::remove(logPath());
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1; // Info
    initLogging();
    qCInfo(lcLogTest) << "info-test-marker";
    closeLogging();

    QFile f(logPath());
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("info-test-marker"));
}

TEST(Logger, DebugSuppressedAtInfoLevel) {
    QFile::remove(logPath());
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1; // Info — debug should be filtered
    initLogging();
    qCDebug(lcLogTest) << "debug-suppressed-marker";
    closeLogging();

    QFile f(logPath());
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_FALSE(data.contains("debug-suppressed-marker"));
}

TEST(Logger, DebugLevelWritesDebugMessages) {
    QFile::remove(logPath());
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 0; // Debug
    initLogging();
    qCDebug(lcLogTest) << "debug-visible-marker";
    closeLogging();

    QFile f(logPath());
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("debug-visible-marker"));
}

TEST(Logger, LoggingDisabledStillWritesInfoLevel) {
    QFile::remove(logPath());
    Config& c = Config::get();
    c.loggingEnabled = false;
    initLogging();
    qCInfo(lcLogTest) << "disabled-info-marker";
    closeLogging();

    QFile f(logPath());
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("disabled-info-marker"));
}

TEST(Logger, RotatesWhenFileTooLarge) {
    QString path = logPath();
    QFile::remove(path);
    QFile::remove(path + ".1");
    QFile::remove(path + ".2");

    // Write 1 MB + 1 byte so it exceeds the 1 MB threshold
    {
        QFile f(path);
        ASSERT_TRUE(f.open(QIODevice::WriteOnly));
        f.write(QByteArray(1024 * 1024 + 1, 'X'));
    }
    qint64 originalSize = QFile(path).size();

    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1;
    c.maxLogSizeMb = 1; // 1 MB threshold — file just exceeds it
    initLogging();
    closeLogging();

    // Original file should have been rotated to .1
    EXPECT_TRUE(QFile::exists(path + ".1"));
    EXPECT_EQ(QFile(path + ".1").size(), originalSize);
    // New log file should have been created fresh (much smaller)
    EXPECT_TRUE(QFile::exists(path));
    EXPECT_LT(QFile(path).size(), originalSize);
}

TEST(Logger, NoRotationWhenFileBelowLimit) {
    QString path = logPath();
    QFile::remove(path);
    QFile::remove(path + ".1");

    {
        QFile f(path);
        ASSERT_TRUE(f.open(QIODevice::WriteOnly));
        f.write(QByteArray(10, 'X'));
    }

    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel = 1;
    c.maxLogSizeMb = 100; // 100 MB limit — file is tiny, no rotation
    initLogging();
    closeLogging();

    EXPECT_FALSE(QFile::exists(path + ".1"));
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("libreai");
    QStandardPaths::setTestModeEnabled(true);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
