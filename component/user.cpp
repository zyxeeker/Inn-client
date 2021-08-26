//
// Created by zyx on 2021/8/25.
//

#include "user.h"

AbstractUser::AbstractUser() {
    m_userName = new QLabel;
    m_userIcon = new QLabel;
    m_userStatue = new QLabel;
    m_userDes = new QLabel;
}

void AbstractUser::resizeEvent(QResizeEvent *e) {
    m_userName->setText(Utils::ElideText(m_userName, "testtesttesttesttesttest"));

}

ListUser::ListUser() {
    m_content = new QHBoxLayout;
    m_ds = new QHBoxLayout;
    m_inside = new QVBoxLayout;

    m_userIcon->setMinimumSize(50, 50);
    m_userIcon->setMaximumSize(50, 50);
    m_userIcon->setStyleSheet("background:white;border-radius:25px;");
    m_userStatue->setMinimumSize(18, 18);
    m_userStatue->setMaximumSize(18, 18);
    m_userStatue->setStyleSheet("background:red;border-radius:9px;");
//    m_userName->setText(Utils::ElideText(m_userName,"testtesttest"));

    m_ds->addWidget(m_userStatue);
    m_ds->addWidget(m_userDes);
    m_inside->addWidget(m_userName);
    m_inside->addLayout(m_ds);
    m_content->addWidget(m_userIcon);
    m_content->addLayout(m_inside);
    this->setLayout(m_content);
}