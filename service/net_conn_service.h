//
// Created by zyx on 2021/9/8.
//

#ifndef INNCLIENT_NET_CONN_SERVICE_H
#define INNCLIENT_NET_CONN_SERVICE_H

#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include <QDebug>
#include <QWidget>

namespace Inn {
    class NetConnService : public QTcpSocket {
    public:
        NetConnService(QString ad, uint16_t port);

        QTcpSocket *GetSocket() const;

        void Send(std::string pkt);

//        std::string ProcessData();
        void Disconnect();

    private:
        QString m_address;
        uint16_t m_port;
        QTcpSocket *m_socket;
        QByteArray *m_buffer;
    private slots:

        void onReceiveData();
    };

    class AuthService : public NetConnService {
    public:
        static int LoginReq(std::string user, std::string pwd);

        static int RegReq(std::string user, std::string pwd);
    };
}


#endif //INNCLIENT_NET_CONN_SERVICE_H
