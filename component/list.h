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
    ListItem(int num, QString title) : m_num(num), m_titleCtx(title) { init(); }

    QWidget *init();

private:
    int m_num;
    QString m_titleCtx;
    QPixmap m_gtoPx;
    QHBoxLayout *m_layout;
    QWidget *m_w;
    QLabel *m_index;
    QLabel *m_title;
    QLabel *m_gto;
};

class ListView : public AbstractListView {
Q_OBJECT
public:
    ListView() { init(); }

    void init();

private:

};


#endif //INNCLIENT_LIST_H
