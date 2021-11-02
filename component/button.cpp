//
// Created by zyx on 2021/8/6.
//

#include "button.h"

AbstractedBtn::AbstractedBtn(QWidget *parent) : QPushButton(parent) {
    m_shadowEffect = new QGraphicsDropShadowEffect(this);
    m_shadowEffect->setBlurRadius(45);
    m_shadowEffect->setXOffset(0);
    m_shadowEffect->setYOffset(3);
    this->setGraphicsEffect(m_shadowEffect);

    m_upAnimation = new QPropertyAnimation(m_shadowEffect, "yOffset");
    m_downAnimation = new QPropertyAnimation(m_shadowEffect, "yOffset");

    m_upAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_upAnimation->setDuration(200);
    m_upAnimation->setEndValue(3);

    m_downAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_downAnimation->setDuration(200);
    m_downAnimation->setEndValue(8);
}

LoginBtn::LoginBtn(QWidget *parent) : AbstractedBtn(parent) {
    m_enterAnimation = new QPropertyAnimation(this,"xBk");
    m_leaveAnimation = new QPropertyAnimation(this,"xBk");
    m_shadowEffect->setColor(QColor(121, 74, 255,200));

    m_enterAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_enterAnimation->setDuration(180);
    m_enterAnimation->setEndValue(150);

    m_leaveAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_leaveAnimation->setDuration(180);
    m_leaveAnimation->setEndValue(250);
}

void LoginBtn::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置渐变色,设置起点、终点
    QLinearGradient linear(0, 50, m_xBk, 50);
    linear.setColorAt(0, QColor(121, 74, 255));
    linear.setColorAt(1, QColor(252,145,200));
    // 设置显示模式
    linear.setSpread(QGradient::PadSpread);
    // 设置画笔颜色、宽度
    painter.setPen(QPen(QColor(255, 255, 255, 0), 1));
    // 设置画刷填充
    painter.setBrush(QBrush(linear));
    // 绘制矩形
    painter.drawRoundedRect(QRect(0,0,this->width(),this->height()),12,12);
    // draw text
    painter.setPen(QPen(QColor(215, 219, 221)));
    painter.setFont(font());
    painter.drawText(rect(), Qt::AlignCenter, text());
}

void LoginBtn::enterEvent(QEvent *event){
    m_isHover = true;
    m_downAnimation->setStartValue(m_shadowEffect->yOffset());
    m_downAnimation->start();
    m_enterAnimation->setStartValue(m_xBk);
    m_enterAnimation->start();
    QPushButton::enterEvent(event);
}

void LoginBtn::leaveEvent(QEvent *event){
    m_isHover = false;
    m_upAnimation->setStartValue(m_shadowEffect->yOffset());
    m_upAnimation->start();
    m_leaveAnimation->setStartValue(m_xBk);
    m_leaveAnimation->start();
    QPushButton::leaveEvent(event);

}

void LoginBtn::mousePressEvent(QMouseEvent *event){
    m_isPressed = true;
    QPushButton::mousePressEvent(event);
}

void LoginBtn::mouseReleaseEvent(QMouseEvent *event){
    m_isPressed = false;
    QPushButton::mouseReleaseEvent(event);
}

void LoginBtn::setXBk(const int xBk){
    m_xBk = xBk;
    update();
}

int LoginBtn::xBk() const{
    return m_xBk;
}
