//
// Created by zyx on 2021/8/16.
//

#include "chat_room.h"
#include <QDebug>

NavItem::NavItem(QWidget *parent) : QPushButton(parent) {
    m_icon = new QLabel(this);
    m_name = new QLabel(this);
    m_layout = new QHBoxLayout(this);

    this->setCheckable(true);
    this->setAutoExclusive(true);
    this->setMinimumHeight(50);
    this->setMaximumHeight(50);
    this->setStyleSheet("QPushButton{border-radius:2px;background-color:rgb(36, 36, 36);color:white;}\n"
                        "QPushButton:hover {background-color:rgb(52, 52, 52);}QPushButton:pressed {background-color:rgb(52, 52, 52);}\n"
                        "QPushButton:checked {background-color:rgb(52, 52, 52);}");

    m_icon->setMaximumSize(40, 40);
    m_icon->setMinimumSize(40, 40);
    m_icon->setPixmap(QPixmap(QString::fromUtf8(":/common/resource/patchNote.png")));
    m_icon->setScaledContents(true);
    m_icon->setStyleSheet("background:transparent;padding:5px;");

    m_name->setMaximumHeight(40);
    m_name->setMinimumHeight(40);
    m_name->setMinimumWidth(0);
    m_name->setStyleSheet("background:transparent;color:white;font-family:'Microsoft YaHei UI';font-size:12px;");

    m_layout->addWidget(m_icon);
    m_layout->addWidget(m_name);
    m_layout->setContentsMargins(4, 4, 4, 4);
}

void NavItem::resizeEvent(QResizeEvent *event) {
    m_name->setText(Utils::ElideText(m_name, "DEV HOME"));
}

ChatRoom::ChatRoom(QWidget *parent) : QWidget(parent) {
    m_hSplitter = new QSplitter;
    m_listLayout = new QVBoxLayout;
    m_gLayout = new QHBoxLayout;
    m_navigationLayout = new QVBoxLayout;
    m_navigation = new SmoothScrollArea;
    m_leftSide = new QWidget;
    m_sideLayout = new QVBoxLayout;
    m_cPanel = new ControlPanel("");
    m_app = new QWidget;
    m_cef = new CefWidget(this);
    m_appLayout = new QHBoxLayout(m_app);

    m_navigationLayout->setAlignment(Qt::AlignTop);
    m_navigationLayout->setContentsMargins(0, 0, 3, 0);
    m_navigationLayout->setSpacing(2);
    m_navigation->SetContentLayout(m_navigationLayout);
    m_sideLayout->addWidget(m_navigation);
    m_sideLayout->addWidget(m_cPanel);
    m_sideLayout->setSpacing(0);
    m_sideLayout->setContentsMargins(0, 0, 0, 0);
    m_leftSide->setMaximumWidth(180);
    m_leftSide->setMinimumWidth(56);
    m_leftSide->setLayout(m_sideLayout);
    m_appLayout->setContentsMargins(0, 0, 0, 0);

    m_listLayout->setAlignment(Qt::AlignTop);
    m_hSplitter->setOrientation(Qt::Horizontal);
    m_hSplitter->addWidget(m_leftSide);
    m_appLayout->addWidget(m_cef);
    m_hSplitter->addWidget(m_app);
    m_hSplitter->setHandleWidth(2);
    m_hSplitter->setStyleSheet("QSplitter::handle{background-color: rgb(59,59,59);}");
    m_gLayout->addWidget(m_hSplitter);
    m_gLayout->setSpacing(0);
    m_gLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_gLayout);
    for (int i = 0; i < 50; ++i) {
        m_navigationLayout->addWidget(new NavItem);
    }
}