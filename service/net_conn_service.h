//
// Created by zyx on 2021/9/8.
//

#ifndef INNCLIENT_NET_CONN_SERVICE_H
#define INNCLIENT_NET_CONN_SERVICE_H

#include <QTcpSocket>
#include <QHostAddress>
#include <string>
#include <QDebug>
#include <QTimer>
#include <QByteArray>
#include "model/define.h"
#include "service/packet_parse_service.h"
#include "service/logger_service.h"

namespace Inn {
    class NetService : public QTcpSocket {
    Q_OBJECT
    public:
        static NetService *Instance(QString ad = nullptr, uint16_t port = 0);
        NetService(QString ad, uint16_t port);
        int Req(NET_SERVICE::REQ_OP req);
        QTcpSocket *GetSocket() const;
        std::string GetUser() const;
        void SetUserInfo(std::string user, std::string pwd);
        void SetUserMsg(std::string msg);
        void Disconnect();
    private:
        void HBTimerService(NET_SERVICE::HB_OP op);
        void ReconnectService(NET_SERVICE::RECONNECT_OP op);
        void Send(std::string pkt);
    private:
        static NetService *m_service;
        std::string m_user;
        std::string m_pwd;
        std::string m_msg;
        QString m_address;
        uint16_t m_port;
        QTcpSocket *m_socket;
        QTimer *m_hbTimer;
        QTimer *m_reconnectTimer;
        QByteArray *m_buffer;
        // TODO Add a function to return connection state
        NET_SERVICE::CONNECTION_STATE m_connSt = NET_SERVICE::SERVER_UNCONNECTED;
    signals:
        void ReqResult(NET_SERVICE::REQ_RESULT);
    private slots:
        void onReceiveData();
        void HBOp();
        void Reconnect();
    };
}


#endif //INNCLIENT_NET_CONN_SERVICE_H
