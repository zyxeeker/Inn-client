//
// Created by zyx on 2021/8/17.
//

#include "chat_content.h"

AbstractChatContent::AbstractChatContent() {
    m_contentTime = new QLabel;
    m_content = new QTextBrowser;
    m_contentLayout = new QHBoxLayout;
}

IconChatContent::IconChatContent() {
    Init();
}

void IconChatContent::Init() {
    m_userIcon = new QLabel;
    m_userName = new QLabel;
    m_contentTitleLayout = new QHBoxLayout;
    m_contentDetailLayout = new QVBoxLayout;
    m_iconLayout = new QVBoxLayout;

    m_userIcon->setMinimumSize(50, 50);
    m_userIcon->setMaximumSize(50, 50);
    m_userIcon->setStyleSheet("background:black;");
    m_userName->setText("AAABBBASBAB");
    m_contentTime->setText("2021/8/18");

    m_iconLayout->addWidget(m_userIcon);
    m_iconLayout->setAlignment(Qt::AlignTop);

    m_contentTitleLayout->addWidget(m_userName);
    m_contentTitleLayout->addWidget(m_contentTime);
    m_contentTitleLayout->setAlignment(Qt::AlignLeft);
    m_contentTitleLayout->setSpacing(8);
    m_contentDetailLayout->addItem(m_contentTitleLayout);
    m_contentDetailLayout->addWidget(m_content);
    m_contentLayout->addLayout(m_iconLayout);
    m_contentLayout->addLayout(m_contentDetailLayout);
    m_content->setContentsMargins(0, 0, 0, 0);

    this->setLayout(m_contentLayout);

}

ChatContent::ChatContent() {
    Init();
}

void ChatContent::Init() {
    m_contentTime->setText("2021/8/18");
    m_contentLayout->addWidget(m_contentTime);
    m_contentLayout->addWidget(m_content);
    this->setLayout(m_contentLayout);
}