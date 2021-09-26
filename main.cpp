#include <QApplication>
#include <iostream>
//#include "mainwindow.h"
//#include "auth.h"
#include "service/net_conn_service.h"
#include "service/core_service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Inn::NetConnService *netConnService = new Inn::NetConnService("192.168.2.202", 9006);
    Inn::CoreService core(netConnService);
//    MainWindow m(netConnService, tray);
#if _DEBUG
#else
    //    Auth auth;
    //    auth.show();
    //    MainWindow m;
    //    m.show();
#endif
    return a.exec();
}
