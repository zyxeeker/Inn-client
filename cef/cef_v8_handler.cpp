//
// Created by zyx on 2021/10/28.
//

#include "cef_v8_handler.h"
#include "service/user_service.h"
#include <QDebug>

bool AppV8Handler::Execute(const CefString &name, CefRefPtr<CefV8Value> object, const CefV8ValueList &arguments,
                           CefRefPtr<CefV8Value> &retval, CefString &exception) {
    if (name == "MsgHandler") {
        if (arguments.size() != 1 || !arguments[0]->IsString()) {
            return false;
        }
        m_msgStr = arguments.at(0)->GetStringValue();
        //消息会被发送到CefClient的OnProcessMessageReceived接口方法
        m_browser->GetMainFrame()->SendProcessMessage(PID_BROWSER, CefProcessMessage::Create(m_msgStr));
        retval = CefV8Value::CreateInt(0);
        return true;
    }
    // Function does not exist.
    return false;
}
