#include "BatchRewriteDialog.hpp"
#include "../core/Config.hpp"

#include <QCheckBox>
#include <QComboBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QMessageBox>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QStackedWidget>
#include <QTableWidget>
#include <QTextEdit>
#include <QTimer>
#include <QVBoxLayout>

static const char* C_BG      = "#1E1E1E";
static const char* C_SURFACE = "#252526";
static const char* C_TEXT    = "#D4D4D4";
static const char* C_MUTED   = "#858585";
static const char* C_BTN     = "#0E639C";
static const char* C_BTN2    = "#3C3C3C";
static const char* C_SUCCESS = "#4EC9B0";
static const char* C_ERROR   = "#F44747";
static const char* C_BORDER  = "#3C3C3C";

BatchRewriteDialog::BatchRewriteDialog(const QString& instruction, QWidget* parent)
    : QDialog(parent)
    , m_instruction(instruction)
{
    setWindowTitle(tr("Batch Rewrite"));
    setMinimumSize(560, 460);

    m_stack = new QStackedWidget(this);
    buildSetupPage();
    buildProgressPage();
    buildResultsPage();

    auto* root = new QVBoxLayout(this);
    root->setContentsMargins(0, 0, 0, 0);
    root->addWidget(m_stack);

    applyStyle();

    // Start with scope = AllHeadings, detect immediately
    onScopeChanged(0);
}

// ── Page builders ─────────────────────────────────────────────────────────────

void BatchRewriteDialog::buildSetupPage() {
    auto* page = new QWidget;
    auto* vl   = new QVBoxLayout(page);
    vl->setSpacing(10);
    vl->setContentsMargins(20, 20, 20, 16);

    auto* titleLbl = new QLabel(tr("<b>Batch Rewrite — Confirm</b>"), page);
    titleLbl->setStyleSheet(QString("color:%1; font-size:14px;").arg(C_TEXT));
    vl->addWidget(titleLbl);

    auto* instrLbl = new QLabel(tr("Instruction:"), page);
    instrLbl->setStyleSheet(QString("color:%1;").arg(C_MUTED));
    vl->addWidget(instrLbl);
    m_instrEdit = new QTextEdit(page);
    m_instrEdit->setPlainText(m_instruction);
    m_instrEdit->setPlaceholderText(tr("e.g. Rewrite for clarity and brevity"));
    m_instrEdit->setMaximumHeight(62);
    vl->addWidget(m_instrEdit);

    // Scope selector
    auto* scopeRow = new QHBoxLayout;
    scopeRow->addWidget(new QLabel(tr("Scope:"), page));
    m_scopeCombo = new QComboBox(page);
    m_scopeCombo->addItem(tr("All headings"),  static_cast<int>(BatchScope::AllHeadings));
    m_scopeCombo->addItem(tr("H1 only"),       static_cast<int>(BatchScope::H1Only));
    m_scopeCombo->addItem(tr("H2 only"),       static_cast<int>(BatchScope::H2Only));
    m_scopeCombo->addItem(tr("H3 only"),       static_cast<int>(BatchScope::H3Only));
    m_scopeCombo->addItem(tr("Paragraphs"),    static_cast<int>(BatchScope::Paragraphs));
    connect(m_scopeCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &BatchRewriteDialog::onScopeChanged);
    scopeRow->addWidget(m_scopeCombo);
    scopeRow->addStretch();
    m_sectionCount = new QLabel(page);
    m_sectionCount->setStyleSheet(QString("color:%1;").arg(C_MUTED));
    scopeRow->addWidget(m_sectionCount);
    vl->addLayout(scopeRow);

    // Section table (preview)
    m_sectionTable = new QTableWidget(0, 3, page);
    m_sectionTable->setHorizontalHeaderLabels({ tr("Level"), tr("Title"), tr("Words") });
    m_sectionTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    m_sectionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_sectionTable->setSelectionMode(QAbstractItemView::NoSelection);
    m_sectionTable->verticalHeader()->setVisible(false);
    m_sectionTable->setMinimumHeight(160);
    vl->addWidget(m_sectionTable);

    m_costEstimate = new QLabel(page);
    m_costEstimate->setStyleSheet(QString("color:%1; font-size:11px;").arg(C_MUTED));
    vl->addWidget(m_costEstimate);

    vl->addStretch();

    // Buttons
    auto* btnRow = new QHBoxLayout;
    btnRow->addStretch();
    auto* cancelBtn  = new QPushButton(tr("Cancel"), page);
    auto* reviewBtn  = new QPushButton(tr("Review Each"), page);
    auto* applyBtn   = new QPushButton(tr("Apply to All"), page);
    applyBtn->setDefault(true);
    btnRow->addWidget(cancelBtn);
    btnRow->addWidget(reviewBtn);
    btnRow->addWidget(applyBtn);
    vl->addLayout(btnRow);

    connect(cancelBtn, &QPushButton::clicked, this, &QDialog::reject);
    connect(reviewBtn, &QPushButton::clicked, this, &BatchRewriteDialog::onReviewEach);
    connect(applyBtn,  &QPushButton::clicked, this, &BatchRewriteDialog::onApplyAll);

    m_stack->addWidget(page);
}

void BatchRewriteDialog::buildProgressPage() {
    auto* page = new QWidget;
    auto* vl   = new QVBoxLayout(page);
    vl->setSpacing(12);
    vl->setContentsMargins(20, 20, 20, 16);

    auto* titleLbl = new QLabel(tr("<b>Batch Rewrite — Processing</b>"), page);
    titleLbl->setStyleSheet(QString("color:%1; font-size:14px;").arg(C_TEXT));
    vl->addWidget(titleLbl);

    m_progressBar = new QProgressBar(page);
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(0);
    vl->addWidget(m_progressBar);

    m_progressLabel = new QLabel(tr("Starting…"), page);
    m_progressLabel->setStyleSheet(QString("color:%1;").arg(C_TEXT));
    vl->addWidget(m_progressLabel);

    m_timeLabel = new QLabel(tr("Elapsed: 0s"), page);
    m_timeLabel->setStyleSheet(QString("color:%1; font-size:11px;").arg(C_MUTED));
    vl->addWidget(m_timeLabel);

    // Review-mode widgets (hidden by default)
    m_reviewTitle = new QLabel(page);
    m_reviewTitle->setStyleSheet(QString("color:%1; font-weight:bold;").arg(C_TEXT));
    m_reviewTitle->hide();
    vl->addWidget(m_reviewTitle);

    m_reviewEdit = new QTextEdit(page);
    m_reviewEdit->setReadOnly(false);
    m_reviewEdit->setMinimumHeight(140);
    m_reviewEdit->hide();
    vl->addWidget(m_reviewEdit);

    auto* reviewBtnRow = new QHBoxLayout;
    m_acceptBtn = new QPushButton(tr("✓ Apply"), page);
    m_skipBtn   = new QPushButton(tr("✗ Skip"),  page);
    m_acceptBtn->hide();
    m_skipBtn->hide();
    reviewBtnRow->addStretch();
    reviewBtnRow->addWidget(m_skipBtn);
    reviewBtnRow->addWidget(m_acceptBtn);
    vl->addLayout(reviewBtnRow);

    connect(m_acceptBtn, &QPushButton::clicked, this, &BatchRewriteDialog::onAcceptSection);
    connect(m_skipBtn,   &QPushButton::clicked, this, &BatchRewriteDialog::onSkipSection);

    vl->addStretch();

    auto* bottomRow = new QHBoxLayout;
    bottomRow->addStretch();
    m_stopBtn = new QPushButton(tr("Stop"), page);
    bottomRow->addWidget(m_stopBtn);
    vl->addLayout(bottomRow);
    connect(m_stopBtn, &QPushButton::clicked, this, &BatchRewriteDialog::onStop);

    // Elapsed timer
    m_uiTimer = new QTimer(this);
    m_uiTimer->setInterval(1000);
    connect(m_uiTimer, &QTimer::timeout, this, [this] {
        ++m_elapsedSecs;
        m_timeLabel->setText(tr("Elapsed: %1s").arg(m_elapsedSecs));
    });

    m_stack->addWidget(page);
}

void BatchRewriteDialog::buildResultsPage() {
    auto* page = new QWidget;
    auto* vl   = new QVBoxLayout(page);
    vl->setSpacing(12);
    vl->setContentsMargins(20, 20, 20, 16);

    auto* titleLbl = new QLabel(tr("<b>Batch Rewrite — Complete</b>"), page);
    titleLbl->setStyleSheet(QString("color:%1; font-size:14px;").arg(C_TEXT));
    vl->addWidget(titleLbl);

    m_resultsLabel = new QLabel(page);
    m_resultsLabel->setWordWrap(true);
    m_resultsLabel->setStyleSheet(QString("color:%1;").arg(C_TEXT));
    vl->addWidget(m_resultsLabel);

    vl->addStretch();

    auto* btnRow = new QHBoxLayout;
    btnRow->addStretch();
    m_exportBtn = new QPushButton(tr("Export Log"), page);
    m_closeBtn  = new QPushButton(tr("Close"), page);
    m_closeBtn->setDefault(true);
    btnRow->addWidget(m_exportBtn);
    btnRow->addWidget(m_closeBtn);
    vl->addLayout(btnRow);

    connect(m_exportBtn, &QPushButton::clicked, this, &BatchRewriteDialog::onExportLog);
    connect(m_closeBtn,  &QPushButton::clicked, this, &BatchRewriteDialog::onClose);

    m_stack->addWidget(page);
}

// ── Style ─────────────────────────────────────────────────────────────────────

void BatchRewriteDialog::applyStyle() {
    setStyleSheet(QString(R"(
        QDialog, QWidget { background:%1; color:%2; }
        QLabel  { color:%2; }
        QComboBox {
            background:%3; color:%2; border:1px solid %5;
            padding:3px 6px; border-radius:3px;
        }
        QComboBox::drop-down { border:none; }
        QTableWidget { background:%3; color:%2; border:1px solid %5; gridline-color:%5; }
        QHeaderView::section { background:%3; color:%2; border:1px solid %5; padding:3px; }
        QProgressBar { background:%3; border:1px solid %5; border-radius:3px; height:16px; }
        QProgressBar::chunk { background:%6; border-radius:3px; }
        QTextEdit { background:%3; color:%2; border:1px solid %5; }
        QPushButton {
            background:%7; color:%2; border:none; padding:5px 14px; border-radius:3px;
        }
        QPushButton:hover   { background:#1177BB; }
        QPushButton:pressed { background:#0D5286; }
        QPushButton[flat="true"] { background:%8; }
        QPushButton[flat="true"]:hover { background:#4C4C4C; }
    )")
    .arg(C_BG, C_TEXT, C_SURFACE, C_MUTED, C_BORDER, C_BTN, C_BTN, C_BTN2));
}

// ── Slots ─────────────────────────────────────────────────────────────────────

void BatchRewriteDialog::onScopeChanged(int /*index*/) {
    auto scope = static_cast<BatchScope>(m_scopeCombo->currentData().toInt());
    m_sections = DocumentParser::detect(scope);
    refreshSectionTable();
}

void BatchRewriteDialog::refreshSectionTable() {
    m_sectionTable->setRowCount(0);
    for (const auto& s : m_sections) {
        int row = m_sectionTable->rowCount();
        m_sectionTable->insertRow(row);
        QString lvl = s.outlineLevel > 0 ? QString("H%1").arg(s.outlineLevel) : tr("¶");
        m_sectionTable->setItem(row, 0, new QTableWidgetItem(lvl));
        m_sectionTable->setItem(row, 1, new QTableWidgetItem(s.title));
        m_sectionTable->setItem(row, 2, new QTableWidgetItem(QString::number(s.wordsBefore)));
    }
    m_sectionCount->setText(tr("%1 sections detected").arg(m_sections.size()));

    // Rough cost estimate for paid providers (skipped for Ollama)
    int totalWords = 0;
    for (const auto& s : m_sections) totalWords += s.wordsBefore;
    double tokens = totalWords * 1.3;     // words → tokens rough ratio
    tokens += tokens * 0.6;               // estimate output ≈ 60% of input
    double cost = (tokens / 1000.0) * 0.00175;
    if (cost > 0.001)
        m_costEstimate->setText(tr("Estimated cost: ~$%1").arg(cost, 0, 'f', 3));
    else
        m_costEstimate->clear();
}

void BatchRewriteDialog::onApplyAll()   { startBatch(false); }
void BatchRewriteDialog::onReviewEach() { startBatch(true);  }

void BatchRewriteDialog::startBatch(bool reviewMode) {
    m_instruction = m_instrEdit->toPlainText().trimmed();
    if (m_instruction.isEmpty()) {
        QMessageBox::information(this, tr("No Instruction"),
            tr("Please enter an instruction before starting."));
        return;
    }
    if (m_sections.isEmpty()) {
        QMessageBox::information(this, tr("No Sections"),
            tr("No sections were detected in the document with the selected scope."));
        return;
    }

    showPage(1);
    m_elapsedSecs = 0;
    m_uiTimer->start();

    // Show review widgets only in review mode
    m_reviewTitle->setVisible(reviewMode);
    m_reviewEdit->setVisible(reviewMode);
    m_acceptBtn->setVisible(reviewMode);
    m_skipBtn->setVisible(reviewMode);

    m_processor = new BatchProcessor(this);
    connect(m_processor, &BatchProcessor::sectionDone,
            this, &BatchRewriteDialog::onSectionDone);
    connect(m_processor, &BatchProcessor::awaitingReview,
            this, &BatchRewriteDialog::onAwaitingReview);
    connect(m_processor, &BatchProcessor::batchCompleted,
            this, &BatchRewriteDialog::onBatchCompleted);
    connect(m_processor, &BatchProcessor::batchCancelled,
            this, &BatchRewriteDialog::onBatchCancelled);
    connect(m_processor, &BatchProcessor::errorOccurred,
            this, &BatchRewriteDialog::onBatchError);

    BatchProcessor::Config cfg;
    cfg.delayMs     = ::Config::get().batchDelayMs;
    cfg.timeoutSec  = ::Config::get().batchTimeoutSec;
    cfg.stopOnError = ::Config::get().batchStopOnError;
    m_processor->start(m_instruction, m_sections, cfg, reviewMode);
}

void BatchRewriteDialog::onStop() {
    if (m_processor) m_processor->cancel();
}

void BatchRewriteDialog::onAcceptSection() {
    if (m_processor) {
        // Update the section's rewritten text from whatever the user edited
        int idx = m_processor->currentIndex();
        if (idx < m_sections.size())
            m_sections[idx].rewrittenText = m_reviewEdit->toPlainText();
        m_processor->acceptCurrent();
    }
}

void BatchRewriteDialog::onSkipSection() {
    if (m_processor) m_processor->skipCurrent();
}

void BatchRewriteDialog::onSectionDone(int index, int total,
                                        const QString& title, bool success) {
    int pct = total > 0 ? (index + 1) * 100 / total : 100;
    m_progressBar->setValue(pct);
    QString status = success
        ? tr("✓ %1 (%2/%3)").arg(title).arg(index + 1).arg(total)
        : tr("✗ %1 (skipped)").arg(title);
    m_progressLabel->setText(status);
    m_progressLabel->setStyleSheet(
        QString("color:%1;").arg(success ? C_SUCCESS : C_ERROR));
}

void BatchRewriteDialog::onAwaitingReview(int index, int total,
                                           const QString& title,
                                           const QString& proposedText) {
    m_progressLabel->setText(tr("Review %1/%2: %3").arg(index + 1).arg(total).arg(title));
    m_reviewTitle->setText(tr("Proposed rewrite for: <b>%1</b>").arg(title));
    m_reviewEdit->setPlainText(proposedText);
    m_acceptBtn->setEnabled(true);
    m_skipBtn->setEnabled(true);
}

void BatchRewriteDialog::onBatchCompleted(int successCount, int errorCount) {
    m_uiTimer->stop();

    int totalWords = 0, rewrittenWords = 0;
    for (const auto& s : m_processor->sections()) {
        totalWords     += s.wordsBefore;
        rewrittenWords += s.wordsAfter;
    }

    int pctChange = totalWords > 0
        ? static_cast<int>((rewrittenWords - totalWords) * 100.0 / totalWords)
        : 0;
    QString sign  = pctChange >= 0 ? "+" : "";

    m_resultsLabel->setText(tr(
        "✓ Completed: %1 successful, %2 failed\n\n"
        "Words before: %3\n"
        "Words after:  %4 (%5%6%)\n"
        "Time elapsed: %7s")
        .arg(successCount)
        .arg(errorCount)
        .arg(totalWords)
        .arg(rewrittenWords)
        .arg(sign)
        .arg(pctChange)
        .arg(m_elapsedSecs));

    showPage(2);
}

void BatchRewriteDialog::onBatchCancelled() {
    m_uiTimer->stop();
    m_resultsLabel->setText(tr("Batch cancelled.\n%1 sections were processed.")
        .arg(m_processor->currentIndex()));
    showPage(2);
}

void BatchRewriteDialog::onBatchError(const QString& message) {
    m_progressLabel->setText(message);
    m_progressLabel->setStyleSheet(QString("color:%1;").arg(C_ERROR));
}

void BatchRewriteDialog::onClose()     { accept(); }

void BatchRewriteDialog::onExportLog() {
    if (!m_processor) return;
    QString path = QFileDialog::getSaveFileName(
        this, tr("Export Batch Log"), QString(), tr("JSON (*.json);;CSV (*.csv)"));
    if (path.isEmpty()) return;

    const auto& secs = m_processor->sections();

    if (path.endsWith(".csv", Qt::CaseInsensitive)) {
        QFile f(path);
        if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
        QTextStream out(&f);
        out << "index,title,level,words_before,words_after,success,error\n";
        for (int i = 0; i < secs.size(); ++i) {
            const auto& s = secs[i];
            out << i << ',' << '"' << s.title << '"' << ','
                << s.outlineLevel << ',' << s.wordsBefore << ',' << s.wordsAfter
                << ',' << (s.success ? "true" : "false")
                << ',' << '"' << s.errorMsg << '"' << '\n';
        }
    } else {
        QJsonArray arr;
        for (int i = 0; i < secs.size(); ++i) {
            const auto& s = secs[i];
            QJsonObject o;
            o["index"]        = i;
            o["title"]        = s.title;
            o["outline_level"]= s.outlineLevel;
            o["words_before"] = s.wordsBefore;
            o["words_after"]  = s.wordsAfter;
            o["success"]      = s.success;
            o["error"]        = s.errorMsg;
            arr.append(o);
        }
        QJsonObject root;
        root["instruction"] = m_instruction;
        root["sections"]    = arr;
        QFile f(path);
        if (!f.open(QIODevice::WriteOnly)) return;
        f.write(QJsonDocument(root).toJson());
    }
}

void BatchRewriteDialog::showPage(int idx) {
    m_stack->setCurrentIndex(idx);
}
