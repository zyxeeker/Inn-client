//
// Created by zyx on 2021/9/16.
//

#include "auth.h"

#define LOGIN_DATA_IS_EMPTY "User/password is empty!"
#define LOGIN_RESULT_SUC "Login success!"
#define LOGIN_RESULT_FAIL "Login failed!"

Auth::Auth(QWidget *parent) : BorderlessWindow(parent) {
    m_netService = Inn::NetService::Instance();
    m_centerWidget = new QWidget(this);
    m_centerLayout = new QVBoxLayout(m_centerWidget);

    m_bar = new AbstractTitleBar(this, true);
    m_title = new QWidget(this);
    m_titleLayout = new QHBoxLayout(m_title);

    m_content = new QWidget(m_centerWidget);
    m_contentLayout = new QHBoxLayout(m_content);
    m_user = new QLineEdit(m_content);
    m_pwd = new QLineEdit(m_content);
    m_uLabel = new QLabel(m_content);
    m_pLabel = new QLabel(m_content);
    m_slogan = new QLabel(m_content);
    m_notification = new QLabel(m_content);
    m_loginBtn = new LoginBtn(m_content);
    m_registerBtn = new QPushButton(m_content);
    m_forgetBtn = new QPushButton(m_content);
    m_remember = new QCheckBox(m_content);

    m_forgetLayout = new QHBoxLayout();
    m_regLayout = new QHBoxLayout();
    m_layout = new QVBoxLayout();
    m_rLayout = new QVBoxLayout();
    m_lHSpacer = new QSpacerItem(430, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_tVSpacer = new QSpacerItem(0, 120, QSizePolicy::Minimum, QSizePolicy::Maximum);
    m_rHSpacer = new QSpacerItem(35, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);
    m_bVSpacer = new QSpacerItem(0, 120, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_fSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_regSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    InitUi();
    InitTitleBar();
    InitContent();

    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setMaximumSize(700, 500);
    this->setMinimumSize(700, 500);

    connect(m_loginBtn, &QPushButton::clicked, this, &Auth::onReceiveUserInfo);
    connect(m_netService, &Inn::NetService::ReqResult, this, &Auth::onReceiveReqResult);
    connect(m_bar, &AbstractTitleBar::SwitchWindow, this, &Auth::SwitchWindow);
}

void Auth::InitUi() {
    this->setObjectName("bk");
    this->setStyleSheet("#bk{background:black;}QWidget:focus{outline: none;}");
    this->setCentralWidget(m_centerWidget);
    m_centerLayout->setContentsMargins(0, 0, 0, 0);
}

void Auth::InitTitleBar() {
    m_titleLayout->setContentsMargins(0, 0, 0, 0);
    m_titleLayout->setSpacing(0);
    m_titleLayout->addWidget(m_bar);
    this->layout()->setMenuBar(m_title);
}

void Auth::InitContent() {
    m_centerLayout->addWidget(m_content);
    QString pLabelStyle = "color:white;font-family:'Microsoft YaHei UI';font-size:12px;";
    QString pStyleSheet = "QLineEdit{" + pLabelStyle +
                          "font-size:14px;border-radius:2px;padding:5px;border:1px solid rgb(48, 48, 48);"
                          "background-color: rgb(36, 36, 36);selection-background-color: rgb(103,78,208);"
                          "selection-color: rgb(36, 36, 36);}"
                          "QLineEdit:focus{border-color: rgb(103,78,208);}";
    QString pBtnStyle = "QPushButton{" + pLabelStyle + "background-color:transparent;}"
                                                       "QPushButton:hover{color:rgb(103,78,208);}"
                                                       "QPushButton:disabled {color:lightgray;}";

    m_content->setObjectName("content");
    m_content->setStyleSheet("#content{background-image: url(:/auth/resource/bk.svg);}");

    m_user->setAttribute(Qt::WA_InputMethodEnabled, false);
    m_pwd->setAttribute(Qt::WA_InputMethodEnabled, false);

    m_contentLayout->setContentsMargins(0, 80, 30, 0);
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
    m_layout->addWidget(m_loginBtn);
    m_layout->addLayout(m_rLayout);
    m_layout->addLayout(m_regLayout);
    m_layout->addLayout(m_forgetLayout);
    m_layout->addItem(m_bVSpacer);

    m_rLayout->addWidget(m_remember);
    m_rLayout->setContentsMargins(0, 10, 0, 0);
    m_remember->setText("remember you?");
    m_remember->setStyleSheet("QCheckBox{" + pLabelStyle + "}QCheckBox::indicator {border:1px solid rgb(103,78,208);"
                                                           "border-radius:2px;background:transparent;width:13px;height:13px;}"
                                                           "QCheckBox::indicator:unchecked:hover{background-color: rgba(255, 255, 255, 50);}"
                                                           "QCheckBox::indicator:checked{background:rgb(103,78,208);"
                                                           "image: url(:/common/resource/checked.png);}");

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
    m_user->setFocus();
    m_pwd->setMaximumHeight(35);
    m_pwd->setMinimumHeight(35);
    m_pwd->setEchoMode(QLineEdit::Password);
    m_notification->setMaximumHeight(20);
    m_notification->setMinimumHeight(20);
    m_notification->setStyleSheet(pLabelStyle);

    m_loginBtn->setStyleSheet(
            "QPushButton{color:white;font-family:'Microsoft YaHei UI';font-size:12px;}");
    m_loginBtn->setText("LOGIN");
    m_loginBtn->setMinimumHeight(34);
    m_loginBtn->setMaximumHeight(34);
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

bool Auth::HitArea(const QPoint &gPos) {
    return m_bar->HitArea(gPos);
}

void Auth::mousePressEvent(QMouseEvent *event) {
#ifdef Q_OS_WIN
    QRect dragRecet(m_bar->rect().x(),
                    m_bar->rect().y(),
                    m_bar->rect().width(),
                    m_bar->rect().height());
    if (dragRecet.contains(event->pos()) && event->button() == Qt::LeftButton) {
        if (::ReleaseCapture()) {
            SendMessage((HWND) this->winId(), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
            event->ignore();
        }
    }
#endif
    BorderlessWindow::mousePressEvent(event);
}

void Auth::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return)
        onReceiveUserInfo();
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
        m_pwd->clear();
        emit LoginSuccess();
    }
}

void Auth::SwitchWindow(WINDOW_STATE st) {
    switch (st) {
        case WINDOW_CLOSE:{
            this->close();
            emit ClientQuit();
            break;
        }
        case WINDOW_MIN:
            this->hide();
            break;
    }
}
