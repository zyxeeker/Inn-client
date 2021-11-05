//
// Created by zyx on 2021/8/16.
//

#include "chat_room.h"
#include <QDebug>

ChatRoom::ChatRoom(QWidget *parent) : QWidget(parent) {
    m_layout = new QHBoxLayout(this);
    m_cef = new CefWidget(this);
    m_layout->addWidget(m_cef);
    m_layout->setContentsMargins(0, 0, 0, 0);
}