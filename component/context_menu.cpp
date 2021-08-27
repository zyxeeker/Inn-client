//
// Created by zyx on 2021/8/26.
//

#include "context_menu.h"

AbstractContextMenu::AbstractContextMenu() {
    m_body = new QWidget(this);
    m_effect = new QGraphicsDropShadowEffect;

    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(0, 0, 0, 150));
    m_effect->setBlurRadius(50);
    m_body->setStyleSheet("background-color:rgb(53,53,56);border-radius:5px;");
    m_body->setGraphicsEffect(m_effect);
    m_body->move(30, 30);
}

void AbstractContextMenu::InitBtn(QPushButton *btn, QString url, QLayout *layout) {
    QIcon icon;
    icon.addFile(url);
    btn->setIcon(icon);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setIconSize(QSize(18, 18));
    btn->setStyleSheet("::hover{background-color:rgb(71,71,74);}");
    btn->setMinimumHeight(28);
    btn->setMinimumWidth(28);
    layout->addWidget(btn);
}

ChatContentContextMenu::ChatContentContextMenu() {
    m_copyBtn = new QPushButton;
    m_highLightBtn = new QPushButton;
    m_layout = new QHBoxLayout;
    InitBtn(m_copyBtn, ":/common/resource/copy.svg", m_layout);
    InitBtn(m_highLightBtn, ":/common/resource/high_light.svg", m_layout);
    m_layout->setContentsMargins(4, 4, 4, 4);
    m_layout->setSpacing(4);
    m_body->setMinimumHeight(36);
    m_body->setMaximumHeight(36);
    m_body->setLayout(m_layout);

}

AllChatContentSelectedContextMenu::AllChatContentSelectedContextMenu() {
    m_thumbUpBtn = new QPushButton;
    m_replyBtn = new QPushButton;
    InitBtn(m_replyBtn, ":/common/resource/reply.svg", m_layout);
    InitBtn(m_thumbUpBtn, ":/common/resource/thumbs_up.svg", m_layout);
}