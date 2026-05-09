#include "ConfigDialog.hpp"
#include "ChatWindow.hpp"
#include "DualListWidget.hpp"
#include "../core/Config.hpp"
#include "../core/CredentialStore.hpp"
#include "../core/Logger.hpp"
#include "../ai/OllamaClient.hpp"
#include "../ai/OpenAIClient.hpp"
#include "../ai/AnthropicClient.hpp"
#include "../ai/GrokClient.hpp"
#include "../ai/GeminiClient.hpp"
#include "../ai/OllamaImageClient.hpp"
#include "../ai/OpenAIImageClient.hpp"
#include "../ai/GrokImageClient.hpp"
#include "../ai/GeminiImageClient.hpp"

#include <QCheckBox>
#include <QComboBox>
#include <QEvent>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QLoggingCategory>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QStackedWidget>
#include <QStandardPaths>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>

Q_LOGGING_CATEGORY(lcConfigDlg, "libreai.configdialog")

static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_BORDER  = "#3C3C3C";

static const struct { const char* code; const char* name; } kLanguages[] = {
    {"en", "English"}, {"fi", "Suomi"},  {"sv", "Svenska"},
    {"da", "Dansk"},   {"nb", "Norsk"},  {"es", "Español"},
    {"de", "Deutsch"}, {"pt", "Português"},
};
static const int kLangCount = static_cast<int>(sizeof(kLanguages) / sizeof(kLanguages[0]));

static const Provider kImgProviders[] = {
    Provider::Ollama, Provider::OpenAI, Provider::Grok, Provider::Gemini
};

ConfigDialog* ConfigDialog::s_instance = nullptr;

ConfigDialog* ConfigDialog::instance() {
    if (!s_instance) s_instance = new ConfigDialog();
    return s_instance;
}

void ConfigDialog::resetInstance() {
    if (s_instance) { s_instance->close(); delete s_instance; s_instance = nullptr; }
}

ConfigDialog::ConfigDialog(QWidget* parent) : QWidget(parent) {
    setMinimumSize(760, 600);
    resize(820, 660);
    setWindowFlags(Qt::Window);
    buildUi();
    applyTheme();
    retranslateUi();
}

// ── buildUi ───────────────────────────────────────────────────────────────────

void ConfigDialog::buildUi() {
    auto* root = new QVBoxLayout(this);
    root->setSpacing(10);
    root->setContentsMargins(14, 14, 14, 14);

    m_tabs = new QTabWidget();
    m_tabs->setObjectName("tabs");
    root->addWidget(m_tabs);

    {
        auto* p = new QWidget(); buildGeneralTab(p);   m_tabs->addTab(p, "");
    }
    {
        auto* p = new QWidget(); buildProvidersTab(p);  m_tabs->addTab(p, "");
    }
    {
        auto* p = new QWidget(); buildTextGenTab(p);    m_tabs->addTab(p, "");
    }
    {
        auto* p = new QWidget(); buildImageGenTab(p);   m_tabs->addTab(p, "");
    }

    connect(m_tabs, &QTabWidget::currentChanged, this, [this](int idx) {
        if (idx == 1 && m_providerCombo->currentIndex() == 0) onFetchOllamaModels();
        if (idx == 2) onTxtProviderChanged(m_txtProviderBox->currentIndex());
        if (idx == 3) onImgProviderChanged(m_imgProviderBox->currentIndex());
    });

    auto* btnRow = new QHBoxLayout();
    btnRow->addStretch();
    m_cancelBtn = new QPushButton(); m_cancelBtn->setObjectName("btn2");
    m_okBtn     = new QPushButton();
    btnRow->addWidget(m_cancelBtn);
    btnRow->addWidget(m_okBtn);
    root->addLayout(btnRow);

    connect(m_okBtn,     &QPushButton::clicked, this, &ConfigDialog::onOk);
    connect(m_cancelBtn, &QPushButton::clicked, this, &QWidget::close);
}

// ── General Settings tab ──────────────────────────────────────────────────────

void ConfigDialog::buildGeneralTab(QWidget* page) {
    auto* form = new QFormLayout(page);
    form->setSpacing(10);
    form->setContentsMargins(12, 14, 12, 10);

    m_langLabel = new QLabel();
    m_langBox   = new QComboBox();
    for (int i = 0; i < kLangCount; ++i)
        m_langBox->addItem(kLanguages[i].name, kLanguages[i].code);
    {
        const QString saved = Config::get().language;
        for (int i = 0; i < kLangCount; ++i)
            if (kLanguages[i].code == saved) { m_langBox->setCurrentIndex(i); break; }
    }
    form->addRow(m_langLabel, m_langBox);

    m_logEnabledBox = new QCheckBox();
    m_logEnabledBox->setChecked(Config::get().loggingEnabled);
    form->addRow(m_logEnabledBox);

    m_logLevelLabel = new QLabel();
    m_logLevelBox   = new QComboBox();
    m_logLevelBox->addItems({"Debug", "Info", "Error"});
    m_logLevelBox->setCurrentIndex(Config::get().logLevel);
    m_logLevelBox->setEnabled(Config::get().loggingEnabled);
    m_logLevelLabel->setEnabled(Config::get().loggingEnabled);
    form->addRow(m_logLevelLabel, m_logLevelBox);

    m_logMaxSizeLabel = new QLabel();
    m_logMaxSizeBox   = new QSpinBox();
    m_logMaxSizeBox->setRange(1, 500);
    m_logMaxSizeBox->setSuffix(" MB");
    m_logMaxSizeBox->setValue(Config::get().maxLogSizeMb);
    m_logMaxSizeBox->setEnabled(Config::get().loggingEnabled);
    m_logMaxSizeLabel->setEnabled(Config::get().loggingEnabled);
    form->addRow(m_logMaxSizeLabel, m_logMaxSizeBox);

    m_logPathLabel = new QLabel();
    m_logPathValue = new QLabel(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation)
        + "/libreai.log");
    m_logPathValue->setObjectName("muted");
    m_logPathValue->setWordWrap(true);
    m_logPathValue->setTextInteractionFlags(Qt::TextSelectableByMouse);
    form->addRow(m_logPathLabel, m_logPathValue);

    connect(m_logEnabledBox, &QCheckBox::toggled, this, [this](bool on) {
        m_logLevelBox->setEnabled(on);   m_logLevelLabel->setEnabled(on);
        m_logMaxSizeBox->setEnabled(on); m_logMaxSizeLabel->setEnabled(on);
    });
}

// ── Providers tab ─────────────────────────────────────────────────────────────

void ConfigDialog::buildProvidersTab(QWidget* page) {
    const Config& cfg = Config::get();

    auto* vbl = new QVBoxLayout(page);
    vbl->setSpacing(10);
    vbl->setContentsMargins(12, 12, 12, 8);

    // Provider selector row
    auto* selRow = new QHBoxLayout();
    auto* selLbl = new QLabel(tr("PROVIDER"));
    selLbl->setObjectName("fieldLabel");
    selRow->addWidget(selLbl);
    m_providerCombo = new QComboBox();
    m_providerCombo->setMinimumWidth(160);
    m_providerCombo->addItems({"Ollama", "OpenAI", "Claude", "Grok", "Gemini"});
    m_providerCombo->setCurrentIndex(0);
    selRow->addWidget(m_providerCombo);
    selRow->addStretch();
    vbl->addLayout(selRow);

    // Separator line
    auto* line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setObjectName("separator");
    vbl->addWidget(line);

    // Stacked widget — one page per provider
    m_providerStack = new QStackedWidget();
    vbl->addWidget(m_providerStack, 1);

    connect(m_providerCombo, &QComboBox::currentIndexChanged, this, [this](int idx) {
        m_providerStack->setCurrentIndex(idx);
        if (idx == 0) onFetchOllamaModels();  // Ollama selected — refresh model list
    });

    // Helper: scroll-wrap a widget
    auto scrolled = [](QWidget* inner) {
        auto* sa = new QScrollArea();
        sa->setWidgetResizable(true);
        sa->setFrameShape(QFrame::NoFrame);
        sa->setWidget(inner);
        return sa;
    };

    // Helper: form field row
    auto addField = [](QFormLayout* f, const QString& lbl,
                       QLineEdit* edit) {
        f->addRow(new QLabel(lbl), edit);
    };

    // ── Ollama page ───────────────────────────────────────────────────────
    {
        auto* inner = new QWidget();
        auto* vb    = new QVBoxLayout(inner);
        vb->setSpacing(10);
        vb->setContentsMargins(4, 4, 4, 4);

        auto* credForm = new QFormLayout();
        credForm->setSpacing(8);

        m_ollamaUrlEdit = new QLineEdit(cfg.ollamaUrl);
        addField(credForm, tr("BASE URL"), m_ollamaUrlEdit);

        auto* authLbl = new QLabel(tr("AUTH"));
        m_ollamaAuthBox = new QComboBox();
        m_ollamaAuthBox->addItems({"None", "Basic Auth", "API Key"});
        m_ollamaAuthBox->setCurrentIndex(static_cast<int>(cfg.ollamaAuth));
        credForm->addRow(authLbl, m_ollamaAuthBox);

        m_ollamaUserEdit = new QLineEdit(cfg.ollamaBasicUser);
        addField(credForm, tr("USERNAME"), m_ollamaUserEdit);

        m_ollamaPassEdit = new QLineEdit(cfg.ollamaBasicPass);
        m_ollamaPassEdit->setEchoMode(QLineEdit::Password);
        addField(credForm, tr("PASSWORD"), m_ollamaPassEdit);

        m_ollamaKeyHeaderEdit = new QLineEdit(cfg.ollamaApiKeyHeader);
        addField(credForm, tr("HEADER"), m_ollamaKeyHeaderEdit);

        m_ollamaKeyValueEdit = new QLineEdit(cfg.ollamaApiKeyValue);
        m_ollamaKeyValueEdit->setEchoMode(QLineEdit::Password);
        addField(credForm, tr("API KEY"), m_ollamaKeyValueEdit);

        vb->addLayout(credForm);

        // Fetch button
        auto* fetchRow = new QHBoxLayout();
        fetchRow->addStretch();
        m_ollamaFetchBtn = new QPushButton("↺  " + tr("Fetch Models"));
        m_ollamaFetchBtn->setObjectName("btn2");
        fetchRow->addWidget(m_ollamaFetchBtn);
        vb->addLayout(fetchRow);

        // Dual list — Text Generation models
        m_ollamaTextList = new DualListWidget(tr("TEXT GENERATION MODELS"));
        m_ollamaTextList->setModels({}, cfg.ollamaTextModels);
        vb->addWidget(m_ollamaTextList);

        // Dual list — Image Generation models
        m_ollamaImgList = new DualListWidget(tr("IMAGE GENERATION MODELS"));
        m_ollamaImgList->setModels({}, cfg.ollamaImageModels);
        vb->addWidget(m_ollamaImgList);

        m_providerStack->addWidget(scrolled(inner));

        // Hint: classifications are persisted
        auto* saveHint = new QLabel(
            tr("Model classifications are saved in config.json and restored on next launch."));
        saveHint->setObjectName("keychainHint");
        saveHint->setWordWrap(true);
        vb->addWidget(saveHint);

        connect(m_ollamaAuthBox, &QComboBox::currentIndexChanged,
                this, &ConfigDialog::onOllamaAuthChanged);
        connect(m_ollamaFetchBtn, &QPushButton::clicked,
                this, &ConfigDialog::onFetchOllamaModels);
        onOllamaAuthChanged(m_ollamaAuthBox->currentIndex());
    }

    // ── OpenAI page ───────────────────────────────────────────────────────
    {
        auto* inner = new QWidget();
        auto* form  = new QFormLayout(inner);
        form->setSpacing(8);
        form->setContentsMargins(4, 4, 4, 4);
        m_openaiUrlEdit = new QLineEdit(cfg.openaiUrl);
        m_openaiKeyEdit = new QLineEdit(cfg.openaiKey);
        m_openaiKeyEdit->setEchoMode(QLineEdit::Password);
        addField(form, tr("BASE URL"), m_openaiUrlEdit);
        addField(form, tr("API KEY"),  m_openaiKeyEdit);
        m_providerStack->addWidget(scrolled(inner));
    }

    // ── Claude page ───────────────────────────────────────────────────────
    {
        auto* inner = new QWidget();
        auto* form  = new QFormLayout(inner);
        form->setSpacing(8);
        form->setContentsMargins(4, 4, 4, 4);
        m_claudeUrlEdit = new QLineEdit(cfg.claudeUrl);
        m_claudeKeyEdit = new QLineEdit(cfg.claudeKey);
        m_claudeKeyEdit->setEchoMode(QLineEdit::Password);
        addField(form, tr("BASE URL"), m_claudeUrlEdit);
        addField(form, tr("API KEY"),  m_claudeKeyEdit);
        m_providerStack->addWidget(scrolled(inner));
    }

    // ── Grok page ─────────────────────────────────────────────────────────
    {
        auto* inner = new QWidget();
        auto* form  = new QFormLayout(inner);
        form->setSpacing(8);
        form->setContentsMargins(4, 4, 4, 4);
        m_grokUrlEdit = new QLineEdit(cfg.grokUrl);
        m_grokKeyEdit = new QLineEdit(cfg.grokKey);
        m_grokKeyEdit->setEchoMode(QLineEdit::Password);
        addField(form, tr("BASE URL"), m_grokUrlEdit);
        addField(form, tr("API KEY"),  m_grokKeyEdit);
        m_providerStack->addWidget(scrolled(inner));
    }

    // ── Gemini page ───────────────────────────────────────────────────────
    {
        auto* inner = new QWidget();
        auto* form  = new QFormLayout(inner);
        form->setSpacing(8);
        form->setContentsMargins(4, 4, 4, 4);
        m_geminiUrlEdit = new QLineEdit(cfg.geminiUrl);
        m_geminiKeyEdit = new QLineEdit(cfg.geminiKey);
        m_geminiKeyEdit->setEchoMode(QLineEdit::Password);
        addField(form, tr("BASE URL"), m_geminiUrlEdit);
        addField(form, tr("API KEY"),  m_geminiKeyEdit);
        m_providerStack->addWidget(scrolled(inner));
    }

    // Keychain hint
    m_keychainHint = new QLabel();
    m_keychainHint->setObjectName("keychainHint");
    m_keychainHint->setWordWrap(true);
    m_keychainHint->setVisible(!CredentialStore::isAvailable());
    vbl->addWidget(m_keychainHint);
}

// ── Text Generation tab ───────────────────────────────────────────────────────

void ConfigDialog::buildTextGenTab(QWidget* page) {
    auto* form = new QFormLayout(page);
    form->setSpacing(10);
    form->setContentsMargins(12, 14, 12, 10);

    auto* provLbl = new QLabel(tr("PROVIDER"));
    m_txtProviderBox = new QComboBox();
    m_txtProviderBox->addItems({"Ollama", "OpenAI", "Claude", "Grok", "Gemini"});
    m_txtProviderBox->setCurrentIndex(static_cast<int>(Config::get().provider));
    form->addRow(provLbl, m_txtProviderBox);

    auto* modelLbl = new QLabel(tr("MODEL"));
    auto* modelRow = new QHBoxLayout();
    m_txtModelBox = new QComboBox();
    m_txtModelBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    modelRow->addWidget(m_txtModelBox);
    m_txtRefreshBtn = new QPushButton("↺");
    m_txtRefreshBtn->setFixedWidth(28);
    m_txtRefreshBtn->setObjectName("btn2");
    modelRow->addWidget(m_txtRefreshBtn);
    form->addRow(modelLbl, modelRow);

    auto* txtDesc = new QLabel(tr("Select the provider and model to use for text generation and chat."));
    txtDesc->setObjectName("keychainHint");
    txtDesc->setWordWrap(true);
    form->addRow(txtDesc);

    m_txtOllamaHint = new QLabel(
        tr("For Ollama: assign models in the Providers tab, then return here."));
    m_txtOllamaHint->setObjectName("keychainHint");
    m_txtOllamaHint->setWordWrap(true);
    m_txtOllamaHint->hide();
    form->addRow(m_txtOllamaHint);

    connect(m_txtProviderBox, &QComboBox::currentIndexChanged,
            this, &ConfigDialog::onTxtProviderChanged);
    connect(m_txtRefreshBtn, &QPushButton::clicked,
            this, &ConfigDialog::onTxtRefreshModels);

    onTxtProviderChanged(m_txtProviderBox->currentIndex());
}

// ── Image Generation tab ──────────────────────────────────────────────────────

void ConfigDialog::buildImageGenTab(QWidget* page) {
    auto* form = new QFormLayout(page);
    form->setSpacing(10);
    form->setContentsMargins(12, 14, 12, 10);

    auto* provLbl = new QLabel(tr("PROVIDER"));
    m_imgProviderBox = new QComboBox();
    m_imgProviderBox->addItems({"Ollama", "OpenAI", "Grok", "Gemini"});
    {
        int sel = 1;
        for (int i = 0; i < 4; ++i)
            if (kImgProviders[i] == Config::get().imageProvider) { sel = i; break; }
        m_imgProviderBox->setCurrentIndex(sel);
    }
    form->addRow(provLbl, m_imgProviderBox);

    auto* modelLbl = new QLabel(tr("MODEL"));
    auto* modelRow = new QHBoxLayout();
    m_imgModelBox = new QComboBox();
    m_imgModelBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    modelRow->addWidget(m_imgModelBox);
    m_imgRefreshBtn = new QPushButton("↺");
    m_imgRefreshBtn->setFixedWidth(28);
    m_imgRefreshBtn->setObjectName("btn2");
    modelRow->addWidget(m_imgRefreshBtn);
    form->addRow(modelLbl, modelRow);

    auto* imgDesc = new QLabel(tr("Select the provider and model to use for image generation."));
    imgDesc->setObjectName("keychainHint");
    imgDesc->setWordWrap(true);
    form->addRow(imgDesc);

    m_imgOllamaHint = new QLabel(
        tr("For Ollama: assign models in the Providers tab, then return here."));
    m_imgOllamaHint->setObjectName("keychainHint");
    m_imgOllamaHint->setWordWrap(true);
    m_imgOllamaHint->hide();
    form->addRow(m_imgOllamaHint);

    connect(m_imgProviderBox, &QComboBox::currentIndexChanged,
            this, &ConfigDialog::onImgProviderChanged);
    connect(m_imgRefreshBtn, &QPushButton::clicked,
            this, &ConfigDialog::onImgRefreshModels);

    onImgProviderChanged(m_imgProviderBox->currentIndex());
}

// ── Providers slots ───────────────────────────────────────────────────────────

void ConfigDialog::onOllamaAuthChanged(int index) {
    bool isBasic  = (index == static_cast<int>(OllamaAuth::Basic));
    bool isApiKey = (index == static_cast<int>(OllamaAuth::ApiKey));
    m_ollamaUserEdit->setVisible(isBasic);
    m_ollamaPassEdit->setVisible(isBasic);
    m_ollamaKeyHeaderEdit->setVisible(isApiKey);
    m_ollamaKeyValueEdit->setVisible(isApiKey);
    // Hide matching form labels via QFormLayout traversal
    auto hideLabel = [](QLineEdit* edit, bool show) {
        auto* w = edit->parentWidget();
        if (!w) return;
        auto* fl = qobject_cast<QFormLayout*>(w->layout());
        if (!fl) return;
        for (int i = 0; i < fl->rowCount(); ++i) {
            auto* fi = fl->itemAt(i, QFormLayout::FieldRole);
            if (fi && fi->widget() == edit) {
                auto* li = fl->itemAt(i, QFormLayout::LabelRole);
                if (li && li->widget()) li->widget()->setVisible(show);
                break;
            }
        }
    };
    hideLabel(m_ollamaUserEdit,      isBasic);
    hideLabel(m_ollamaPassEdit,      isBasic);
    hideLabel(m_ollamaKeyHeaderEdit, isApiKey);
    hideLabel(m_ollamaKeyValueEdit,  isApiKey);
}

void ConfigDialog::onFetchOllamaModels() {
    qCInfo(lcConfigDlg) << "onFetchOllamaModels";
    delete m_ollamaFetchClient;
    OllamaAuthConfig auth;
    auth.type         = static_cast<OllamaAuth>(m_ollamaAuthBox->currentIndex());
    auth.basicUser    = m_ollamaUserEdit->text();
    auth.basicPass    = m_ollamaPassEdit->text();
    auth.apiKeyHeader = m_ollamaKeyHeaderEdit->text();
    auth.apiKeyValue  = m_ollamaKeyValueEdit->text();
    m_ollamaFetchClient = new OllamaClient(m_ollamaUrlEdit->text(), auth, this);

    connect(m_ollamaFetchClient, &AIClient::modelsReady, this, [this](QStringList models) {
        qCInfo(lcConfigDlg) << "Ollama all models count=" << models.size();
        m_ollamaTextList->setModels(models, m_ollamaTextList->selectedModels());
        m_ollamaImgList->setModels(models,  m_ollamaImgList->selectedModels());
        m_ollamaFetchBtn->setEnabled(true);
    });
    connect(m_ollamaFetchClient, &AIClient::errorOccurred, this, [this](const QString& err) {
        qCWarning(lcConfigDlg) << "Ollama fetch error:" << err;
        m_ollamaFetchBtn->setEnabled(true);
    });
    m_ollamaFetchBtn->setEnabled(false);
    m_ollamaFetchClient->fetchAllModels();
}

// ── Text Generation slots ─────────────────────────────────────────────────────

QString ConfigDialog::credentialForProvider(Provider p) const {
    switch (p) {
        case Provider::Ollama:  return m_ollamaUrlEdit->text();
        case Provider::OpenAI:  return m_openaiKeyEdit->text();
        case Provider::Claude:  return m_claudeKeyEdit->text();
        case Provider::Grok:    return m_grokKeyEdit->text();
        case Provider::Gemini:  return m_geminiKeyEdit->text();
    }
    return {};
}

void ConfigDialog::onTxtProviderChanged(int index) {
    m_txtModelBox->clear();
    auto p = static_cast<Provider>(index);
    const Config& cfg = Config::get();

    if (p == Provider::Ollama) {
        QStringList models = m_ollamaTextList->selectedModels();
        m_txtModelBox->addItems(models);
        if (!cfg.ollamaModel.isEmpty()) m_txtModelBox->setCurrentText(cfg.ollamaModel);
        m_txtOllamaHint->setVisible(models.isEmpty());
        m_txtRefreshBtn->setEnabled(false);
        return;
    }
    m_txtOllamaHint->hide();

    bool hasCred = !credentialForProvider(p).trimmed().isEmpty();
    m_txtModelBox->setEnabled(hasCred);
    m_txtRefreshBtn->setEnabled(hasCred);

    QString saved;
    switch (p) {
        case Provider::OpenAI: saved = cfg.openaiModel; break;
        case Provider::Claude: saved = cfg.claudeModel; break;
        case Provider::Grok:   saved = cfg.grokModel;   break;
        case Provider::Gemini: saved = cfg.geminiModel; break;
        default: break;
    }
    if (!saved.isEmpty()) { m_txtModelBox->addItem(saved); m_txtModelBox->setCurrentText(saved); }
    if (hasCred && m_tabs->currentIndex() == 2) onTxtRefreshModels();
}

void ConfigDialog::onTxtRefreshModels() {
    qCInfo(lcConfigDlg) << "onTxtRefreshModels";
    delete m_txtClient; m_txtClient = nullptr;

    switch (static_cast<Provider>(m_txtProviderBox->currentIndex())) {
        case Provider::Ollama: return;
        case Provider::OpenAI:
            m_txtClient = new OpenAIClient(m_openaiUrlEdit->text(), m_openaiKeyEdit->text(), this); break;
        case Provider::Claude:
            m_txtClient = new AnthropicClient(m_claudeKeyEdit->text(), m_claudeUrlEdit->text(), this); break;
        case Provider::Grok:
            m_txtClient = new GrokClient(m_grokKeyEdit->text(), m_grokUrlEdit->text(), this); break;
        case Provider::Gemini:
            m_txtClient = new GeminiClient(m_geminiKeyEdit->text(), m_geminiUrlEdit->text(), this); break;
    }

    connect(m_txtClient, &AIClient::modelsReady, this, [this](QStringList models) {
        m_txtModelBox->setEnabled(true);
        m_txtRefreshBtn->setEnabled(true);
        m_txtModelBox->clear();
        m_txtModelBox->addItems(models);
        const QString saved = Config::get().currentModel();
        if (!saved.isEmpty()) m_txtModelBox->setCurrentText(saved);
    });
    connect(m_txtClient, &AIClient::errorOccurred, this, [this](const QString& err) {
        qCWarning(lcConfigDlg) << "Text model fetch error:" << err;
        m_txtRefreshBtn->setEnabled(true);
    });
    m_txtRefreshBtn->setEnabled(false);
    m_txtClient->fetchModels();
}

// ── Image Generation slots ────────────────────────────────────────────────────

void ConfigDialog::onImgProviderChanged(int index) {
    if (index < 0 || index > 3) return;
    Provider p = kImgProviders[index];
    const Config& cfg = Config::get();
    m_imgModelBox->clear();

    if (p == Provider::Ollama) {
        QStringList models = m_ollamaImgList->selectedModels();
        m_imgModelBox->addItems(models);
        if (!cfg.ollamaImageModel.isEmpty()) m_imgModelBox->setCurrentText(cfg.ollamaImageModel);
        m_imgOllamaHint->setVisible(models.isEmpty());
        m_imgRefreshBtn->setEnabled(false);
        return;
    }
    m_imgOllamaHint->hide();

    bool hasCred = !credentialForProvider(p).trimmed().isEmpty();
    m_imgModelBox->setEnabled(hasCred);
    m_imgRefreshBtn->setEnabled(hasCred);

    QString saved;
    switch (p) {
        case Provider::OpenAI:  saved = cfg.openaiImageModel;  break;
        case Provider::Grok:    saved = cfg.grokImageModel;    break;
        case Provider::Gemini:  saved = cfg.geminiImageModel;  break;
        default: break;
    }
    if (!saved.isEmpty()) { m_imgModelBox->addItem(saved); m_imgModelBox->setCurrentText(saved); }
    if (hasCred && m_tabs->currentIndex() == 3) onImgRefreshModels();
}

void ConfigDialog::onImgRefreshModels() {
    qCInfo(lcConfigDlg) << "onImgRefreshModels";
    delete m_imgClient; m_imgClient = nullptr;
    int index = m_imgProviderBox->currentIndex();
    if (index < 0 || index > 3) return;
    Provider p = kImgProviders[index];
    if (p == Provider::Ollama) return;

    switch (p) {
        case Provider::OpenAI:
            m_imgClient = new OpenAIImageClient(m_openaiUrlEdit->text(), m_openaiKeyEdit->text(), this); break;
        case Provider::Grok:
            m_imgClient = new GrokImageClient(m_grokKeyEdit->text(), m_grokUrlEdit->text(), this); break;
        case Provider::Gemini:
            m_imgClient = new GeminiImageClient(m_geminiKeyEdit->text(), m_geminiUrlEdit->text(), this); break;
        default: return;
    }

    connect(m_imgClient, &ImageClient::imageModelsReady, this, [this](QStringList models) {
        m_imgModelBox->setEnabled(true);
        m_imgRefreshBtn->setEnabled(true);
        m_imgModelBox->clear();
        m_imgModelBox->addItems(models);
        const QString saved = Config::get().currentImageModel();
        if (!saved.isEmpty()) m_imgModelBox->setCurrentText(saved);
    });
    connect(m_imgClient, &ImageClient::errorOccurred, this, [this](const QString& err) {
        qCWarning(lcConfigDlg) << "Image model fetch error:" << err;
        m_imgRefreshBtn->setEnabled(true);
    });
    m_imgRefreshBtn->setEnabled(false);
    m_imgClient->fetchImageModels();
}

// ── onOk ─────────────────────────────────────────────────────────────────────

void ConfigDialog::onOk() {
    auto& cfg = Config::get();

    // General
    int li = m_langBox->currentIndex();
    bool langChanged   = (cfg.language != kLanguages[li].code);
    cfg.language       = kLanguages[li].code;
    cfg.loggingEnabled = m_logEnabledBox->isChecked();
    cfg.logLevel       = m_logLevelBox->currentIndex();
    cfg.maxLogSizeMb   = m_logMaxSizeBox->value();

    // Providers
    cfg.ollamaUrl          = m_ollamaUrlEdit->text();
    cfg.ollamaAuth         = static_cast<OllamaAuth>(m_ollamaAuthBox->currentIndex());
    cfg.ollamaBasicUser    = m_ollamaUserEdit->text();
    cfg.ollamaBasicPass    = m_ollamaPassEdit->text();
    cfg.ollamaApiKeyHeader = m_ollamaKeyHeaderEdit->text();
    cfg.ollamaApiKeyValue  = m_ollamaKeyValueEdit->text();
    cfg.openaiUrl          = m_openaiUrlEdit->text();
    cfg.openaiKey          = m_openaiKeyEdit->text();
    cfg.claudeUrl          = m_claudeUrlEdit->text();
    cfg.claudeKey          = m_claudeKeyEdit->text();
    cfg.grokUrl            = m_grokUrlEdit->text();
    cfg.grokKey            = m_grokKeyEdit->text();
    cfg.geminiUrl          = m_geminiUrlEdit->text();
    cfg.geminiKey          = m_geminiKeyEdit->text();

    // Ollama model lists
    cfg.ollamaTextModels  = m_ollamaTextList->selectedModels();
    cfg.ollamaImageModels = m_ollamaImgList->selectedModels();

    // Text Generation
    cfg.provider = static_cast<Provider>(m_txtProviderBox->currentIndex());
    switch (cfg.provider) {
        case Provider::Ollama:  cfg.ollamaModel  = m_txtModelBox->currentText(); break;
        case Provider::OpenAI:  cfg.openaiModel  = m_txtModelBox->currentText(); break;
        case Provider::Claude:  cfg.claudeModel  = m_txtModelBox->currentText(); break;
        case Provider::Grok:    cfg.grokModel    = m_txtModelBox->currentText(); break;
        case Provider::Gemini:  cfg.geminiModel  = m_txtModelBox->currentText(); break;
    }

    // Image Generation
    {
        int ii = m_imgProviderBox->currentIndex();
        if (ii >= 0 && ii <= 3) {
            cfg.imageProvider = kImgProviders[ii];
            switch (cfg.imageProvider) {
                case Provider::Ollama:  cfg.ollamaImageModel  = m_imgModelBox->currentText(); break;
                case Provider::OpenAI:  cfg.openaiImageModel  = m_imgModelBox->currentText(); break;
                case Provider::Grok:    cfg.grokImageModel    = m_imgModelBox->currentText(); break;
                case Provider::Gemini:  cfg.geminiImageModel  = m_imgModelBox->currentText(); break;
                default: break;
            }
        }
    }

    cfg.save();
    initLogging();

    if (langChanged) {
        Config::applyLanguage();
        ChatWindow::resetInstance();
        ConfigDialog::resetInstance();
    } else {
        close();
    }
}

// ── retranslateUi / changeEvent / applyTheme ─────────────────────────────────

void ConfigDialog::retranslateUi() {
    setWindowTitle(tr("LibreAI — Configuration"));
    m_tabs->setTabText(0, tr("General Settings"));
    m_tabs->setTabText(1, tr("Providers"));
    m_tabs->setTabText(2, tr("Text Generation"));
    m_tabs->setTabText(3, tr("Image Generation"));

    m_langLabel->setText(tr("LANGUAGE"));
    m_logEnabledBox->setText(tr("Enable verbose logging"));
    m_logLevelLabel->setText(tr("LEVEL"));
    m_logMaxSizeLabel->setText(tr("MAX SIZE"));
    m_logPathLabel->setText(tr("LOG FILE"));

    if (m_keychainHint)
        m_keychainHint->setText(tr("Keychain unavailable — credentials will not be saved between sessions"));

    m_ollamaTextList->setTitle(tr("TEXT GENERATION MODELS"));
    m_ollamaImgList->setTitle(tr("IMAGE GENERATION MODELS"));

    m_okBtn->setText(tr("OK"));
    m_cancelBtn->setText(tr("Cancel"));
}

void ConfigDialog::changeEvent(QEvent* e) {
    if (e->type() == QEvent::LanguageChange) retranslateUi();
    QWidget::changeEvent(e);
}

void ConfigDialog::applyTheme() {
    setStyleSheet(QString(R"(
        ConfigDialog { background: %1; }
        QTabWidget::pane { border: 1px solid %7; background: %1; }
        QTabBar::tab {
            background: %6; color: %3; padding: 6px 16px;
            border: 1px solid %7; border-bottom: none;
        }
        QTabBar::tab:selected { background: %1; color: %3; }
        QLabel { color: %3; }
        QLabel#muted, QLabel#keychainHint { color: %4; font-size: 11px; }
        QLabel#sectionHdr, QLabel#fieldLabel { color: %4; font-size: 11px; font-weight: bold; }
        QComboBox, QLineEdit {
            background: %2; color: %3; border: 1px solid %7;
            border-radius: 2px; padding: 3px 6px;
        }
        QComboBox QAbstractItemView { background: %2; color: %3; selection-background-color: %5; }
        QPushButton {
            background: %5; color: white; border: none; border-radius: 2px;
            padding: 5px 12px; font-weight: bold;
        }
        QPushButton:hover  { background: #1177bb; }
        QPushButton:pressed{ background: #0a4f7d; }
        QPushButton#btn2 { background: %6; color: %3; font-weight: normal; }
        QPushButton#btn2:hover { background: #4a4a4a; }
        QCheckBox { color: %3; spacing: 6px; }
        QCheckBox::indicator { width: 14px; height: 14px; border: 1px solid %7; border-radius: 2px; background: %2; }
        QCheckBox::indicator:checked { background: %5; border-color: %5; }
        QLabel:disabled, QComboBox:disabled { color: %4; }
        QComboBox:disabled { background: %6; }
        QSpinBox { background: %2; color: %3; border: 1px solid %7; border-radius: 2px; padding: 3px 6px; }
        QSpinBox:disabled { color: %4; background: %6; }
        QListWidget {
            background: %2; color: %3; border: 1px solid %7; border-radius: 2px;
            outline: none;
        }
        QListWidget::item { padding: 3px 6px; }
        QListWidget::item:selected { background: %5; color: white; }
        QScrollArea { background: %1; border: none; }
        QScrollArea > QWidget > QWidget { background: %1; }
        QFrame#separator { color: %7; }
    )")
    .arg(C_BG, C_SURFACE, C_TEXT, C_MUTED, C_BTN, C_BTN2, C_BORDER));
}
