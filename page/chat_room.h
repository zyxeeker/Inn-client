//
// Created by zyx on 2021/8/16.
//

#ifndef INNCLIENT_CHAT_ROOM_H
#define INNCLIENT_CHAT_ROOM_H

#include <QWidget>
#include <QHBoxLayout>
#include "cef/cef_widget.h"

class ChatRoom : public QWidget {
Q_OBJECT
public:
    ChatRoom(QWidget *parent = nullptr);
private:
    CefWidget *m_cef;
    QHBoxLayout *m_layout;
};


#endif //INNCLIENT_CHAT_ROOM_H
