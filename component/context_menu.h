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
    void InitBtn(QPushButton *btn, QString url);

protected:
    QWidget *m_body;
    QHBoxLayout *m_layout;

    QPushButton *m_copyBtn;
    QPushButton *m_highLightBtn;

private:
    QGraphicsDropShadowEffect *m_effect;
};

class ChatContentSelectedContextMenu : public AbstractContextMenu {
public:
    ChatContentSelectedContextMenu();

};

class AllChatContentSelectedContextMenu : public ChatContentSelectedContextMenu {
public:
    AllChatContentSelectedContextMenu();

private:
    QPushButton *m_thumbUpBtn;
    QPushButton *m_replyBtn;
};

class TextEditContentContextMenu : public AbstractContextMenu {
public:
    TextEditContentContextMenu();

protected:
    QPushButton *m_pasteBtn;
    QPushButton *m_cutBtn;

};

class TextEditContentSelectedContextMenu : public TextEditContentContextMenu {
public:
    TextEditContentSelectedContextMenu();

};

class AllTextEditContentSelectedContextMenu : public TextEditContentContextMenu {
public:
    AllTextEditContentSelectedContextMenu();

};

#endif //INNCLIENT_CONTEXT_MENU_H
