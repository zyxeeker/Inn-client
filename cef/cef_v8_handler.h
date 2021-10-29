//
// Created by zyx on 2021/10/28.
//

#ifndef INNCLIENT_CEF_V8_HANDLER_H
#define INNCLIENT_CEF_V8_HANDLER_H

#include <include/cef_v8.h>
#include <iostream>

class AppV8Handler : public CefV8Handler {
public:
    AppV8Handler(CefRefPtr<CefBrowser> browser) : m_browser(browser) {}
    virtual bool Execute(const CefString &name,
                         CefRefPtr<CefV8Value> object,
                         const CefV8ValueList &arguments,
                         CefRefPtr<CefV8Value> &retval,
                         CefString &exception) override;
IMPLEMENT_REFCOUNTING(AppV8Handler);
private:
    CefRefPtr<CefBrowser> m_browser;
};


#endif //INNCLIENT_CEF_V8_HANDLER_H
