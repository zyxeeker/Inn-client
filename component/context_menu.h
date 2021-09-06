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

    QPushButton *m_copyBtn = nullptr;
    QPushButton *m_highlightBtn = nullptr;

private:
    QGraphicsDropShadowEffect *m_effect;

signals:

    void Operation(int);
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

class ControlPanelContextMenu : public QWidget {
Q_OBJECT
public:
    ControlPanelContextMenu();

private:
    void InitBtn(QPushButton *btn, QString url, QString name);

private:
    QPushButton *m_onlineBtn;
    QPushButton *m_busyBtn;
    QPushButton *m_sleepBtn;
    QVBoxLayout *m_layout;
    QWidget *m_body;
    QGraphicsDropShadowEffect *m_effect;

};

#endif //INNCLIENT_CONTEXT_MENU_H
