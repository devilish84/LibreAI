#pragma once
#include <QByteArray>
#include <QObject>
#include <QStringList>

class ImageClient : public QObject {
    Q_OBJECT
public:
    explicit ImageClient(QObject* parent = nullptr) : QObject(parent) {}
    ~ImageClient() override;

    // Populate model list; emits imageModelsReady or errorOccurred
    virtual void fetchImageModels() = 0;

    // Request image generation; emits imageReady (raw PNG bytes) or errorOccurred
    // size is a string like "1024x1024", "1792x1024", "1024x1792"
    virtual void generateImage(const QString& model,
                               const QString& prompt,
                               const QString& size) = 0;

signals:
    void imageModelsReady(QStringList models);
    void imageReady(QByteArray pngData);
    void errorOccurred(QString error);
};
