//
// Created by zyx on 2021/8/2.
//

#ifndef INNCLIENT_OVERVIEW_H
#define INNCLIENT_OVERVIEW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "./component/popup.h"
#include "./component/button.h"

class Overview : public QWidget {
Q_OBJECT

public:
    explicit Overview(std::string u, QWidget *parent = nullptr);
    ~Overview();
private:
    void InitUI();
private:
    void RegYYService();
    void RegBanner();
    void SetBannerPosition();
protected:
    void resizeEvent(QResizeEvent *e);
private:
    std::string m_user;
    QLabel *m_title;
    QPushButton *m_yY;
    QNetworkAccessManager *m_netAM;
    QNetworkRequest m_netRq;
    QSslConfiguration m_sslConf;
private slots:
    void test(QNetworkReply *);
    void YYRefresh();
};


#endif //INNCLIENT_OVERVIEW_H
