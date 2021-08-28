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
#include "./model/define.h"

class AbstractContextMenu : public QWidget {
Q_OBJECT
public:
    AbstractContextMenu();

    virtual void SetBtnGroup(int st) = 0;

protected:
    void InitBtn(QPushButton *btn, QString url);

protected:
    int m_st;
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

    void SetBtnGroup(int st);

private:
    QPushButton *m_thumbUpBtn;
    QPushButton *m_replyBtn;
};

class TextEditContentContextMenu : public AbstractContextMenu {
public:
    TextEditContentContextMenu();

    void SetBtnGroup(int st);

protected:
    QPushButton *m_pasteBtn;
    QPushButton *m_cutBtn;

};

#endif //INNCLIENT_CONTEXT_MENU_H
