//
// Created by zyx on 2021/9/22.
//

#ifndef INNCLIENT_MAINWINDOW_H
#define INNCLIENT_MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QIcon>
#include <QSystemTrayIcon>
#include "auth.h"
#include "service/net_conn_service.h"

#ifdef Q_OS_WIN

#include <windows.h>

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lParam) ((int)(short)LOWORD(lParam))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lParam) ((int)(short)HIWORD(lParam))
#endif
#endif

enum SIZE_STATE {
    MAX, MIN
};

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(Inn::NetConnService *s);
private:
    void InitUI();
    void InitTitle();
    void InitContent();
    void InitBtn(QPushButton *b, int s1, int s2, QString s, QString url, QString ourl = nullptr);
private:
    void SwitchSizeBtn(SIZE_STATE s);
protected:
    bool nativeEvent(const QByteArray &et, void *m, long *r);
private:
    QLabel *m_titleName;
    QWidget *m_centerWidget;
    QWidget *m_title;
    QWidget *m_content;
    QVBoxLayout *m_main;
    QHBoxLayout *m_titleLayout;
    QVBoxLayout *m_navLayout;
    QHBoxLayout *m_contentLayout;
    QPushButton *m_homeBtn;
    QPushButton *m_singleChatBtn;
    QPushButton *m_groupChatBtn;
    QPushButton *m_streamBtn;
    QPushButton *m_settingBtn;
    QPushButton *m_exitBtn;
    QPushButton *m_closeBtn;
    QPushButton *m_minBtn;
    QPushButton *m_maxBtn;
    QSpacerItem *m_titleSpacer;
    QSpacerItem *m_uNavSpacer;
    QSpacerItem *m_dNavSpacer;
    QStackedWidget *m_stackedContent;
    bool m_maximized = false;
    bool m_loginSt = false;
    Inn::NetConnService *m_netService;
signals:
    void UserLogout();
};


#endif //INNCLIENT_MAINWINDOW_H
