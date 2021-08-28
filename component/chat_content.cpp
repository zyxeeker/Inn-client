//
// Created by zyx on 2021/8/17.
//

#include "chat_content.h"
#include <QDebug>

TextBrowser::TextBrowser() {
    m_menu = new QMenu;
    m_aWidget = new QWidgetAction(m_menu);
    m_menuContainer = new QWidget(this);
    m_menuLayout = new QHBoxLayout;
    m_menuBody = new ChatContentSelectedContextMenu;

    m_menuLayout->setContentsMargins(0, 0, 0, 0);
    m_menuLayout->addWidget(m_menuBody);
    m_menuContainer->setLayout(m_menuLayout);
    m_menuContainer->setMinimumHeight(80);
    m_menuContainer->setMinimumWidth(400);

    m_aWidget->setDefaultWidget(m_menuContainer);
    m_menu->setWindowFlags(Qt::FramelessWindowHint);
    m_menu->setWindowFlag(Qt::Popup, true);
    m_menu->setAttribute(Qt::WA_TranslucentBackground);
    m_menu->setStyleSheet("background:transparent;");
    m_menu->addAction(m_aWidget);
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(m_menu->winId());
    DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
    class_style &= ~CS_DROPSHADOW;
    ::SetClassLong(hwnd, GCL_STYLE, class_style);
#endif

}

void TextBrowser::contextMenuEvent(QContextMenuEvent *e) {
    if (this->textCursor().selectedText() == this->document()->toPlainText())
        m_menuBody->SetBtnGroup(SELECTED_ALL);
    else if (this->textCursor().selectedText() != nullptr)
        m_menuBody->SetBtnGroup(SELECTED_PART);
    else {
        m_menuBody->SetBtnGroup(SELECTED_ALL);
        this->selectAll();
    }
    m_menu->exec(QPoint(cursor().pos().x() - 30, cursor().pos().y() - 30));
}

AbstractChatContent::AbstractChatContent() {
    m_contentTime = new QLabel;
    m_content = new TextBrowser;
    m_contentLayout = new QHBoxLayout;

    this->setStyleSheet("background:rgb(28,30,39);");
    m_contentTime->setMinimumWidth(60);
    m_contentTime->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:11px;");
    m_content->setStyleSheet(
            "border-width:0;border-style:outset;color:white;font-family:'Microsoft YaHei UI';font-size:13px;");
    m_content->setText(
            "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    m_content->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_content->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(m_content->document(), SIGNAL(contentsChanged()), this, SLOT(ChangeTextAreaSize()));

}

void AbstractChatContent::ChangeTextAreaSize() {
    QSize size = m_content->document()->size().toSize();
    m_content->setFixedHeight(size.height() + 3);
    this->setMinimumHeight(size.height() + 50);
    this->setMaximumHeight(size.height() + 50);
}

void AbstractChatContent::resizeEvent(QResizeEvent *e) {
    ChangeTextAreaSize();
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
            m_color = "rgb(255, 85, 127);";
            break;
        case MSG_UNREAD:
            m_color = "grey;";
            break;
    }
    m_layout = new QHBoxLayout;
    m_lLine = new QLabel;
    m_rLine = new QLabel;
    m_time = new QLabel;

    InitLine(m_rLine);
    InitLine(m_lLine);

    m_time->setText("2021/8/18");
    m_time->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    m_time->setStyleSheet("color:" + m_color + ";font-family:'Microsoft YaHei UI';font-size:14px;font-weight:medium;");

    m_layout->addWidget(m_lLine);
    m_layout->addWidget(m_time);
    m_layout->addWidget(m_rLine);
    this->setMinimumHeight(50);
    this->setMaximumHeight(50);
    this->setLayout(m_layout);
}

void ChatContentTimeStamp::InitLine(QLabel *l) {
    l->setStyleSheet("background-color:" + m_color);
    l->setMinimumHeight(2);
    l->setMaximumHeight(2);
}