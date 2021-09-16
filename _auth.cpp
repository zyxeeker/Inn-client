//
// Created by zyx on 2021/9/16.
//

#include "_auth.h"

Auth::Auth(Inn::NetConnService *service) {
    InitUi();
}

void Auth::InitUi() {
    m_user = new QLineEdit;
    m_pwd = new QLineEdit;
    m_uLabel = new QLabel;
    m_pLabel = new QLabel;
    m_loginBtn = new QPushButton;
    m_exitBtn = new QPushButton;
    m_remember = new QCheckBox;
    m_rLabel = new QLabel;
    m_title = new QWidget;
    m_content = new QWidget;
    m_titleLabel = new QLabel;
    m_minBtn = new QPushButton;
    m_closeBtn = new QPushButton;
    m_titleLayout = new QHBoxLayout;
    m_mainLayout = new QVBoxLayout;
    m_layout = new QVBoxLayout;
    m_layout_1 = new QHBoxLayout;
    m_contentLayout = new QHBoxLayout;
    m_rLayout = new QVBoxLayout;
    m_lHSpacer = new QSpacerItem(430, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_tVSpacer = new QSpacerItem(0, 80, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_rHSpacer = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_bVSpacer = new QSpacerItem(0, 150, QSizePolicy::Expanding, QSizePolicy::Minimum);

    this->setLayout(m_mainLayout);
    m_mainLayout->addWidget(m_title);
    m_mainLayout->addWidget(m_content);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    InitTitle();
    InitContent();
}

void Auth::InitTitle() {
    QIcon pCloseIcon;
    QIcon pMinIcon;
    m_title->setObjectName("title");
    m_title->setMaximumSize(700, 30);
    m_title->setMinimumSize(700, 30);
    m_title->setStyleSheet("#title{background-color: rgb(36, 36, 36);"
                           "border-top-right-radius:2px;border-top-left-radius:2px;}");
    m_title->setLayout(m_titleLayout);
    m_titleLayout->setContentsMargins(5, 0, 0, 0);
    m_titleLayout->setSpacing(0);
    m_titleLayout->addWidget(m_titleLabel);
    m_titleLayout->addWidget(m_minBtn);
    m_titleLayout->addWidget(m_closeBtn);

    m_minBtn->setMinimumSize(30, 30);
    m_minBtn->setMaximumSize(30, 30);
    m_closeBtn->setMinimumSize(30, 30);
    m_closeBtn->setMaximumSize(30, 30);
    m_minBtn->setStyleSheet("QPushButton{border-top-right-radius:2px;background-color:rgba(65, 65, 65, 120);}"
                            "QPushButton:hover {background-color:rgba(65, 65, 65, 200);color:white;}"
                            "QPushButton:pressed {background-color:rgb(65, 65, 65);}");
    m_closeBtn->setStyleSheet("QPushButton{border-top-right-radius:2px;background-color:rgb(167, 35, 58);}"
                              "QPushButton:hover {background-color:rgba(205, 45, 75, 240);color:white;}"
                              "QPushButton:pressed {background-color:rgb(205, 45, 75);}");
    m_titleLabel->setText("Inn");
    m_titleLabel->setStyleSheet("color:lightgray;");

    pCloseIcon.addFile(":/common/resource/close.svg");
    m_closeBtn->setIcon(pCloseIcon);
    m_closeBtn->setIconSize(QSize(15, 15));

    pMinIcon.addFile(":/common/resource/hide.svg");
    m_minBtn->setIcon(pMinIcon);
    m_minBtn->setIconSize(QSize(15, 15));

    m_closeBtn->setCursor(Qt::PointingHandCursor);
    m_minBtn->setCursor(Qt::PointingHandCursor);
}

void Auth::InitContent() {
    QIcon pExitIcon;
    QString pStyleSheet = "QLineEdit{color:white;border-radius:2px;padding:5px;border:1px solid rgb(48, 48, 48);background-color: rgb(36, 36, 36);selection-background-color: rgb(251, 174, 60);selection-color: rgb(36, 36, 36);}QLineEdit:focus{border-color: rgb(251, 174, 60);}";
    m_content->setMaximumSize(700, 500);
    m_content->setMinimumSize(700, 500);
    m_content->setLayout(m_contentLayout);

    m_contentLayout->addItem(m_lHSpacer);
    m_contentLayout->addLayout(m_layout);
    m_contentLayout->addItem(m_rHSpacer);

    m_layout->setSpacing(6);
    m_layout->addItem(m_tVSpacer);
    m_layout->addWidget(m_uLabel);
    m_layout->addWidget(m_user);
    m_layout->addWidget(m_pLabel);
    m_layout->addWidget(m_pwd);
    m_layout->addLayout(m_layout_1);
    m_layout->addLayout(m_rLayout);
    m_layout->addItem(m_bVSpacer);

    m_rLayout->addWidget(m_remember);
    m_rLayout->addWidget(m_rLabel);
    m_rLayout->setContentsMargins(0, 0, 0, 0);
    m_rLayout->setSpacing(2);

    m_layout_1->addWidget(m_exitBtn);
    m_layout_1->addWidget(m_loginBtn);

    m_uLabel->setText("Username");
    m_uLabel->setStyleSheet("color:white;");
    m_uLabel->setMinimumHeight(20);
    m_uLabel->setMaximumHeight(20);
    m_pLabel->setText("Password");
    m_pLabel->setStyleSheet("color:white;");
    m_pLabel->setMinimumHeight(20);
    m_pLabel->setMaximumHeight(20);
    m_user->setStyleSheet(pStyleSheet);
    m_pwd->setStyleSheet(pStyleSheet);
    m_user->setMaximumHeight(35);
    m_user->setMinimumHeight(35);
    m_pwd->setMaximumHeight(35);
    m_pwd->setMinimumHeight(35);
    m_pwd->setEchoMode(QLineEdit::Password);
    m_exitBtn->setStyleSheet(
            "QPushButton{border-radius:2px;border-top-right-radius:5px;border-top-left-radius:15px;border-bottom-left-radius:5px;border-bottom-right-radius:5px;background-color:#A7233A;}QPushButton:hover {background-color:rgb(205, 45, 75);color:white;}QPushButton:pressed {background-color:rgb(205, 45, 75);}QPushButton:disabled {background-color:gray;color:lightgray;}");
    m_exitBtn->setMinimumSize(35, 35);
    m_exitBtn->setMaximumSize(35, 35);
    pExitIcon.addFile(":/auth/resource/exit.png");
    m_exitBtn->setIconSize(QSize(15, 15));
    m_exitBtn->setIcon(pExitIcon);
    m_exitBtn->setCursor(Qt::PointingHandCursor);
    m_loginBtn->setStyleSheet(
            "QPushButton{border-top-right-radius:15px;border-top-left-radius:5px;border-bottom-left-radius:5px;border-bottom-right-radius:5px;background-color:rgb(65, 65, 65);color:white;}QPushButton:hover {background-color:rgba(251, 174, 60, 250);color:white;}QPushButton:pressed {background-color:rgba(251, 174, 60, 250);}QPushButton:disabled {background-color:gray;color:lightgray;}");
    m_loginBtn->setText("LOGIN");
    m_loginBtn->setMaximumHeight(35);
    m_loginBtn->setMaximumHeight(35);
    m_loginBtn->setCursor(Qt::PointingHandCursor);

}