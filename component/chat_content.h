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
#include <QWidgetAction>

#ifdef Q_OS_WIN

#include <windows.h>

#endif

#include "./model/define.h"
#include "context_menu.h"

class TextBrowser : public QTextBrowser {
Q_OBJECT
public:
    TextBrowser();

protected:
    void contextMenuEvent(QContextMenuEvent *e);

private:
    QMenu *m_menu;
    QWidgetAction *m_aWidget;
    QPoint m_mousePosition;
    QWidget *m_menuContainer;
    QHBoxLayout *m_menuLayout;
    ChatContentSelectedContextMenu *m_menuBody;

private slots:

    void Operation(int);
};

class AbstractChatContent : public QWidget {
Q_OBJECT
public:
    AbstractChatContent();

protected:
    void resizeEvent(QResizeEvent *e);

protected:
    QLabel *m_contentTime;
    TextBrowser *m_content;
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
    void InitLine(QLabel *l);

private:
    QHBoxLayout *m_layout;
    QLabel *m_rLine;
    QLabel *m_lLine;
    QLabel *m_time;
    QString m_color;
};

#endif //INNCLIENT_CHAT_CONTENT_H
