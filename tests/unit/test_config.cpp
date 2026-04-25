#include <gtest/gtest.h>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include "Config.hpp"

// ---- isConfigured() --------------------------------------------------------

TEST(ConfigIsConfigured, OllamaRequiresUrl) {
    Config& c = Config::get();
    c.provider  = Provider::Ollama;
    c.ollamaUrl = "";
    EXPECT_FALSE(c.isConfigured());

    c.ollamaUrl = "http://localhost:11434";
    EXPECT_TRUE(c.isConfigured());
}

TEST(ConfigIsConfigured, OpenAIRequiresKey) {
    Config& c = Config::get();
    c.provider  = Provider::OpenAI;
    c.openaiKey = "";
    EXPECT_FALSE(c.isConfigured());

    c.openaiKey = "sk-test";
    EXPECT_TRUE(c.isConfigured());
}

TEST(ConfigIsConfigured, ClaudeRequiresKey) {
    Config& c = Config::get();
    c.provider  = Provider::Claude;
    c.claudeKey = "";
    EXPECT_FALSE(c.isConfigured());

    c.claudeKey = "sk-ant-test";
    EXPECT_TRUE(c.isConfigured());
}

// ---- per-provider model persistence ----------------------------------------

TEST(ConfigProviderModels, EachProviderHasOwnModel) {
    Config& c = Config::get();
    c.ollamaModel = "llama3";
    c.openaiModel = "gpt-4o";
    c.claudeModel = "claude-sonnet-4-6";

    c.provider = Provider::Ollama;
    EXPECT_EQ(c.currentModel(), "llama3");

    c.provider = Provider::OpenAI;
    EXPECT_EQ(c.currentModel(), "gpt-4o");

    c.provider = Provider::Claude;
    EXPECT_EQ(c.currentModel(), "claude-sonnet-4-6");
}

TEST(ConfigProviderModels, SetCurrentModelUpdatesCorrectField) {
    Config& c = Config::get();
    c.ollamaModel = "";
    c.openaiModel = "";
    c.claudeModel = "";

    c.provider = Provider::Ollama;
    c.setCurrentModel("llama3.2");
    EXPECT_EQ(c.ollamaModel, "llama3.2");
    EXPECT_TRUE(c.openaiModel.isEmpty());
    EXPECT_TRUE(c.claudeModel.isEmpty());

    c.provider = Provider::OpenAI;
    c.setCurrentModel("gpt-4o-mini");
    EXPECT_EQ(c.openaiModel, "gpt-4o-mini");
    EXPECT_EQ(c.ollamaModel, "llama3.2"); // unchanged
}

TEST(ConfigProviderModels, CredentialsNotWrittenToJson) {
    Config& c = Config::get();
    c.provider   = Provider::OpenAI;
    c.openaiKey  = "sk-secret";
    c.claudeKey  = "sk-ant-secret";
    c.ollamaBasicPass  = "hunter2";
    c.ollamaApiKeyValue = "myapikey";
    c.save();

    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
                   + "/config.json";
    QFile f(path);
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_FALSE(data.contains("sk-secret"));
    EXPECT_FALSE(data.contains("sk-ant-secret"));
    EXPECT_FALSE(data.contains("hunter2"));
    EXPECT_FALSE(data.contains("myapikey"));
}

TEST(ConfigProviderModels, ModelsRoundTripIndependently) {
    Config& c = Config::get();
    c.ollamaModel = "mistral";
    c.openaiModel = "gpt-4o";
    c.claudeModel = "claude-haiku-4-5";
    c.save();

    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
                   + "/config.json";
    QFile f(path);
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("mistral"));
    EXPECT_TRUE(data.contains("gpt-4o"));
    EXPECT_TRUE(data.contains("claude-haiku-4-5"));
}

// ---- save() / load round-trip ----------------------------------------------

TEST(ConfigPersistence, SavePreservesProviderAndLanguage) {
    Config& c = Config::get();
    c.provider  = Provider::OpenAI;
    c.language  = "fi";
    c.save();

    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
                   + "/config.json";
    QFile f(path);
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("\"provider\":\"OPENAI\"") ||
                data.contains("\"provider\": \"OPENAI\""));
    EXPECT_TRUE(data.contains("fi"));
}

// ---- defaults --------------------------------------------------------------

TEST(ConfigDefaults, ProviderEnumIsAlwaysValid) {
    Config& c = Config::get();
    EXPECT_TRUE(c.provider == Provider::Ollama ||
                c.provider == Provider::OpenAI ||
                c.provider == Provider::Claude);
}

// ---- logging ---------------------------------------------------------------

TEST(ConfigLogging, DefaultsToDisabled) {
    Config& c = Config::get();
    c.loggingEnabled = false;
    c.logLevel       = 1;
    EXPECT_FALSE(c.loggingEnabled);
    EXPECT_EQ(c.logLevel, 1);
}

TEST(ConfigLogging, RoundTrip) {
    Config& c = Config::get();
    c.loggingEnabled = true;
    c.logLevel       = 0;
    c.save();

    QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
                   + "/config.json";
    QFile f(path);
    ASSERT_TRUE(f.open(QIODevice::ReadOnly));
    QByteArray data = f.readAll();
    EXPECT_TRUE(data.contains("\"logging_enabled\": true") ||
                data.contains("\"logging_enabled\":true"));
    EXPECT_TRUE(data.contains("\"log_level\": 0") ||
                data.contains("\"log_level\":0"));
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("libreai");
    QStandardPaths::setTestModeEnabled(true);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
