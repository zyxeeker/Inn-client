//
// Created by zyx on 2021/9/22.
//

#include "component/context_menu.h"
#include "service/logger_service.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : BorderlessWindow(parent) {
    m_netService = Inn::NetService::Instance();
    m_centerWidget = new QWidget(this);
    m_centerLayout = new QVBoxLayout(m_centerWidget);
    m_content = new QWidget(m_centerWidget);
    m_contentLayout = new QHBoxLayout(m_content);
    m_nav = new Navigation(m_content);
    m_stackedContent = new QStackedWidget(m_content);
    m_bar = new AbstractTitleBar(this);
    m_title = new QWidget(this);
    m_titleLayout = new QVBoxLayout(m_title);
    m_overview = new Overview(m_netService->GetUser(), m_stackedContent);
    m_chatRoom = new ChatRoom;

    InitUi();
    InitTitleBar();

    this->setMinimumSize(800, 600);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_DeleteOnClose, true);

    connect(m_nav, &Navigation::SwitchNav, this, &MainWindow::SwitchNav);
    connect(m_bar, &AbstractTitleBar::SwitchWindow, this, &MainWindow::SwitchWindow);
    connect(this, &MainWindow::UpdateWindowState, m_bar, &AbstractTitleBar::SetMaximizedState);

    connect(&CtrlMenu::Instance(), &CtrlMenu::Logout, this, [=]() {
        emit UserLogout();
        CtrlMenu::Instance().close();
    });
    connect(&CtrlMenu::Instance(), &CtrlMenu::Exit, this, [=]() {
        emit Exit();
        CtrlMenu::Instance().close();
    });
}

void MainWindow::InitUi() {
    this->setCentralWidget(m_centerWidget);
    m_centerWidget->setObjectName("content");
    m_centerWidget->setStyleSheet("#content{background-color:rgb(23, 23, 23);}");

    m_centerLayout->addWidget(m_content);
    m_centerLayout->setContentsMargins(0, 0, 0, 0);

    m_contentLayout->setSpacing(0);
    m_contentLayout->setContentsMargins(0, 5, 0, 0);
    m_contentLayout->addWidget(m_nav);
    m_contentLayout->addWidget(m_stackedContent);

    m_stackedContent->setStyleSheet(
            "#stackedContent{margin-top:5px;border-top-left-radius:5px;background-color: rgb(0, 17, 34);}");
    m_stackedContent->addWidget(m_overview);
    m_stackedContent->addWidget(m_chatRoom);
    m_stackedContent->setCurrentIndex(0);
}

void MainWindow::InitTitleBar() {
    m_titleLayout->setContentsMargins(0, 0, 0, 0);
    m_titleLayout->setSpacing(0);
    m_titleLayout->addWidget(m_bar);
    this->layout()->setMenuBar(m_title);
}

bool MainWindow::HitArea(const QPoint &gPos) {
    return m_bar->HitArea(gPos);
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
#ifdef Q_OS_WIN
    QRect dragRecet(m_bar->rect().x(),
                    m_bar->rect().y(),
                    m_bar->rect().width(),
                    m_bar->rect().height());
    if (dragRecet.contains(event->pos()) && event->button() == Qt::LeftButton) {
        if (::ReleaseCapture()) {
            SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
            event->ignore();
        }
    }
#endif
    BorderlessWindow::mousePressEvent(event);

}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *event) {
#ifdef Q_OS_WIN
    QRect dragRecet(m_bar->rect().x(),
                    m_bar->rect().y(),
                    m_bar->rect().width(),
                    m_bar->rect().height());
    if (dragRecet.contains(event->pos()) && event->button() == Qt::LeftButton) {
        if (this->isMaximized())
            SwitchWindow(WINDOW_NORMAL);
        else
            SwitchWindow(WINDOW_MAX);
    }
#endif

}

void MainWindow::SwitchNav(NAVIGATION nav) {
    switch (nav) {
        case HOME:
            m_stackedContent->setCurrentIndex(0);
            break;
        case CHAT:
            m_stackedContent->setCurrentIndex(1);
            break;
    }
}

void MainWindow::SwitchWindow(WINDOW_STATE st) {
    switch (st) {
        case WINDOW_CLOSE:
            this->hide();
            break;
        case WINDOW_MAX: {
            this->showMaximized();
            emit UpdateWindowState(true);
            break;
        }
        case WINDOW_NORMAL: {
            this->showNormal();
            emit UpdateWindowState(false);
            break;
        }
        case WINDOW_MIN:
            this->showMinimized();
            break;
    }
}