//
// Created by zyx on 2021/9/16.
//

#include "packet_parse_service.h"

NET_SERVICE::REQ_RESULT Inn::PacketParseService::ParsePacket(const QByteArray *m_buffer) {
    std::string pPacket = QString(*m_buffer).toStdString();
    if (pPacket == std::to_string(NET_SERVICE::HEART_BEAT_COPY))
        return NET_SERVICE::HEART_BEAT_COPY;
    if (pPacket == std::to_string(NET_SERVICE::LOGIN_SUC))
        return NET_SERVICE::LOGIN_SUC;
    if (pPacket == std::to_string(NET_SERVICE::LOGIN_FAIL))
        return NET_SERVICE::LOGIN_FAIL;
    if (pPacket == std::to_string(NET_SERVICE::REG_SUC))
        return NET_SERVICE::REG_SUC;
    if (pPacket == std::to_string(NET_SERVICE::REG_WRONG))
        return NET_SERVICE::REG_WRONG;
    if (pPacket == std::to_string(NET_SERVICE::LOGOUT_SUC))
        return NET_SERVICE::LOGOUT_SUC;
}