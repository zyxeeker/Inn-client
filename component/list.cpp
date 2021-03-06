//
// Created by zyx on 2021/8/7.
//

#include "list.h"
#include <QDebug>

AbstractListItem::AbstractListItem(int num, QString title, QWidget *parent) : m_num(num), m_titleCtx(title),
                                                                              QWidget(parent) {

    m_gtoPx = Utils::LoadSvg(":/component/resource/gto.svg", 20, 20);
    m_body = new QWidget(this);
    m_layout = new QHBoxLayout(m_body);
    m_gto = new QLabel(m_body);
    m_index = new QLabel(m_body);
    m_title = new QLabel(m_body);
    m_body->setObjectName("body");
    m_body->setStyleSheet("#body{margin-left:10px;margin-right:10px;}");
    m_index->setMinimumSize(30, 30);
    m_index->setMaximumSize(30, 30);
    m_index->setAlignment(Qt::AlignHCenter);
    m_index->setAlignment(Qt::AlignVCenter);
    m_index->setText(QString::number(m_num));
    m_index->setStyleSheet("font-family:'Microsoft YaHei UI';font-size:12px;font-weight:bold;color:rgb(149,149,149);");
    m_title->setMinimumSize(200, 40);
    m_title->setMaximumSize(200, 40);
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:14px;");
    m_title->setText(Utils::ElideText(m_title, m_titleCtx));
    m_gto->setMinimumSize(20, 20);
    m_gto->setMaximumSize(20, 20);
    m_gto->setPixmap(m_gtoPx);
    m_gto->setStyleSheet("border:none;background:transparent;");
    m_layout->addWidget(m_index);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_gto);
    m_layout->setContentsMargins(10, 0, 10, 0);
    m_body->setLayout(m_layout);
}

AbstractListView::AbstractListView(QWidget *parent) : QListWidget(parent) {
    ScrollAnimation();
    setViewMode(QListView::ListMode);
    setFlow(QListView::TopToBottom);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
}

void AbstractListView::ScrollAnimation() {
    m_animation = new QPropertyAnimation(this->verticalScrollBar(), "value");
    m_animation->setEasingCurve(QEasingCurve::InOutQuad);
    m_animation->setDuration(380);
}

void AbstractListView::wheelEvent(QWheelEvent *e) {
    int degree = e->angleDelta().y();
    int cur = this->verticalScrollBar()->value();
    if (m_animation->state() == QAbstractAnimation::Stopped) {
        m_animation->setEndValue(cur - degree);
        m_animation->start();
    }
    e->accept();
}


void WBListView::init() {
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setGeometry(QRect(10, 5, 250, 310));
    this->setStyleSheet("background:transparent;border:none;");
    this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    for (int i = 0; i < 50; ++i) {
        ListItem *src = new ListItem(22, "Age of Empire 2:Definition Edition");
        QListWidgetItem *dst = new QListWidgetItem(this, 0);
        dst->setSizeHint(QSize(500, 40));
        this->setItemWidget(dst, src);
        this->addItem(dst);
    }
}
