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

class AbstractPopup : public QWidget {
Q_OBJECT
private:
    void ShowAnimation();

    void CloseAnimation();

protected:

private:
    QPropertyAnimation *m_showAnimation;

    QPropertyAnimation *m_closeAnimation;

};

class Popup : public AbstractPopup {
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

    QIcon *m_refreshIcon;
    QIcon *m_backIcon;

    QHBoxLayout *m_hLayout;
    QVBoxLayout *m_vLayout;
};


#endif //INNCLIENT_POPUP_H
