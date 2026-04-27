#include "ChatWindow.hpp"
#include "../core/Config.hpp"
#include "../uno/UnoHelper.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../ai/AnthropicClient.hpp"
#include "../ai/GrokClient.hpp"
#include "../ai/GeminiClient.hpp"

#include <QApplication>
#include <QDateTime>
#include <QEvent>
#include <QLoggingCategory>

Q_LOGGING_CATEGORY(lcChat, "libreai.chat")
#include <QLabel>
#include <QListWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QVBoxLayout>
#include <QHBoxLayout>

static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_SUCCESS = "#4EC9B0";
static const char* C_ERROR   = "#F44747";
static const char* C_BORDER  = "#3C3C3C";

ChatWindow* ChatWindow::s_instance = nullptr;

ChatWindow* ChatWindow::instance() {
    if (!s_instance) s_instance = new ChatWindow();
    return s_instance;
}

void ChatWindow::resetInstance() {
    if (s_instance) { s_instance->close(); delete s_instance; s_instance = nullptr; }
}

ChatWindow::ChatWindow(QWidget* parent) : QWidget(parent) {
    setMinimumSize(320, 560);
    resize(380, 640);
    setWindowFlags(Qt::Window);
    buildUi();
    applyTheme();
    retranslateUi();
}

void ChatWindow::buildUi() {
    auto* root = new QVBoxLayout(this);
    root->setSpacing(6);
    root->setContentsMargins(8, 8, 8, 8);

    m_headerLabel = new QLabel();
    m_headerLabel->setObjectName("header");
    root->addWidget(m_headerLabel);

    m_grabBtn = new QPushButton();
    m_grabBtn->setObjectName("btn2");
    root->addWidget(m_grabBtn);

    m_selLabel = new QLabel();
    m_selLabel->setObjectName("sectionLabel");
    root->addWidget(m_selLabel);
    m_selEdit = new QPlainTextEdit();
    m_selEdit->setFixedHeight(80);
    root->addWidget(m_selEdit);

    m_instrLabel = new QLabel();
    m_instrLabel->setObjectName("sectionLabel");
    root->addWidget(m_instrLabel);
    m_instrEdit = new QPlainTextEdit();
    m_instrEdit->setFixedHeight(80);
    root->addWidget(m_instrEdit);

    auto* actRow = new QHBoxLayout();
    m_rewriteBtn   = new QPushButton();
    m_sendBtn      = new QPushButton();
    m_clearHistBtn = new QPushButton();
    m_clearHistBtn->setObjectName("btn2");
    actRow->addWidget(m_rewriteBtn);
    actRow->addWidget(m_sendBtn);
    actRow->addWidget(m_clearHistBtn);
    root->addLayout(actRow);

    m_historyToggleBtn = new QPushButton();
    m_historyToggleBtn->setObjectName("btn2");
    m_historyToggleBtn->setCheckable(true);
    root->addWidget(m_historyToggleBtn);

    m_historyList = new QListWidget();
    m_historyList->setWordWrap(true);
    m_historyList->setFixedHeight(160);
    m_historyList->setVisible(false);
    root->addWidget(m_historyList);

    m_respLabel = new QLabel();
    m_respLabel->setObjectName("sectionLabel");
    root->addWidget(m_respLabel);
    m_respEdit = new QPlainTextEdit();
    m_respEdit->setReadOnly(true);
    root->addWidget(m_respEdit, 1);

    m_applyBtn = new QPushButton();
    root->addWidget(m_applyBtn);

    m_statusLabel = new QLabel();
    m_statusLabel->setObjectName("status");
    root->addWidget(m_statusLabel);

    connect(m_grabBtn,      &QPushButton::clicked, this, &ChatWindow::onGrabSelection);
    connect(m_sendBtn,      &QPushButton::clicked, this, &ChatWindow::onSend);
    connect(m_rewriteBtn,   &QPushButton::clicked, this, &ChatWindow::onRewrite);
    connect(m_applyBtn,     &QPushButton::clicked, this, &ChatWindow::onApply);
    connect(m_clearHistBtn, &QPushButton::clicked, this, &ChatWindow::onClearHistory);
    connect(m_historyToggleBtn, &QPushButton::toggled, this, [this](bool open) {
        m_historyList->setVisible(open);
        retranslateUi();
    });
}

void ChatWindow::retranslateUi() {
    setWindowTitle(tr("LibreAI"));
    m_headerLabel->setText(tr("≡ LibreAI"));
    m_grabBtn->setText(tr("Grab Selection"));
    m_selLabel->setText(tr("SELECTED TEXT"));
    m_selEdit->setPlaceholderText(tr("Selected text from document…"));
    m_instrLabel->setText(tr("INSTRUCTION / CHAT"));
    m_instrEdit->setPlaceholderText(tr("Type your instruction or message…"));
    m_rewriteBtn->setText(tr("Rewrite"));
    m_sendBtn->setText(tr("Send"));
    m_clearHistBtn->setText(tr("Clear History"));
    int exchanges = m_history.size() / 2;
    m_historyToggleBtn->setText(
        (m_historyToggleBtn->isChecked() ? tr("▼ History (%1)") : tr("▶ History (%1)"))
        .arg(exchanges));
    m_respLabel->setText(tr("RESPONSE"));
    m_respEdit->setPlaceholderText(tr("AI response appears here…"));
    m_applyBtn->setText(tr("Apply to Document"));
}

void ChatWindow::changeEvent(QEvent* e) {
    if (e->type() == QEvent::LanguageChange) retranslateUi();
    QWidget::changeEvent(e);
}

void ChatWindow::applyTheme() {
    setStyleSheet(QString(R"(
        ChatWindow {
            background: %1;
        }
        QLabel {
            color: %2;
        }
        QLabel#header {
            color: %2;
            font-size: 14px;
            font-weight: bold;
            padding: 4px 0;
        }
        QLabel#sectionLabel {
            color: %3;
            font-size: 10px;
            font-weight: bold;
            margin-top: 4px;
        }
        QLabel#status {
            color: %3;
            font-size: 11px;
        }
        QPlainTextEdit {
            background: %4;
            color: %2;
            border: 1px solid %5;
            border-radius: 2px;
            font-family: monospace;
        }
        QPushButton {
            background: %6;
            color: white;
            border: none;
            border-radius: 2px;
            padding: 5px 12px;
            font-weight: bold;
        }
        QPushButton:hover  { background: #1177bb; }
        QPushButton:pressed{ background: #0a4f7d; }
        QPushButton#btn2 {
            background: %7;
            color: %2;
            font-weight: normal;
        }
        QPushButton#btn2:hover  { background: #4a4a4a; }
        QPushButton:disabled { background: #2a2a2a; color: %3; }
        QListWidget {
            background: %4;
            color: %2;
            border: 1px solid %5;
            border-radius: 2px;
            font-family: monospace;
            font-size: 11px;
        }
        QListWidget::item { padding: 3px 6px; border-bottom: 1px solid %5; }
        QListWidget::item:selected { background: %6; color: white; }
    )")
    .arg(C_BG, C_TEXT, C_MUTED, C_SURFACE, C_BORDER, C_BTN, C_BTN2));
}

AIClient* ChatWindow::buildClient() {
    qCDebug(lcChat) << "buildClient, provider=" << static_cast<int>(Config::get().provider);
    delete m_client;
    auto& cfg = Config::get();
    switch (cfg.provider) {
        case Provider::Ollama:
            m_client = new OllamaClient(cfg.ollamaUrl, OllamaAuthConfig::fromConfig(), this); break;
        case Provider::OpenAI:
            m_client = new OpenAIClient(cfg.openaiUrl, cfg.openaiKey, this); break;
        case Provider::Claude:
            m_client = new AnthropicClient(cfg.claudeKey, this); break;
        case Provider::Grok:
            m_client = new GrokClient(cfg.grokKey, this); break;
        case Provider::Gemini:
            m_client = new GeminiClient(cfg.geminiKey, this); break;
    }
    return m_client;
}

void ChatWindow::onGrabSelection() {
    qCDebug(lcChat) << "onGrabSelection";
    QString sel = UnoHelper::getSelectedText();
    if (sel.isEmpty()) { setStatus(tr("No text selected"), C_MUTED); return; }
    m_selEdit->setPlainText(sel);
    setStatus(tr("Selection grabbed"));
}

void ChatWindow::onSend() {
    qCInfo(lcChat) << "onSend, model=" << Config::get().currentModel();
    QString instr = m_instrEdit->toPlainText().trimmed();
    QString sel   = m_selEdit->toPlainText().trimmed();
    if (instr.isEmpty() && sel.isEmpty()) return;

    QString prompt;
    if (instr.isEmpty())
        prompt = sel;
    else if (sel.isEmpty())
        prompt = instr;
    else
        prompt = "Context:\n" + sel + "\n\n" + instr;

    setBusy(true);
    setStatus(tr("Sending…"));

    auto* client = buildClient();
    connect(client, &AIClient::responseReady, this, [this, prompt](QString resp) {
        qCInfo(lcChat) << "Send response received, length=" << resp.length();
        m_respEdit->setPlainText(resp);
        const auto& cfg = Config::get();
        QString ts   = QDateTime::currentDateTime().toString(Qt::ISODate);
        QString prov = cfg.provider == Provider::Ollama  ? "ollama"
                     : cfg.provider == Provider::OpenAI  ? "openai"
                     : cfg.provider == Provider::Claude  ? "claude"
                     : cfg.provider == Provider::Grok    ? "grok"
                     : "gemini";
        QString mdl  = cfg.currentModel();
        m_history.append({"user",      prompt, ts, prov, mdl});
        m_history.append({"assistant", resp,   ts, prov, mdl});
        refreshHistoryPane();
        setBusy(false);
        setStatus(tr("Done"), C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        qCWarning(lcChat) << "Send error:" << err;
        setStatus(tr("Error: ") + err, C_ERROR);
        setBusy(false);
    });
    client->sendChat(Config::get().currentModel(), m_history, prompt);
}

void ChatWindow::onRewrite() {
    qCInfo(lcChat) << "onRewrite, model=" << Config::get().currentModel();
    QString sel = m_selEdit->toPlainText().trimmed();
    if (sel.isEmpty()) { setStatus(tr("No text to rewrite"), C_MUTED); return; }
    QString instr = m_instrEdit->toPlainText().trimmed();
    QString prompt = instr.isEmpty()
        ? "Rewrite the following text:\n\n" + sel
        : instr + "\n\nText:\n\n" + sel;

    setBusy(true);
    setStatus(tr("Rewriting…"));

    auto* client = buildClient();
    connect(client, &AIClient::responseReady, this, [this](QString resp) {
        m_respEdit->setPlainText(resp);
        setBusy(false);
        setStatus(tr("Done"), C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        setStatus(tr("Error: ") + err, C_ERROR);
        setBusy(false);
    });
    client->sendChat(Config::get().currentModel(), {}, prompt);
}

void ChatWindow::refreshHistoryPane() {
    m_historyList->clear();
    for (const auto& msg : m_history) {
        QString prefix = (msg.role == "user") ? tr("You: ") : tr("AI:  ");
        QString text   = msg.content.simplified().left(200);
        if (msg.content.length() > 200) text += "…";
        auto* item = new QListWidgetItem(prefix + text);
        item->setForeground(msg.role == "user"
            ? QColor(C_TEXT) : QColor(C_SUCCESS));
        m_historyList->addItem(item);
    }
    m_historyList->scrollToBottom();
    retranslateUi();
}

void ChatWindow::onClearHistory() {
    qCInfo(lcChat) << "onClearHistory, clearing" << m_history.size() << "messages";
    m_history.clear();
    refreshHistoryPane();
    setStatus(tr("History cleared"), C_MUTED);
}

void ChatWindow::onApply() {
    qCInfo(lcChat) << "onApply";
    QString text = m_respEdit->toPlainText();
    if (text.isEmpty()) { setStatus(tr("No response to apply"), C_MUTED); return; }
    UnoHelper::applyText(text);
    setStatus(tr("Applied to document"), C_SUCCESS);
}

void ChatWindow::setStatus(const QString& msg, const QString& color) {
    m_statusLabel->setText(msg);
    m_statusLabel->setStyleSheet("color: " + color + "; font-size: 11px;");
}

void ChatWindow::setBusy(bool busy) {
    m_sendBtn->setEnabled(!busy);
    m_rewriteBtn->setEnabled(!busy);
    m_applyBtn->setEnabled(!busy);

    if (busy) {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        m_spinFrame = 0;
        if (!m_spinTimer) {
            m_spinTimer = new QTimer(this);
            connect(m_spinTimer, &QTimer::timeout, this, [this] {
                static const char* frames[] = {
                    "⠋","⠙","⠹","⠸","⠼","⠴","⠦","⠧","⠇","⠏"
                };
                m_spinFrame = (m_spinFrame + 1) % 10;
                m_respEdit->setPlainText(
                    QString("%1  %2").arg(frames[m_spinFrame]).arg(tr("Thinking…")));
            });
        }
        m_respEdit->setPlainText(QString("⠋  %1").arg(tr("Thinking…")));
        m_spinTimer->start(80);
    } else {
        QApplication::restoreOverrideCursor();
        if (m_spinTimer) m_spinTimer->stop();
    }
}

void ChatWindow::setPendingSelection(const QString& text) {
    m_selEdit->setPlainText(text);
}
