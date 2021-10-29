//
// Created by zyx on 2021/10/9.
//

#include "cef_handler.h"
#include <QApplication>
#include <include/cef_task.h>
#include <include/wrapper/cef_closure_task.h>
#include <include/wrapper/cef_helpers.h>
#include <QDebug>

void CefHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
    m_delegate->BrowserCreated(browser);
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
    m_delegate->BrowserKeyEvent(browser, event, os_event);
    return false;
}

bool CefHandler::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                          CefProcessId source_process, CefRefPtr<CefProcessMessage> message) {
    m_delegate->BrowserMessageEvent(browser, frame, source_process, message);
    return true;
}