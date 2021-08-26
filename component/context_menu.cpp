//
// Created by zyx on 2021/8/26.
//

#include "context_menu.h"

AbstractContextMenu::AbstractContextMenu() {
    m_body = new QWidget(this);
    m_effect = new QGraphicsDropShadowEffect;

    m_body->setStyleSheet("background-color:black;border-radius:5px;");
    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(0, 0, 0, 100));
    m_effect->setBlurRadius(50);
    m_body->setGraphicsEffect(m_effect);

}

ChatContentContextMenu::ChatContentContextMenu() {
    m_copyBtn = new QPushButton;
    m_replyBtn = new QPushButton;
    m_agreeBtn = new QPushButton;
    m_layout = new QHBoxLayout;

    InitBtn(m_copyBtn, ":/common/resource/copy.svg");

    m_layout->addWidget(m_copyBtn);
    m_body->setMinimumHeight(40);
    m_body->setMaximumHeight(40);
    m_body->setLayout(m_layout);

}

void ChatContentContextMenu::InitBtn(QPushButton *btn, QString url) {
    btn->setStyleSheet("background-color:red;");
    QIcon icon;
    icon.addFile(url);
    btn->setIcon(icon);
}