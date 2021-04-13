#include "auth.h"
#include <string>
#include <iostream>

void auth::send_message() {
	QByteArray buffer = m_socket->readAll();
	ui.message->setText(buffer);
	m_socket->abort();
}


void auth::send_data() {
	m_socket = new QTcpSocket();
	connect(m_socket, &QTcpSocket::readyRead, [=]() {
		send_message();
	});
	m_socket->connectToHost(QHostAddress("127.0.0.1"), 9006);
	m_socket->write(m_data.c_str());
}

void auth::login_info() {
	m_user = ui.user->text();
	m_pwd = ui.passwd->text();
	m_data = "LOGIN " + m_user.toStdString() + " " + m_pwd.toStdString();
	send_data();
}

void auth::reg_info() {
	if ((ui.reg_user->text()).isEmpty()) {
		send_message("用户名为空!");
		return;
	}

	m_user = ui.reg_user->text();
	m_pwd = ui.reg_passwd->text();
	QString pwd_sec = ui.reg_passwd_again->text();
	if (pwd_sec == m_pwd) {
		m_data = "REG " + m_user.toStdString() + " " + m_pwd.toStdString();
		send_data();
	}

	send_message("两次密码不相同!");
}

auth::auth(QWidget* parent) : QMainWindow(parent) {
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	ui.setupUi(this);
	
	ui.reg_widget->hide();

	connect(ui.login, &QPushButton::clicked, this, &auth::login_info);
	connect(ui.reg_confirm, &QPushButton::clicked, this, &auth::reg_info);

	connect(ui.back, &QPushButton::clicked, [=]() {
		send_message(Q_NULLPTR);
	});

	connect(ui.reg, &QPushButton::clicked, [=]() {
		send_message(Q_NULLPTR);
	});

}
