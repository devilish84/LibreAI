#include "ConfigDialog.hpp"
#include "ChatWindow.hpp"
#include "../core/Config.hpp"
#include "../core/CredentialStore.hpp"
#include "../core/Logger.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../ai/AnthropicClient.hpp"
#include "../ai/GrokClient.hpp"
#include "../ai/GeminiClient.hpp"

#include <QCheckBox>
#include <QComboBox>
#include <QLoggingCategory>
#include <QSpinBox>
#include <QStandardPaths>

Q_LOGGING_CATEGORY(lcConfigDlg, "libreai.configdialog")
#include <QEvent>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_BORDER  = "#3C3C3C";

static const struct { const char* code; const char* name; } kLanguages[] = {
    {"en", "English"},
    {"fi", "Suomi"},
    {"sv", "Svenska"},
    {"da", "Dansk"},
    {"nb", "Norsk"},
    {"es", "Español"},
    {"de", "Deutsch"},
    {"pt", "Português"},
};
static const int kLangCount = static_cast<int>(sizeof(kLanguages) / sizeof(kLanguages[0]));

ConfigDialog* ConfigDialog::s_instance = nullptr;

ConfigDialog* ConfigDialog::instance() {
    if (!s_instance) s_instance = new ConfigDialog();
    return s_instance;
}

void ConfigDialog::resetInstance() {
    if (s_instance) { s_instance->close(); delete s_instance; s_instance = nullptr; }
}

ConfigDialog::ConfigDialog(QWidget* parent) : QWidget(parent) {
    qCDebug(lcConfigDlg) << "ConfigDialog constructing";
    setMinimumWidth(440);
    setWindowFlags(Qt::Window);
    buildUi();
    applyTheme();
    retranslateUi();
}

// ── buildUi ───────────────────────────────────────────────────────────────────

void ConfigDialog::buildUi() {
    qCDebug(lcConfigDlg) << "buildUi";
    auto* root = new QVBoxLayout(this);
    root->setSpacing(10);
    root->setContentsMargins(14, 14, 14, 14);

    m_tabs = new QTabWidget();
    m_tabs->setObjectName("tabs");
    root->addWidget(m_tabs);

    // ── General Settings tab ──────────────────────────────────────────────
    auto* generalPage = new QWidget();
    auto* generalForm = new QFormLayout(generalPage);
    generalForm->setSpacing(10);
    generalForm->setContentsMargins(10, 14, 10, 10);

    m_langLabel = new QLabel();
    m_langBox   = new QComboBox();
    for (int i = 0; i < kLangCount; ++i)
        m_langBox->addItem(kLanguages[i].name, kLanguages[i].code);
    {
        const QString saved = Config::get().language;
        for (int i = 0; i < kLangCount; ++i)
            if (kLanguages[i].code == saved) { m_langBox->setCurrentIndex(i); break; }
    }
    generalForm->addRow(m_langLabel, m_langBox);

    m_logEnabledBox = new QCheckBox();
    m_logEnabledBox->setChecked(Config::get().loggingEnabled);
    generalForm->addRow(m_logEnabledBox);

    m_logLevelLabel = new QLabel();
    m_logLevelBox   = new QComboBox();
    m_logLevelBox->addItems({"Debug", "Info", "Error"});
    m_logLevelBox->setCurrentIndex(Config::get().logLevel);
    m_logLevelBox->setEnabled(Config::get().loggingEnabled);
    m_logLevelLabel->setEnabled(Config::get().loggingEnabled);
    generalForm->addRow(m_logLevelLabel, m_logLevelBox);

    m_logMaxSizeLabel = new QLabel();
    m_logMaxSizeBox   = new QSpinBox();
    m_logMaxSizeBox->setRange(1, 500);
    m_logMaxSizeBox->setSuffix(" MB");
    m_logMaxSizeBox->setValue(Config::get().maxLogSizeMb);
    m_logMaxSizeBox->setEnabled(Config::get().loggingEnabled);
    m_logMaxSizeLabel->setEnabled(Config::get().loggingEnabled);
    generalForm->addRow(m_logMaxSizeLabel, m_logMaxSizeBox);

    m_logPathLabel = new QLabel();
    m_logPathValue = new QLabel(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
        + "/libreai.log");
    m_logPathValue->setObjectName("logPathValue");
    m_logPathValue->setWordWrap(true);
    m_logPathValue->setTextInteractionFlags(Qt::TextSelectableByMouse);
    generalForm->addRow(m_logPathLabel, m_logPathValue);

    connect(m_logEnabledBox, &QCheckBox::toggled, this, [this](bool on) {
        m_logLevelBox->setEnabled(on);
        m_logLevelLabel->setEnabled(on);
        m_logMaxSizeBox->setEnabled(on);
        m_logMaxSizeLabel->setEnabled(on);
    });

    m_tabs->addTab(generalPage, "");

    // ── Model Selection tab — single flat QFormLayout ─────────────────────
    auto* modelPage = new QWidget();
    m_modelForm = new QFormLayout(modelPage);
    m_modelForm->setSpacing(10);
    m_modelForm->setContentsMargins(10, 14, 10, 10);

    m_providerLabel = new QLabel();
    m_providerBox   = new QComboBox();
    m_providerBox->addItems({"Ollama", "OpenAI", "Claude", "Grok", "Gemini"});
    m_providerBox->setCurrentIndex(static_cast<int>(Config::get().provider));
    m_modelForm->addRow(m_providerLabel, m_providerBox);

    // Ollama fields
    m_ollamaUrlLabel = new QLabel();
    m_ollamaUrlEdit  = new QLineEdit(Config::get().ollamaUrl);
    m_modelForm->addRow(m_ollamaUrlLabel, m_ollamaUrlEdit);

    m_ollamaAuthLabel = new QLabel();
    m_ollamaAuthBox   = new QComboBox();
    m_ollamaAuthBox->addItems({"None", "Basic Auth", "API Key"});
    m_ollamaAuthBox->setCurrentIndex(static_cast<int>(Config::get().ollamaAuth));
    m_modelForm->addRow(m_ollamaAuthLabel, m_ollamaAuthBox);

    m_ollamaUserLabel = new QLabel();
    m_ollamaUserEdit  = new QLineEdit(Config::get().ollamaBasicUser);
    m_modelForm->addRow(m_ollamaUserLabel, m_ollamaUserEdit);

    m_ollamaPassLabel = new QLabel();
    m_ollamaPassEdit  = new QLineEdit(Config::get().ollamaBasicPass);
    m_ollamaPassEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_ollamaPassLabel, m_ollamaPassEdit);

    m_ollamaKeyHeaderLabel = new QLabel();
    m_ollamaKeyHeaderEdit  = new QLineEdit(Config::get().ollamaApiKeyHeader);
    m_modelForm->addRow(m_ollamaKeyHeaderLabel, m_ollamaKeyHeaderEdit);

    m_ollamaKeyValueLabel = new QLabel();
    m_ollamaKeyValueEdit  = new QLineEdit(Config::get().ollamaApiKeyValue);
    m_ollamaKeyValueEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_ollamaKeyValueLabel, m_ollamaKeyValueEdit);

    // OpenAI fields
    m_openaiUrlLabel = new QLabel();
    m_openaiUrlEdit  = new QLineEdit(Config::get().openaiUrl);
    m_modelForm->addRow(m_openaiUrlLabel, m_openaiUrlEdit);

    m_openaiKeyLabel = new QLabel();
    m_openaiKeyEdit  = new QLineEdit(Config::get().openaiKey);
    m_openaiKeyEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_openaiKeyLabel, m_openaiKeyEdit);

    // Claude fields
    m_claudeKeyLabel = new QLabel();
    m_claudeKeyEdit  = new QLineEdit(Config::get().claudeKey);
    m_claudeKeyEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_claudeKeyLabel, m_claudeKeyEdit);

    // Grok fields
    m_grokKeyLabel = new QLabel();
    m_grokKeyEdit  = new QLineEdit(Config::get().grokKey);
    m_grokKeyEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_grokKeyLabel, m_grokKeyEdit);

    // Gemini fields
    m_geminiKeyLabel = new QLabel();
    m_geminiKeyEdit  = new QLineEdit(Config::get().geminiKey);
    m_geminiKeyEdit->setEchoMode(QLineEdit::Password);
    m_modelForm->addRow(m_geminiKeyLabel, m_geminiKeyEdit);

    // Keychain hint (spanning label, no label column)
    m_keychainHint = new QLabel();
    m_keychainHint->setObjectName("keychainHint");
    m_keychainHint->setWordWrap(true);
    m_modelForm->addRow(m_keychainHint);

    // Model row
    m_modelLabel = new QLabel();
    auto* modelRow = new QHBoxLayout();
    m_modelBox = new QComboBox();
    m_modelBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    modelRow->addWidget(m_modelBox);
    m_refreshBtn = new QPushButton("\u21BA");
    m_refreshBtn->setFixedWidth(28);
    m_refreshBtn->setObjectName("btn2");
    modelRow->addWidget(m_refreshBtn);
    m_modelForm->addRow(m_modelLabel, modelRow);

    m_tabs->addTab(modelPage, "");

    // ── Bottom buttons ────────────────────────────────────────────────────
    auto* btnRow = new QHBoxLayout();
    btnRow->addStretch();
    m_cancelBtn = new QPushButton();
    m_cancelBtn->setObjectName("btn2");
    m_okBtn = new QPushButton();
    btnRow->addWidget(m_cancelBtn);
    btnRow->addWidget(m_okBtn);
    root->addLayout(btnRow);

    // Wire signals
    connect(m_tabs,         &QTabWidget::currentChanged,      this, [this](int idx) {
        if (idx == 1) onProviderChanged(m_providerBox->currentIndex());
    });
    connect(m_providerBox,  &QComboBox::currentIndexChanged,  this, &ConfigDialog::onProviderChanged);
    connect(m_ollamaAuthBox,&QComboBox::currentIndexChanged,  this, &ConfigDialog::onOllamaAuthChanged);
    connect(m_refreshBtn,   &QPushButton::clicked,            this, &ConfigDialog::onRefreshModels);
    connect(m_okBtn,        &QPushButton::clicked,            this, &ConfigDialog::onOk);
    connect(m_cancelBtn,    &QPushButton::clicked,            this, &ConfigDialog::close);

    // Auto-fetch when key/url field loses focus
    auto autoFetch = [this]() {
        if (!currentCredential().trimmed().isEmpty()) onRefreshModels();
    };
    connect(m_ollamaUrlEdit,    &QLineEdit::editingFinished, this, autoFetch);
    connect(m_ollamaPassEdit,   &QLineEdit::editingFinished, this, autoFetch);
    connect(m_ollamaKeyValueEdit,&QLineEdit::editingFinished,this, autoFetch);
    connect(m_openaiKeyEdit,    &QLineEdit::editingFinished, this, autoFetch);
    connect(m_claudeKeyEdit,    &QLineEdit::editingFinished, this, autoFetch);
    connect(m_grokKeyEdit,      &QLineEdit::editingFinished, this, autoFetch);
    connect(m_geminiKeyEdit,    &QLineEdit::editingFinished, this, autoFetch);

    // Init visibility
    onProviderChanged(m_providerBox->currentIndex());
    onOllamaAuthChanged(m_ollamaAuthBox->currentIndex());
}

// ── Slot implementations ──────────────────────────────────────────────────────

void ConfigDialog::setRowVisible(QLabel* lbl, QWidget* field, bool visible) {
    if (lbl)   lbl->setVisible(visible);
    if (field) field->setVisible(visible);
}

void ConfigDialog::onProviderChanged(int index) {
    qCDebug(lcConfigDlg) << "onProviderChanged, index=" << index;
    auto& cfg = Config::get();
    bool isOllama = (index == static_cast<int>(Provider::Ollama));
    bool isOpenAI = (index == static_cast<int>(Provider::OpenAI));
    bool isClaude = (index == static_cast<int>(Provider::Claude));
    bool isGrok   = (index == static_cast<int>(Provider::Grok));
    bool isGemini = (index == static_cast<int>(Provider::Gemini));

    setRowVisible(m_ollamaUrlLabel,      m_ollamaUrlEdit,      isOllama);
    setRowVisible(m_ollamaAuthLabel,     m_ollamaAuthBox,      isOllama);
    setRowVisible(m_openaiUrlLabel,      m_openaiUrlEdit,      isOpenAI);
    setRowVisible(m_openaiKeyLabel,      m_openaiKeyEdit,      isOpenAI);
    setRowVisible(m_claudeKeyLabel,      m_claudeKeyEdit,      isClaude);
    setRowVisible(m_grokKeyLabel,        m_grokKeyEdit,        isGrok);
    setRowVisible(m_geminiKeyLabel,      m_geminiKeyEdit,      isGemini);

    // Ollama auth sub-rows: delegate to onOllamaAuthChanged (only if Ollama)
    if (isOllama)
        onOllamaAuthChanged(m_ollamaAuthBox->currentIndex());
    else {
        setRowVisible(m_ollamaUserLabel,      m_ollamaUserEdit,      false);
        setRowVisible(m_ollamaPassLabel,      m_ollamaPassEdit,      false);
        setRowVisible(m_ollamaKeyHeaderLabel, m_ollamaKeyHeaderEdit, false);
        setRowVisible(m_ollamaKeyValueLabel,  m_ollamaKeyValueEdit,  false);
    }

    // Keychain hint
    m_keychainHint->setVisible(!CredentialStore::isAvailable());

    m_modelBox->clear();

    // Restore saved model for this provider
    QString saved;
    switch (static_cast<Provider>(index)) {
        case Provider::Ollama:  saved = cfg.ollamaModel; break;
        case Provider::OpenAI:  saved = cfg.openaiModel; break;
        case Provider::Claude:  saved = cfg.claudeModel; break;
        case Provider::Grok:    saved = cfg.grokModel;   break;
        case Provider::Gemini:  saved = cfg.geminiModel; break;
    }
    if (!saved.isEmpty()) {
        m_modelBox->addItem(saved);
        m_modelBox->setCurrentText(saved);
    }

    bool hasCredential = !currentCredential().trimmed().isEmpty();
    m_modelBox->setEnabled(hasCredential);
    m_refreshBtn->setEnabled(hasCredential);

    if (hasCredential && m_tabs->currentIndex() == 1)
        onRefreshModels();
}

void ConfigDialog::onOllamaAuthChanged(int index) {
    qCDebug(lcConfigDlg) << "onOllamaAuthChanged, index=" << index;
    bool isBasic  = (index == static_cast<int>(OllamaAuth::Basic));
    bool isApiKey = (index == static_cast<int>(OllamaAuth::ApiKey));
    setRowVisible(m_ollamaUserLabel,      m_ollamaUserEdit,      isBasic);
    setRowVisible(m_ollamaPassLabel,      m_ollamaPassEdit,      isBasic);
    setRowVisible(m_ollamaKeyHeaderLabel, m_ollamaKeyHeaderEdit, isApiKey);
    setRowVisible(m_ollamaKeyValueLabel,  m_ollamaKeyValueEdit,  isApiKey);
}

QString ConfigDialog::currentCredential() const {
    qCDebug(lcConfigDlg) << "currentCredential";
    switch (static_cast<Provider>(m_providerBox->currentIndex())) {
        case Provider::Ollama:
            switch (static_cast<OllamaAuth>(m_ollamaAuthBox->currentIndex())) {
                case OllamaAuth::None:   return m_ollamaUrlEdit->text();
                case OllamaAuth::Basic:  return m_ollamaPassEdit->text();
                case OllamaAuth::ApiKey: return m_ollamaKeyValueEdit->text();
            }
            break;
        case Provider::OpenAI: return m_openaiKeyEdit->text();
        case Provider::Claude: return m_claudeKeyEdit->text();
        case Provider::Grok:   return m_grokKeyEdit->text();
        case Provider::Gemini: return m_geminiKeyEdit->text();
    }
    return {};
}

void ConfigDialog::onRefreshModels() {
    qCInfo(lcConfigDlg) << "onRefreshModels, provider=" << m_providerBox->currentIndex();
    delete m_client;
    m_client = nullptr;
    auto& cfg = Config::get();

    switch (static_cast<Provider>(m_providerBox->currentIndex())) {
        case Provider::Ollama: {
            OllamaAuthConfig auth;
            auth.type         = static_cast<OllamaAuth>(m_ollamaAuthBox->currentIndex());
            auth.basicUser    = m_ollamaUserEdit->text();
            auth.basicPass    = m_ollamaPassEdit->text();
            auth.apiKeyHeader = m_ollamaKeyHeaderEdit->text();
            auth.apiKeyValue  = m_ollamaKeyValueEdit->text();
            m_client = new OllamaClient(m_ollamaUrlEdit->text(), auth, this);
            break;
        }
        case Provider::OpenAI:
            m_client = new OpenAIClient(m_openaiUrlEdit->text(), m_openaiKeyEdit->text(), this);
            break;
        case Provider::Claude:
            m_client = new AnthropicClient(m_claudeKeyEdit->text(), this);
            break;
        case Provider::Grok:
            m_client = new GrokClient(m_grokKeyEdit->text(), this);
            break;
        case Provider::Gemini:
            m_client = new GeminiClient(m_geminiKeyEdit->text(), this);
            break;
    }

    connect(m_client, &AIClient::modelsReady, this, [this](QStringList models) {
        qCInfo(lcConfigDlg) << "Models received, count=" << models.size();
        m_modelBox->setEnabled(true);
        m_refreshBtn->setEnabled(true);
        m_modelBox->clear();
        m_modelBox->addItems(models);
        const QString saved = Config::get().currentModel();
        if (!saved.isEmpty()) m_modelBox->setCurrentText(saved);
    });
    connect(m_client, &AIClient::errorOccurred, this, [this](const QString& err) {
        qCWarning(lcConfigDlg) << "Model fetch error:" << err;
        m_refreshBtn->setEnabled(true);
    });
    m_refreshBtn->setEnabled(false);
    m_client->fetchModels();
}

void ConfigDialog::onOk() {
    qCInfo(lcConfigDlg) << "onOk: saving configuration";
    auto& cfg = Config::get();

    // Language
    int li = m_langBox->currentIndex();
    bool langChanged = (cfg.language != kLanguages[li].code);
    cfg.language = kLanguages[li].code;

    // Logging
    cfg.loggingEnabled = m_logEnabledBox->isChecked();
    cfg.logLevel       = m_logLevelBox->currentIndex();
    cfg.maxLogSizeMb   = m_logMaxSizeBox->value();

    // Provider
    cfg.provider = static_cast<Provider>(m_providerBox->currentIndex());

    // Ollama
    cfg.ollamaUrl          = m_ollamaUrlEdit->text();
    cfg.ollamaAuth         = static_cast<OllamaAuth>(m_ollamaAuthBox->currentIndex());
    cfg.ollamaBasicUser    = m_ollamaUserEdit->text();
    cfg.ollamaBasicPass    = m_ollamaPassEdit->text();
    cfg.ollamaApiKeyHeader = m_ollamaKeyHeaderEdit->text();
    cfg.ollamaApiKeyValue  = m_ollamaKeyValueEdit->text();

    // OpenAI
    cfg.openaiUrl = m_openaiUrlEdit->text();
    cfg.openaiKey = m_openaiKeyEdit->text();

    // Claude
    cfg.claudeKey = m_claudeKeyEdit->text();

    // Grok
    cfg.grokKey = m_grokKeyEdit->text();

    // Gemini
    cfg.geminiKey = m_geminiKeyEdit->text();

    // Per-provider model
    switch (cfg.provider) {
        case Provider::Ollama:  cfg.ollamaModel  = m_modelBox->currentText(); break;
        case Provider::OpenAI:  cfg.openaiModel  = m_modelBox->currentText(); break;
        case Provider::Claude:  cfg.claudeModel  = m_modelBox->currentText(); break;
        case Provider::Grok:    cfg.grokModel    = m_modelBox->currentText(); break;
        case Provider::Gemini:  cfg.geminiModel  = m_modelBox->currentText(); break;
    }

    cfg.save();
    initLogging();

    if (langChanged) {
        Config::applyLanguage();
        ChatWindow::resetInstance();
        ConfigDialog::resetInstance();  // closes & deletes self — must be last
    } else {
        close();
    }
}

// ── UI helpers ────────────────────────────────────────────────────────────────

void ConfigDialog::retranslateUi() {
    qCDebug(lcConfigDlg) << "retranslateUi";
    setWindowTitle(tr("LibreAI — Configuration"));
    m_tabs->setTabText(0, tr("General Settings"));
    m_tabs->setTabText(1, tr("Model Selection"));
    m_langLabel->setText(tr("LANGUAGE"));
    m_logEnabledBox->setText(tr("Enable verbose logging"));
    m_logLevelLabel->setText(tr("LEVEL"));
    m_logMaxSizeLabel->setText(tr("MAX SIZE"));
    m_logPathLabel->setText(tr("LOG FILE"));
    m_providerLabel->setText(tr("PROVIDER"));
    m_ollamaUrlLabel->setText(tr("BASE URL"));
    m_ollamaAuthLabel->setText(tr("AUTH"));
    m_ollamaUserLabel->setText(tr("USERNAME"));
    m_ollamaPassLabel->setText(tr("PASSWORD"));
    m_ollamaKeyHeaderLabel->setText(tr("HEADER"));
    m_ollamaKeyValueLabel->setText(tr("API KEY"));
    m_openaiUrlLabel->setText(tr("BASE URL"));
    m_openaiKeyLabel->setText(tr("API KEY"));
    m_claudeKeyLabel->setText(tr("API KEY"));
    m_grokKeyLabel->setText(tr("API KEY"));
    m_geminiKeyLabel->setText(tr("API KEY"));
    m_keychainHint->setText(tr("Keychain unavailable — credentials will not be saved between sessions"));
    m_modelLabel->setText(tr("MODEL"));
    m_okBtn->setText(tr("OK"));
    m_cancelBtn->setText(tr("Cancel"));
}

void ConfigDialog::changeEvent(QEvent* e) {
    if (e->type() == QEvent::LanguageChange) retranslateUi();
    QWidget::changeEvent(e);
}

void ConfigDialog::applyTheme() {
    setStyleSheet(QString(R"(
        ConfigDialog {
            background: %1;
        }
        QTabWidget::pane {
            border: 1px solid %5;
            background: %1;
        }
        QTabBar::tab {
            background: %7;
            color: %2;
            padding: 6px 14px;
            border: 1px solid %5;
            border-bottom: none;
        }
        QTabBar::tab:selected {
            background: %1;
            color: %2;
        }
        QLabel {
            color: %2;
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
        QPushButton#btn2:hover { background: #4a4a4a; }
        QCheckBox {
            color: %2;
            spacing: 6px;
        }
        QCheckBox::indicator {
            width: 14px;
            height: 14px;
            border: 1px solid %5;
            border-radius: 2px;
            background: %4;
        }
        QCheckBox::indicator:checked {
            background: %6;
            border-color: %6;
        }
        QLabel:disabled, QComboBox:disabled {
            color: %3;
        }
        QComboBox:disabled {
            background: %7;
        }
        QLabel#keychainHint {
            color: %3;
            font-size: 11px;
        }
        QLabel#logPathValue {
            color: %3;
            font-size: 11px;
        }
        QSpinBox {
            background: %4;
            color: %2;
            border: 1px solid %5;
            border-radius: 2px;
            padding: 3px 6px;
        }
        QSpinBox:disabled {
            color: %3;
            background: %7;
        }
    )")
    .arg(C_BG, C_TEXT, C_MUTED, C_SURFACE, C_BORDER, C_BTN, C_BTN2));
}
