//
// Created by zyx on 2021/8/16.
//

#include "chat_room.h"

SingleChatRoom::SingleChatRoom() {
    Init();

}

void SingleChatRoom::Init() {
    m_layout = new QHBoxLayout;
    m_splitter = new QSplitter;
    m_chatContentViewArea = new SmoothScrollArea;
    m_chatContentLayout = new QVBoxLayout;
    m_chatInputArea = new QWidget;
    m_chatInput = new TextEditor;
    m_chatInputLayout = new QHBoxLayout;

    m_chatContentViewArea->SetContentLayout(m_chatContentLayout);

    m_chatInputLayout->addWidget(m_chatInput);
    m_chatInputLayout->setContentsMargins(0, 0, 0, 0);
    m_chatInputArea->setLayout(m_chatInputLayout);
    m_chatInputArea->setStyleSheet("background:black;");

    m_splitter->setOrientation(Qt::Vertical);
    m_splitter->addWidget(m_chatContentViewArea);
    m_splitter->addWidget(m_chatInputArea);
    m_layout->addWidget(m_splitter);
    m_layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_layout);

#if 1
    AddChatContent();
    AddChatContent();
    AddChatContent();
    AddChatContent();
    AddChatContent();
    AddChatContent();
    AddChatContent();
#endif

}

void SingleChatRoom::AddChatContent() {
    auto *t = new IconChatContent;
    t->setStyleSheet("border:1px solid red;");
    m_chatContentLayout->addWidget(t);
}