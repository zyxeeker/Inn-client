//
// Created by zyx on 2021/10/9.
//

#ifndef INNCLIENT_APP_H
#define INNCLIENT_APP_H

#include <include/cef_app.h>
#include <include/wrapper/cef_helpers.h>
#include "cef_handler.h"

class App : public CefApp, public CefBrowserProcessHandler, public CefRenderProcessHandler {
public:
    // CefApp methods:
    virtual void
    OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line) override;
    CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
        return this;
    }
    CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override {
        return this;
    }
//    窗口bind值或者函数
    void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                          CefRefPtr<CefV8Context> context) override;

private:
    // Include the default reference counting implementation.
IMPLEMENT_REFCOUNTING(App);

};


#endif //INNCLIENT_APP_H
