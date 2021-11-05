//
// Created by zyx on 2021/9/26.
//

#ifndef INNCLIENT_CORE_SERVICE_H
#define INNCLIENT_CORE_SERVICE_H

#include <QSystemTrayIcon>
#include "net_conn_service.h"
#include "model/define.h"
#include "mainwindow.h"
#include "auth.h"

typedef CORE_SERVICE::GUI_STATE GUI_STATE;

namespace Inn {
    class CoreService : public QObject {
    public:
        CoreService(NetConnService &ser);
    private:
        void InitTrayService();
        void InitAuthGUI();
    private:
        NetConnService *m_netService;
        QSystemTrayIcon *m_tray;
        MainWindow *m_mGUI;
        Auth *m_aGUI;
        GUI_STATE m_guiState = GUI_STATE::AUTH_WINDOW;
    private slots:
        void onReceiveQuit();
        void onReceiveLogout();
        void onReceiveLoginSuccess();
        void onReceiveTrayAction(QSystemTrayIcon::ActivationReason reason);
    };
}


#endif //INNCLIENT_CORE_SERVICE_H
