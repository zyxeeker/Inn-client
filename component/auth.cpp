//
// Created by zyx on 2021/7/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Auth.h" resolved

#include "auth.h"
#include "ui_Auth.h"


Auth::Auth(QWidget *parent) :
        QWidget(parent), ui(new Ui::Auth) {
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
}

Auth::~Auth() {
    delete ui;
}

void Auth::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_mousePress = true;
        m_mousePosition = event->pos();
    }
}

void Auth::mouseMoveEvent(QMouseEvent *event) {
    if (m_mousePress) {
        QPoint position = event->globalPos();
        this->move(position - m_mousePosition);
    }
}

void Auth::mouseReleaseEvent(QMouseEvent *event) {
    m_mousePress = false;
}

void Auth::on_loginBtn_clicked() {
    if (ui->usename->text() == nullptr || ui->pwd->text() == nullptr)
        ui->tip->setText("ERROR:wrong username and password!");
    else {
        ui->tip->setText("INFO:authentication!");
        m_username = ui->usename->text();
        m_pwd = ui->pwd->text();
    }
}

