//
// Created by zyx on 2021/10/9.
//

#ifndef INNCLIENT_APP_H
#define INNCLIENT_APP_H

#include <include/cef_app.h>
#include <include/wrapper/cef_helpers.h>
#include "handler.h"

class App : public CefApp, public CefBrowserProcessHandler {
public:
    App();

    // CefApp methods:
    virtual void
    OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line) override;

    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
        return this;
    }

    // CefBrowserProcessHandler methods:
    virtual void OnContextInitialized() override;

private:
    // Include the default reference counting implementation.
IMPLEMENT_REFCOUNTING(App);

};


#endif //INNCLIENT_APP_H
