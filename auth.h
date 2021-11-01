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
#include <QSystemTrayIcon>
#include <windows.h>
#include "service/net_conn_service.h"
#include "component/borderless_window.h"
#include "component/title_bar.h"
#include "model/define.h"

class Auth : public BorderlessWindow {
Q_OBJECT
public:
    Auth(Inn::NetConnService *s, QWidget *parent = nullptr);
    bool HitArea(const QPoint &gPos) override;
private:
    void InitUi();
    void InitTitleBar();
    void InitContent();
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    Inn::NetConnService *m_netService;
    AbstractTitleBar *m_bar;

    QWidget *m_centerWidget;
    QWidget *m_title;
    QWidget *m_content;

    QLineEdit *m_user;
    QLineEdit *m_pwd;
    QLabel *m_uLabel;
    QLabel *m_pLabel;
    QLabel *m_slogan;
    QLabel *m_notification;
    QPushButton *m_loginBtn;
    QPushButton *m_quitBtn;

    QPushButton *m_registerBtn;
    QPushButton *m_forgetBtn;
    QCheckBox *m_remember;

    QVBoxLayout *m_centerLayout;
    QHBoxLayout *m_titleLayout;
    QHBoxLayout *m_layout_1;
    QHBoxLayout *m_contentLayout;
    QHBoxLayout *m_forgetLayout;
    QHBoxLayout *m_regLayout;
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
    void LoginSuccess();
private slots:
    void onReceiveUserInfo();
    void onReceiveReqResult(NET_SERVICE::REQ_RESULT);
    void SwitchWindow(WINDOW_STATE);
};


#endif //INNCLIENT_AUTH_H
