//
// Created by zyx on 2021/8/26.
//

#include "context_menu.h"
#include <QDebug>

AbstractContextMenu::AbstractContextMenu() {
    m_body = new QWidget(this);
    m_effect = new QGraphicsDropShadowEffect;
    m_layout = new QHBoxLayout;

    m_layout->setContentsMargins(4, 4, 4, 4);
    m_layout->setSpacing(4);
    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(0, 0, 0, 150));
    m_effect->setBlurRadius(50);
    m_body->setStyleSheet("background-color:rgb(53,53,56);border-radius:5px;");
    m_body->setGraphicsEffect(m_effect);
    m_body->move(30, 30);
    m_body->setMinimumHeight(36);
    m_body->setMaximumHeight(36);
    m_body->setLayout(m_layout);
}

void AbstractContextMenu::InitBtn(QPushButton *btn, QString url) {
    QIcon icon;
    icon.addFile(url);
    btn->setIcon(icon);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setIconSize(QSize(18, 18));
    btn->setStyleSheet("::hover{background-color:rgb(71,71,74);}");
    btn->setMinimumHeight(28);
    btn->setMinimumWidth(28);
}

ChatContentSelectedContextMenu::ChatContentSelectedContextMenu() {
    m_st = SELECTED_PART;
    m_copyBtn = new QPushButton;
    m_highlightBtn = new QPushButton;
    m_thumbUpBtn = new QPushButton;
    m_replyBtn = new QPushButton;
    InitBtn(m_copyBtn, ":/common/resource/copy.svg");
    InitBtn(m_highlightBtn, ":/common/resource/high_light.svg");
    InitBtn(m_replyBtn, ":/common/resource/reply.svg");
    InitBtn(m_thumbUpBtn, ":/common/resource/thumbs_up.svg");
    m_layout->addWidget(m_copyBtn);
    m_layout->addWidget(m_highlightBtn);
    connect(m_copyBtn, &QPushButton::clicked, this, [=]() {
        emit Operation(COPY);
    });
}

void ChatContentSelectedContextMenu::SetBtnGroup(int st) {
    switch (st) {
        case SELECTED_ALL:
            if (m_st == SELECTED_PART) {
                m_layout->addWidget(m_replyBtn);
                m_layout->addWidget(m_thumbUpBtn);
                m_body->adjustSize();
            }
            m_st = SELECTED_ALL;
            break;
        case SELECTED_PART:
            if (m_st == SELECTED_ALL) {
                m_layout->removeWidget(m_replyBtn);
                m_layout->removeWidget(m_thumbUpBtn);
                m_body->adjustSize();
            }
            m_st = SELECTED_PART;
            break;
    }
}

TextEditContentContextMenu::TextEditContentContextMenu() {
    m_st = INPUT_AREA_EMPTY;
    m_copyBtn = new QPushButton;
    m_pasteBtn = new QPushButton;
    m_cutBtn = new QPushButton;
    m_highlightBtn = new QPushButton;
    InitBtn(m_pasteBtn, ":/common/resource/paste.svg");
    InitBtn(m_cutBtn, ":/common/resource/cut.svg");
    InitBtn(m_highlightBtn, ":/common/resource/high_light.svg");
    InitBtn(m_copyBtn, ":/common/resource/copy.svg");
    m_layout->addWidget(m_pasteBtn);
    connect(m_copyBtn, &QPushButton::clicked, this, [=]() {
        emit Operation(COPY);
    });
    connect(m_pasteBtn, &QPushButton::clicked, this, [=]() {
        emit Operation(PASTE);
    });
    connect(m_cutBtn, &QPushButton::clicked, this, [=]() {
        emit Operation(CUT);
    });
}

void TextEditContentContextMenu::SetBtnGroup(int st) {
    switch (st) {
        case INPUT_AREA_EMPTY:
            if (m_st != INPUT_AREA_EMPTY) {
                m_layout->removeWidget(m_copyBtn);
                m_layout->removeWidget(m_highlightBtn);
                m_layout->removeWidget(m_cutBtn);
                m_body->adjustSize();
            }
            m_st = INPUT_AREA_EMPTY;
            break;
        default:
            m_layout->addWidget(m_copyBtn);
            m_layout->addWidget(m_cutBtn);
            m_layout->addWidget(m_highlightBtn);
            m_body->adjustSize();
            m_st = INPUT_AREA_NOT_EMPTY;
            break;

    }
}

ControlPanelContextMenu::ControlPanelContextMenu() {
    m_onlineBtn = new QPushButton;
    m_busyBtn = new QPushButton;
    m_sleepBtn = new QPushButton;
    m_layout = new QVBoxLayout;
    m_effect = new QGraphicsDropShadowEffect;
    m_body = new QWidget(this);

    InitBtn(m_onlineBtn, ":/user/resource/online.svg", "  在线");
    InitBtn(m_busyBtn, ":/user/resource/busy.svg", "  忙碌");
    InitBtn(m_sleepBtn, ":/user/resource/sleep.svg", "  离开");

    connect(m_onlineBtn, &QPushButton::clicked, this, [=]() {
        emit StatueChanged(ONLINE);
    });
    connect(m_busyBtn, &QPushButton::clicked, this, [=]() {
        emit StatueChanged(BUSY);
    });
    connect(m_sleepBtn, &QPushButton::clicked, this, [=]() {
        emit StatueChanged(SLEEP);
    });

    m_effect->setOffset(0, 0);
    m_effect->setColor(QColor(0, 0, 0, 150));
    m_effect->setBlurRadius(50);
    m_body->setStyleSheet("background-color:rgb(53,53,56);border-radius:3px;");
    m_body->setGraphicsEffect(m_effect);
    m_body->move(30, 30);
    m_body->setLayout(m_layout);
    m_body->setMinimumSize(80, 86);
    m_body->setMaximumSize(80, 86);
    m_layout->setContentsMargins(2, 2, 2, 2);
    m_layout->setSpacing(2);
}

void ControlPanelContextMenu::InitBtn(QPushButton *btn, QString url, QString name) {
    QIcon icon;
    icon.addFile(url);
    btn->setIcon(icon);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setIconSize(QSize(18, 18));
    btn->setStyleSheet(
            "QPushButton{color:rgb(216,216,216);font-family:'Microsoft YaHei UI';font-size:13px;}QPushButton::hover{background-color:rgb(71,71,74);}");
    btn->setMinimumHeight(26);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setText(name);
    m_layout->addWidget(btn);
}
