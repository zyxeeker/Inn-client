//
// Created by zyx on 2021/10/13.
//

#include "navigation.h"
#include "model/utils.h"

#define NAV_STYLE_2 "QPushButton{background-color:rgb(36, 36, 36);border-radius:5px;margin:5px;}"\
                    "QPushButton:hover {background-color:rgb(195, 44, 73);}"\
                    "QPushButton:pressed {background-color:rgb(205, 45, 75);}"

Navigation::Navigation(QWidget *parent) : QWidget(parent) {
    m_layout = new QVBoxLayout(this);
    m_homeBtn = new NavBtn(":/nav/resource/home.svg", this);
    m_chatBtn = new NavBtn(":/nav/resource/chat.svg", this);
    m_streamBtn = new NavBtn(":/nav/resource/live.svg", this);
    m_settingBtn = new NavBtn(":/nav/resource/setting.svg", this);
    m_exitBtn = new QPushButton(this);
    m_uSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_dSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Preferred);
    InitUi();
    connect(m_homeBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(HOME);
    });
    connect(m_chatBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(CHAT);
    });
//    connect(m_streamBtn,&QPushButton::clicked,this,[=]{
//        emit SwitchNav(STREAM);
//    });
    connect(m_settingBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(SETTING);
    });
    connect(m_exitBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(EXIT);
    });
}

void Navigation::InitUi() {
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_homeBtn);
    m_layout->addWidget(m_chatBtn);
    m_layout->addWidget(m_streamBtn);
    m_layout->addWidget(m_settingBtn);
    m_layout->addItem(m_uSpacer);
    m_layout->addWidget(m_exitBtn);
    m_layout->addItem(m_dSpacer);
    m_layout->setSpacing(5);
    m_layout->setContentsMargins(0, 0, 0, 0);
    Utils::InitBtn(m_exitBtn, 50, 20, NAV_STYLE_2, ":/auth/resource/exit.png");
    m_homeBtn->setChecked(true);
}
