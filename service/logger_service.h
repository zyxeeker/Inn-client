//
// Created by zyx on 2021/9/17.
//

#ifndef INNCLIENT_LOGGER_SERVICE_H
#define INNCLIENT_LOGGER_SERVICE_H

#include <string>
#include <ctime>
#include <iostream>
#include <QDebug>
#include <QString>
#include "model/define.h"

// QT LOG
#define QLOG(x) Inn::Logger::Trans(INN_INFO); qDebug()<<x;
#define QLOGU(x) Inn::Logger::Trans(INN_UNKNOWN); qDebug()<<x;
#define QLOGD(x) Inn::Logger::Trans(INN_DEBUG); qDebug()<<x;
#define QLOGW(x) Inn::Logger::Trans(INN_WARN); qDebug()<<x;
#define QLOGF(x) Inn::Logger::Trans(INN_FATAL); qDebug()<<x;
#define QLOGE(x) Inn::Logger::Trans(INN_ERROR); qDebug()<<x;
// LOG
#define LOG(x) Inn::Logger::Trans(INN_INFO); std::cout << x << std::endl;
#define LOGU(x) Inn::Logger::Trans(INN_UNKNOWN); std::cout << x << std::endl;
#define LOGD(x) Inn::Logger::Trans(INN_DEBUG); std::cout << x << std::endl;
#define LOGW(x) Inn::Logger::Trans(INN_WARN); std::cout << x << std::endl;
#define LOGF(x) Inn::Logger::Trans(INN_FATAL); std::cout << x << std::endl;
#define LOGE(x) Inn::Logger::Trans(INN_ERROR); std::cout << x << std::endl;

namespace Inn {
    struct Logger {
        static std::string toString(LOG_LEVEL level);
        static void Trans(LOG_LEVEL level);
    };
}


#endif //INNCLIENT_LOGGER_SERVICE_H
