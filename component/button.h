//
// Created by zyx on 2021/8/6.
//

#ifndef INNCLIENT_BUTTON_H
#define INNCLIENT_BUTTON_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QEvent>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>

class AbstractedButton : public QWidget {
Q_OBJECT
//public:
//    AbstractedButton();
//private:
//

};

class OverviewBtn : public AbstractedButton {
Q_OBJECT
public:
    OverviewBtn(QString url, QString title, QWidget *parent = nullptr);

    void Init();

private:
    void InitAnimation();

    void BtnMoveUp();

    void BtnBack2Origin();

protected:
    bool OverviewBtn::eventFilter(QObject *obj, QEvent *event);

private:
    QWidget *m_mainCtx;
    QVBoxLayout *m_layout;

    QLabel *m_title;
    QLabel *m_icon;
    QPixmap m_iconPx;

    QPropertyAnimation *m_upAnimation;
    QPropertyAnimation *m_downAnimation;
    QGraphicsDropShadowEffect *m_effect;

    QString m_titleCtx = "WB";
    QString m_iconUrl = ":/component/resource/weibo.svg";

};


#endif //INNCLIENT_BUTTON_H
