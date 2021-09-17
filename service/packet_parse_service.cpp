//
// Created by zyx on 2021/9/16.
//

#include "packet_parse_service.h"

REQ_RESULT Inn::PacketParseService::ParsePacket(const QByteArray *m_buffer) {
    std::string pPacket = QString(*m_buffer).toStdString();
    if (pPacket == std::to_string(HEART_BEAT_COPY))
        return HEART_BEAT_COPY;
    if (pPacket == std::to_string(LOGIN_SUC))
        return LOGIN_SUC;
    if (pPacket == std::to_string(LOGIN_WRONG))
        return LOGIN_WRONG;
    if (pPacket == std::to_string(REG_SUC))
        return REG_SUC;
    if (pPacket == std::to_string(REG_WRONG))
        return REG_WRONG;
    if (pPacket == std::to_string(LOGOUT_SUC))
        return LOGOUT_SUC;
}