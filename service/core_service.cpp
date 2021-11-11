//
// Created by zyx on 2021/9/26.
//

#include "core_service.h"

Inn::CoreService::CoreService(NetService *ser) : m_netService(ser) {
    InitTrayService();
    InitAuthGUI();
    connect(m_tray, &QSystemTrayIcon::activated, this, &Inn::CoreService::onReceiveTrayAction);
    connect(m_aGUI, &Auth::LoginSuccess, this, &Inn::CoreService::onReceiveLoginSuccess);
    connect(m_aGUI, &Auth::ClientQuit, this, &Inn::CoreService::onReceiveQuit);
}

void Inn::CoreService::InitTrayService() {
    m_tray = new QSystemTrayIcon;
    QIcon icon;
    icon.addFile(":/common/resource/hide.svg");
    m_tray->setIcon(icon);
    m_tray->setToolTip(QObject::trUtf8("TEST TRAY"));
    //在系统托盘显示此对象
    m_tray->show();
}

void Inn::CoreService::InitAuthGUI() {
    m_aGUI = new Auth;
    m_aGUI->show();
}


void Inn::CoreService::onReceiveTrayAction(QSystemTrayIcon::ActivationReason reason) {
    switch (reason) {
        case QSystemTrayIcon::Trigger:
            break;
        case QSystemTrayIcon::DoubleClick:
            if (m_guiState == GUI_STATE::MAIN_WINDOW) m_mGUI->showNormal();
            else m_aGUI->showNormal();
            break;
        default:
            break;
    }
}

void Inn::CoreService::onReceiveLoginSuccess() {
    m_guiState = GUI_STATE::MAIN_WINDOW;
    m_mGUI = new MainWindow;
    m_mGUI->show();
    m_aGUI->close();
    connect(m_mGUI, &MainWindow::UserLogout, this, &Inn::CoreService::onReceiveLogout);
    connect(m_mGUI, &MainWindow::Exit, this, &Inn::CoreService::onReceiveQuit);
}

void Inn::CoreService::onReceiveLogout() {
    disconnect(m_mGUI, &MainWindow::UserLogout, this, &Inn::CoreService::onReceiveLogout);
    m_mGUI->close();
    m_guiState = GUI_STATE::AUTH_WINDOW;
    m_aGUI->show();
}

void Inn::CoreService::onReceiveQuit() {
    if (m_mGUI)
        m_mGUI->close();
    m_netService->Disconnect();
    m_tray->deleteLater();
}