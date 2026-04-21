#include "ChatWindow.hpp"
#include "Config.hpp"
#include "UnoHelper.hpp"
#include "OllamaClient.hpp"
#include "OpenAIClient.hpp"
#include "AnthropicClient.hpp"

#include <QApplication>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QSplitter>
#include <QFrame>

// ── Palette ──────────────────────────────────────────────────────────────────
static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_SUCCESS = "#4EC9B0";
static const char* C_ERROR   = "#F44747";
static const char* C_BORDER  = "#3C3C3C";

ChatWindow* ChatWindow::instance() {
    static ChatWindow* w = nullptr;
    if (!w) w = new ChatWindow();
    return w;
}

ChatWindow::ChatWindow(QWidget* parent) : QWidget(parent) {
    setWindowTitle("LibreAI");
    setMinimumSize(320, 640);
    resize(380, 720);
    setWindowFlag(Qt::Window);
    buildUi();
    applyTheme();
}

void ChatWindow::buildUi() {
    auto* root = new QVBoxLayout(this);
    root->setSpacing(6);
    root->setContentsMargins(8, 8, 8, 8);

    // Header
    auto* header = new QLabel("≡ LibreAI");
    header->setObjectName("header");
    root->addWidget(header);

    // Provider row
    auto* provRow = new QHBoxLayout();
    provRow->addWidget(new QLabel("PROVIDER"));
    m_providerBox = new QComboBox();
    m_providerBox->addItems({"Ollama", "OpenAI", "Claude"});
    provRow->addWidget(m_providerBox, 1);
    root->addLayout(provRow);

    // Connection
    auto* connRow = new QHBoxLayout();
    m_connLabel = new QLabel("BASE URL");
    connRow->addWidget(m_connLabel);
    m_connEdit = new QLineEdit();
    connRow->addWidget(m_connEdit, 1);
    root->addLayout(connRow);

    // Model row
    auto* modelRow = new QHBoxLayout();
    modelRow->addWidget(new QLabel("MODEL"));
    m_modelBox = new QComboBox();
    m_modelBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    modelRow->addWidget(m_modelBox, 1);
    m_refreshBtn = new QPushButton("↺");
    m_refreshBtn->setFixedWidth(28);
    m_refreshBtn->setObjectName("btn2");
    modelRow->addWidget(m_refreshBtn);
    root->addLayout(modelRow);

    // Grab selection
    m_grabBtn = new QPushButton("Grab Selection");
    m_grabBtn->setObjectName("btn2");
    root->addWidget(m_grabBtn);

    auto makeLabel = [](const char* text) {
        auto* l = new QLabel(text);
        l->setObjectName("sectionLabel");
        return l;
    };

    // Selected text
    root->addWidget(makeLabel("SELECTED TEXT"));
    m_selEdit = new QPlainTextEdit();
    m_selEdit->setPlaceholderText("Selected text from document…");
    m_selEdit->setFixedHeight(80);
    root->addWidget(m_selEdit);

    // Instruction
    root->addWidget(makeLabel("INSTRUCTION / CHAT"));
    m_instrEdit = new QPlainTextEdit();
    m_instrEdit->setPlaceholderText("Type your instruction or message…");
    m_instrEdit->setFixedHeight(80);
    root->addWidget(m_instrEdit);

    // Action buttons
    auto* actRow = new QHBoxLayout();
    m_rewriteBtn = new QPushButton("Rewrite");
    m_sendBtn    = new QPushButton("Send");
    actRow->addWidget(m_rewriteBtn);
    actRow->addWidget(m_sendBtn);
    root->addLayout(actRow);

    // Response
    root->addWidget(makeLabel("RESPONSE")); // NOLINT — lambda still in scope
    m_respEdit = new QPlainTextEdit();
    m_respEdit->setReadOnly(true);
    m_respEdit->setPlaceholderText("AI response appears here…");
    root->addWidget(m_respEdit, 1);

    // Apply
    m_applyBtn = new QPushButton("Apply to Document");
    root->addWidget(m_applyBtn);

    // Status
    m_statusLabel = new QLabel();
    m_statusLabel->setObjectName("status");
    root->addWidget(m_statusLabel);

    // Load saved config
    auto& cfg = Config::get();
    m_providerBox->setCurrentIndex(static_cast<int>(cfg.provider));
    onProviderChanged(m_providerBox->currentIndex());
    if (!cfg.model.isEmpty()) {
        m_modelBox->addItem(cfg.model);
        m_modelBox->setCurrentText(cfg.model);
    }

    // Connections
    connect(m_providerBox, &QComboBox::currentIndexChanged, this, &ChatWindow::onProviderChanged);
    connect(m_refreshBtn,  &QPushButton::clicked, this, &ChatWindow::onRefreshModels);
    connect(m_grabBtn,     &QPushButton::clicked, this, &ChatWindow::onGrabSelection);
    connect(m_sendBtn,     &QPushButton::clicked, this, &ChatWindow::onSend);
    connect(m_rewriteBtn,  &QPushButton::clicked, this, &ChatWindow::onRewrite);
    connect(m_applyBtn,    &QPushButton::clicked, this, &ChatWindow::onApply);
    connect(m_connEdit,    &QLineEdit::editingFinished, this, [this] {
        auto& cfg = Config::get();
        switch (static_cast<Provider>(m_providerBox->currentIndex())) {
            case Provider::Ollama:  cfg.ollamaUrl = m_connEdit->text(); break;
            case Provider::OpenAI:  cfg.openaiKey = m_connEdit->text(); break;
            case Provider::Claude:  cfg.claudeKey = m_connEdit->text(); break;
        }
        cfg.save();
    });
    connect(m_modelBox, &QComboBox::currentTextChanged, this, [](const QString& m) {
        Config::get().model = m;
        Config::get().save();
    });
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
        QComboBox, QLineEdit {
            background: %4;
            color: %2;
            border: 1px solid %5;
            border-radius: 2px;
            padding: 3px 6px;
        }
        QComboBox QAbstractItemView {
            background: %4;
            color: %2;
            selection-background-color: %6;
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

void ChatWindow::onProviderChanged(int index) {
    auto& cfg = Config::get();
    cfg.provider = static_cast<Provider>(index);
    cfg.save();
    delete m_client;
    m_client = nullptr;

    switch (static_cast<Provider>(index)) {
        case Provider::Ollama:
            m_connLabel->setText("BASE URL");
            m_connEdit->setText(cfg.ollamaUrl);
            m_connEdit->setEchoMode(QLineEdit::Normal);
            break;
        case Provider::OpenAI:
            m_connLabel->setText("API KEY");
            m_connEdit->setText(cfg.openaiKey);
            m_connEdit->setEchoMode(QLineEdit::Password);
            break;
        case Provider::Claude:
            m_connLabel->setText("API KEY");
            m_connEdit->setText(cfg.claudeKey);
            m_connEdit->setEchoMode(QLineEdit::Password);
            break;
    }
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

void ChatWindow::onRefreshModels() {
    setStatus("Fetching models…");
    auto* client = buildClient();
    connect(client, &AIClient::modelsReady, this, [this](QStringList models) {
        m_modelBox->clear();
        m_modelBox->addItems(models);
        auto saved = Config::get().model;
        if (!saved.isEmpty()) m_modelBox->setCurrentText(saved);
        setStatus("Models loaded", C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        setStatus("Error: " + err, C_ERROR);
    });
    client->fetchModels();
}

void ChatWindow::onGrabSelection() {
    QString sel = UnoHelper::getSelectedText();
    if (sel.isEmpty()) { setStatus("No text selected", C_MUTED); return; }
    m_selEdit->setPlainText(sel);
    setStatus("Selection grabbed");
}

void ChatWindow::onSend() {
    QString prompt = m_instrEdit->toPlainText().trimmed();
    if (prompt.isEmpty()) return;

    QString sel = m_selEdit->toPlainText().trimmed();
    if (!sel.isEmpty())
        prompt = "Context:\n" + sel + "\n\n" + prompt;

    setBusy(true);
    setStatus("Sending…");

    auto* client = buildClient();
    connect(client, &AIClient::responseReady, this, [this, prompt](QString resp) {
        m_respEdit->setPlainText(resp);
        m_history.append({"user", m_instrEdit->toPlainText().trimmed()});
        m_history.append({"assistant", resp});
        setBusy(false);
        setStatus("Done", C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        setStatus("Error: " + err, C_ERROR);
        setBusy(false);
    });
    client->sendChat(m_modelBox->currentText(), m_history, prompt);
}

void ChatWindow::onRewrite() {
    QString sel = m_selEdit->toPlainText().trimmed();
    if (sel.isEmpty()) { setStatus("No text to rewrite", C_MUTED); return; }
    QString instr = m_instrEdit->toPlainText().trimmed();
    QString prompt = instr.isEmpty()
        ? "Rewrite the following text:\n\n" + sel
        : instr + "\n\nText:\n\n" + sel;

    setBusy(true);
    setStatus("Rewriting…");

    auto* client = buildClient();
    connect(client, &AIClient::responseReady, this, [this](QString resp) {
        m_respEdit->setPlainText(resp);
        setBusy(false);
        setStatus("Done", C_SUCCESS);
    });
    connect(client, &AIClient::errorOccurred, this, [this](QString err) {
        setStatus("Error: " + err, C_ERROR);
        setBusy(false);
    });
    client->sendChat(m_modelBox->currentText(), {}, prompt);
}

void ChatWindow::onApply() {
    QString text = m_respEdit->toPlainText();
    if (text.isEmpty()) { setStatus("No response to apply", C_MUTED); return; }
    UnoHelper::applyText(text);
    setStatus("Applied to document", C_SUCCESS);
}

void ChatWindow::setStatus(const QString& msg, const QString& color) {
    m_statusLabel->setText(msg);
    m_statusLabel->setStyleSheet("color: " + color + "; font-size: 11px;");
}

void ChatWindow::setBusy(bool busy) {
    m_sendBtn->setEnabled(!busy);
    m_rewriteBtn->setEnabled(!busy);
    m_applyBtn->setEnabled(!busy);
    if (busy)
        QApplication::setOverrideCursor(Qt::WaitCursor);
    else
        QApplication::restoreOverrideCursor();
}

void ChatWindow::setPendingSelection(const QString& text) {
    m_selEdit->setPlainText(text);
}
