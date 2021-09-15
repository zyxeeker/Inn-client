//
// Created by zyx on 2021/9/8.
//

#include "net_conn_service.h"

Inn::NetConnService::NetConnService(QString ad, uint16_t port) : m_address(ad), m_port(port) {
    m_socket = new QTcpSocket;
    m_socket->connectToHost(m_address, m_port);
    while (m_socket->state() != QAbstractSocket::ConnectedState)
        m_socket->waitForConnected(1000);
    if (m_socket->state() == QAbstractSocket::UnconnectedState)
        qDebug() << "error";

    connect(m_socket, &QTcpSocket::readyRead, this, &NetConnService::onReceiveData);
}

void Inn::NetConnService::Send(std::string pkt) {
    m_socket->write(pkt.c_str());
    m_socket->flush();
}

QTcpSocket *Inn::NetConnService::GetSocket() const {
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
    qDebug() << m_buffer->data();
}

int Inn::NetConnService::Req(REQ_OP req) {
    switch (req) {
        case INN_LOGIN_REQ:
            Send("LOGIN " + m_user + " " + m_pwd);
            break;
        case INN_REG_REQ:
            Send("REG " + m_user + " " + m_pwd);
            break;
        case INN_HEART_BEAT:
            break;
        case INN_LOGOUT_REQ:
            Send("LOGOUT " + m_user);
            break;
    }
    return 0;
}

void Inn::NetConnService::SetUserInfo(std::string user, std::string pwd) {
    m_user = user;
    m_pwd = pwd;
}