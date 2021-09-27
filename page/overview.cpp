//
// Created by zyx on 2021/8/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Overview.h" resolved

#include "overview.h"
#include <QDebug>


Overview::Overview(std::string u, QWidget *parent) : QWidget(parent), m_user(u) {
    m_banner = new QLabel(this);
    m_icon = new QLabel(this);
    m_title = new QLabel(this);
    InitUI();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void Overview::InitUI() {
    RegBanner();
    SetBannerPosition();
}

void Overview::RegBanner() {
    std::string tmp = "WELCOME," + m_user + "!";
    m_banner->setStyleSheet("background-image:url(:/common/resource/bk.jpg);");
    m_icon->setText(QString("🛠"));
    m_icon->setStyleSheet("font-size:60px;background-color:transparent;");
    m_title->setText(QString::fromStdString(tmp));
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:50px;background-color:transparent;");

}

void Overview::SetBannerPosition() {
    m_banner->setGeometry(QRect(0, 0, this->width(), 250));
    m_icon->setGeometry(QRect(this->width() / 6, 210, 80, 80));
    m_title->setGeometry(QRect(this->width() / 6, 300, this->width(), 50));

}

void Overview::resizeEvent(QResizeEvent *e) {
    SetBannerPosition();
}