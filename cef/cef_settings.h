//
// Created by zyx on 2021/10/14.
//

#ifndef INNCLIENT_CEF_SETTINGS_H
#define INNCLIENT_CEF_SETTINGS_H

#include <include/cef_base.h>

class AppSettings {
public:
    AppSettings();
    static AppSettings &Instance();
    void GetSettings(CefSettings &settings);
public:
    static bool seperate_sub_process;
    ///
    /// \brief 分离式时，除了浏览器进程之外的进程可执行体路径
    ///
    static CefString browser_sub_process_path;

    static int chrome_runtime;

    static CefString resource_directory_path;

    static CefString locales_directory_path;
    static CefString user_agent;
    ///
    /// \brief 缓存数据存放目录
    ///
    static CefString cache_path;

    static CefString root_cache_path;
    static CefString user_data_path;
    static int persist_session_cookies;
    static int persist_user_preferences;
    static CefString locale;
    static int remote_debugging_port;
    static cef_color_t background_color;
    static CefString accept_language_list;
};


#endif //INNCLIENT_CEF_SETTINGS_H
