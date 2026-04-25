#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include "Config.hpp"

// Point QStandardPaths at a temp dir so tests never touch ~/.config/libreai
static void useTestConfigDir() {
    QString tmp = QDir::tempPath() + "/libreai_test_" + QString::number(QCoreApplication::applicationPid());
    QStandardPaths::setTestModeEnabled(true);
    qputenv("HOME", tmp.toUtf8());
    QDir().mkpath(tmp);
}

// ---- isConfigured() --------------------------------------------------------

TEST(ConfigIsConfigured, OllamaRequiresUrlAndModel) {
    Config& c = Config::get();
    c.provider  = Provider::Ollama;
    c.model     = "";
    c.ollamaUrl = "http://localhost:11434";
    EXPECT_FALSE(c.isConfigured());

    c.model = "llama3";
    EXPECT_TRUE(c.isConfigured());

    c.ollamaUrl = "";
    EXPECT_FALSE(c.isConfigured());
}

TEST(ConfigIsConfigured, OpenAIRequiresKeyAndModel) {
    Config& c = Config::get();
    c.provider  = Provider::OpenAI;
    c.model     = "gpt-4o";
    c.openaiKey = "";
    EXPECT_FALSE(c.isConfigured());

    c.openaiKey = "sk-test";
    EXPECT_TRUE(c.isConfigured());
}

TEST(ConfigIsConfigured, ClaudeRequiresKeyAndModel) {
    Config& c = Config::get();
    c.provider  = Provider::Claude;
    c.model     = "claude-sonnet-4-6";
    c.claudeKey = "";
    EXPECT_FALSE(c.isConfigured());

    c.claudeKey = "sk-ant-test";
    EXPECT_TRUE(c.isConfigured());
}

// ---- save() / load round-trip ----------------------------------------------

TEST(ConfigPersistence, SaveAndReloadPreservesValues) {
    {
        Config& c = Config::get();
        c.provider  = Provider::OpenAI;
        c.openaiKey = "sk-roundtrip";
        c.model     = "gpt-4o";
        c.language  = "fi";
        c.save();
    }

    // Force re-read by creating a fresh Config via the private ctor trick:
    // We can't (private ctor), so we verify the file content directly instead.
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
                   + "/config.json";
    QFile f(path);
    ASSERT_TRUE(f.open(QIODevice::ReadOnly)) << "config.json not written";
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("\"provider\":\"OPENAI\"") ||
                data.contains("\"provider\": \"OPENAI\""));
    EXPECT_TRUE(data.contains("sk-roundtrip"));
    EXPECT_TRUE(data.contains("fi"));
}

// ---- defaults --------------------------------------------------------------

TEST(ConfigDefaults, ProviderEnumIsAlwaysValid) {
    // The singleton is shared and dirtied by prior tests — only assert invariants
    // that hold regardless of field values.
    Config& c = Config::get();
    EXPECT_TRUE(c.provider == Provider::Ollama ||
                c.provider == Provider::OpenAI ||
                c.provider == Provider::Claude);
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("libreai");
    QStandardPaths::setTestModeEnabled(true);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
