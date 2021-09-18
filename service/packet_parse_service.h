//
// Created by zyx on 2021/9/16.
//

#ifndef INNCLIENT_PACKET_PARSE_SERVICE_H
#define INNCLIENT_PACKET_PARSE_SERVICE_H

#include <QByteArray>
#include <QString>
#include "model/define.h"

namespace Inn {
    class PacketParseService {
    public:
        static NET_SERVICE::REQ_RESULT ParsePacket(const QByteArray *m_buffer);
    };
}

#endif //INNCLIENT_PACKET_PARSE_SERVICE_H
