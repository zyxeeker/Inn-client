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

enum TEXT_OPS {
    COPY,
    PASTE,
    CUT
};

enum USER_ST {
    ONLINE,
    BUSY,
    SLEEP
};

enum REQ_OP {
    LOGIN_REQ,
    REG_REQ,
    LOGOUT_REQ,
    HEART_BEAT
};

enum REQ_RESULT {
    HEART_BEAT_COPY = -1,
    LOGIN_SUC = 0,
    LOGIN_WRONG = 1,
    REG_SUC = 2,
    REG_WRONG = 3,
    LOGOUT_SUC = 4,
    LOGOUT_FAIL = 5
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

#endif //INNCLIENT_DEFINE_H
