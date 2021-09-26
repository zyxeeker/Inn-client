//
// Created by zyx on 2021/9/16.
//

#include "auth.h"

#define LOGIN_DATA_IS_EMPTY "User/password is empty!"
#define LOGIN_RESULT_SUC "Login success!"
#define LOGIN_RESULT_FAIL "Login failed!"

Auth::Auth(Inn::NetConnService *s) : m_netService(s) {
    m_user = new QLineEdit;
    m_pwd = new QLineEdit;
    m_uLabel = new QLabel;
    m_pLabel = new QLabel;
    m_slogan = new QLabel;
    m_titleLabel = new QLabel;
    m_notification = new QLabel;
    m_loginBtn = new QPushButton;
    m_quitBtn = new QPushButton;
    m_registerBtn = new QPushButton;
    m_forgetBtn = new QPushButton;
    m_remember = new QCheckBox;
    m_title = new QWidget;
    m_content = new QWidget;
    m_minBtn = new QPushButton;
    m_closeBtn = new QPushButton;
    m_titleLayout = new QHBoxLayout;
    m_forgetLayout = new QHBoxLayout;
    m_regLayout = new QHBoxLayout;
    m_mainLayout = new QVBoxLayout;
    m_layout = new QVBoxLayout;
    m_layout_1 = new QHBoxLayout;
    m_contentLayout = new QHBoxLayout;
    m_rLayout = new QVBoxLayout;
    m_lHSpacer = new QSpacerItem(430, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_tVSpacer = new QSpacerItem(0, 120, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_rHSpacer = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_bVSpacer = new QSpacerItem(0, 120, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_fSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_regSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    InitUi();
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

void Auth::InitUi() {
    this->setLayout(m_mainLayout);
    this->setMaximumSize(700, 500);
    this->setMinimumSize(700, 500);
    this->setObjectName("bk");
    this->setStyleSheet("#bk{background:black;}QWidget:focus{outline: none;}");
    m_mainLayout->addWidget(m_title);
    m_mainLayout->addWidget(m_content);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->setSpacing(0);
    InitTitle();
    InitContent();
    connect(m_loginBtn, &QPushButton::clicked, this, &Auth::onReceiveUserInfo);
    connect(m_netService, &Inn::NetConnService::ReqResult, this, &Auth::onReceiveReqResult);
    connect(m_quitBtn, &QPushButton::clicked, [=]() {
        this->close();
        emit ClientQuit();
    });
    connect(m_minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(m_closeBtn, &QPushButton::clicked, this, [=]() {
        this->hide();
    });
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
    m_titleLabel->setStyleSheet("font-family:'Microsoft YaHei UI';font-size:13px;color:lightgray;");

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
    QString pLabelStyle = "color:white;font-family:'Microsoft YaHei UI';font-size:12px;";
    QString pStyleSheet = "QLineEdit{" + pLabelStyle +
                          "font-size:14px;border-radius:2px;padding:5px;border:1px solid rgb(48, 48, 48);"
                          "background-color: rgb(36, 36, 36);selection-background-color: rgb(251, 174, 60);"
                          "selection-color: rgb(36, 36, 36);}"
                          "QLineEdit:focus{border-color: rgb(251, 174, 60);}";
    QString pBtnStyle = "QPushButton{" + pLabelStyle + "background-color:transparent;}"
                                                       "QPushButton:hover{color:rgb(251, 174, 60);}"
                                                       "QPushButton:disabled {color:lightgray;}";

    m_content->setObjectName("content");
    m_content->setStyleSheet("#content{background-image: url(:/auth/resource/bk.png);"
                             "border-bottom-left-radius: 5px;border-bottom-right-radius: 5px;}");
    m_content->setMaximumSize(700, 500);
    m_content->setMinimumSize(700, 500);
    m_content->setLayout(m_contentLayout);

    m_contentLayout->addItem(m_lHSpacer);
    m_contentLayout->addLayout(m_layout);
    m_contentLayout->addItem(m_rHSpacer);

    m_layout->setSpacing(6);
    m_layout->addItem(m_tVSpacer);
    m_layout->addWidget(m_slogan);
    m_layout->addWidget(m_uLabel);
    m_layout->addWidget(m_user);
    m_layout->addWidget(m_pLabel);
    m_layout->addWidget(m_pwd);
    m_layout->addWidget(m_notification);
    m_layout->addLayout(m_layout_1);
    m_layout->addLayout(m_rLayout);
    m_layout->addLayout(m_regLayout);
    m_layout->addLayout(m_forgetLayout);
    m_layout->addItem(m_bVSpacer);

    m_rLayout->addWidget(m_remember);
    m_rLayout->setContentsMargins(0, 0, 0, 0);
    m_remember->setText("remember you?");
    m_remember->setStyleSheet("QCheckBox{" + pLabelStyle + "}QCheckBox::indicator {border:1px solid rgb(251, 174, 60);"
                                                           "border-radius:2px;background:transparent;width:13px;height:13px;}"
                                                           "QCheckBox::indicator:unchecked:hover{background-color: rgba(255, 255, 255, 50);}"
                                                           "QCheckBox::indicator:checked{background:rgb(251, 174, 60);"
                                                           "image: url(:/common/resource/checked.png);}");

    m_layout_1->addWidget(m_quitBtn);
    m_layout_1->addWidget(m_loginBtn);

    m_slogan->setMaximumHeight(30);
    m_slogan->setMinimumHeight(30);
    m_slogan->setText("LOGIN");
    m_slogan->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:20px;");
    m_slogan->setAlignment(Qt::AlignCenter);

    m_uLabel->setText("Username");
    m_uLabel->setStyleSheet(pLabelStyle);
    m_uLabel->setMinimumHeight(20);
    m_uLabel->setMaximumHeight(20);
    m_pLabel->setText("Password");
    m_pLabel->setStyleSheet(pLabelStyle);
    m_pLabel->setMinimumHeight(20);
    m_pLabel->setMaximumHeight(20);
    m_user->setStyleSheet(pStyleSheet);
    m_pwd->setStyleSheet(pStyleSheet);
    m_user->setMaximumHeight(35);
    m_user->setMinimumHeight(35);
    m_pwd->setMaximumHeight(35);
    m_pwd->setMinimumHeight(35);
    m_pwd->setEchoMode(QLineEdit::Password);
    m_notification->setMaximumHeight(20);
    m_notification->setMinimumHeight(20);
    m_notification->setStyleSheet(pLabelStyle);
    m_quitBtn->setStyleSheet(
            "QPushButton{border-radius:2px;border-top-right-radius:5px;"
            "border-top-left-radius:15px;border-bottom-left-radius:5px;border-bottom-right-radius:5px;"
            "background-color:#A7233A;}"
            "QPushButton:hover {background-color:rgb(205, 45, 75);color:white;}"
            "QPushButton:pressed {background-color:rgb(205, 45, 75);}"
            "QPushButton:disabled {background-color:gray;color:lightgray;}");
    m_quitBtn->setMinimumSize(35, 35);
    m_quitBtn->setMaximumSize(35, 35);
    pExitIcon.addFile(":/auth/resource/exit.png");
    m_quitBtn->setIconSize(QSize(15, 15));
    m_quitBtn->setIcon(pExitIcon);
    m_quitBtn->setCursor(Qt::PointingHandCursor);
    m_loginBtn->setStyleSheet(
            "QPushButton{color:white;font-family:'Microsoft YaHei UI';font-size:12px;"
            "border-top-right-radius:15px;border-top-left-radius:5px;border-bottom-left-radius:5px;"
            "border-bottom-right-radius:5px;background-color:rgb(65, 65, 65);color:white;}"
            "QPushButton:hover {background-color:rgba(251, 174, 60, 250);color:white;}"
            "QPushButton:pressed {background-color:rgba(251, 174, 60, 250);}"
            "QPushButton:disabled {background-color:gray;color:lightgray;}");
    m_loginBtn->setText("LOGIN");
    m_loginBtn->setMaximumHeight(35);
    m_loginBtn->setMaximumHeight(35);
    m_loginBtn->setCursor(Qt::PointingHandCursor);

    m_regLayout->addItem(m_regSpacer);
    m_regLayout->addWidget(m_registerBtn);
    m_regLayout->addItem(m_regSpacer);
    m_registerBtn->setStyleSheet(pBtnStyle);
    m_registerBtn->setText("Register");
    m_registerBtn->setCursor(Qt::PointingHandCursor);

    m_forgetLayout->addItem(m_fSpacer);
    m_forgetLayout->addWidget(m_forgetBtn);
    m_forgetLayout->addItem(m_fSpacer);
    m_forgetBtn->setStyleSheet(pBtnStyle);
    m_forgetBtn->setText("Forget?");
    m_forgetBtn->setCursor(Qt::PointingHandCursor);

}

void Auth::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
        if (m_mousePosition.x() <= m_titleXMin) return;
        if (m_mousePosition.x() >= m_titleXMax) return;
        if (m_mousePosition.y() <= m_titleYMin) return;
        if (m_mousePosition.y() >= m_titleYMax) return;
        m_mousePress = true;
    }
}

void Auth::mouseMoveEvent(QMouseEvent *e) {
    if (m_mousePress) {
        QPoint position = e->globalPos();
        this->move(position - m_mousePosition);
    }
}

void Auth::mouseReleaseEvent(QMouseEvent *e) {
    m_mousePress = false;
}

void Auth::onReceiveUserInfo() {
    QString pUser = m_user->text();
    QString pPwd = m_pwd->text();
    if (pUser.isEmpty() || pPwd.isEmpty())
        m_notification->setText(LOGIN_DATA_IS_EMPTY);
    else {
        m_netService->SetUserInfo(pUser.toStdString(), pPwd.toStdString());
        m_netService->Req(NET_SERVICE::LOGIN_REQ);
    }
}

void Auth::onReceiveReqResult(NET_SERVICE::REQ_RESULT result) {
    if (result == NET_SERVICE::LOGIN_FAIL)
        m_notification->setText(LOGIN_RESULT_FAIL);
    else if (result == NET_SERVICE::LOGIN_SUC) {
        m_notification->setText(LOGIN_RESULT_SUC);
        m_pwd->clear();
        emit LoginSuccess();
    }
}