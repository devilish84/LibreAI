#pragma once
#include "AIClient.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTabWidget;
QT_END_NAMESPACE

class ConfigDialog : public QWidget {
    Q_OBJECT
public:
    static ConfigDialog* instance();
    static void          resetInstance();
    explicit ConfigDialog(QWidget* parent = nullptr);

protected:
    void changeEvent(QEvent* e) override;

private:
    void buildUi();
    void applyTheme();
    void retranslateUi();
    void onProviderChanged(int index);
    void onRefreshModels();
    void onOk();

    // tabs
    QTabWidget*  m_tabs;

    // General Settings tab
    QLabel*      m_langLabel;
    QComboBox*   m_langBox;

    // Model Selection tab
    QLabel*      m_providerLabel;
    QComboBox*   m_providerBox;
    QLabel*      m_connLabel;
    QLineEdit*   m_connEdit;
    QLabel*      m_modelLabel;
    QComboBox*   m_modelBox;
    QPushButton* m_refreshBtn;

    QPushButton* m_okBtn;
    QPushButton* m_cancelBtn;

    AIClient*    m_client = nullptr;

    static ConfigDialog* s_instance;
};
