#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QListWidget;
class QPushButton;
QT_END_NAMESPACE

// Two-pane list with >> > < << transfer buttons and Up/Down ordering on the right pane.
class DualListWidget : public QWidget {
    Q_OBJECT
public:
    explicit DualListWidget(const QString& title = QString(),
                            QWidget* parent = nullptr);

    // Populate: puts (all - selected) on left, selected on right
    void setModels(const QStringList& all, const QStringList& selected);

    // Returns the current right-pane (selected) items in order
    QStringList selectedModels() const;

    void setTitle(const QString& title);

private:
    void moveToRight(bool all);
    void moveToLeft(bool all);

    QLabel*      m_titleLabel;
    QListWidget* m_left;
    QListWidget* m_right;
    QPushButton* m_allRight;
    QPushButton* m_oneRight;
    QPushButton* m_oneLeft;
    QPushButton* m_allLeft;
};
