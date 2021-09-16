//
// Created by zyx on 2021/9/16.
//

#ifndef INNCLIENT__AUTH_H
#define INNCLIENT__AUTH_H

#include <QIcon>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "service/net_conn_service.h"

class Auth : public QWidget {
public:
    Auth(Inn::NetConnService *service = nullptr);
private:
    void InitUi();
    void InitTitle();
    void InitContent();
private:
    Inn::NetConnService *m_netService;
    QLineEdit *m_user;
    QLineEdit *m_pwd;
    QLabel *m_uLabel;
    QLabel *m_pLabel;
    QLabel *m_rLabel;
    QLabel *m_titleLabel;
    QPushButton *m_loginBtn;
    QPushButton *m_exitBtn;
    QPushButton *m_minBtn;
    QPushButton *m_closeBtn;
    QCheckBox *m_remember;
    QWidget *m_title;
    QWidget *m_content;
    QHBoxLayout *m_titleLayout;
    QHBoxLayout *m_layout_1;
    QHBoxLayout *m_contentLayout;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_layout;
    QVBoxLayout *m_rLayout;
    QSpacerItem *m_lHSpacer;
    QSpacerItem *m_rHSpacer;
    QSpacerItem *m_tVSpacer;
    QSpacerItem *m_bVSpacer;

};


#endif //INNCLIENT__AUTH_H
