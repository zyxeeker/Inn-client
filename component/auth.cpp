//
// Created by zyx on 2021/7/30.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Auth.h" resolved

#include "auth.h"
#include "ui_Auth.h"


Auth::Auth(QWidget *parent) :
        QWidget(parent), ui(new Ui::Auth) {
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
}

Auth::~Auth() {
    delete ui;
}

