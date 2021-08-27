//
// Created by zyx on 2021/8/26.
//

#ifndef INNCLIENT_CONTEXT_MENU_H
#define INNCLIENT_CONTEXT_MENU_H

#include <QWidget>
#include <QMenu>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "./model/utils.h"

class AbstractContextMenu : public QWidget {
Q_OBJECT
public:
    AbstractContextMenu();

protected:
    void InitBtn(QPushButton *btn, QString url, QLayout *layout);

protected:
    QWidget *m_body;

private:
    QGraphicsDropShadowEffect *m_effect;
};

class ChatContentContextMenu : public AbstractContextMenu {
public:
    ChatContentContextMenu();

protected:
    QHBoxLayout *m_layout;

private:
    QPushButton *m_copyBtn;
    QPushButton *m_highLightBtn;
};

class AllChatContentSelectedContextMenu : public ChatContentContextMenu {
public:
    AllChatContentSelectedContextMenu();

private:
    QPushButton *m_thumbUpBtn;
    QPushButton *m_replyBtn;
};

#endif //INNCLIENT_CONTEXT_MENU_H
