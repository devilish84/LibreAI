#include "BatchProcessor.hpp"
#include "Config.hpp"
#include "../ai/AIClient.hpp"
#include "../ai/AnthropicClient.hpp"
#include "../ai/GeminiClient.hpp"
#include "../ai/GrokClient.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../uno/DocumentParser.hpp"
#include "../uno/UnoHelper.hpp"

#include <QDebug>
#include <QTextDocument>

#include <com/sun/star/document/XUndoManager.hpp>
#include <com/sun/star/document/XUndoManagerSupplier.hpp>
#include <com/sun/star/frame/XController.hpp>
#include <com/sun/star/frame/XModel.hpp>

namespace css = ::com::sun::star;
using namespace css::uno;

BatchProcessor::BatchProcessor(QObject* parent)
    : QObject(parent)
{
    m_delayTimer.setSingleShot(true);
    connect(&m_delayTimer,   &QTimer::timeout, this, &BatchProcessor::processNext);

    m_timeoutTimer.setSingleShot(true);
    connect(&m_timeoutTimer, &QTimer::timeout, this, &BatchProcessor::onTimeout);
}

BatchProcessor::~BatchProcessor() {
    delete m_client;
}

// ── Public API ────────────────────────────────────────────────────────────────

void BatchProcessor::start(const QString& instruction,
                           QList<BatchSection> sections,
                           const Config& cfg,
                           bool reviewMode) {
    m_instruction = instruction;
    m_sections    = std::move(sections);
    m_cfg         = cfg;
    m_current     = 0;
    m_successes   = 0;
    m_errors      = 0;
    m_running     = true;
    m_cancelled   = false;
    m_reviewMode  = reviewMode;
    m_elapsed.start();

    // Open undo context so one Ctrl+Z undoes the whole batch
    try {
        auto frame = UnoHelper::getCurrentFrame();
        if (frame.is()) {
            auto xModel = Reference<css::frame::XModel>(
                frame->getController()->getModel(), UNO_QUERY);
            if (xModel.is()) {
                auto xUndoSupplier = Reference<css::document::XUndoManagerSupplier>(
                    xModel, UNO_QUERY);
                if (xUndoSupplier.is()) {
                    auto xUndo = xUndoSupplier->getUndoManager();
                    if (xUndo.is())
                        xUndo->enterUndoContext(
                            rtl::OUString::createFromAscii("Batch Rewrite"));
                }
            }
        }
    } catch (...) {}

    // Start first section immediately
    m_delayTimer.start(0);
}

void BatchProcessor::cancel() {
    if (!m_running) return;
    m_cancelled = true;
    m_running   = false;
    m_delayTimer.stop();
    m_timeoutTimer.stop();
    delete m_client;
    m_client = nullptr;
    closeUndoContext();
    emit batchCancelled();
}

// ── Private ───────────────────────────────────────────────────────────────────

void BatchProcessor::processNext() {
    if (m_cancelled || !m_running) return;

    if (m_current >= m_sections.size()) {
        // All done
        m_running = false;
        closeUndoContext();
        emit batchCompleted(m_successes, m_errors);
        return;
    }

    auto& s = m_sections[m_current];

    QString prompt =
        "Process the following text according to the instruction below.\n"
        "Return ONLY the rewritten text with no preamble or explanation.\n\n"
        "Instruction: " + m_instruction + "\n\n"
        "Text:\n\n" + s.originalText;

    delete m_client;
    m_client = buildClient();
    if (!m_client) {
        finishSection(false, "Failed to build AI client");
        return;
    }

    connect(m_client, &AIClient::responseReady, this, &BatchProcessor::onResponseReady,
            Qt::SingleShotConnection);
    connect(m_client, &AIClient::errorOccurred,  this, &BatchProcessor::onAiError,
            Qt::SingleShotConnection);

    m_timeoutTimer.start(m_cfg.timeoutSec * 1000);
    m_client->sendChat(::Config::get().currentModel(), {}, prompt);
}

void BatchProcessor::onResponseReady(const QString& response) {
    m_timeoutTimer.stop();
    if (m_cancelled) return;

    auto& s = m_sections[m_current];
    s.rewrittenText = response;

    if (m_reviewMode) {
        m_pendingResponse = response;
        emit awaitingReview(m_current, m_sections.size(), s.title, response);
    } else {
        applySection(m_current);
        finishSection(true);
    }
}

void BatchProcessor::onAiError(const QString& error) {
    m_timeoutTimer.stop();
    if (m_cancelled) return;

    emit errorOccurred(tr("Section \"%1\" failed: %2")
        .arg(m_sections[m_current].title, error));
    finishSection(false, error);
}

void BatchProcessor::onTimeout() {
    if (m_cancelled) return;
    delete m_client;
    m_client = nullptr;
    emit errorOccurred(tr("Section \"%1\" timed out")
        .arg(m_sections[m_current].title));
    finishSection(false, "timeout");
}

void BatchProcessor::acceptCurrent() {
    if (!m_running || !m_reviewMode) return;
    applySection(m_current);
    finishSection(true);
}

void BatchProcessor::skipCurrent() {
    if (!m_running || !m_reviewMode) return;
    finishSection(false, "skipped");
}

void BatchProcessor::applySection(int index) {
    auto& s = m_sections[index];
    try {
        auto cursor = DocumentParser::buildBodyCursor(s);
        if (!cursor.is()) {
            s.success  = false;
            s.errorMsg = "Could not build text cursor";
            return;
        }
        QTextDocument doc;
        doc.setMarkdown(s.rewrittenText);
        UnoHelper::applyRichTextToRange(&doc, cursor);
        s.success    = true;
        s.wordsAfter = s.rewrittenText.split(' ', Qt::SkipEmptyParts).size();
    } catch (...) {
        s.success  = false;
        s.errorMsg = "Exception during apply";
    }
}

void BatchProcessor::finishSection(bool success, const QString& error) {
    auto& s   = m_sections[m_current];
    s.success  = success;
    s.errorMsg = error;

    if (success) ++m_successes; else ++m_errors;

    emit sectionDone(m_current, m_sections.size(), s.title, success);

    ++m_current;

    if (m_cancelled || (!success && m_cfg.stopOnError)) {
        m_running = false;
        closeUndoContext();
        if (m_cfg.stopOnError && !m_cancelled)
            emit batchCompleted(m_successes, m_errors);
        return;
    }

    m_delayTimer.start(m_cfg.delayMs);
}

void BatchProcessor::closeUndoContext() {
    try {
        auto frame = UnoHelper::getCurrentFrame();
        if (!frame.is()) return;
        auto xModel = Reference<css::frame::XModel>(
            frame->getController()->getModel(), UNO_QUERY);
        if (!xModel.is()) return;
        auto xUndoSupplier = Reference<css::document::XUndoManagerSupplier>(
            xModel, UNO_QUERY);
        if (!xUndoSupplier.is()) return;
        auto xUndo = xUndoSupplier->getUndoManager();
        if (xUndo.is()) xUndo->leaveUndoContext();
    } catch (...) {}
}

AIClient* BatchProcessor::buildClient() {
    auto& cfg = ::Config::get();
    AIClient* c = nullptr;
    switch (cfg.provider) {
        case Provider::Ollama:
            c = new OllamaClient(cfg.ollamaUrl, OllamaAuthConfig::fromConfig(), this); break;
        case Provider::OpenAI:
            c = new OpenAIClient(cfg.openaiUrl, cfg.openaiKey, this); break;
        case Provider::Claude:
            c = new AnthropicClient(cfg.claudeKey, cfg.claudeUrl, this); break;
        case Provider::Grok:
            c = new GrokClient(cfg.grokKey, cfg.grokUrl, this); break;
        case Provider::Gemini:
            c = new GeminiClient(cfg.geminiKey, cfg.geminiUrl, this); break;
    }
    return c;
}
