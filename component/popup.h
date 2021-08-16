//
// Created by zyx on 2021/8/6.
//

#ifndef INNCLIENT_POPUP_H
#define INNCLIENT_POPUP_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include "list.h"
#include "./model/define.h"
#include <QDebug>

class AbstractPopup : public QWidget {
Q_OBJECT
protected:
    virtual void ShowStatue(int, QRect) = 0;
};

class OverviewPopup : public AbstractPopup {
Q_OBJECT
public:
    OverviewPopup(int px, int py);

private:
    void Init();

    void InitBanner();

    void InitAnimation();

    void ShowStatue(int, QRect pos) override;

protected:
    virtual void SetContent() = 0;

protected:
    QWidget *m_content;

private:
    int m_px = 0;
    int m_py = 0;
    int m_popupSt;
    QWidget *m_bk;
    QWidget *m_body;
    QWidget *m_banner;
    QLabel *m_title;
    QLabel *m_secTitle;
    QPushButton *m_refreshBtn;
    QPushButton *m_backBtn;
    QIcon *m_refreshIcon;
    QIcon *m_backIcon;
    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;
    QVBoxLayout *m_contentLayout;
    QVBoxLayout *m_bodyLayout;
    QPropertyAnimation *m_animation;
    QGraphicsDropShadowEffect *m_effect;
signals:

    void Finish();

public slots:

    void ChangeSt(QRect pos) { ShowStatue(POPUP_SHOW, pos); }
};

class WBPopup : public OverviewPopup {
public:
    WBPopup(int px, int py);

private:
    void Init();

    void SetContent() override;

private:
    WBListView *m_list;
    QHBoxLayout *m_layout;
};


#endif //INNCLIENT_POPUP_H
