//
// Created by zyx on 2021/8/16.
//

#include "chat_room.h"

AbstractChatRoom::AbstractChatRoom() {
    m_layout = new QHBoxLayout;
    m_splitter = new QSplitter;
    m_chatInputArea = new QWidget;
    m_chatInput = new TextEditor;
    m_chatInputLayout = new QHBoxLayout;
    m_chatContentViewArea = new SmoothScrollArea;
    m_chatContentLayout = new QVBoxLayout;

    m_chatContentLayout->setAlignment(Qt::AlignTop);
    m_chatContentViewArea->SetContentLayout(m_chatContentLayout);

    m_chatInputLayout->addWidget(m_chatInput);
    m_chatInputLayout->setContentsMargins(0, 0, 0, 0);
    m_chatInputArea->setLayout(m_chatInputLayout);
    m_chatInputArea->setStyleSheet("background:rgb(28,30,39);");

    m_splitter->setOrientation(Qt::Vertical);
    m_splitter->addWidget(m_chatContentViewArea);
    m_splitter->addWidget(m_chatInputArea);
    m_splitter->setHandleWidth(1);
    m_splitter->setStyleSheet("QSplitter::handle{background-color: rgb(59,59,59);}");

    m_layout->addWidget(m_splitter);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

SingleChatRoom::SingleChatRoom() {
    Init();

}

void SingleChatRoom::Init() {
    this->setLayout(m_layout);

//#if _DEBUG
    AddChatContent();
//    AddChatContent();
//    AddChatContent();
//    AddChatContent();
//    AddChatContent();
//    AddChatContent();
//    AddChatContent();
//#endif

}

void SingleChatRoom::AddChatContent() {
    auto *t1 = new ChatContentTimeStamp(0);
    auto *t2 = new ChatContent;
    auto *t = new IconChatContent;
    m_chatContentLayout->addWidget(t1);
    m_chatContentLayout->addWidget(t);
    m_chatContentLayout->addWidget(t2);

}

GroupChatRoom::GroupChatRoom() {
    m_hSplitter = new QSplitter;
    m_userListArea = new SmoothScrollArea;
    m_listLayout = new QVBoxLayout;
    m_gLayout = new QHBoxLayout;
    m_navigationLayout = new QVBoxLayout;
    m_navigation = new SmoothScrollArea;
    m_leftSide = new QWidget;
    m_sideLayout = new QVBoxLayout;
    m_cPanel = new ControlPanel("");

    m_navigationLayout->setAlignment(Qt::AlignTop);
    m_navigation->setLayout(m_navigationLayout);
//    m_navigation->setStyleSheet("background:white;");
    m_sideLayout->addWidget(m_navigation);
    m_sideLayout->addWidget(m_cPanel);
    m_sideLayout->setSpacing(0);
    m_sideLayout->setContentsMargins(0, 0, 0, 0);
//    m_leftSide->setMaximumWidth(180);
    m_leftSide->setMinimumWidth(180);
    m_leftSide->setLayout(m_sideLayout);

    m_listLayout->setAlignment(Qt::AlignTop);
    m_userListArea->SetContentLayout(m_listLayout);
    m_hSplitter->setOrientation(Qt::Horizontal);
    m_hSplitter->addWidget(m_leftSide);
    m_hSplitter->addWidget(m_splitter);
    m_hSplitter->addWidget(m_userListArea);
    m_hSplitter->setHandleWidth(1);
    m_hSplitter->setStyleSheet("QSplitter::handle{background-color: rgb(59,59,59);}");
    m_gLayout->addWidget(m_hSplitter);
    m_gLayout->setSpacing(0);
    m_gLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_gLayout);
#if _DEBUG
    auto *t = new ListUser;
    auto *t1 = new ListUser;
    auto *t2 = new ListUser;
    m_listLayout->addWidget(t);
    m_listLayout->addWidget(t1);
    m_listLayout->addWidget(t2);
#endif
}