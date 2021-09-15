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
    INN_LOGIN_REQ,
    INN_REG_REQ,
    INN_LOGOUT_REQ,
    INN_HEART_BEAT
};

#endif //INNCLIENT_DEFINE_H
