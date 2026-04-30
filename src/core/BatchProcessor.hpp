#pragma once
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include "../uno/DocumentParser.hpp"

class AIClient;

class BatchProcessor : public QObject {
    Q_OBJECT
public:
    struct Config {
        int  delayMs         = 500;
        int  timeoutSec      = 60;
        bool stopOnError     = false;
    };

    explicit BatchProcessor(QObject* parent = nullptr);
    ~BatchProcessor() override;

    // Begin processing. Takes ownership of the section list.
    void start(const QString& instruction,
               QList<BatchSection> sections,
               const Config& cfg,
               bool reviewMode = false);

    static Config defaultConfig() { return Config{}; }

    void cancel();

    bool isRunning() const { return m_running; }
    int  currentIndex() const { return m_current; }
    int  totalSections() const { return m_sections.size(); }

    const QList<BatchSection>& sections() const { return m_sections; }

signals:
    // Emitted after each section completes (success or skip).
    void sectionDone(int index, int total, const QString& title, bool success);

    // Emitted in "Review Each" mode: caller should show proposed text,
    // then call acceptCurrent() or skipCurrent().
    void awaitingReview(int index, int total,
                        const QString& title, const QString& proposedText);

    void batchCompleted(int successCount, int errorCount);
    void batchCancelled();
    void errorOccurred(const QString& message);

public slots:
    // Used only in review mode — accept the proposed rewrite.
    void acceptCurrent();
    // Used only in review mode — skip the current section.
    void skipCurrent();

private slots:
    void onResponseReady(const QString& response);
    void onAiError(const QString& error);
    void onTimeout();

private:
    void processNext();
    void applySection(int index);
    void finishSection(bool success, const QString& error = {});
    void closeUndoContext();
    AIClient* buildClient();

    QList<BatchSection> m_sections;
    QString             m_instruction;
    Config              m_cfg;
    AIClient*           m_client     = nullptr;
    QTimer              m_delayTimer;
    QTimer              m_timeoutTimer;
    QElapsedTimer       m_elapsed;
    int                 m_current    = 0;
    int                 m_successes  = 0;
    int                 m_errors     = 0;
    bool                m_running    = false;
    bool                m_cancelled  = false;
    bool                m_reviewMode = false;
    QString             m_pendingResponse;  // held during review
};
