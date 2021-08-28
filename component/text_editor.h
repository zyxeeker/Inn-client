//
// Created by zyx on 2021/8/16.
//

#ifndef INNCLIENT_TEXT_EDITOR_H
#define INNCLIENT_TEXT_EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QWidgetAction>

#ifdef Q_OS_WIN

#include <windows.h>

#endif

#include "context_menu.h"
#include "./model/define.h"

class TextEdit : public QTextEdit {
public:
    TextEdit();

protected:
    void contextMenuEvent(QContextMenuEvent *e);

private:
    QMenu *m_menu;
    QWidgetAction *m_aWidget;
    QWidget *m_menuContainer;
    QHBoxLayout *m_menuLayout;
    TextEditContentContextMenu *m_menuBody;
};

class TextEditor : public QWidget {
Q_OBJECT
public:
    TextEditor();

private:
    void Init();

    void InitTextBlock();

private:
    QHBoxLayout *m_layout;
    TextEdit *m_editBlock;
};


#endif //INNCLIENT_TEXT_EDITOR_H
