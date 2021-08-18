//
// Created by zyx on 2021/8/17.
//

#include "chat_content.h"

AbstractChatContent::AbstractChatContent() {
    m_contentTime = new QLabel;
    m_content = new QTextBrowser;
    m_contentLayout = new QHBoxLayout;

    this->setStyleSheet("background:black");
    m_contentTime->setMinimumWidth(60);
    m_contentTime->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:11px;");
    m_content->setStyleSheet(
            "border-width:0;border-style:outset;color:white;font-family:'Microsoft YaHei UI';font-size:13px;");
    m_content->setText("AAAAA");
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
    m_userIcon->setStyleSheet("background:white;border-radius:25px;");
    m_userName->setStyleSheet("padding-left:1px;color:white;font-family:'Microsoft YaHei UI';font-size:14px;");
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
    m_contentLayout->setSpacing(10);

    this->setLayout(m_contentLayout);

}

ChatContent::ChatContent() {
    Init();
}

void ChatContent::Init() {
    m_contentTime->setText("00:00");
    m_contentTime->setAlignment(Qt::AlignCenter);
    m_contentLayout->addWidget(m_contentTime);
    m_contentLayout->addWidget(m_content);
    this->setLayout(m_contentLayout);
}

ChatContentTimeStamp::ChatContentTimeStamp(int st) {
    switch (st) {
        case MSG_READ:
            m_style = "color: rgb(255, 85, 127);";
            break;
        case MSG_UNREAD:
            m_style = "color: grey;";
            break;
    }
    m_layout = new QHBoxLayout;
    m_lLine = new QFrame;
    m_rLine = new QFrame;
    m_time = new QLabel;

    InitLine(m_rLine);
    InitLine(m_lLine);

    m_time->setText("2021/8/18");
    m_time->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    m_time->setStyleSheet(m_style + "font-family:'Microsoft YaHei UI';font-size:14px;font-weight:medium;");

    m_layout->addWidget(m_lLine);
    m_layout->addWidget(m_time);
    m_layout->addWidget(m_rLine);
    this->setLayout(m_layout);
}

void ChatContentTimeStamp::InitLine(QFrame *l) {
    l->setStyleSheet(m_style);
    l->setFrameShadow(QFrame::Plain);
    l->setLineWidth(4);
    l->setFrameShape(QFrame::HLine);
}