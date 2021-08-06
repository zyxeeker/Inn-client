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
//#include "../model/utils.hpp"

class Popup : public QWidget {
Q_OBJECT
public:
    Popup();

private:
    void Init();

private:
    int m_bkW;
    int m_bkH;
    int m_bodyPx = 0;
    int m_bodyPy = 0;

    QWidget *m_bk;
    QWidget *m_body;
    QWidget *m_banner;

    QLabel *m_title;
    QLabel *m_secTitle;

    QPushButton *m_refreshBtn;
    QPushButton *m_backBtn;

    QPixmap m_refreshIcon;
    QPixmap m_backIcon;

    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;
};


#endif //INNCLIENT_POPUP_H
