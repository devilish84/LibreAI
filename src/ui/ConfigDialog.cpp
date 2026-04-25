#include "ConfigDialog.hpp"
#include "ChatWindow.hpp"
#include "../core/Config.hpp"
#include "../core/Logger.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../ai/AnthropicClient.hpp"

#include <QCheckBox>
#include <QComboBox>
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
    setMinimumWidth(420);
    setWindowFlags(Qt::Window);
    buildUi();
    applyTheme();
    retranslateUi();
}

void ConfigDialog::buildUi() {
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

    // Select saved language
    const QString saved = Config::get().language;
    for (int i = 0; i < kLangCount; ++i) {
        if (kLanguages[i].code == saved) { m_langBox->setCurrentIndex(i); break; }
    }

    generalForm->addRow(m_langLabel, m_langBox);

    // Logging controls
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

    connect(m_logEnabledBox, &QCheckBox::toggled, this, [this](bool on) {
        m_logLevelBox->setEnabled(on);
        m_logLevelLabel->setEnabled(on);
    });

    m_tabs->addTab(generalPage, "");

    // ── Model Selection tab ───────────────────────────────────────────────
    auto* modelPage = new QWidget();
    auto* modelForm = new QFormLayout(modelPage);
    modelForm->setSpacing(10);
    modelForm->setContentsMargins(10, 14, 10, 10);

    m_providerLabel = new QLabel();
    m_providerBox   = new QComboBox();
    m_providerBox->addItems({"Ollama", "OpenAI", "Claude"});
    m_providerBox->setCurrentIndex(static_cast<int>(Config::get().provider));
    modelForm->addRow(m_providerLabel, m_providerBox);

    m_connLabel = new QLabel();
    m_connEdit  = new QLineEdit();
    modelForm->addRow(m_connLabel, m_connEdit);

    m_modelLabel = new QLabel();
    auto* modelRow = new QHBoxLayout();
    m_modelBox = new QComboBox();
    m_modelBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    modelRow->addWidget(m_modelBox);
    m_refreshBtn = new QPushButton("↺");
    m_refreshBtn->setFixedWidth(28);
    m_refreshBtn->setObjectName("btn2");
    modelRow->addWidget(m_refreshBtn);
    modelForm->addRow(m_modelLabel, modelRow);

    m_tabs->addTab(modelPage, "");

    // Init connection field from saved config
    onProviderChanged(m_providerBox->currentIndex());
    if (!Config::get().model.isEmpty()) {
        m_modelBox->addItem(Config::get().model);
        m_modelBox->setCurrentText(Config::get().model);
    }

    // ── Bottom buttons ────────────────────────────────────────────────────
    auto* btnRow = new QHBoxLayout();
    btnRow->addStretch();
    m_cancelBtn = new QPushButton();
    m_cancelBtn->setObjectName("btn2");
    m_okBtn = new QPushButton();
    btnRow->addWidget(m_cancelBtn);
    btnRow->addWidget(m_okBtn);
    root->addLayout(btnRow);

    connect(m_providerBox, &QComboBox::currentIndexChanged, this, &ConfigDialog::onProviderChanged);
    connect(m_refreshBtn,  &QPushButton::clicked,           this, &ConfigDialog::onRefreshModels);
    connect(m_okBtn,       &QPushButton::clicked,           this, &ConfigDialog::onOk);
    connect(m_cancelBtn,   &QPushButton::clicked,           this, &ConfigDialog::close);
}

void ConfigDialog::retranslateUi() {
    setWindowTitle(tr("LibreAI — Configuration"));
    m_tabs->setTabText(0, tr("General Settings"));
    m_tabs->setTabText(1, tr("Model Selection"));
    m_langLabel->setText(tr("LANGUAGE"));
    m_logEnabledBox->setText(tr("Enable logging"));
    m_logLevelLabel->setText(tr("LEVEL"));
    m_providerLabel->setText(tr("PROVIDER"));
    m_modelLabel->setText(tr("MODEL"));
    m_okBtn->setText(tr("OK"));
    m_cancelBtn->setText(tr("Cancel"));

    // Connection label depends on current provider
    onProviderChanged(m_providerBox->currentIndex());
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
    )")
    .arg(C_BG, C_TEXT, C_MUTED, C_SURFACE, C_BORDER, C_BTN, C_BTN2));
}

void ConfigDialog::onProviderChanged(int index) {
    auto& cfg = Config::get();
    switch (static_cast<Provider>(index)) {
        case Provider::Ollama:
            m_connLabel->setText(tr("BASE URL"));
            m_connEdit->setText(cfg.ollamaUrl);
            m_connEdit->setEchoMode(QLineEdit::Normal);
            break;
        case Provider::OpenAI:
            m_connLabel->setText(tr("API KEY"));
            m_connEdit->setText(cfg.openaiKey);
            m_connEdit->setEchoMode(QLineEdit::Password);
            break;
        case Provider::Claude:
            m_connLabel->setText(tr("API KEY"));
            m_connEdit->setText(cfg.claudeKey);
            m_connEdit->setEchoMode(QLineEdit::Password);
            break;
    }
    m_modelBox->clear();
    if (!cfg.model.isEmpty()) {
        m_modelBox->addItem(cfg.model);
        m_modelBox->setCurrentText(cfg.model);
    }
}

void ConfigDialog::onRefreshModels() {
    delete m_client;
    auto& cfg = Config::get();
    switch (static_cast<Provider>(m_providerBox->currentIndex())) {
        case Provider::Ollama:
            m_client = new OllamaClient(m_connEdit->text(), this); break;
        case Provider::OpenAI:
            m_client = new OpenAIClient(cfg.openaiUrl, m_connEdit->text(), this); break;
        case Provider::Claude:
            m_client = new AnthropicClient(m_connEdit->text(), this); break;
    }
    connect(m_client, &AIClient::modelsReady, this, [this](QStringList models) {
        m_modelBox->clear();
        m_modelBox->addItems(models);
        auto saved = Config::get().model;
        if (!saved.isEmpty()) m_modelBox->setCurrentText(saved);
    });
    m_client->fetchModels();
}

void ConfigDialog::onOk() {
    auto& cfg = Config::get();

    // Save language
    int li = m_langBox->currentIndex();
    bool langChanged = (cfg.language != kLanguages[li].code);
    cfg.language = kLanguages[li].code;

    // Save model settings
    cfg.provider = static_cast<Provider>(m_providerBox->currentIndex());
    switch (cfg.provider) {
        case Provider::Ollama:  cfg.ollamaUrl = m_connEdit->text(); break;
        case Provider::OpenAI:  cfg.openaiKey = m_connEdit->text(); break;
        case Provider::Claude:  cfg.claudeKey = m_connEdit->text(); break;
    }
    cfg.model          = m_modelBox->currentText();
    cfg.loggingEnabled = m_logEnabledBox->isChecked();
    cfg.logLevel       = m_logLevelBox->currentIndex();
    cfg.save();
    initLogging();

    if (langChanged) {
        Config::applyLanguage();
        // Recreate windows so they open fresh in the new language next time
        ChatWindow::resetInstance();
        ConfigDialog::resetInstance();  // closes & deletes self — must be last
    } else {
        close();
    }
}
