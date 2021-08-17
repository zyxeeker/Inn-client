//
// Created by zyx on 2021/8/16.
//

#ifndef INNCLIENT_TEXT_EDITOR_H
#define INNCLIENT_TEXT_EDITOR_H

#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>

class TextEditor : public QWidget {
Q_OBJECT
public:
    TextEditor();

private:
    void Init();

    void InitTextBlock();

private:
    QHBoxLayout *m_layout;
    QTextEdit *m_editBlock;
};


#endif //INNCLIENT_TEXT_EDITOR_H
