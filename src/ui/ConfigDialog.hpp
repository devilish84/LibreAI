#pragma once
#include "../ai/AIClient.hpp"
#include "../ai/ImageClient.hpp"
#include "../ai/OllamaClient.hpp"
#include "../core/Config.hpp"
#include "DualListWidget.hpp"
#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QFormLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class QScrollArea;
class QSpinBox;
class QStackedWidget;
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
    void buildGeneralTab(QWidget* page);
    void buildProvidersTab(QWidget* page);
    void buildTextGenTab(QWidget* page);
    void buildImageGenTab(QWidget* page);
    void applyTheme();
    void retranslateUi();

    void onOllamaAuthChanged(int index);
    void onFetchOllamaModels();
    void onTxtProviderChanged(int index);
    void onTxtRefreshModels();
    void onImgProviderChanged(int index);
    void onImgRefreshModels();
    void onOk();

    QString credentialForProvider(Provider p) const;

    // ── Tabs ──────────────────────────────────────────────────────────────
    QTabWidget*    m_tabs;

    // General tab
    QLabel*        m_langLabel;
    QComboBox*     m_langBox;
    QCheckBox*     m_logEnabledBox;
    QLabel*        m_logLevelLabel;
    QComboBox*     m_logLevelBox;
    QLabel*        m_logMaxSizeLabel;
    QSpinBox*      m_logMaxSizeBox;
    QLabel*        m_logPathLabel;
    QLabel*        m_logPathValue;

    // Providers tab — combo selects provider, stack shows settings
    QComboBox*     m_providerCombo;
    QStackedWidget* m_providerStack;

    // Ollama page widgets
    QLineEdit*     m_ollamaUrlEdit;
    QComboBox*     m_ollamaAuthBox;
    QLineEdit*     m_ollamaUserEdit;
    QLineEdit*     m_ollamaPassEdit;
    QLineEdit*     m_ollamaKeyHeaderEdit;
    QLineEdit*     m_ollamaKeyValueEdit;
    QPushButton*   m_ollamaFetchBtn;
    DualListWidget* m_ollamaTextList;
    DualListWidget* m_ollamaImgList;

    // OpenAI page
    QLineEdit*     m_openaiUrlEdit;
    QLineEdit*     m_openaiKeyEdit;

    // Claude page
    QLineEdit*     m_claudeUrlEdit;
    QLineEdit*     m_claudeKeyEdit;

    // Grok page
    QLineEdit*     m_grokUrlEdit;
    QLineEdit*     m_grokKeyEdit;

    // Gemini page
    QLineEdit*     m_geminiUrlEdit;
    QLineEdit*     m_geminiKeyEdit;

    QLabel*        m_keychainHint;

    // Text Generation tab
    QComboBox*     m_txtProviderBox;
    QComboBox*     m_txtModelBox;
    QPushButton*   m_txtRefreshBtn;
    QLabel*        m_txtOllamaHint;
    AIClient*      m_txtClient = nullptr;

    // Image Generation tab
    QComboBox*     m_imgProviderBox;
    QComboBox*     m_imgModelBox;
    QPushButton*   m_imgRefreshBtn;
    QLabel*        m_imgOllamaHint;
    ImageClient*   m_imgClient = nullptr;

    // Bottom buttons
    QPushButton*   m_okBtn;
    QPushButton*   m_cancelBtn;

    // Ollama model fetch client
    OllamaClient*  m_ollamaFetchClient = nullptr;

    static ConfigDialog* s_instance;
};
