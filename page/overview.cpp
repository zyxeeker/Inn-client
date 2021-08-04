//
// Created by zyx on 2021/8/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Overview.h" resolved

#include "overview.h"
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

}

void Overview::InitUI() {
    RegBanner();
//    RegTitle();
//    Icon();
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

    SetBannerPosition();
}

void Overview::SetBannerPosition() {
    m_banner->setGeometry(QRect(0, 0, this->width(), 250));
    m_icon->setGeometry(QRect(this->width() / 6, 210, 80, 80));
    m_title->setGeometry(QRect(this->width() / 6, 300, this->width(), 50));
}


void Overview::resizeEvent(QResizeEvent *e) {
    SetBannerPosition();
}

