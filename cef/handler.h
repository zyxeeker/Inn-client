//
// Created by zyx on 2021/10/9.
//

#ifndef INNCLIENT_HANDLER_H
#define INNCLIENT_HANDLER_H


#include <include/cef_client.h>
#include <list>

class Handler : public CefClient,
                public CefLifeSpanHandler,
                public CefLoadHandler {
public:
    explicit Handler();
    ~Handler();

    // Provide access to the single global instance of this object.
    static Handler *GetInstance();

    virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override {
        return this;
    }

    virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }

    // CefLifeSpanHandler methods:
    virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;
    virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;
    virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

    // CefLoadHandler methods:
    virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
                             CefRefPtr<CefFrame> frame,
                             ErrorCode errorCode,
                             const CefString &errorText,
                             const CefString &failedUrl) override;

    // Request that all existing browser windows close.
    void CloseAllBrowsers(bool force_close);

    bool IsClosing() const { return is_closing_; }
    std::list<CefRefPtr<CefBrowser>> getCefBrowerList();

private:
    // List of existing browser windows. Only accessed on the CEF UI thread.
    typedef std::list<CefRefPtr<CefBrowser>> BrowserList;
    BrowserList browser_list_;

    bool is_closing_;

    // Include the default reference counting implementation.
IMPLEMENT_REFCOUNTING(Handler);
};


#endif //INNCLIENT_HANDLER_H
