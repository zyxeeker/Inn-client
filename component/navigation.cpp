//
// Created by zyx on 2021/10/13.
//

#include "navigation.h"
#include "model/utils.h"

#define NAV_STYLE_1 "QPushButton{background-color:rgb(36, 36, 36);border-radius:5px;margin:5px;}" \
                    "QPushButton:hover {background-color:rgb(52, 52, 52);}QPushButton:pressed {background-color:rgb(52, 52, 52);}" \
                    "QPushButton:checked {background-color:rgb(52, 52, 52);}"
#define NAV_STYLE_2 "QPushButton{background-color:rgb(36, 36, 36);border-radius:5px;margin:5px;}"\
                    "QPushButton:hover {background-color:rgb(195, 44, 73);}"\
                    "QPushButton:pressed {background-color:rgb(205, 45, 75);}"

Navigation::Navigation(QWidget *parent) : QWidget(parent) {
    m_layout = new QVBoxLayout(this);
    m_homeBtn = new QPushButton(this);
    m_singleChatBtn = new QPushButton(this);
    m_groupChatBtn = new QPushButton(this);
    m_streamBtn = new QPushButton(this);
    m_settingBtn = new QPushButton(this);
    m_exitBtn = new QPushButton(this);
    m_uSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_dSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Preferred);
    InitUi();
    connect(m_homeBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(HOME);
    });
//    connect(m_singleChatBtn,&QPushButton::clicked,this,[=]{
//        emit SwitchNav(HOME);
//    });
    connect(m_groupChatBtn, &QPushButton::clicked, this, [=] {
        emit SwitchNav(GROUP);
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
    m_layout->addWidget(m_singleChatBtn);
    m_layout->addWidget(m_groupChatBtn);
    m_layout->addWidget(m_streamBtn);
    m_layout->addWidget(m_settingBtn);
    m_layout->addItem(m_uSpacer);
    m_layout->addWidget(m_exitBtn);
    m_layout->addItem(m_dSpacer);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 0, 0, 0);
    Utils::InitBtn(m_homeBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/home.svg", ":/nav/resource/home_checked.svg");
    Utils::InitBtn(m_singleChatBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/people.svg",
                   ":/nav/resource/people_checked.svg");
    Utils::InitBtn(m_groupChatBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/group.svg", ":/nav/resource/group_checked.svg");
    Utils::InitBtn(m_streamBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/live.svg", ":/nav/resource/live_checked.svg");
    Utils::InitBtn(m_settingBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/setting.svg",
                   ":/nav/resource/setting_checked.svg");
    Utils::InitBtn(m_exitBtn, 50, 20, NAV_STYLE_2, ":/auth/resource/exit.png");
    m_homeBtn->setChecked(true);
}
