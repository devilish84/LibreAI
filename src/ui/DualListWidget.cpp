#include "DualListWidget.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

DualListWidget::DualListWidget(const QString& title, QWidget* parent)
    : QWidget(parent)
{
    auto* root = new QVBoxLayout(this);
    root->setSpacing(4);
    root->setContentsMargins(0, 0, 0, 0);

    m_titleLabel = new QLabel(title);
    m_titleLabel->setObjectName("sectionHdr");
    root->addWidget(m_titleLabel);

    auto* row = new QHBoxLayout();
    row->setSpacing(6);

    // Left list
    m_left = new QListWidget();
    m_left->setSelectionMode(QAbstractItemView::ExtendedSelection);
    row->addWidget(m_left, 1);

    // Transfer buttons (centre column)
    auto* mid = new QVBoxLayout();
    mid->setSpacing(4);
    mid->addStretch();
    m_allRight = new QPushButton(">>");
    m_oneRight = new QPushButton(">");
    m_oneLeft  = new QPushButton("<");
    m_allLeft  = new QPushButton("<<");
    for (auto* b : {m_allRight, m_oneRight, m_oneLeft, m_allLeft}) {
        b->setFixedWidth(36);
        b->setObjectName("btn2");
        mid->addWidget(b);
    }
    mid->addStretch();
    row->addLayout(mid);

    // Right list
    m_right = new QListWidget();
    m_right->setSelectionMode(QAbstractItemView::ExtendedSelection);
    row->addWidget(m_right, 1);

    root->addLayout(row);

    connect(m_allRight, &QPushButton::clicked, this, [this]{ moveToRight(true);  });
    connect(m_oneRight, &QPushButton::clicked, this, [this]{ moveToRight(false); });
    connect(m_oneLeft,  &QPushButton::clicked, this, [this]{ moveToLeft(false);  });
    connect(m_allLeft,  &QPushButton::clicked, this, [this]{ moveToLeft(true);   });
}

void DualListWidget::setTitle(const QString& title) {
    m_titleLabel->setText(title);
}

void DualListWidget::setModels(const QStringList& all, const QStringList& selected) {
    m_left->clear();
    m_right->clear();

    for (const QString& s : selected)
        m_right->addItem(s);

    for (const QString& s : all)
        if (!selected.contains(s))
            m_left->addItem(s);
}

QStringList DualListWidget::selectedModels() const {
    QStringList out;
    for (int i = 0; i < m_right->count(); ++i)
        out << m_right->item(i)->text();
    return out;
}

void DualListWidget::moveToRight(bool all) {
    if (all) {
        while (m_left->count()) {
            auto* item = m_left->takeItem(0);
            m_right->addItem(item->text());
            delete item;
        }
    } else {
        for (auto* item : m_left->selectedItems()) {
            m_right->addItem(item->text());
            delete m_left->takeItem(m_left->row(item));
        }
    }
}

void DualListWidget::moveToLeft(bool all) {
    if (all) {
        while (m_right->count()) {
            auto* item = m_right->takeItem(0);
            m_left->addItem(item->text());
            delete item;
        }
    } else {
        for (auto* item : m_right->selectedItems()) {
            m_left->addItem(item->text());
            delete m_right->takeItem(m_right->row(item));
        }
    }
}

