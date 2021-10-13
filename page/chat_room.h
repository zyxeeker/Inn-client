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
#include "./component/text_editor.h"
#include "./component/chat_content.h"
#include "./component/smooth_scroll_area.h"
#include "./component/user.h"
#include "./component/control_panel.h"
#include "cef/_app.h"


class AbstractChatRoom : public QWidget {
Q_OBJECT
public:
    AbstractChatRoom();

protected:
    QHBoxLayout *m_layout;
    QSplitter *m_splitter;
    QWidget *m_chatInputArea;
    TextEditor *m_chatInput;
    QHBoxLayout *m_chatInputLayout;
    SmoothScrollArea *m_chatContentViewArea;
    QVBoxLayout *m_chatContentLayout;
};

class SingleChatRoom : public AbstractChatRoom {
public:
    SingleChatRoom();

private:
    void Init();

private:
    void AddChatContent();
};

class GroupChatRoom : public AbstractChatRoom {
public:
    GroupChatRoom();
    QWidget *GetWTest();

private:
    ControlPanel *m_cPanel;
    QSplitter *m_hSplitter;
    SmoothScrollArea *m_userListArea;
    QVBoxLayout *m_listLayout;
    SmoothScrollArea *m_navigation;
    QVBoxLayout *m_navigationLayout;
    QWidget *m_leftSide;
    QWidget *m_ceftest;
    QVBoxLayout *m_sideLayout;
    QHBoxLayout *m_gLayout;
    AppTest *ap;
//    CefRefPtr<SimpleHandler> simple_handler_; // 这里是新增的CefRefPtr<SimpleHandler>成员
};


#endif //INNCLIENT_CHAT_ROOM_H
