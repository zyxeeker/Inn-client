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
//    PIC
    bool BrowserMessageEvent(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId source_process,
                             CefRefPtr<CefProcessMessage> message) override;

    CefRefPtr<CefBrowser> GetInstance() { return m_browser; }
protected:
    void resizeEvent(QResizeEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
private:
    void InitUi();
    bool CreateBrowser(const CefRect &rect, const CefBrowserSettings &settings,
                       CefRefPtr<CefDictionaryValue> extra_info,
                       CefRefPtr<CefRequestContext> request_context);
    void ResizeBrowser(QSize size);
public:
//    bool m_isDevToolOpen = false;
private:
    CefRefPtr<CefBrowser> m_browser;
    CefRefPtr<CefHandler> m_handler;
    CefWindowInfo m_info;
    QWindow *m_window;
    QVBoxLayout *m_layout;
    QWidget *m_container;
    QRect m_rect;
    CefWindowHandle m_winHandle;
    bool m_createMark = false;
public slots:
    void SendData();
signals:
    void OpenDevTools();
};

class CefDevTools : public QWidget, public Delegate {
public:
    CefDevTools(CefRefPtr<CefBrowser> browser);
    //    LifeSpan
    void BrowserCreated(CefRefPtr<CefBrowser> browser) override;
    void BrowserClose(CefRefPtr<CefBrowser> browser) {}
//    ContextMenu
    void
    BrowserContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefContextMenuParams> params,
                       CefRefPtr<CefMenuModel> model) {}
//    Keyboard
    bool BrowserPreKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event,
                            bool *is_keyboard_shortcut) { return false; }
    bool BrowserKeyEvent(CefRefPtr<CefBrowser> browser, const CefKeyEvent &event, MSG *os_event) { return false; }
//    IPC
    bool BrowserMessageEvent(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessId source_process,
                             CefRefPtr<CefProcessMessage> message) override { return false; }
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    void InitUi();
    void Resize(QSize size);
private:
    QWindow *m_window;
    QVBoxLayout *m_layout;
    QWidget *m_container;
    CefRefPtr<CefHandler> m_devHandler;
    CefRefPtr<CefBrowser> m_devBrowser;
    CefRefPtr<CefBrowser> m_targetBrowser;
    CefWindowHandle m_winHandle;
    bool m_createdMark = false;
};

#endif //INNCLIENT_CEF_WIDGET_H
