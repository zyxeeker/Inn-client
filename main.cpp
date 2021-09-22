#include <QApplication>
#include <QSystemTrayIcon>
#include <iostream>
#include "mainwindow.h"
#include "auth.h"
#include "service/net_conn_service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QSystemTrayIcon *tray = new QSystemTrayIcon;
    QIcon icon;
    icon.addFile(":/common/resource/hide.svg");
    tray->setIcon(icon);
    tray->setToolTip(QObject::trUtf8("测试系统托盘图标"));
    //在系统托盘显示此对象
    tray->show();
#if _DEBUG
    Inn::NetConnService *netConnService;
    netConnService = new Inn::NetConnService("192.168.2.202", 9006);
    Auth auth(tray, netConnService);
    auth.show();
    MainWindow m(tray);
    m.show();
#else
    //    Auth auth;
    //    auth.show();
    //    MainWindow m;
    //    m.show();
#endif
    return a.exec();
}
