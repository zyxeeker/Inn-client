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
#include "page/overview.h"
#include "page/chat_room.h"

#include "cef/cef_handler.h"
#include <include/cef_request_context.h>
#include "component/borderless_window.h"
#include "component/title_bar.h"
#include "component/navigation.h"
#include "model/define.h"

class MainWindow : public BorderlessWindow {
Q_OBJECT
public:
    MainWindow(Inn::NetConnService *s = nullptr, QWidget *parent = nullptr);
    bool HitArea(const QPoint &gPos) override;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
private:
    void InitUi();
    void InitTitleBar();
private:
    AbstractTitleBar *m_bar;
    Navigation *m_nav;
    QWidget *m_content;
    QWidget *m_centerWidget;
    QWidget *m_title;

    QVBoxLayout *m_titleLayout;
    QVBoxLayout *m_centerLayout;
    QHBoxLayout *m_contentLayout;
    QStackedWidget *m_stackedContent;

    Overview *m_overview;
    ChatRoom *m_chatRoom;
//    CefRefPtr<CefClientHandler> simple_handler_;
    Inn::NetConnService *m_netService;
public slots:
    void SwitchNav(NAVIGATION);
    void SwitchWindow(WINDOW_STATE);
signals:
    void UserLogout();

};


#endif //INNCLIENT_MAINWINDOW_H
