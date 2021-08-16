//
// Created by zyx on 2021/8/6.
//

#include "button.h"
#include <QDebug>

OverviewBtn::OverviewBtn(QString url, QString title, QWidget *parent) : m_iconUrl(url), m_titleCtx(title) {
    Init();
    InitAnimation();
}

void OverviewBtn::Init() {
    m_mainCtx = new QWidget(this);
    m_effect = new QGraphicsDropShadowEffect(this);
    m_title = new QLabel(m_mainCtx);
    m_icon = new QLabel(m_mainCtx);
    m_layout = new QVBoxLayout(m_mainCtx);
    m_upAnimation = new QPropertyAnimation(m_mainCtx, "geometry");
    m_downAnimation = new QPropertyAnimation(m_mainCtx, "geometry");

    m_mainCtx->setGeometry(QRect(10, 10, 150, 150));
    m_mainCtx->setAttribute(Qt::WA_Hover, true);
    m_mainCtx->installEventFilter(this);
    m_mainCtx->setCursor(Qt::PointingHandCursor);
    m_mainCtx->setObjectName("content");
    m_mainCtx->setMaximumSize(150, 150);
    m_mainCtx->setMinimumSize(150, 150);
    m_mainCtx->setStyleSheet(
            "#content{border-radius:8px;background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(121, 74, 255, 255), stop:0.59887 rgba(154, 75, 255, 255), stop:1 rgba(174, 76, 255, 255));}");

    m_iconPx = Utils::LoadSvg(m_iconUrl, 80, 80);

    m_icon->setPixmap(m_iconPx);
    m_icon->setAlignment(Qt::AlignCenter);
    m_icon->setMaximumSize(150, 85);
    m_icon->setMinimumSize(150, 85);

    m_title->setText(m_titleCtx);
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:18px;");
    m_title->setAlignment(Qt::AlignCenter);

    m_effect->setOffset(10, 10);
    m_effect->setColor(QColor(0, 0, 0, 100));
    m_effect->setBlurRadius(50);
    m_mainCtx->setGraphicsEffect(m_effect);

    m_layout->addWidget(m_icon);
    m_layout->addWidget(m_title);
    m_layout->setContentsMargins(0, 20, 0, 20);
    m_mainCtx->setLayout(m_layout);

}

void OverviewBtn::InitAnimation() {
    m_upAnimation->setEasingCurve(QEasingCurve::InQuad);
    m_upAnimation->setDuration(100);
    m_upAnimation->setEndValue(QRect(10, 5, 150, 150));

    m_downAnimation->setEasingCurve(QEasingCurve::InQuad);
    m_downAnimation->setDuration(100);
    m_downAnimation->setEndValue(QRect(10, 8, 150, 150));
}

void OverviewBtn::BtnMoveUp() {
    m_upAnimation->setStartValue(m_mainCtx->geometry());
    m_upAnimation->start();
}

void OverviewBtn::BtnBack2Origin() {
    m_downAnimation->setStartValue(m_mainCtx->geometry());
    m_downAnimation->start();
}

bool OverviewBtn::eventFilter(QObject *obj, QEvent *event) {
    if (obj == m_mainCtx) {
        if (event->type() == QEvent::HoverEnter)
            BtnMoveUp();
        if (event->type() == QEvent::HoverLeave)
            BtnBack2Origin();
        if (event->type() == QEvent::MouseButtonRelease)
                emit OpenPopup();
    }
    return QObject::eventFilter(obj, event);
}