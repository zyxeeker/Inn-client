//
// Created by zyx on 2021/9/7.
//

#ifndef INNCLIENT_AUTH_CORE_SERVICE_H
#define INNCLIENT_AUTH_CORE_SERVICE_H

#include <QTcpSocket>
#include <QHostAddress>

class AuthCoreService {
public:
    AuthCoreService(QString ad, uint8_t port);

private:
    QTcpSocket *m_socket;

};


#endif //INNCLIENT_AUTH_CORE_SERVICE_H
