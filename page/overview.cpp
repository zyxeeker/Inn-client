//
// Created by zyx on 2021/8/2.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Overview.h" resolved

#include "overview.h"
#include <QDebug>

#define OVERVIEW_SLOGAN "欢迎你，"

Overview::Overview(std::string u, QWidget *parent) : QWidget(parent), m_user(u) {
    m_title = new QLabel(this);
    m_yY = new QPushButton(this);
    m_netAM = new QNetworkAccessManager(this);
    InitUI();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

Overview::~Overview() noexcept {

}

void Overview::InitUI() {
    RegBanner();
    SetBannerPosition();
    RegYYService();
    connect(m_netAM, &QNetworkAccessManager::finished, this, &Overview::test);
    connect(m_yY, &QPushButton::clicked, this, &Overview::YYRefresh);
    m_netAM->get(m_netRq);
}

void Overview::RegYYService() {
    m_sslConf = m_netRq.sslConfiguration();
    m_sslConf.setPeerVerifyMode(QSslSocket::VerifyNone);
    m_sslConf.setProtocol(QSsl::TlsV1SslV3);
    m_netRq.setSslConfiguration(m_sslConf);
    m_netRq.setUrl(QUrl("https://v1.hitokoto.cn/?c=c&encode=text"));
}

void Overview::RegBanner() {
    m_title->setText(QString::fromUtf8(OVERVIEW_SLOGAN) + QString::fromStdString(m_user) + "!");
    m_title->setStyleSheet(
            "color:white;font-family:'Microsoft YaHei UI';font-size:42px;font-weight:bold;background-color:transparent;");
    m_yY->setStyleSheet(
            "QPushButton{color:white;font-family:'Microsoft YaHei UI';font-size:16px;background-color:transparent;border-radius:5px;}QPushButton:hover{background-color:rgba(0, 0, 0, 100);}QPushButton:pressed{background-color:rgba(0, 0, 0, 100);}");
    m_yY->setCursor(Qt::PointingHandCursor);
}

void Overview::SetBannerPosition() {
    m_title->setGeometry(this->width() / 16, 70, this->width(), 50);
    m_yY->setGeometry(this->width() / 16 - 8, 130, m_yY->text().length() * 16 + 16, 30);
}

void Overview::resizeEvent(QResizeEvent *e) {
    SetBannerPosition();
}

void Overview::test(QNetworkReply *r) {
    if (r->error() == QNetworkReply::NoError) {
        QString str = QString::fromUtf8(r->readAll());
        m_yY->setText(str);
        SetBannerPosition();
    }
}

void Overview::YYRefresh() {
    m_netAM->get(m_netRq);
}