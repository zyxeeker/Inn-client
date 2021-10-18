//
// Created by zyx on 2021/10/9.
//

#ifndef INNCLIENT_CEF_HANDLER_H
#define INNCLIENT_CEF_HANDLER_H

#include <include/cef_client.h>
#include <list>

struct Delegate {
    virtual void BrowserCreated(CefRefPtr<CefBrowser> browser) = 0;
    virtual void BrowserClose(CefRefPtr<CefBrowser> browser) = 0;
    virtual void
    BrowserContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefContextMenuParams> params,
                       CefRefPtr<CefMenuModel> model) = 0;
    virtual bool BrowserPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                                    bool *is_keyboard_shortcut) = 0;
    virtual bool BrowserKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) = 0;
};

class CefHandler
        : public CefClient, public CefLifeSpanHandler, public CefContextMenuHandler, public CefKeyboardHandler {
public:
    CefHandler(Delegate *delegate) : m_delegate(delegate) {}
    CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override { return this; }
    CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override { return this; }
    CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() override { return this; }
    // LifeSpan
    void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
    void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;
    // ContextMenu
    void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                             CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model) override;
    // Keyboard
    bool OnPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                       bool *is_keyboard_shortcut) override;
    bool OnKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) override;
private:
    Delegate *m_delegate;
IMPLEMENT_REFCOUNTING(CefHandler);
//    DISALLOW_COPY_AND_ASSIGN(CefHandler);
};


#endif //INNCLIENT_CEF_HANDLER_H
