//
// Created by zyx on 2021/10/13.
//

#include "title_bar.h"
#include "model/utils.h"

#define TITLE_STYLE_1 "QPushButton{border-radius:none;}"\
                    "QPushButton:hover {background-color:rgba(65, 65, 65, 200);}"\
                    "QPushButton:pressed {background-color:rgb(65, 65, 65);}"
#define TITLE_STYLE_2 "QPushButton{border-radius:none;}"\
                    "QPushButton:hover {background-color:rgba(205, 45, 75, 240);}"\
                    "QPushButton:pressed {background-color:rgb(205, 45, 75);}"


AbstractTitleBar::AbstractTitleBar(QWidget *parent, bool isAuth) : QWidget(parent), m_isAuth(isAuth) {
    m_layout = new QHBoxLayout(this);
    m_closeBtn = new QPushButton(this);
    m_minBtn = new QPushButton(this);
    m_maximizedBtn = new QPushButton(this);
    m_name = new QLabel(this);
    m_titleSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_layout->setContentsMargins(5, 0, 0, 0);
    InitUi();
    connect(m_minBtn, &QPushButton::clicked, this, [=]() {
        emit SwitchWindow(WINDOW_MIN);
    });
    if (!m_isAuth)
        connect(m_maximizedBtn, &QPushButton::clicked, this, [=]() {
            if (m_maximized)
                    emit SwitchWindow(WINDOW_NORMAL);
            else
                    emit SwitchWindow(WINDOW_MAX);
        });
    connect(m_closeBtn, &QPushButton::clicked, this, [=]() {
        emit SwitchWindow(WINDOW_CLOSE);
    });
}

void AbstractTitleBar::InitUi() {
    this->setMinimumHeight(25);
    this->setMaximumHeight(25);
    this->setStyleSheet("background:black;");
    m_layout->setContentsMargins(5, 0, 0, 0);
    m_layout->addWidget(m_name);
    m_layout->addItem(m_titleSpacer);
    m_layout->addWidget(m_minBtn);
    if (!m_isAuth) {
        m_layout->addWidget(m_maximizedBtn);
        Utils::InitBtn(m_maximizedBtn, 25, 15, TITLE_STYLE_1, ":/common/resource/max.svg", ":/common/resource/min.svg");
    }
    m_layout->addWidget(m_closeBtn);
    m_layout->setSpacing(0);
    m_name->setText("Inn");
    m_name->setStyleSheet("font-family:'Microsoft YaHei UI';font-size:13px;color:lightgray;");
    Utils::InitBtn(m_minBtn, 25, 15, TITLE_STYLE_1, ":/common/resource/hide.svg");
    Utils::InitBtn(m_closeBtn, 25, 15, TITLE_STYLE_2, ":/common/resource/close.svg");
}

QRectF AbstractTitleBar::BtnRect() {
    auto y = window()->isMaximized() ? 8 : 1;
    QRect captionRect{0, y, width(), height()};
    QRectF rectClose(captionRect.x() + captionRect.width() - 25,
                     y,
                     25,
                     25);
    QRectF rectMax(rectClose.x() - 25,
                   y,
                   25,
                   25);
    QRectF rectMini(rectMax.x() - 25,
                    y,
                    25,
                    25);

    return QRect(rectMini.topLeft().toPoint(), rectClose.bottomRight().toPoint());
}

bool AbstractTitleBar::HitArea(const QPoint &gPos) {
    // ?????????????????????????????????
    auto pos = mapFromGlobal(gPos);
    // ??????????????????????????????????????????????????????????????? HITCAPTION
    if (!this->rect().contains(pos)) {
        return false;
    }
    // ???????????????????????????????????????????????????????????????????????? HITCAPTION
    return !childAt(pos) && !BtnRect().contains(pos);
}

void AbstractTitleBar::SetMaximizedState(bool st) {
    m_maximized = st;
    st ? m_maximizedBtn->setChecked(true) : m_maximizedBtn->setChecked(false);
}
