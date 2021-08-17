//
// Created by zyx on 2021/8/16.
//

#ifndef INNCLIENT_CHAT_ROOM_H
#define INNCLIENT_CHAT_ROOM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QSplitter>
#include "./component/text_editor.h"

class AbstractChatRoom : public QWidget {
Q_OBJECT
};

class SingleChatRoom : public AbstractChatRoom {
public:
    SingleChatRoom();

private:
    void Init();

private:
    QWidget *m_textEditorWidget;
    QWidget *m_textViewWidget;
    TextEditor *m_textEditor;
    QSplitter *m_splitter;
    QHBoxLayout *m_viewLayout;
    QHBoxLayout *m_editorLayout;
};


#endif //INNCLIENT_CHAT_ROOM_H
