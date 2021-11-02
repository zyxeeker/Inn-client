//
// Created by zyx on 2021/8/6.
//

#ifndef INNCLIENT_BUTTON_H
#define INNCLIENT_BUTTON_H

#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include "./model/utils.h"

class AbstractedBtn : public QPushButton {
Q_OBJECT
public:
    AbstractedBtn(QWidget *parent = nullptr);
protected:
    bool m_isHover = false;
    bool m_isPressed = false;
    QGraphicsDropShadowEffect *m_shadowEffect;
    QPropertyAnimation *m_upAnimation;
    QPropertyAnimation *m_downAnimation;
    QPropertyAnimation *m_enterAnimation;
    QPropertyAnimation *m_leaveAnimation;
};

class LoginBtn : public AbstractedBtn{
    Q_OBJECT
    Q_PROPERTY(double xBk READ xBk WRITE setXBk);
public:
    LoginBtn(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    int xBk() const;
    void setXBk(const int xBk);
private:
    int m_xBk = 250;
};


#endif //INNCLIENT_BUTTON_H
