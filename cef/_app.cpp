//
// Created by zyx on 2021/10/9.
//

#include "_app.h"
#include <QDebug>
#include <iostream>

AppTest::AppTest(QWidget *parent) : QWidget(parent) {
    this->resize(800, 600);
    this->setAttribute(Qt::WA_NativeWindow, true);
    this->setAttribute(Qt::WA_InputMethodEnabled, true);
    this->setAttribute(Qt::WA_DontCreateNativeAncestors, true);
    InitCef();
    HWND hwnd = reinterpret_cast<HWND>(this->winId());
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
//    ::SetWindowLong((HWND)this->winId(),GWL_EXSTYLE,WS_EX_LAYERED);
}

void AppTest::InitCef() {
    // 以下是将 SimpleHandler 与窗体进行关联的代码
    CefWindowHandle hwnd = (CefWindowHandle) this->winId();
    QString str_url = "https://www.google.com";

    RECT rc = {0, 0, 0, 0};
    ::GetWindowRect(hwnd, &rc);
    RegisterTouchWindow(hwnd, 0);


    cef_wnd_info.SetAsChild(hwnd, {0, 0, rc.right - rc.left, rc.bottom - rc.left});
    if (GetWindowLongPtr(hwnd, GWL_EXSTYLE) & WS_EX_NOACTIVATE) {
        // Don't activate the browser window on creation.
        cef_wnd_info.ex_style |= WS_EX_NOACTIVATE;
    }
//    cef_wnd_info.ex_style = WS_EX_NOACTIVATE;

//    if (GetWindowLongPtr(hwnd, GWL_EXSTYLE) & WS_EX_NOACTIVATE) {
//        // Don't activate the browser window on creation.
//        cef_wnd_info.ex_style |= WS_EX_NOACTIVATE;
//    }

    CefBrowserSettings cef_browser_settings;
    m_handler = CefRefPtr<Handler>(new Handler());
    CefBrowserHost::CreateBrowser(cef_wnd_info,
                                  m_handler,
                                  str_url.toStdString(),
                                  cef_browser_settings,
                                  nullptr,
                                  CefRequestContext::GetGlobalContext());

}

void AppTest::resizeEvent(QResizeEvent *e) {
    RECT WindowUserClientRect;
    GetClientRect(reinterpret_cast<HWND>(this->winId()), &WindowUserClientRect);
    // 最后一个参数必须为 'false' 否则移动的时候会闪屏
    std::list<CefRefPtr<CefBrowser>> cefBrowerList = m_handler->getCefBrowerList();
    if (cefBrowerList.empty())
        return;

    CefRefPtr<CefBrowser> pBrower = cefBrowerList.front();

    if (pBrower.get()) {
        HWND hwnd_ = pBrower->GetHost()->GetWindowHandle();
        if (hwnd_) {
            ::MoveWindow(hwnd_, 0, 0, this->width(), this->height(), TRUE);
        }
    }

}
