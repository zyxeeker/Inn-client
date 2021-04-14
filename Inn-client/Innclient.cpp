#include "Innclient.h"
#include <QDebug>

void Innclient::chat_content() {
    QDateTime time = QDateTime::currentDateTime();
    QString str = "YOU " + time.toString("yyyy.MM.dd hh:mm:ss ddd") + " :\n";
    ui.textBrowser->append(str + m_content);
}

void Innclient::chat_content(QByteArray text) {
    QDateTime time = QDateTime::currentDateTime();
    QString str = m_item->text() + " " + time.toString("yyyy.MM.dd hh:mm:ss ddd") + " :\n" + text;

    ui.textBrowser->append(str);
}

void Innclient::send_to_client() {
    QByteArray buffer = auth::m_socket->readAll();
    if(buffer.size())
        chat_content(buffer);
    qDebug() << buffer;
}

void Innclient::send(std::string comand) {
    connect(auth::m_socket, &QTcpSocket::readyRead, [=]() {
        send_to_client();
    });

    auth::m_socket->connectToHost(QHostAddress("127.0.0.1"), 9006);
    auth::m_socket->write(comand.c_str());
}

Innclient::Innclient(QWidget *parent)
    : QMainWindow(parent)
{
    m_item = new QListWidgetItem;

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    ui.setupUi(this);
    
    connect(ui.online_user, &QListWidget::itemDoubleClicked, [=]() {
        m_item = ui.online_user->currentItem();
        ui.username->setText(m_item->text());
    });

    connect(ui.send, &QPushButton::clicked, [=]() {
        m_content = ui.content->toPlainText();
        qDebug() << m_content;
        chat_content();
        send("CHAT " + m_item->text().toStdString() + ' ' + m_content.toStdString());
    });

}
