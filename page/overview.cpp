//
// Created by zyx on 2021/8/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Overview.h" resolved

#include "overview.h"
#include <QDebug>
//#include "ui_Overview.h"


//Overview::Overview(QWidget *parent) :
//        QWidget(parent), ui(new Ui::Overview) {
//    ui->setupUi(this);
//}

//
//Overview::~Overview() {
//    delete ui;
//}

Overview::Overview(QWidget *parent) {
    InitUI();
    connect(m_wbBtn, SIGNAL(OpenPopup()), m_wbPopup, SLOT(ChangeSt()));
    connect(m_wbPopup, SIGNAL(Finish()), this, SLOT(PopupClose()));

}

void Overview::InitUI() {
    RegBanner();
    SetBtns();
    SetPopup();
    SetBannerPosition();
}

void Overview::RegBanner() {
    m_banner = new QLabel(this);
    m_banner->setStyleSheet(QString::fromUtf8("background-image:url(:/common/resource/bk.jpg);"));

    m_icon = new QLabel(this);
    m_icon->setText(QString("🛠"));
    m_icon->setStyleSheet(QString::fromUtf8("font-size:60px;background-color:transparent;"));

    m_title = new QLabel(this);
    m_title->setText(QString("WELCOME!"));
    m_title->setStyleSheet(QString::fromUtf8(
            "color:white;font-family:'Microsoft YaHei UI';font-size:50px;background-color:transparent;"));

}

void Overview::SetPopup(/*int px, int py*/) {
    m_popupBk = new QWidget(this);
    m_popup = new QHBoxLayout;
    m_wbPopup = new WBPopup(20, 50);
    m_popup->setContentsMargins(0, 0, 0, 0);
    m_popup->addWidget(m_wbPopup);
    m_popupBk->setLayout(m_popup);
    m_popupBk->raise();
}

void Overview::SetBtns() {
    m_btn = new QWidget(this);
    auto *btnLayout = new QHBoxLayout(m_btn);
    m_wbBtn = new OverviewBtn(":/component/resource/weibo.svg", "WBSA");
    btnLayout->addWidget(m_wbBtn);
    m_btn->setLayout(btnLayout);
}

void Overview::SetBannerPosition() {
    m_banner->setGeometry(QRect(0, 0, this->width(), 250));
    m_icon->setGeometry(QRect(this->width() / 6, 210, 80, 80));
    m_title->setGeometry(QRect(this->width() / 6, 300, this->width(), 50));
    m_btn->setGeometry(QRect(this->width() / 6, 350, this->width(), 200));
    m_popupBk->setGeometry(QRect(0, 0, this->width(), this->height()));
}

void Overview::resizeEvent(QResizeEvent *e) {
    SetBannerPosition();
}

void Overview::PopupClose() {
    m_popupBk->close();
}