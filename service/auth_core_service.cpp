//
// Created by zyx on 2021/9/7.
//

#include "auth_core_service.h"

AuthCoreService::AuthCoreService(QString ad, uint8_t port) {
    m_socket = new QTcpSocket;
    m_socket->connectToHost(QHostAddress(ad), port);
}