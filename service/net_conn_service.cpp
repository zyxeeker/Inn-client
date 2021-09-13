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

int Inn::AuthService::LoginReq(std::string user, std::string pwd) {

}

int Inn::AuthService::RegReq(std::string user, std::string pwd) {

}