//
// Created by zyx on 2021/8/16.
//

#ifndef INNCLIENT_CHAT_ROOM_H
#define INNCLIENT_CHAT_ROOM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSplitter>
#include <QScrollArea>
#include <QResizeEvent>
#include "component/smooth_scroll_area.h"
#include "component/control_panel.h"
#include "cef/cef_widget.h"

class NavItem : public QPushButton {
Q_OBJECT
public:
    NavItem(QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    QLabel *m_icon;
    QLabel *m_name;
    QHBoxLayout *m_layout;
};

class ChatRoom : public QWidget {
Q_OBJECT
public:
    ChatRoom(QWidget *parent = nullptr);
private:
    ControlPanel *m_cPanel;
    QSplitter *m_hSplitter;
    QVBoxLayout *m_listLayout;
    SmoothScrollArea *m_navigation;
    QVBoxLayout *m_navigationLayout;
    QWidget *m_leftSide;
    QWidget *m_app;
    QVBoxLayout *m_sideLayout;
    QHBoxLayout *m_gLayout;
    QHBoxLayout *m_appLayout;
    CefWidget *m_cef;
};


#endif //INNCLIENT_CHAT_ROOM_H
