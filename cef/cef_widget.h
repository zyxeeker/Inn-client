//
// Created by zyx on 2021/10/14.
//

#ifndef INNCLIENT_CEF_WIDGET_H
#define INNCLIENT_CEF_WIDGET_H

#include "cef/cef_handler.h"
#include <QWidget>
#include <QWindow>
#include <memory>
#include <QAction>
#include <QMenu>
#include <QVBoxLayout>


class CefWidget : public QWidget, public Delegate {
Q_OBJECT
public:
    CefWidget(QWidget *parent = nullptr);
//    LifeSpan
    void BrowserCreated(CefRefPtr<CefBrowser> browser) override;
    void BrowserClose(CefRefPtr<CefBrowser> browser) override;
//    ContextMenu
    void
    BrowserContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefContextMenuParams> params,
                       CefRefPtr<CefMenuModel> model) override;
//    Keyboard
    bool BrowserPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                            bool *is_keyboard_shortcut) override;
    bool BrowserKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) override;
protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private:
    void InitUi();
    bool CreateBrowser(const CefRect &rect, const CefBrowserSettings &settings,
                       CefRefPtr<CefDictionaryValue> extra_info,
                       CefRefPtr<CefRequestContext> request_context);
    void ResizeBrowser(QSize size);
private:
    CefRefPtr<CefBrowser> m_browser;
    CefRefPtr<CefHandler> m_handler;
    QWindow *m_window;
    QVBoxLayout *m_layout;
    QWidget *m_container;
    QRect m_rect;
    HWND m_winHandle;
};

#endif //INNCLIENT_CEF_WIDGET_H
