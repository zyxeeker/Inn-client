#include <QApplication>
#include <iostream>
#include "service/net_conn_service.h"
#include "service/core_service.h"
#include "cef/app.h"
#include <include/cef_app.h>
#include "cef/_app.h"

/**
 * 初始化QT以及CEF相关
 */
int init_qt_cef() {
    CefEnableHighDPISupport();
    const HINSTANCE h_instance = static_cast<HINSTANCE>(GetModuleHandle(nullptr));

    const CefMainArgs main_args(h_instance);
    const CefRefPtr<App> app(new App); //CefApp实现，用于处理进程相关的回调。

    const int exit_code = CefExecuteProcess(main_args, app.get(), nullptr);
    if (exit_code >= 0) {
        return exit_code;
    }

    // 设置配置
    CefSettings settings;
    settings.multi_threaded_message_loop = true; //多线程消息循环
    settings.log_severity = LOGSEVERITY_DISABLE; //日志
    settings.no_sandbox = true; //沙盒
//    settings.windowless_rendering_enabled = true;

    CefInitialize(main_args, settings, app, nullptr);

    return -1;
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    const int result = init_qt_cef();
    if (result >= 0) {
        return result;
    }
//    AppTest app;
//    app.show();
    Inn::NetConnService *netConnService = new Inn::NetConnService("192.168.2.202", 9006);
    Inn::CoreService core(netConnService);
#if _DEBUG
#else
#endif
    a.exec();
    CefShutdown(); // 关闭CEF，释放资源

    return 0;
}
