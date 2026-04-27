#pragma once
#include "../ai/AIClient.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QFormLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class QSpinBox;
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
    void onOllamaAuthChanged(int index);
    void onRefreshModels();
    void onOk();

    QString currentCredential() const;
    void    setRowVisible(QLabel* lbl, QWidget* field, bool visible);

    // tabs
    QTabWidget*  m_tabs;

    // General Settings tab
    QLabel*      m_langLabel;
    QComboBox*   m_langBox;
    QCheckBox*   m_logEnabledBox;
    QLabel*      m_logLevelLabel;
    QComboBox*   m_logLevelBox;
    QLabel*      m_logMaxSizeLabel;
    QSpinBox*    m_logMaxSizeBox;
    QLabel*      m_logPathLabel;
    QLabel*      m_logPathValue;

    // Model Selection tab — single flat QFormLayout
    QFormLayout* m_modelForm;
    QLabel*      m_providerLabel;
    QComboBox*   m_providerBox;

    // Ollama fields
    QLabel*      m_ollamaUrlLabel;
    QLineEdit*   m_ollamaUrlEdit;
    QLabel*      m_ollamaAuthLabel;
    QComboBox*   m_ollamaAuthBox;
    QLabel*      m_ollamaUserLabel;
    QLineEdit*   m_ollamaUserEdit;
    QLabel*      m_ollamaPassLabel;
    QLineEdit*   m_ollamaPassEdit;
    QLabel*      m_ollamaKeyHeaderLabel;
    QLineEdit*   m_ollamaKeyHeaderEdit;
    QLabel*      m_ollamaKeyValueLabel;
    QLineEdit*   m_ollamaKeyValueEdit;

    // OpenAI fields
    QLabel*      m_openaiUrlLabel;
    QLineEdit*   m_openaiUrlEdit;
    QLabel*      m_openaiKeyLabel;
    QLineEdit*   m_openaiKeyEdit;

    // Claude fields
    QLabel*      m_claudeKeyLabel;
    QLineEdit*   m_claudeKeyEdit;

    // Grok fields
    QLabel*      m_grokKeyLabel;
    QLineEdit*   m_grokKeyEdit;

    // Gemini fields
    QLabel*      m_geminiKeyLabel;
    QLineEdit*   m_geminiKeyEdit;

    // Keychain status hint
    QLabel*      m_keychainHint;

    // Model row (shared)
    QLabel*      m_modelLabel;
    QComboBox*   m_modelBox;
    QPushButton* m_refreshBtn;

    QPushButton* m_okBtn;
    QPushButton* m_cancelBtn;

    AIClient*    m_client = nullptr;

    static ConfigDialog* s_instance;
};
