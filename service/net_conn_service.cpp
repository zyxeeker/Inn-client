//
// Created by zyx on 2021/9/8.
//

#include "net_conn_service.h"

Inn::NetConnService::NetConnService(QString ad, uint16_t port) : m_address(ad), m_port(port) {
    m_socket = new QTcpSocket;
    m_hbTimer = new QTimer;
    m_reconnectTimer = new QTimer;
    m_socket->connectToHost(m_address, m_port);
    if (m_socket->state() != QAbstractSocket::ConnectedState) {
        ReconnectService(NET_SERVICE::RECONNECT_INIT);
        ReconnectService(NET_SERVICE::RECONNECT_START);
    }
    connect(m_socket, &QTcpSocket::connected, this, [=]() {
        if (m_reconnectTimer->isActive())
            ReconnectService(NET_SERVICE::RECONNECT_STOP);
        m_connSt = NET_SERVICE::SERVER_CONNECTED;
#if _DEBUG
        LOGD("Connect to Server");
#endif
    });
    connect(m_socket, &QTcpSocket::disconnected, this, [=]() {
        if (m_hbTimer->isActive())
            HBTimerService(NET_SERVICE::TIMER_STOP);
        ReconnectService(NET_SERVICE::RECONNECT_INIT);
        ReconnectService(NET_SERVICE::RECONNECT_START);
        m_connSt = NET_SERVICE::SERVER_DISCONNECTED;
#if _DEBUG
        LOGD("Disconnect from server");
#endif
    });
    connect(m_socket, &QTcpSocket::readyRead, this, &NetConnService::onReceiveData);
}

void Inn::NetConnService::Send(std::string pkt) {
    m_socket->write(pkt.c_str());
    m_socket->flush();
}

QTcpSocket *Inn::NetConnService::GetSocket() const {
    return m_socket;
}

std::string Inn::NetConnService::GetUser() const {
    return m_user;
}

void Inn::NetConnService::Disconnect() {
#if _DEBUG
    LOGD("Client Quiting...");
#endif
    m_socket->disconnectFromHost();
    m_socket->close();
}

void Inn::NetConnService::onReceiveData() {
    m_buffer = new QByteArray(m_socket->readAll());
    emit ReqResult(Inn::PacketParseService::ParsePacket(m_buffer));
}

int Inn::NetConnService::Req(NET_SERVICE::REQ_OP req) {
    switch (req) {
        case NET_SERVICE::LOGIN_REQ:
            Send("LOGIN " + m_user + " " + m_pwd);
            break;
        case NET_SERVICE::REG_REQ:
            Send("REG " + m_user + " " + m_pwd);
            break;
        case NET_SERVICE::HEART_BEAT: {
            HBTimerService(NET_SERVICE::TIMER_INIT);
            HBTimerService(NET_SERVICE::TIMER_START);
            break;
        }
        case NET_SERVICE::LOGOUT_REQ:
            Send("LOGOUT " + m_user);
            break;
    }
    return 0;
}

void Inn::NetConnService::SetUserInfo(std::string user, std::string pwd) {
    m_user = user;
    m_pwd = pwd;
}

void Inn::NetConnService::HBTimerService(NET_SERVICE::HB_OP op) {
    switch (op) {
        case NET_SERVICE::TIMER_INIT: {
            m_hbTimer->setInterval(5000);
            m_hbTimer->setTimerType(Qt::CoarseTimer);
            connect(m_hbTimer, &QTimer::timeout, this, &NetConnService::HBOp);
            break;
        }
        case NET_SERVICE::TIMER_START:
            m_hbTimer->start();
            break;
        case NET_SERVICE::TIMER_STOP:
            m_hbTimer->stop();
            break;
    }
}
// TODO Adjust interval time
void Inn::NetConnService::ReconnectService(NET_SERVICE::RECONNECT_OP op) {
    switch (op) {
        case NET_SERVICE::RECONNECT_INIT: {
            m_reconnectTimer->setInterval(3000);
            m_reconnectTimer->setTimerType(Qt::CoarseTimer);
            connect(m_reconnectTimer, &QTimer::timeout, this, &NetConnService::Reconnect);
            break;
        }
        case NET_SERVICE::RECONNECT_START:
            m_reconnectTimer->start();
            break;
        case NET_SERVICE::RECONNECT_STOP:
            m_reconnectTimer->stop();
            break;
    }

}

void Inn::NetConnService::HBOp() {
    Send("ALIVE " + m_user);
}

void Inn::NetConnService::Reconnect() {
    m_connSt = NET_SERVICE::SERVER_RECONNECTED;
#if _DEBUG
    LOGD("Reconnect to server");
#endif
    m_socket->abort();
    m_socket->connectToHost(m_address, m_port);
}