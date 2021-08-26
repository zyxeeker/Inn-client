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

    m_userIcon->setMinimumSize(30, 30);
    m_userIcon->setMaximumSize(0, 30);
    m_userIcon->setStyleSheet("background:white;border-radius:15px;");
    m_userStatue->setMinimumSize(14, 14);
    m_userStatue->setMaximumSize(14, 14);
    m_userStatue->setStyleSheet("background:red;border-radius:7px;");
    m_userName->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:14px;");

    m_ds->addWidget(m_userStatue);
    m_ds->addWidget(m_userDes);
    m_inside->addWidget(m_userName);
    m_inside->addLayout(m_ds);
    m_content->addWidget(m_userIcon);
    m_content->addLayout(m_inside);
    m_content->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_content);
}