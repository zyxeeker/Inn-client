//
// Created by zyx on 2021/9/8.
//

#ifndef INNCLIENT_NET_CONN_SERVICE_H
#define INNCLIENT_NET_CONN_SERVICE_H

#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include <QDebug>
#include "model/define.h"

namespace Inn {
    class NetConnService : public QTcpSocket {
    public:
        NetConnService(QString ad, uint16_t port);
        int Req(REQ_OP req);
        QTcpSocket *GetSocket() const;
        void SetUserInfo(std::string user, std::string pwd);
    private:
        void Send(std::string pkt);
//        std::string ProcessData();
        void Disconnect();
    private:
        std::string m_user;
        std::string m_pwd;
        QString m_address;
        uint16_t m_port;
        QTcpSocket *m_socket;
        QByteArray *m_buffer;
    private slots:
        void onReceiveData();
    };
}


#endif //INNCLIENT_NET_CONN_SERVICE_H
