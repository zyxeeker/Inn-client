//
// Created by zyx on 2021/11/1.
//

#ifndef INNCLIENT_USER_SERVICE_H
#define INNCLIENT_USER_SERVICE_H

#include <QString>

class UserService {
public:
    static UserService &Instance() {
        static UserService userService;
        return userService;
    }
public:
    static std::string userName;
};


#endif //INNCLIENT_USER_SERVICE_H
