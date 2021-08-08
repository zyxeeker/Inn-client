//
// Created by zyx on 2021/8/7.
//

#ifndef INNCLIENT_LIST_H
#define INNCLIENT_LIST_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QLabel>
#include <QWheelEvent>
#include <QScrollBar>
#include <QPropertyAnimation>
#include <QScroller>

class AbstractListItem : public QWidget {
Q_OBJECT
public:
    AbstractListItem(int num, QString title, QWidget *parent = nullptr);

private:
    int m_num;
    QWidget *m_body;
    QString m_titleCtx;
    QPixmap m_gtoPx;
    QHBoxLayout *m_layout;
    QLabel *m_index;
    QLabel *m_title;
    QLabel *m_gto;
};

class AbstractListView : public QListWidget {
Q_OBJECT
public:
    AbstractListView(QWidget *parent = nullptr);

private:
    void ScrollAnimation();

protected:
    void wheelEvent(QWheelEvent *e) override;

private:
    QPropertyAnimation *m_animation;
};


class ListItem : public AbstractListItem {
Q_OBJECT
public:
    ListItem(int num, QString title) : AbstractListItem(num, title) {}

private:
};

class WBListView : public AbstractListView {
Q_OBJECT
public:
    WBListView() { init(); }

    void init();
};


#endif //INNCLIENT_LIST_H
