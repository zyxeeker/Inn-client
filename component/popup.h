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
public:
    AbstractPopup();

protected:
    void SetAnimation(int st, QRect pos);

private:
    void InitAnimation();

signals:

    void Close(QRect);

protected slots:
//    void ShowPopup();

    void ClosePopup(QRect);

private:
    QPropertyAnimation *m_showAnimation;

    QPropertyAnimation *m_closeAnimation;

};

class Popup : public AbstractPopup {
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
    QWidget *m_content;
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
};


#endif //INNCLIENT_POPUP_H
