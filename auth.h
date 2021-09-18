//
// Created by zyx on 2021/9/16.
//

#ifndef INNCLIENT_AUTH_H
#define INNCLIENT_AUTH_H

#include <QIcon>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMoveEvent>
#include "service/net_conn_service.h"

class Auth : public QWidget {
    Q_OBJECT
public:
    Auth(Inn::NetConnService *service = nullptr);
private:
    void InitUi();
    void InitTitle();
    void InitContent();
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    Inn::NetConnService *m_netService;
    const int m_titleXMin = 0;
    const int m_titleYMin = 0;
    const int m_titleXMax = 700;
    const int m_titleYMax = 30;
    bool m_mousePress;
    QPoint m_mousePosition;
    QLineEdit *m_user;
    QLineEdit *m_pwd;
    QLabel *m_uLabel;
    QLabel *m_pLabel;
    QLabel *m_titleLabel;
    QLabel *m_slogan;
    QLabel *m_notification;
    QPushButton *m_loginBtn;
    QPushButton *m_exitBtn;
    QPushButton *m_minBtn;
    QPushButton *m_closeBtn;
    QPushButton *m_registerBtn;
    QPushButton *m_forgetBtn;
    QCheckBox *m_remember;
    QWidget *m_title;
    QWidget *m_content;
    QHBoxLayout *m_titleLayout;
    QHBoxLayout *m_layout_1;
    QHBoxLayout *m_contentLayout;
    QHBoxLayout *m_forgetLayout;
    QHBoxLayout *m_regLayout;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_layout;
    QVBoxLayout *m_rLayout;
    QSpacerItem *m_lHSpacer;
    QSpacerItem *m_rHSpacer;
    QSpacerItem *m_tVSpacer;
    QSpacerItem *m_bVSpacer;
    QSpacerItem *m_fSpacer;
    QSpacerItem *m_regSpacer;
signals:
    void ClientQuit();
private slots:
    void onReceiveUserInfo();
    void onReceiveReqResult(NET_SERVICE::REQ_RESULT);
};


#endif //INNCLIENT_AUTH_H
