#include <gtest/gtest.h>
#include <QCoreApplication>
#include "OllamaClient.hpp"
#include "OpenAIClient.hpp"
#include "AnthropicClient.hpp"

// ---- OllamaClient::parseModels ---------------------------------------------

TEST(OllamaParseModels, ParsesNamesFromModelsArray) {
    QByteArray json = R"({"models":[
        {"name":"llama3"},
        {"name":"mistral"},
        {"name":"phi3"}
    ]})";
    QStringList result = OllamaClient::parseModels(json);
    EXPECT_EQ(result.size(), 3);
    EXPECT_TRUE(result.contains("llama3"));
    EXPECT_TRUE(result.contains("mistral"));
    EXPECT_TRUE(result.contains("phi3"));
}

TEST(OllamaParseModels, ExcludesCodeModels) {
    QByteArray json = R"({"models":[
        {"name":"llama3"},
        {"name":"codellama"},
        {"name":"deepseek-coder"},
        {"name":"codegemma"}
    ]})";
    QStringList result = OllamaClient::parseModels(json);
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("llama3"));
}

TEST(OllamaParseModels, ExcludesMultimodalModels) {
    QByteArray json = R"({"models":[
        {"name":"mistral"},
        {"name":"llava"},
        {"name":"whisper-large"},
        {"name":"stable-diffusion-xl"}
    ]})";
    QStringList result = OllamaClient::parseModels(json);
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("mistral"));
}

TEST(OllamaParseModels, ExclusionIsCaseInsensitive) {
    QByteArray json = R"({"models":[
        {"name":"CodeLLaMA"},
        {"name":"mistral"}
    ]})";
    QStringList result = OllamaClient::parseModels(json);
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("mistral"));
}

TEST(OllamaParseModels, EmptyModelsArray) {
    QByteArray json = R"({"models":[]})";
    EXPECT_TRUE(OllamaClient::parseModels(json).isEmpty());
}

TEST(OllamaParseModels, MalformedJsonReturnsEmpty) {
    EXPECT_TRUE(OllamaClient::parseModels("not json").isEmpty());
}

// ---- OllamaClient::parseResponse -------------------------------------------

TEST(OllamaParseResponse, ExtractsMessageContent) {
    QByteArray json = R"({"message":{"role":"assistant","content":"Hello, world!"}})";
    EXPECT_EQ(OllamaClient::parseResponse(json), "Hello, world!");
}

TEST(OllamaParseResponse, MissingContentReturnsEmpty) {
    EXPECT_TRUE(OllamaClient::parseResponse("{}").isEmpty());
}

// ---- OpenAIClient::parseModels ---------------------------------------------

TEST(OpenAIParseModels, ParsesIdsFromDataArray) {
    QByteArray json = R"({"data":[
        {"id":"gpt-4o"},
        {"id":"gpt-4o-mini"},
        {"id":"gpt-3.5-turbo"}
    ]})";
    QStringList result = OpenAIClient::parseModels(json);
    EXPECT_EQ(result.size(), 3);
    EXPECT_TRUE(result.contains("gpt-4o"));
}

TEST(OpenAIParseModels, ExcludesNonChatModels) {
    QByteArray json = R"({"data":[
        {"id":"gpt-4o"},
        {"id":"text-embedding-ada-002"},
        {"id":"dall-e-3"},
        {"id":"tts-1"},
        {"id":"whisper-1"}
    ]})";
    QStringList result = OpenAIClient::parseModels(json);
    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(result.contains("gpt-4o"));
}

TEST(OpenAIParseModels, ResultIsSorted) {
    QByteArray json = R"({"data":[
        {"id":"gpt-4o-mini"},
        {"id":"gpt-3.5-turbo"},
        {"id":"gpt-4o"}
    ]})";
    QStringList result = OpenAIClient::parseModels(json);
    ASSERT_EQ(result.size(), 3);
    EXPECT_LT(result[0], result[1]);
    EXPECT_LT(result[1], result[2]);
}

TEST(OpenAIParseModels, EmptyDataArray) {
    QByteArray json = R"({"data":[]})";
    EXPECT_TRUE(OpenAIClient::parseModels(json).isEmpty());
}

TEST(OpenAIParseModels, MalformedJsonReturnsEmpty) {
    EXPECT_TRUE(OpenAIClient::parseModels("bad").isEmpty());
}

// ---- OpenAIClient::parseResponse -------------------------------------------

TEST(OpenAIParseResponse, ExtractsFirstChoiceContent) {
    QByteArray json = R"({
        "choices":[
            {"message":{"role":"assistant","content":"Hello from OpenAI"}}
        ]
    })";
    EXPECT_EQ(OpenAIClient::parseResponse(json), "Hello from OpenAI");
}

TEST(OpenAIParseResponse, MissingChoicesReturnsEmpty) {
    EXPECT_TRUE(OpenAIClient::parseResponse(R"({"choices":[]})").isEmpty());
}

// ---- AnthropicClient::hardcodedModels --------------------------------------

TEST(AnthropicHardcodedModels, ContainsExpectedModels) {
    QStringList models = AnthropicClient::hardcodedModels();
    EXPECT_FALSE(models.isEmpty());
    EXPECT_TRUE(models.contains("claude-sonnet-4-6"));
    EXPECT_TRUE(models.contains("claude-opus-4-7"));
    EXPECT_TRUE(models.contains("claude-haiku-4-5-20251001"));
}

// ---- AnthropicClient::parseResponse ----------------------------------------

TEST(AnthropicParseResponse, ExtractsTextFromContentArray) {
    QByteArray json = R"({
        "content":[
            {"type":"text","text":"Hello from Claude"}
        ]
    })";
    EXPECT_EQ(AnthropicClient::parseResponse(json), "Hello from Claude");
}

TEST(AnthropicParseResponse, EmptyContentReturnsEmpty) {
    EXPECT_TRUE(AnthropicClient::parseResponse(R"({"content":[]})").isEmpty());
}

TEST(AnthropicParseResponse, MalformedJsonReturnsEmpty) {
    EXPECT_TRUE(AnthropicClient::parseResponse("not json").isEmpty());
}

int main(int argc, char** argv) {
    QCoreApplication app(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
