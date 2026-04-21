#pragma once
#include "AIClient.hpp"
#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QPushButton;
class QStatusBar;
QT_END_NAMESPACE

class ChatWindow : public QWidget {
    Q_OBJECT
public:
    static ChatWindow* instance();
    void setPendingSelection(const QString& text);

private:
    explicit ChatWindow(QWidget* parent = nullptr);

    void buildUi();
    void applyTheme();
    void onProviderChanged(int index);
    void onRefreshModels();
    void onGrabSelection();
    void onSend();
    void onRewrite();
    void onApply();
    void setStatus(const QString& msg, const QString& color = "#858585");
    void setBusy(bool busy);
    AIClient* buildClient();

    // controls
    QComboBox*     m_providerBox;
    QLabel*        m_connLabel;
    QLineEdit*     m_connEdit;
    QComboBox*     m_modelBox;
    QPushButton*   m_refreshBtn;
    QPushButton*   m_grabBtn;
    QPlainTextEdit* m_selEdit;
    QPlainTextEdit* m_instrEdit;
    QPlainTextEdit* m_respEdit;
    QPushButton*   m_sendBtn;
    QPushButton*   m_rewriteBtn;
    QPushButton*   m_applyBtn;
    QLabel*        m_statusLabel;

    QVector<Message> m_history;
    AIClient*        m_client = nullptr;
};
