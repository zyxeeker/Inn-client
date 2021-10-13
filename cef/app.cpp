//
// Created by zyx on 2021/10/9.
//

#include "app.h"


App::App() {}

void App::OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line) {
//    command_line->AppendSwitch("no-proxy-server");
    command_line->AppendSwitch("allow-file-access-from-files");
    command_line->AppendSwitch("allow-universal-access-from-files");
    command_line->AppendSwitch("disable-spell-checking");
    command_line->AppendSwitch("enable-network-service");
    command_line->AppendSwitch("enable-gpu");
    command_line->AppendSwitch("enable-gpu-compositing");
    command_line->AppendSwitch("enable-begin-frame-scheduling");
}

void App::OnContextInitialized() {
    CEF_REQUIRE_UI_THREAD();
}
