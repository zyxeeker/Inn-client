//
// Created by zyx on 2021/10/9.
//

#include "cef_handler.h"
#include <QApplication>

void CefHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
    m_delegate->BrowserCreated(browser);
    return;
}

void CefHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
    return;
}

void CefHandler::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                     CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model) {
    return;
}

bool CefHandler::OnPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                               bool *is_keyboard_shortcut) {
    return false;
}

bool CefHandler::OnKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) {
    return false;
}