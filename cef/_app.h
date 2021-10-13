//
// Created by zyx on 2021/10/9.
//

#ifndef INNCLIENT__APP_H
#define INNCLIENT__APP_H

#include <QWidget>
#include <include/cef_app.h>
#include <include/cef_request_context.h>
#include "cef/handler.h"
#include "cef/app.h"


class AppTest : public QWidget {
Q_OBJECT
public:
    AppTest(QWidget *parent = nullptr);
    void InitCef();
protected:
    void resizeEvent(QResizeEvent *e);
private:
    CefRefPtr<Handler> m_handler; // 这里是新增的CefRefPtr<SimpleHandler>成员
    CefWindowInfo cef_wnd_info;
};


#endif //INNCLIENT__APP_H
