//
// Created by zyx on 2021/10/14.
//

#include "cef_widget.h"
#include <QApplication>
#include <QtDebug>
#include <QThread>
#include <QCloseEvent>
#include <QTimer>
#include <QDateTime>
#include <QStyle>
#include <QScreen>
#include <WinUser.h>
#include <include/wrapper/cef_helpers.h>


CefWidget::CefWidget(QWidget *parent) : QWidget(parent) {
    m_window = new QWindow(windowHandle());
    m_layout = new QVBoxLayout(this);
    m_container = QWidget::createWindowContainer(m_window);
    std::string url = "www.google.com";
    m_handler = new CefHandler(this);
    InitUi();
    CefRect pRect{this->x(), this->y(), this->width(), this->height()};
    CefBrowserSettings pSettings;
    CreateBrowser(pRect, pSettings, nullptr, nullptr);
}

void CefWidget::InitUi() {
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_container);
}

bool CefWidget::CreateBrowser(const CefRect &rect, const CefBrowserSettings &settings,
                              CefRefPtr<CefDictionaryValue> extra_info, CefRefPtr<CefRequestContext> request_context) {
    CefWindowInfo pInfo;
    RECT pRect = {rect.x, rect.y, rect.x + rect.width, rect.y + rect.height};
    pInfo.SetAsChild((CefWindowHandle) m_window->winId(), pRect);
    return CefBrowserHost::CreateBrowser(pInfo, m_handler, "file:///D:/program/Inn-client/index.html", settings,
                                         extra_info, request_context);
}

void CefWidget::ResizeBrowser(QSize size) {
    ::MoveWindow(m_winHandle, 0, 0, size.width(), size.height(), false);
    ::SetWindowPos(m_winHandle, HWND_BOTTOM, 0, 0, size.width(), size.height(), SWP_NOACTIVATE);
}

void CefWidget::resizeEvent(QResizeEvent *event) {
    ResizeBrowser(event->size());
}

void CefWidget::closeEvent(QCloseEvent *event) {
    m_browser->GetHost()->CloseBrowser(false);
}

// LifeSpan
void CefWidget::BrowserCreated(CefRefPtr<CefBrowser> browser) {
    m_browser = browser;
    m_winHandle = browser->GetHost()->GetWindowHandle();
}

void CefWidget::BrowserClose(CefRefPtr<CefBrowser> browser) {

}

// ContextMenu
void CefWidget::BrowserContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                   CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model) {

}

// Keyboard
bool CefWidget::BrowserPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                                   bool *is_keyboard_shortcut) {
    return false;
}

bool CefWidget::BrowserKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) {
    return false;
}
