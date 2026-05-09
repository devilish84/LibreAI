#include "ImageGenDialog.hpp"
#include "../ai/GeminiImageClient.hpp"
#include "../ai/GrokImageClient.hpp"
#include "../ai/ImageClient.hpp"
#include "../ai/OllamaImageClient.hpp"
#include "../ai/OpenAIImageClient.hpp"
#include "../core/Config.hpp"
#include "../uno/UnoHelper.hpp"

#include <QComboBox>
#include <QEvent>
#include <QLabel>
#include <QLoggingCategory>
#include <QPixmap>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QVBoxLayout>

Q_LOGGING_CATEGORY(lcImgDlg, "libreai.imagedialog")

static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_BORDER  = "#3C3C3C";
static const char* C_ERROR   = "#F44747";
static const char* C_OK      = "#4EC9B0";

ImageGenDialog::ImageGenDialog(QWidget* parent) : QWidget(parent) {
    setMinimumSize(520, 600);
    setWindowFlags(Qt::Window);
    buildUi();
    applyTheme();
    retranslateUi();
}

ImageGenDialog::~ImageGenDialog() {
    delete m_client;
}

void ImageGenDialog::setContextHint(const QString& selectedText) {
    if (selectedText.isEmpty()) {
        m_contextLabel->hide();
        m_contextValue->hide();
    } else {
        QString preview = selectedText.length() > 120
            ? selectedText.left(120) + "…"
            : selectedText;
        m_contextValue->setText(preview);
        m_contextLabel->show();
        m_contextValue->show();
    }
}

void ImageGenDialog::buildUi() {
    auto* root = new QVBoxLayout(this);
    root->setSpacing(10);
    root->setContentsMargins(14, 14, 14, 14);

    // Optional context hint (selected text)
    m_contextLabel = new QLabel();
    m_contextLabel->setObjectName("sectionLabel");
    root->addWidget(m_contextLabel);

    m_contextValue = new QLabel();
    m_contextValue->setObjectName("contextValue");
    m_contextValue->setWordWrap(true);
    m_contextValue->setTextInteractionFlags(Qt::TextSelectableByMouse);
    root->addWidget(m_contextValue);

    // Prompt
    m_promptLabel = new QLabel();
    m_promptLabel->setObjectName("sectionLabel");
    root->addWidget(m_promptLabel);

    m_promptEdit = new QPlainTextEdit();
    m_promptEdit->setFixedHeight(90);
    m_promptEdit->setPlaceholderText("Describe the image…");
    root->addWidget(m_promptEdit);

    // Size selector
    auto* sizeRow = new QHBoxLayout();
    m_sizeLabel = new QLabel();
    sizeRow->addWidget(m_sizeLabel);
    m_sizeBox = new QComboBox();
    m_sizeBox->addItem("1024 × 1024",  QStringLiteral("1024x1024"));
    m_sizeBox->addItem("1792 × 1024",  QStringLiteral("1792x1024"));
    m_sizeBox->addItem("1024 × 1792",  QStringLiteral("1024x1792"));
    m_sizeBox->addItem("512 × 512",    QStringLiteral("512x512"));
    sizeRow->addWidget(m_sizeBox);
    sizeRow->addStretch();
    root->addLayout(sizeRow);

    // Generate button
    m_generateBtn = new QPushButton();
    root->addWidget(m_generateBtn);

    // Status line
    m_statusLabel = new QLabel();
    m_statusLabel->setObjectName("statusLabel");
    m_statusLabel->setWordWrap(true);
    root->addWidget(m_statusLabel);

    // Preview area
    m_previewScroll = new QScrollArea();
    m_previewScroll->setWidgetResizable(true);
    m_previewScroll->setMinimumHeight(260);
    m_previewLabel = new QLabel();
    m_previewLabel->setObjectName("previewLabel");
    m_previewLabel->setAlignment(Qt::AlignCenter);
    m_previewScroll->setWidget(m_previewLabel);
    root->addWidget(m_previewScroll, 1);

    // Bottom buttons
    auto* btnRow = new QHBoxLayout();
    btnRow->addStretch();
    m_insertBtn = new QPushButton();
    m_insertBtn->setEnabled(false);
    m_closeBtn = new QPushButton();
    m_closeBtn->setObjectName("btn2");
    btnRow->addWidget(m_insertBtn);
    btnRow->addWidget(m_closeBtn);
    root->addLayout(btnRow);

    connect(m_generateBtn, &QPushButton::clicked, this, &ImageGenDialog::onGenerate);
    connect(m_insertBtn,   &QPushButton::clicked, this, &ImageGenDialog::onInsert);
    connect(m_closeBtn,    &QPushButton::clicked, this, &QWidget::close);
}

ImageClient* ImageGenDialog::buildClient() const {
    const Config& cfg = Config::get();
    switch (cfg.imageProvider) {
        case Provider::Ollama:
            return new OllamaImageClient(
                cfg.ollamaUrl,
                OllamaAuthConfig::fromConfig());
        case Provider::OpenAI:
            return new OpenAIImageClient(cfg.openaiUrl, cfg.openaiKey);
        case Provider::Grok:
            return new GrokImageClient(cfg.grokKey, cfg.grokUrl);
        case Provider::Gemini:
            return new GeminiImageClient(cfg.geminiKey, cfg.geminiUrl);
        default:
            return new OpenAIImageClient(cfg.openaiUrl, cfg.openaiKey);
    }
}

void ImageGenDialog::setGenerating(bool on) {
    m_generateBtn->setEnabled(!on);
    m_insertBtn->setEnabled(false);
    m_statusLabel->setStyleSheet(QString("color: %1;").arg(C_MUTED));
    m_statusLabel->setText(on ? tr("Generating image…") : QString());
}

void ImageGenDialog::onGenerate() {
    const QString prompt = m_promptEdit->toPlainText().trimmed();
    if (prompt.isEmpty()) {
        m_statusLabel->setStyleSheet(QString("color: %1;").arg(C_ERROR));
        m_statusLabel->setText(tr("Please enter a prompt."));
        return;
    }

    const Config& cfg = Config::get();
    const QString& model = cfg.currentImageModel();
    if (model.isEmpty()) {
        m_statusLabel->setStyleSheet(QString("color: %1;").arg(C_ERROR));
        m_statusLabel->setText(tr("No image model selected. Configure one in Settings → Image Generation."));
        return;
    }

    qCInfo(lcImgDlg) << "onGenerate model=" << model;

    delete m_client;
    m_client = buildClient();
    m_client->setParent(this);

    connect(m_client, &ImageClient::imageReady,     this, &ImageGenDialog::onImageReady);
    connect(m_client, &ImageClient::errorOccurred,  this, &ImageGenDialog::onError);

    setGenerating(true);
    m_client->generateImage(model, prompt,
                            m_sizeBox->currentData().toString());
}

void ImageGenDialog::onImageReady(const QByteArray& pngData) {
    qCInfo(lcImgDlg) << "onImageReady, bytes=" << pngData.size();
    m_lastPng = pngData;

    QPixmap px;
    px.loadFromData(pngData);
    if (!px.isNull()) {
        // Scale to fit the preview area while keeping aspect ratio
        QSize maxSz = m_previewScroll->size() - QSize(8, 8);
        m_previewLabel->setPixmap(
            px.scaled(maxSz, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    m_statusLabel->setStyleSheet(QString("color: %1;").arg(C_OK));
    m_statusLabel->setText(tr("Image ready."));
    m_generateBtn->setEnabled(true);
    m_insertBtn->setEnabled(true);
}

void ImageGenDialog::onError(const QString& error) {
    qCWarning(lcImgDlg) << "onError:" << error;
    m_statusLabel->setStyleSheet(QString("color: %1;").arg(C_ERROR));
    m_statusLabel->setText(error);
    m_generateBtn->setEnabled(true);
}

void ImageGenDialog::onInsert() {
    if (m_lastPng.isEmpty()) return;
    qCInfo(lcImgDlg) << "onInsert, bytes=" << m_lastPng.size();
    UnoHelper::insertImage(m_lastPng);
    close();
}

void ImageGenDialog::retranslateUi() {
    setWindowTitle(tr("LibreAI — Generate Image"));
    m_contextLabel->setText(tr("SELECTED TEXT (CONTEXT)"));
    m_promptLabel->setText(tr("PROMPT"));
    m_sizeLabel->setText(tr("SIZE"));
    m_generateBtn->setText(tr("Generate"));
    m_insertBtn->setText(tr("Insert into Document"));
    m_closeBtn->setText(tr("Close"));
    m_previewLabel->setText(tr("Preview will appear here"));
}

void ImageGenDialog::changeEvent(QEvent* e) {
    if (e->type() == QEvent::LanguageChange) retranslateUi();
    QWidget::changeEvent(e);
}

void ImageGenDialog::applyTheme() {
    setStyleSheet(QString(R"(
        ImageGenDialog {
            background: %1;
        }
        QLabel {
            color: %3;
        }
        QLabel#sectionLabel {
            color: %5;
            font-size: 11px;
            font-weight: bold;
            text-transform: uppercase;
        }
        QLabel#contextValue {
            color: %3;
            font-size: 11px;
            background: %2;
            border: 1px solid %7;
            border-radius: 2px;
            padding: 4px 6px;
        }
        QLabel#previewLabel {
            color: %5;
            background: %2;
        }
        QLabel#statusLabel {
            color: %5;
            font-size: 11px;
        }
        QPlainTextEdit {
            background: %2;
            color: %3;
            border: 1px solid %7;
            border-radius: 2px;
            padding: 4px 6px;
        }
        QComboBox {
            background: %2;
            color: %3;
            border: 1px solid %7;
            border-radius: 2px;
            padding: 3px 6px;
        }
        QComboBox QAbstractItemView {
            background: %2;
            color: %3;
            selection-background-color: %6;
        }
        QPushButton {
            background: %6;
            color: white;
            border: none;
            border-radius: 2px;
            padding: 5px 14px;
            font-weight: bold;
        }
        QPushButton:hover  { background: #1177bb; }
        QPushButton:pressed{ background: #0a4f7d; }
        QPushButton:disabled { background: %7; color: %5; font-weight: normal; }
        QPushButton#btn2 {
            background: %7;
            color: %3;
            font-weight: normal;
        }
        QPushButton#btn2:hover { background: #4a4a4a; }
        QScrollArea {
            background: %2;
            border: 1px solid %7;
            border-radius: 2px;
        }
    )")
    .arg(C_BG, C_SURFACE, C_TEXT, C_MUTED, C_MUTED, C_BTN, C_BORDER));
}
