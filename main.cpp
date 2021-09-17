#include <QApplication>
#include <iostream>
#include <thread>
#include "model/define.h"
#include "mainwindow.h"
#include "auth.h"
#include "service/net_conn_service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
#if _DEBUG
    Inn::NetConnService *netConnService;
    netConnService = new Inn::NetConnService("192.168.2.202", 9006);
    Auth auth(netConnService);
    auth.show();
#else
    //    Auth auth;
    //    auth.show();
    //    MainWindow m;
    //    m.show();
#endif
    return a.exec();
}
