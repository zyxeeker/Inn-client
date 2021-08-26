//
// Created by zyx on 2021/8/26.
//

#ifndef INNCLIENT_CONTEXT_MENU_H
#define INNCLIENT_CONTEXT_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include "./model/utils.h"

class AbstractContextMenu : public QWidget {
public:
    AbstractContextMenu();

protected:
    QWidget *m_body;

private:
    QGraphicsDropShadowEffect *m_effect;
};

class ChatContentContextMenu : public AbstractContextMenu {
public:
    ChatContentContextMenu();

private:
    void InitBtn(QPushButton *btn, QString url);

private:
    QHBoxLayout *m_layout;
    QPushButton *m_copyBtn;
    QPushButton *m_replyBtn;
    QPushButton *m_agreeBtn;
};

#endif //INNCLIENT_CONTEXT_MENU_H
