//
// Created by zyx on 2021/8/12.
//

#ifndef INNCLIENT_DEFINE_H
#define INNCLIENT_DEFINE_H

#define POPUP_CLOSE 0
#define POPUP_SHOW 1
#define MSG_READ 0
#define MSG_UNREAD 1
#define SELECTED_ALL 0
#define SELECTED_PART 1
#define INPUT_AREA_EMPTY 0
#define INPUT_AREA_NOT_EMPTY 1

enum LOG_LEVEL {
    INN_UNKNOWN,
    INN_DEBUG,
    INN_INFO,
    INN_WARN,
    INN_ERROR,
    INN_FATAL
};

enum TEXT_OPS {
    COPY,
    PASTE,
    CUT
};

enum USER_ST {
    ONLINE,
    BUSY,
    AWAY
};

enum Q_CONN_OP {
    CONNECT,
    DISCONNECT
};

struct NET_SERVICE {
    enum REQ_OP {
        LOGIN_REQ,
        REG_REQ,
        LOGOUT_REQ,
        HEART_BEAT,
        MSG_REQ
    };
    enum HB_OP {
        TIMER_INIT,
        TIMER_START,
        TIMER_STOP
    };
    enum RECONNECT_OP {
        RECONNECT_INIT,
        RECONNECT_START,
        RECONNECT_STOP
    };
    enum REQ_RESULT {
        HEART_BEAT_COPY = -1,
        LOGIN_SUC = 0,
        LOGIN_FAIL = 1,
        REG_SUC = 2,
        REG_WRONG = 3,
        LOGOUT_SUC = 4,
        LOGOUT_FAIL = 5
    };
    enum CONNECTION_STATE {
        SERVER_UNCONNECTED,
        SERVER_DISCONNECTED,
        SERVER_CONNECTED,
        SERVER_RECONNECTED
    };
};

struct CORE_SERVICE {
    enum GUI_STATE {
        MAIN_WINDOW,
        AUTH_WINDOW
    };
};

enum WINDOW_STATE {
    WINDOW_CLOSE,
    WINDOW_NORMAL,
    WINDOW_MAX,
    WINDOW_MIN
};

enum NAVIGATION {
    HOME,
    CHAT,
    STREAM,
    SETTING
};

#endif //INNCLIENT_DEFINE_H
