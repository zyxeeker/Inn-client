#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qbuttongroup.h>
#include "ui_auth.h"
#include <QString>
#include<QtNetwork/QtNetwork>

class auth : public QMainWindow
{
	Q_OBJECT
public:
	auth(QWidget* parent = Q_NULLPTR);

	void send_data();

	void send_message(const char* text) {
		ui.message->setText(QString::fromLocal8Bit(text));
	};
	
	void send_message();

private slots:
	void login_info();

	void reg_info();

private:
	Ui::authClass ui;

	QString m_user;
	QString m_pwd;

	char m_message_buff[1024];
	QTcpSocket* m_socket;

	std::string m_data;
};

