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
        ReconnectService(RECONNECT_INIT);
        ReconnectService(RECONNECT_START);
    }
    connect(m_socket, &QTcpSocket::connected, this, [=]() {
        if (m_reconnectTimer->isActive())
            ReconnectService(RECONNECT_STOP);
        m_connSt = SERVER_CONNECTED;
        qDebug() << "connected";
    });
    connect(m_socket, &QTcpSocket::disconnected, this, [=]() {
        if (m_hbTimer->isActive())
            HBTimerService(TIMER_STOP);
        ReconnectService(RECONNECT_INIT);
        ReconnectService(RECONNECT_START);
        m_connSt = SERVER_DISCONNECTED;
        qDebug() << "disconnected";
    });
    connect(m_socket, &QTcpSocket::readyRead, this, &NetConnService::onReceiveData);
}

void Inn::NetConnService::Send(std::string pkt) {
    m_socket->write(pkt.c_str());
    m_socket->flush();
}

QTcpSocket *Inn::NetConnService::GetSocket() const {
//    qDebug()<<m_socket->state();
    return m_socket;
}

void Inn::NetConnService::Disconnect() {
    m_socket->disconnectFromHost();
}

//std::string Inn::NetConnService::ProcessData() {
//    QByteArray buffer = m_socket->readAll();
//    qDebug()<<buffer;
//}

void Inn::NetConnService::onReceiveData() {
    m_buffer = new QByteArray(m_socket->readAll());
    emit ReqResult(Inn::PacketParseService::ParsePacket(m_buffer));
}

int Inn::NetConnService::Req(REQ_OP req) {
    switch (req) {
        case LOGIN_REQ:
            Send("LOGIN " + m_user + " " + m_pwd);
            break;
        case REG_REQ:
            Send("REG " + m_user + " " + m_pwd);
            break;
        case HEART_BEAT: {
            HBTimerService(TIMER_INIT);
            HBTimerService(TIMER_START);
            break;
        }
        case LOGOUT_REQ:
            Send("LOGOUT " + m_user);
            break;
    }
    return 0;
}

void Inn::NetConnService::SetUserInfo(std::string user, std::string pwd) {
    m_user = user;
    m_pwd = pwd;
}

void Inn::NetConnService::HBTimerService(HB_OP op) {
    switch (op) {
        case TIMER_INIT: {
            m_hbTimer->setInterval(5000);
            m_hbTimer->setTimerType(Qt::CoarseTimer);
            connect(m_hbTimer, &QTimer::timeout, this, &NetConnService::HBOp);
            break;
        }
        case TIMER_START:
            m_hbTimer->start();
            break;
        case TIMER_STOP:
            m_hbTimer->stop();
            break;
    }
}
// TODO Adjust interval time
void Inn::NetConnService::ReconnectService(RECONNECT_OP op) {
    switch (op) {
        case RECONNECT_INIT: {
            m_reconnectTimer->setInterval(3000);
            m_reconnectTimer->setTimerType(Qt::CoarseTimer);
            connect(m_reconnectTimer, &QTimer::timeout, this, &NetConnService::Reconnect);
            break;
        }
        case RECONNECT_START:
            m_reconnectTimer->start();
            break;
        case RECONNECT_STOP:
            m_reconnectTimer->stop();
            break;
    }

}

void Inn::NetConnService::HBOp() {
    Send("ALIVE " + m_user);
}

void Inn::NetConnService::Reconnect() {
    m_connSt = SERVER_RECONNECTED;
    qDebug() << "Re...";
    m_socket->abort();
    m_socket->connectToHost(m_address, m_port);
}