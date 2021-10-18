//
// Created by zyx on 2021/10/9.
//

#include "app.h"

void App::OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line) {
//    command_line->AppendSwitch("no-proxy-server");
    command_line->AppendSwitch("allow-file-access-from-files");
    command_line->AppendSwitch("allow-universal-access-from-files");
    command_line->AppendSwitch("disable-spell-checking");
    command_line->AppendSwitch("enable-network-service");
    command_line->AppendSwitch("enable-begin-frame-scheduling");
    command_line->HasSwitch("disable-pdf-extension");
    command_line->HasSwitch("disable-extensions");
    // 合并渲染进程
    command_line->AppendSwitch("process-per-site");
    if (process_type.empty()) {
        command_line->AppendSwitch("disable-gpu");
        command_line->AppendSwitch("disable-gpu-compositing");
    }
}

void App::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) {
    // The var type can accept all object or variable
    CefRefPtr<CefV8Value> window = context->GetGlobal();

    // bind value into window[or you can bind value into window sub node]
    CefRefPtr<CefV8Value> strValue = CefV8Value::CreateString("say yes");
    window->SetValue("val", strValue, V8_PROPERTY_ATTRIBUTE_NONE);
}