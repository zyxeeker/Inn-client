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
#include <QResizeEvent>
#include <QScrollBar>
#include "./model/define.h"

class AbstractChatContent : public QWidget {
Q_OBJECT
public:
    AbstractChatContent();

protected:
    void resizeEvent(QResizeEvent *e);

protected:
    QLabel *m_contentTime;
    QTextBrowser *m_content;
    QHBoxLayout *m_contentLayout;

private slots:

    void ChangeTextAreaSize();
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

class ChatContentTimeStamp : public QWidget {
public:
    ChatContentTimeStamp(int st);

private:
    void InitLine(QFrame *l);

private:
    QHBoxLayout *m_layout;
    QFrame *m_rLine;
    QFrame *m_lLine;
    QLabel *m_time;
    QString m_style;
};

#endif //INNCLIENT_CHAT_CONTENT_H
