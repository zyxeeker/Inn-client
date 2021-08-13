//
// Created by zyx on 2021/8/6.
//

#include "popup.h"
#include "./model/define.h"
#include <QDebug>

AbstractPopup::AbstractPopup() {
    connect(this, SIGNAL(Close(QRect)), this, SLOT(ClosePopup(QRect)));
}

void AbstractPopup::SetAnimation(int st, QRect pos) {
    switch (st) {
        case POPUP_SHOW:
            m_showAnimation->setStartValue(pos);
        case POPUP_CLOSE:
            m_closeAnimation->setStartValue(pos);
    }
}

void AbstractPopup::InitAnimation() {
    m_showAnimation = new QPropertyAnimation();
    m_closeAnimation = new QPropertyAnimation();
    m_showAnimation->setEasingCurve(QEasingCurve::InQuad);
    m_showAnimation->setDuration(100);
    m_closeAnimation->setEasingCurve(QEasingCurve::InQuad);
    m_closeAnimation->setDuration(100);
}

void AbstractPopup::ClosePopup(QRect pos) {
    qDebug() << pos;
}

Popup::Popup() {
    Init();
    connect(m_backBtn, &QPushButton::clicked, this, [=]() {
        emit Close(m_body->geometry());
    });
}

void Popup::Init() {
    m_bk = new QWidget(this);
    m_body = new QWidget(m_bk);
    m_content = new QWidget(m_body);
    m_banner = new QWidget(m_body);
    m_title = new QLabel(m_banner);
    m_secTitle = new QLabel(m_banner);
    m_refreshBtn = new QPushButton(m_banner);
    m_backBtn = new QPushButton(m_banner);
    m_bodyLayout = new QVBoxLayout(m_body);
    m_contentLayout = new QVBoxLayout;
    m_hLayout = new QHBoxLayout;
    m_vLayout = new QVBoxLayout;
    m_refreshIcon = new QIcon;
    m_backIcon = new QIcon;

    m_refreshIcon->addFile(":/component/resource/refresh.svg");
    m_backIcon->addFile(":/component/resource/left-small-down.svg");

    m_bk->setGeometry(m_bodyPx, m_bodyPy, 500, 500);
    m_bk->setObjectName("bk");
    m_bk->setStyleSheet("#bk{background:black;}");

    m_body->setObjectName("bk");
    m_body->setGeometry(QRect(0, 0, 300, 400));
    m_body->setStyleSheet("#bk{border-radius:8px;background-color:rgb(28, 28, 30);}");

    m_banner->setObjectName("title");
    m_banner->setMinimumSize(150, 80);
    m_banner->setMaximumSize(300, 80);
    m_banner->setStyleSheet(
            "#title{border-top-left-radius:8px;border-top-right-radius:8px;background:url(:/component/resource/weibo_banner.jpg);}");

    m_title->setText("今天");
    m_title->setMaximumHeight(50);
    m_title->setMinimumHeight(50);
    m_title->setStyleSheet(
            "padding-top:18px;padding-left:2px;color:white;font-weight:bold;font-family:'Microsoft YaHei UI';font-size:20px;");

    m_secTitle->setText("2021-8-5");
    m_secTitle->setMaximumHeight(30);
    m_secTitle->setMinimumHeight(30);
    m_secTitle->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:13px;");

    m_refreshBtn->setIcon(QIcon("m_refreshIcon"));
    m_refreshBtn->setIcon(*m_refreshIcon);
    m_refreshBtn->setIconSize(QSize(16, 16));
    m_refreshBtn->setMinimumSize(26, 26);
    m_refreshBtn->setMaximumSize(26, 26);
    m_refreshBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                                "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                                "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_backBtn->setObjectName("backBtn");
    m_backBtn->setIcon(*m_backIcon);
    m_backBtn->setIconSize(QSize(16, 16));
    m_backBtn->setMinimumSize(26, 26);
    m_backBtn->setMaximumSize(26, 26);
    m_backBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                             "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                             "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_contentLayout->addWidget(m_content);
    m_contentLayout->setContentsMargins(8, 0, 8, 8);

    m_hLayout->addWidget(m_secTitle);
    m_hLayout->addWidget(m_refreshBtn);
    m_hLayout->addWidget(m_backBtn);
    m_hLayout->setSpacing(10);
    m_hLayout->setContentsMargins(10, 0, 10, 0);
    m_vLayout->addWidget(m_title);
    m_vLayout->addItem(m_hLayout);
    m_vLayout->setSpacing(0);
    m_vLayout->setContentsMargins(5, 8, 5, 5);
    m_banner->setLayout(m_vLayout);
    m_bodyLayout->addWidget(m_banner);
    m_bodyLayout->addItem(m_contentLayout);
    m_bodyLayout->setContentsMargins(0, 0, 0, 0);

}