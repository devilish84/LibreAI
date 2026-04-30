#pragma once
#include <QDialog>
#include "../core/BatchProcessor.hpp"
#include "../uno/DocumentParser.hpp"

class QCheckBox;
class QComboBox;
class QLabel;
class QProgressBar;
class QPushButton;
class QRadioButton;
class QStackedWidget;
class QTableWidget;
class QTextEdit;

class BatchRewriteDialog : public QDialog {
    Q_OBJECT
public:
    // instruction may be empty — user can type it in the dialog.
    explicit BatchRewriteDialog(const QString& instruction = {}, QWidget* parent = nullptr);

private slots:
    void onScopeChanged(int index);
    void onApplyAll();
    void onReviewEach();
    void onStop();
    void onAcceptSection();
    void onSkipSection();
    void onClose();
    void onExportLog();

    // BatchProcessor signals
    void onSectionDone(int index, int total, const QString& title, bool success);
    void onAwaitingReview(int index, int total,
                          const QString& title, const QString& proposedText);
    void onBatchCompleted(int successCount, int errorCount);
    void onBatchCancelled();
    void onBatchError(const QString& message);

private:
    void buildSetupPage();
    void buildProgressPage();
    void buildResultsPage();
    void applyStyle();
    void refreshSectionTable();
    void startBatch(bool reviewMode);
    void showPage(int idx);

    // Pages
    QStackedWidget* m_stack         = nullptr;

    // Page 0 — Setup/Confirm
    QTextEdit*      m_instrEdit     = nullptr;
    QComboBox*      m_scopeCombo    = nullptr;
    QTableWidget*   m_sectionTable  = nullptr;
    QLabel*         m_sectionCount  = nullptr;
    QLabel*         m_costEstimate  = nullptr;

    // Page 1 — Progress
    QProgressBar*   m_progressBar   = nullptr;
    QLabel*         m_progressLabel = nullptr;
    QLabel*         m_timeLabel     = nullptr;
    QPushButton*    m_stopBtn       = nullptr;
    // Review-mode widgets (shown only in review mode)
    QTextEdit*      m_reviewEdit    = nullptr;
    QLabel*         m_reviewTitle   = nullptr;
    QPushButton*    m_acceptBtn     = nullptr;
    QPushButton*    m_skipBtn       = nullptr;

    // Page 2 — Results
    QLabel*         m_resultsLabel  = nullptr;
    QPushButton*    m_closeBtn      = nullptr;
    QPushButton*    m_exportBtn     = nullptr;

    // Data
    QString         m_instruction;
    QList<BatchSection> m_sections;
    BatchProcessor* m_processor     = nullptr;
    QTimer*         m_uiTimer       = nullptr;   // updates elapsed time display
    int             m_elapsedSecs   = 0;
};
