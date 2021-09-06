//
// Created by zyx on 2021/8/30.
//

#include "control_panel.h"

ControlPanel::ControlPanel(QString name) {
    m_userIcon = new QLabel;
    m_userName = new QLabel;
    m_userStatue = new QLabel;
    m_moreBtn = new QPushButton;
    m_layout = new QHBoxLayout;
    m_userLayout = new QVBoxLayout;

    this->setObjectName("bk");
    m_userIcon->setMinimumSize(40, 40);
    m_userIcon->setMaximumSize(40, 40);
    m_userIcon->setStyleSheet("border-radius:20px;background:white;");
    m_userName->setText("TEST TEST TEST");
    m_userName->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:14px;font-weight:medium;");
    m_userStatue->setText("OUTLINE");
    m_userStatue->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:10px;font-weight:medium;");

    m_moreBtn->setMaximumSize(30, 30);
    m_moreBtn->setMinimumSize(30, 30);
    m_moreBtn->setIcon(QIcon(":/common/resource/more.svg"));
    m_moreBtn->setIconSize(QSize(22, 22));
    m_moreBtn->setCursor(Qt::PointingHandCursor);
    m_moreBtn->setStyleSheet(
            "QPushButton{background:rgb(36, 36, 36);border-radius:6px;}QPushButton:hover{background:rgb(23, 23, 23);}");
    m_userLayout->addWidget(m_userName);
    m_userLayout->addWidget(m_userStatue);
    m_userLayout->setContentsMargins(0, 5, 0, 5);
    m_userLayout->setSpacing(1);
    m_layout->addWidget(m_userIcon);
    m_layout->addLayout(m_userLayout);
    m_layout->addWidget(m_moreBtn);
    m_layout->setContentsMargins(10, 5, 10, 5);
    InitMenu();
    connect(m_moreBtn, &QPushButton::clicked, [=]() {
        m_menu->exec(QPoint(QPoint(m_moreBtn->mapToGlobal(QPoint(0, 0)).x(),
                                   m_moreBtn->mapToGlobal(QPoint(0, 0)).y() - 90)));
    });
    this->setLayout(m_layout);
    this->setStyleSheet("#bk{border-top:1px solid rgb(59,59,59);background:rgb(36, 36, 36);}");
}

void ControlPanel::InitMenu() {
    m_menu = new QMenu;
    m_aWidget = new QWidgetAction(m_menu);
    m_menuContainer = new QWidget(this);
    m_menuLayout = new QHBoxLayout;
    m_menuBody = new ControlPanelContextMenu;
    m_menuLayout->setContentsMargins(0, 0, 0, 0);
    m_menuLayout->addWidget(m_menuBody);
    m_menuContainer->setLayout(m_menuLayout);
    m_menuContainer->setMinimumHeight(150);
    m_menuContainer->setMinimumWidth(200);

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