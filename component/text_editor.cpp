//
// Created by zyx on 2021/8/16.
//

#include "text_editor.h"

TextEditor::TextEditor() {
    Init();
}

void TextEditor::Init() {
    InitTextBlock();
}

void TextEditor::InitTextBlock() {
    m_editBlock = new QTextEdit(this);
    m_layout = new QHBoxLayout(this);

    m_layout->addWidget(m_editBlock);
    m_editBlock->setMinimumHeight(40);
    m_editBlock->setStyleSheet("QTextEdit{color:white;border-radius:6px;padding:5px;border:1px solid rgb(48, 48, 48);"
                               "color:white;font-family:'Microsoft YaHei UI';font-size:13px;selection-color: rgb(36, 36, 36);"
                               "background-color: rgb(36, 36, 36);selection-background-color: rgb(251, 174, 60);}"
                               "QTextEdit:focus{border-color: rgb(251, 174, 60);/*border-color: rgb(144, 187, 255);*/}");
    m_editBlock->setPlaceholderText("Wanna type something?");
    this->setLayout(m_layout);
}