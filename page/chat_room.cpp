//
// Created by zyx on 2021/8/16.
//

#include "chat_room.h"

SingleChatRoom::SingleChatRoom() {
    Init();

}

void SingleChatRoom::Init() {
    m_splitter = new QSplitter(this);
    m_editorLayout = new QHBoxLayout;
    QHBoxLayout *layout = new QHBoxLayout;
    m_textEditor = new TextEditor;
    m_textEditorWidget = new QWidget;
    m_textViewWidget = new QWidget;

    m_editorLayout->setContentsMargins(0, 0, 0, 0);
    m_editorLayout->addWidget(m_textEditor);
    m_textEditorWidget->setLayout(m_editorLayout);

    m_textViewWidget->setMinimumHeight(200);
    m_textEditorWidget->setMaximumHeight(500);
    m_textEditorWidget->setStyleSheet("background:black;");

    m_splitter->setOrientation(Qt::Vertical);
    m_splitter->addWidget(m_textViewWidget);
    m_splitter->addWidget(m_textEditorWidget);
    layout->addWidget(m_splitter);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}