#pragma once
#include "../ai/AIClient.hpp"
#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
class QLabel;
class QPlainTextEdit;
class QTextEdit;
class QPushButton;
class QTimer;
class QListWidget;
QT_END_NAMESPACE

class ChatWindow : public QWidget {
    Q_OBJECT
public:
    static ChatWindow* instance();
    static void        resetInstance();
    void setPendingSelection(const QString& text);

protected:
    void changeEvent(QEvent* e) override;

private:
    explicit ChatWindow(QWidget* parent = nullptr);

    void buildUi();
    void applyTheme();
    void retranslateUi();
    void onGrabSelection();
    void onSend();
    void onRewrite();
    void onApply();
    void onClearHistory();
    void refreshHistoryPane();
    void setStatus(const QString& msg, const QString& color = "#858585");
    void setBusy(bool busy);
    AIClient* buildClient();

    QLabel*         m_headerLabel;
    QPushButton*    m_grabBtn;
    QLabel*         m_selLabel;
    QPlainTextEdit* m_selEdit;
    QLabel*         m_instrLabel;
    QPlainTextEdit* m_instrEdit;
    QPushButton*    m_rewriteBtn;
    QPushButton*    m_sendBtn;
    QPushButton*    m_clearHistBtn;
    QPushButton*    m_historyToggleBtn;
    QListWidget*    m_historyList;
    QLabel*         m_respLabel;
    QTextEdit*      m_respEdit;
    QPushButton*    m_applyBtn;
    QLabel*         m_statusLabel;

    QVector<Message> m_history;
    AIClient*        m_client    = nullptr;
    QTimer*          m_spinTimer = nullptr;
    int              m_spinFrame = 0;

    static ChatWindow* s_instance;
};
