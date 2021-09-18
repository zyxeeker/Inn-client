//
// Created by zyx on 2021/9/17.
//

#include "logger_service.h"

std::string Inn::Logger::toString(LOG_LEVEL level) {
    switch (level) {
#define TRANS(level) \
    case LOG_LEVEL::level: \
        return #level; \
        break;
        TRANS(INN_DEBUG);
        TRANS(INN_INFO);
        TRANS(INN_WARN);
        TRANS(INN_ERROR);
        TRANS(INN_FATAL);
        TRANS(INN_UNKNOWN);
#undef TRANS
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}

void Inn::Logger::Trans(LOG_LEVEL level) {
    char date[50];
    time_t now = time(nullptr);
    strftime(date, 50, "%x %X", localtime(&now));
    std::cout << date << " [" << toString(level) << "]:";
}
