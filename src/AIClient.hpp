#pragma once
#include <QObject>
#include <QString>
#include <QVector>

struct Message {
    QString role;    // "user" or "assistant"
    QString content;
};

class AIClient : public QObject {
    Q_OBJECT
public:
    explicit AIClient(QObject* parent = nullptr) : QObject(parent) {}
    virtual void fetchModels() = 0;
    virtual void sendChat(const QString& model, const QVector<Message>& history,
                          const QString& prompt) = 0;
signals:
    void modelsReady(QStringList models);
    void responseReady(QString text);
    void errorOccurred(QString error);
};
