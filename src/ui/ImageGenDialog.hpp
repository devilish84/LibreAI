#pragma once
#include <QByteArray>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QPlainTextEdit;
class QPushButton;
class QScrollArea;
QT_END_NAMESPACE

class ImageClient;

class ImageGenDialog : public QWidget {
    Q_OBJECT
public:
    explicit ImageGenDialog(QWidget* parent = nullptr);
    ~ImageGenDialog() override;

    void setContextHint(const QString& selectedText);

protected:
    void changeEvent(QEvent* e) override;

private:
    void buildUi();
    void applyTheme();
    void retranslateUi();

    void onGenerate();
    void onInsert();
    void onImageReady(const QByteArray& pngData);
    void onError(const QString& error);

    ImageClient* buildClient() const;
    void         setGenerating(bool on);

    QLabel*        m_contextLabel;
    QLabel*        m_contextValue;
    QLabel*        m_promptLabel;
    QPlainTextEdit* m_promptEdit;
    QLabel*        m_sizeLabel;
    QComboBox*     m_sizeBox;
    QPushButton*   m_generateBtn;
    QLabel*        m_statusLabel;
    QScrollArea*   m_previewScroll;
    QLabel*        m_previewLabel;
    QPushButton*   m_insertBtn;
    QPushButton*   m_closeBtn;

    QByteArray     m_lastPng;
    ImageClient*   m_client = nullptr;
};
