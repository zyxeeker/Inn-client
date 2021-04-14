#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Innclient.h"
#include "auth.h"
#include <QListWidget>
#include <QString>
#include <QDateTime>
#include <QtNetwork/QtNetwork>

class Innclient : public QMainWindow
{
    Q_OBJECT

public:
    Innclient(QWidget *parent = Q_NULLPTR);

    void chat_content();

    void chat_content(QByteArray content);

private:
    void send(std::string comand);

    void send_to_client();

private:
    Ui::InnclientClass ui;
    QListWidgetItem* m_item;

    QString m_content;
};
