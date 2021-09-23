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
    Inn::NetConnService *netConnService = new Inn::NetConnService("192.168.2.202", 9006);
//    Auth auth(netConnService, tray);
//    auth.isHidden();
//    auth.show();
    MainWindow m(netConnService, tray);
//    m.show();
#if _DEBUG
#else
    //    Auth auth;
    //    auth.show();
    //    MainWindow m;
    //    m.show();
#endif
    return a.exec();
}
