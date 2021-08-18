//
// Created by zyx on 2021/8/17.
//

#ifndef INNCLIENT_CHAT_CONTENT_H
#define INNCLIENT_CHAT_CONTENT_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include "./model/define.h"

class AbstractChatContent : public QWidget {
Q_OBJECT
public:
    AbstractChatContent();

protected:
    QLabel *m_contentTime;
    QTextBrowser *m_content;
    QHBoxLayout *m_contentLayout;

};

class IconChatContent : public AbstractChatContent {
public:
    IconChatContent();

private:
    void Init();

private:
    QLabel *m_userIcon;
    QLabel *m_userName;

    QVBoxLayout *m_iconLayout;
    QHBoxLayout *m_contentTitleLayout;
    QVBoxLayout *m_contentDetailLayout;
};

class ChatContent : public AbstractChatContent {
public:
    ChatContent();

private:
    void Init();

};

#endif //INNCLIENT_CHAT_CONTENT_H
