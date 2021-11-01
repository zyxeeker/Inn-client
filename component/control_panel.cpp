//
// Created by zyx on 2021/8/30.
//

#include "control_panel.h"
#include "service/user_service.h"
#include "model/utils.h"
#include <QDebug>

#define FONT_STYLE "color:white;font-family:'Microsoft YaHei UI';font-weight:medium;"

ControlPanel::ControlPanel(QString name) {
    m_container = new QWidget(this);
    m_userIcon = new QLabel(m_container);
    m_userName = new QLabel(m_container);
    m_userStText = new QLabel(m_container);
    m_userStIcon = new QLabel(m_container);
    m_moreBtn = new QPushButton(m_container);
    m_containerLayout = new QHBoxLayout(this);
    m_layout = new QHBoxLayout(m_container);
    m_userLayout = new QVBoxLayout;

    m_userIcon->setMinimumSize(40, 40);
    m_userIcon->setMaximumSize(40, 40);
    m_userIcon->setStyleSheet("border-radius:20px;background:white;");
    m_userName->setStyleSheet(QString(FONT_STYLE) + "font-size:14px;");
    m_userStText->setStyleSheet(QString(FONT_STYLE) + "font-size:10px;");

    m_userStIcon->setPixmap(m_online);
    m_userStIcon->setScaledContents(true);
    m_userStIcon->setGeometry(30, 31, 18, 18);

    m_moreBtn->setMaximumSize(30, 30);
    m_moreBtn->setMinimumSize(30, 30);
    m_moreBtn->setIcon(QIcon(":/common/resource/more.svg"));
    m_moreBtn->setIconSize(QSize(22, 22));
    m_moreBtn->setCursor(Qt::PointingHandCursor);
    m_moreBtn->setStyleSheet("QPushButton{background:rgb(36, 36, 36);border-radius:6px;}"
                             "QPushButton:hover{background:rgb(23, 23, 23);}");
    m_userLayout->addWidget(m_userName);
    m_userLayout->addWidget(m_userStText);
    m_userLayout->setContentsMargins(0, 5, 0, 5);
    m_userLayout->setSpacing(1);
    m_layout->addWidget(m_userIcon);
    m_layout->addLayout(m_userLayout);
    m_layout->addWidget(m_moreBtn);
    m_layout->setContentsMargins(8, 5, 10, 5);
    InitMenu();
    m_container->setObjectName("bk");
    m_container->setLayout(m_layout);
    m_container->setStyleSheet("#bk{border-top:1px solid rgb(59,59,59);background:rgb(36, 36, 36);}");
    m_containerLayout->addWidget(m_container);
    m_containerLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_containerLayout);
    connect(m_moreBtn, &QPushButton::clicked, [=]() {
        m_menu->exec(QPoint(QPoint(m_moreBtn->mapToGlobal(QPoint(0, 0)).x(),
                                   m_moreBtn->mapToGlobal(QPoint(0, 0)).y() - 90)));
    });
    connect(m_menuBody, &ControlPanelContextMenu::StatueChanged, this, &ControlPanel::StatueChanged);
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
    HWND hwnd = (HWND) m_menu->winId();
    DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
    class_style &= ~CS_DROPSHADOW;
    ::SetClassLong(hwnd, GCL_STYLE, class_style);
#endif
}

void ControlPanel::resizeEvent(QResizeEvent *event) {
    m_userName->setText(Utils::ElideText(m_userName, QString::fromStdString(UserService::Instance().userName)));
    m_userStText->setText(Utils::ElideText(m_userStText, m_st));
    if (event->size().width() <= 90)
        m_moreBtn->hide();
    if (event->size().width() > 90)
        m_moreBtn->show();
}

void ControlPanel::StatueChanged(int st) {
    switch (st) {
        case ONLINE: {
            m_st = "ONLINE";
            m_userStIcon->setPixmap(m_online);
            break;
        }
        case BUSY: {
            m_st = "BUSY";
            m_userStIcon->setPixmap(m_busy);
            break;
        }
        case SLEEP: {
            m_st = "SLEEP";
            m_userStIcon->setPixmap(m_sleep);
            break;
        }
    }
    m_userStText->setText(m_st);
    m_menu->close();
}