#include "ChatWindow.hpp"
#include "../core/Config.hpp"
#include "../uno/UnoHelper.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../ai/AnthropicClient.hpp"

#include <QApplication>
#include <QEvent>
#include <QLabel>
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
    m_rewriteBtn = new QPushButton();
    m_sendBtn    = new QPushButton();
    actRow->addWidget(m_rewriteBtn);
    actRow->addWidget(m_sendBtn);
    root->addLayout(actRow);

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

    connect(m_grabBtn,    &QPushButton::clicked, this, &ChatWindow::onGrabSelection);
    connect(m_sendBtn,    &QPushButton::clicked, this, &ChatWindow::onSend);
    connect(m_rewriteBtn, &QPushButton::clicked, this, &ChatWindow::onRewrite);
    connect(m_applyBtn,   &QPushButton::clicked, this, &ChatWindow::onApply);
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
    )")
    .arg(C_BG, C_TEXT, C_MUTED, C_SURFACE, C_BORDER, C_BTN, C_BTN2));
}

AIClient* ChatWindow::buildClient() {
    delete m_client;
    auto& cfg = Config::get();
    switch (cfg.provider) {
        case Provider::Ollama:
            m_client = new OllamaClient(cfg.ollamaUrl, this); break;
        case Provider::OpenAI:
            m_client = new OpenAIClient(cfg.openaiUrl, cfg.openaiKey, this); break;
        case Provider::Claude:
            m_client = new AnthropicClient(cfg.claudeKey, this); break;
    }
    return m_client;
}

void ChatWindow::onGrabSelection() {
    QString sel = UnoHelper::getSelectedText();
    if (sel.isEmpty()) { setStatus(tr("No text selected"), C_MUTED); return; }
    m_selEdit->setPlainText(sel);
    setStatus(tr("Selection grabbed"));
}

void ChatWindow::onSend() {
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
        m_respEdit->setPlainText(resp);
        m_history.append({"user", prompt});
        m_history.append({"assistant", resp});
        setBusy(false);
        setStatus(tr("Done"), C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        setStatus(tr("Error: ") + err, C_ERROR);
        setBusy(false);
    });
    client->sendChat(Config::get().model, m_history, prompt);
}

void ChatWindow::onRewrite() {
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
    client->sendChat(Config::get().model, {}, prompt);
}

void ChatWindow::onApply() {
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
