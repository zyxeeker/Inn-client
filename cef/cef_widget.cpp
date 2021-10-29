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

static int mp = 0;

CefWidget::CefWidget(QWidget *parent) : QWidget(parent) {
    std::string url = "www.google.com";
    InitUi();
    CefRect pRect{this->x(), this->y(), this->width(), this->height()};
    CefBrowserSettings pSettings;
}

void CefWidget::InitUi() {
    m_window = new QWindow(windowHandle());
    m_layout = new QVBoxLayout(this);
    m_container = QWidget::createWindowContainer(m_window);
    m_handler = new CefHandler(this);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_container);
}

bool CefWidget::CreateBrowser(const CefRect &rect, const CefBrowserSettings &settings,
                              CefRefPtr<CefDictionaryValue> extra_info, CefRefPtr<CefRequestContext> request_context) {
    RECT pRect = {rect.x, rect.y, rect.x + rect.width, rect.y + rect.height};
    m_info.SetAsChild((CefWindowHandle) m_window->winId(), pRect);
    return CefBrowserHost::CreateBrowser(m_info, m_handler, "file:///D:/program/Inn-client/src/app/dist/index.html",
                                         settings,
                                         extra_info, request_context);
}

void CefWidget::ResizeBrowser(QSize size) {
    if (m_browser) {
        ::MoveWindow(m_winHandle, 0, 0, size.width(), size.height(), false);
        ::SetWindowPos(m_winHandle, HWND_BOTTOM, 0, 0, size.width(), size.height(), SWP_NOACTIVATE);
    }
}

void CefWidget::resizeEvent(QResizeEvent *event) {
    if (!m_createMark) {
        CefRect rect{x(), y(), x() + event->size().width(), y() + event->size().height()};
        CefBrowserSettings pBrowserSettings;
        CreateBrowser(rect, pBrowserSettings, nullptr, nullptr);
        m_createMark = true;
    } else
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
    if (event.modifiers == EVENTFLAG_NONE && event.windows_key_code == VK_F12 && event.type == KEYEVENT_RAWKEYDOWN)
            emit OpenDevTools();
    return false;
}

bool CefWidget::BrowserMessageEvent(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                    CefProcessId source_process, CefRefPtr<CefProcessMessage> message) {
#if 1
    qInfo() << QString(message->GetName().ToString().c_str());
#endif
}

void CefWidget::SendData() {
}

CefDevTools::CefDevTools(CefRefPtr<CefBrowser> browser) : m_targetBrowser(browser) {
    m_window = new QWindow(windowHandle());
    m_layout = new QVBoxLayout(this);
    m_devHandler = new CefHandler(this);
    InitUi();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void CefDevTools::BrowserCreated(CefRefPtr<CefBrowser> browser) {
    m_devBrowser = browser;
    m_winHandle = browser->GetHost()->GetWindowHandle();
}

void CefDevTools::InitUi() {
    m_container = QWidget::createWindowContainer(m_window);
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_container);
}

void CefDevTools::Resize(QSize size) {
    if (m_devBrowser) {
        ::MoveWindow(m_winHandle, 0, 0, size.width(), size.height(), false);
        ::SetWindowPos(m_winHandle, HWND_BOTTOM, 0, 0, size.width(), size.height(), SWP_NOACTIVATE);
    }
}

void CefDevTools::resizeEvent(QResizeEvent *event) {
    if (!m_createdMark) {
        CefBrowserSettings pBrowserSettings;
        CefWindowInfo pWindowInfo;

        RECT pRect = {0, 0, event->size().width(), event->size().height()};
        pWindowInfo.SetAsChild((CefWindowHandle) m_window->winId(), pRect);

        m_targetBrowser->GetHost()->ShowDevTools(pWindowInfo, m_devHandler, pBrowserSettings, CefPoint());
        m_createdMark = true;
    }
    Resize(event->size());
}

