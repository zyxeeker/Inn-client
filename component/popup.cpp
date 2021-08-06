//
// Created by zyx on 2021/8/6.
//

#include "popup.h"

Popup::Popup() {
//    m_refreshIcon = Utils::LoadSvg(":/component/resource/refresh.svg", 15, 15);
//    m_backIcon = Utils::LoadSvg(":/component/resource/left-small-down.svg", 15, 15);
    Init();
}

void Popup::Init() {
    m_bk = new QWidget(this);
    m_body = new QWidget(m_bk);
    m_banner = new QWidget(m_body);
    m_title = new QLabel(m_banner);
    m_secTitle = new QLabel(m_banner);
    m_refreshBtn = new QPushButton(m_banner);
    m_backBtn = new QPushButton(m_banner);
    m_hLayout = new QHBoxLayout;
    m_vLayout = new QVBoxLayout;

    m_bk->setGeometry(m_bodyPx, m_bodyPy, 300, 400);
    m_bk->setObjectName("bk");
    m_bk->setStyleSheet("#bk{background:black;}");

    m_body->setObjectName("bk");
    m_body->setGeometry(QRect(0, 250, 149, 149));
    m_body->setStyleSheet("#bk{border-radius:24px;background-color:rgb(28, 28, 30);}");

    m_banner->setObjectName("title");
    m_banner->setMinimumSize(150, 100);
    m_banner->setMaximumSize(300, 110);
    m_banner->setStyleSheet(
            "#title{border-top-left-radius:24px;border-top-right-radius:24px;background:url(:/component/resource/weibo_banner.jpg);}");

    m_title->setText("今天");
    m_title->setMaximumHeight(50);
    m_title->setMinimumHeight(50);
    m_title->setStyleSheet(
            "padding-top:25px;padding-left:2px;color:white;font-weight:bold;font-family:'Microsoft YaHei UI';font-size:20px;");

    m_secTitle->setText("2021-8-5");
    m_secTitle->setMaximumHeight(30);
    m_secTitle->setMinimumHeight(30);
    m_secTitle->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:13px;");

    m_refreshBtn->setIcon(QIcon("m_refreshIcon"));
    m_refreshBtn->setMinimumSize(25, 25);
    m_refreshBtn->setMaximumSize(25, 25);
    m_refreshBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                                "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                                "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_backBtn->setObjectName("backBtn");
    m_backBtn->setIcon(QIcon(m_backIcon));
    m_backBtn->setMinimumSize(25, 25);
    m_backBtn->setMaximumSize(25, 25);
    m_backBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                             "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                             "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_hLayout->addWidget(m_secTitle);
    m_hLayout->addWidget(m_refreshBtn);
    m_hLayout->addWidget(m_backBtn);
    m_hLayout->setSpacing(5);
    m_hLayout->setContentsMargins(10, 0, 10, 0);
    m_vLayout->addWidget(m_title);
    m_vLayout->addItem(m_hLayout);
    m_vLayout->setSpacing(0);
    m_vLayout->setContentsMargins(5, 20, 5, 0);
    m_body->setLayout(m_vLayout);

}