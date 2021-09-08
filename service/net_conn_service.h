//
// Created by zyx on 2021/9/8.
//

#ifndef INNCLIENT_NET_CONN_SERVICE_H
#define INNCLIENT_NET_CONN_SERVICE_H

#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include <QDebug>

namespace Inn {
    class NetConnService {
    public:
        NetConnService(QString ad, uint16_t port);

        QTcpSocket *GetSocket() const;

        void Send(std::string pkt);

        void Disconnect();

    private:
        QString m_address;
        uint16_t m_port;
        QTcpSocket *m_socket;

    };
}


#endif //INNCLIENT_NET_CONN_SERVICE_H
