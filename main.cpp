#include <QApplication>
#include <iostream>
#include "service/net_conn_service.h"
#include "service/core_service.h"
#include "cef/cef_manager.h"
#include "cef/dev_widget.h"

#define SERVER "192.168.2.202"
#define PORT 9006
/**
 * 初始化QT以及CEF相关
 */
int init_qt_cef() {
    CefEnableHighDPISupport();
    const HINSTANCE h_instance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    const CefMainArgs main_args(h_instance);
    const CefRefPtr<CefApp> app(new App); //CefApp实现，用于处理进程相关的回调

    const int exit_code = CefExecuteProcess(main_args, app.get(), nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }

    AppSettings pSettings;
    CefSettings settings;
    pSettings.Instance().GetSettings(settings);

    CefInitialize(main_args, settings, app, nullptr);

    return -1;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    const int result = init_qt_cef();
    if (result >= 0) {
        return result;
    }
    Inn::CoreService core(Inn::NetConnService::Instance(SERVER, PORT));
//    DevWidget w;
//    w.show();
//
//    MainWindow w;
//    w.show();
#if _DEBUG
#else
#endif
    a.exec();
    CefShutdown(); // 关闭CEF，释放资源

    return 0;
}
