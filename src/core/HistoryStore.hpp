#pragma once
#include "../ai/AIClient.hpp"
#include <QVector>

class HistoryStore {
public:
    static void load(QVector<Message>& history);
    static void save(const QVector<Message>& history, int maxMessages);
    static void clear();
private:
    static QString historyPath();
};
