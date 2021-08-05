//
// Created by zyx on 2021/8/4.
//

#ifndef INNCLIENT_WIDGET_SMALL_H
#define INNCLIENT_WIDGET_SMALL_H

#include <QWidget>
#include <QLabel>
#include <QSvgRenderer>
#include <QPainter>
#include <QPushButton>
#include <QListWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QDebug>

class ListItem : public QWidget {
public:
    ListItem(int num, QString title) : m_num(num), m_titleCtx(title) {}

    QWidget *init();

private:
    int m_num;
    QString m_titleCtx;

    QHBoxLayout *m_layout;
    QWidget *m_w;
    QLabel *m_index;
    QLabel *m_title;
    QPushButton *m_gto;
};

class SWidget : public QWidget {
public:
    SWidget();

    static QPixmap LoadSvg(QString url, int w, int h);
private:
    void InitUI();

    void RegBanner();

    void RegSContent();

    void RegList();

    void RegBk();

    void load();

private:
    QWidget *m_banner;
    QWidget *m_sContent;

    QVBoxLayout *m_layout;
    QHBoxLayout *m_btns;
    QVBoxLayout *m_listLayout;

    QPushButton *m_refreshBtn;
    QPushButton *m_backBtn;

    QPixmap m_refreshIcon;
    QPixmap m_minimizedIcon;

    QWidget *m_listContainer;
    QListWidget *m_list;
    QListWidgetItem *m_item;

    QLabel *m_bk;
    QLabel *m_icon;
    QLabel *m_title;

    QLabel *m_no1;
    QLabel *m_no2;
    QLabel *m_no3;
    QLabel *m_hotTitle1;
    QLabel *m_hotTitle2;
    QLabel *m_hotTitle3;

    QWidget *m_content;
    QPixmap m_px;
    QPixmap m_px1;
    QPixmap m_px2;
    QPixmap m_px3;

    QPushButton *m_btn;

private slots:

    void on_backBtn_clicked();

};


#endif //INNCLIENT_WIDGET_SMALL_H
