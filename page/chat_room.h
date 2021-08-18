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

class AbstractChatRoom : public QWidget {
Q_OBJECT
};

class SingleChatRoom : public AbstractChatRoom {
public:
    SingleChatRoom();

private:
    void Init();

private:
    void AddChatContent();

private:
    QHBoxLayout *m_layout;
    QSplitter *m_splitter;

    QScrollArea *m_chatContentViewArea;
    QWidget *m_chatContentWidget;
    QVBoxLayout *m_chatContentLayout;

    QWidget *m_chatInputArea;
    TextEditor *m_chatInput;
    QHBoxLayout *m_chatInputLayout;
};


#endif //INNCLIENT_CHAT_ROOM_H
