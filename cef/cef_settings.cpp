//
// Created by zyx on 2021/10/14.
//

#include <QDir>
#include <QApplication>
#include <QStandardPaths>
#include <include/cef_command_line.h>
#include "cef_settings.h"

bool AppSettings::seperate_sub_process;

CefString AppSettings::browser_sub_process_path;

CefString AppSettings::resource_directory_path;

CefString AppSettings::locales_directory_path;

CefString AppSettings::user_agent = "Mozilla/5.0(Windows NT 6.1;WOW64) "
                                    "AppleWebKit/537.36(KHTML,like Gecko) "
                                    "Chrome/94.0.4606.61 Safari/537.36 "
                                    "Inn/1.0.0b";

CefString AppSettings::cache_path;

CefString AppSettings::root_cache_path;

CefString AppSettings::user_data_path;

int AppSettings::persist_session_cookies = 1;

int AppSettings::persist_user_preferences = 1;

CefString AppSettings::locale;

uint AppSettings::remote_debugging_port = 12233;

cef_color_t AppSettings::background_color;

CefString AppSettings::accept_language_list;

AppSettings::AppSettings() {
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(dataPath);
    const char *sudDir = "CEF";
    if (!dir.cd(sudDir)) {
        dir.mkdir(sudDir);
    }
    dir.cd(sudDir);
    auto cachePath = dir.absolutePath();

    cache_path.FromString(cachePath.toStdString());
    root_cache_path.FromString(dataPath.toStdString());

    locale.FromString("zh-CN");
    accept_language_list.FromString("zh-CN");
    background_color = CefColorSetARGB(255, 163, 198, 218);    //163,198,218

    // render process path
    auto path = qApp->applicationDirPath();
    browser_sub_process_path.FromString(path.toStdString());

    // resource file path
    resource_directory_path.FromString(path.toStdString());
}

AppSettings &AppSettings::Instance() {
    static AppSettings appSettings;
    return appSettings;
}

void AppSettings::GetSettings(CefSettings &settings) {
    // Parse command-line arguments for use in this method.
    CefRefPtr<CefCommandLine> pCmd = CefCommandLine::CreateCommandLine();
    pCmd->InitFromString(::GetCommandLineW());

    CefString(&settings.cache_path) = cache_path;
    CefString(&settings.root_cache_path) = root_cache_path;

    if (pCmd->HasSwitch("remote-debugging-port")) {
        std::string port = pCmd->GetSwitchValue("remote-debugging-port");
        uint portI = QString::fromStdString(port).toUInt();
        settings.remote_debugging_port = portI == 0 ? remote_debugging_port : portI;
    } else
        settings.remote_debugging_port = remote_debugging_port;

    settings.log_severity = LOGSEVERITY_WARNING;
    settings.background_color = background_color;
    settings.persist_session_cookies = persist_session_cookies;
    settings.persist_user_preferences = persist_user_preferences;
    settings.multi_threaded_message_loop = true; //多线程消息循环
    settings.no_sandbox = true; //沙盒
}