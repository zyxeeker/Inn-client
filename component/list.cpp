//
// Created by zyx on 2021/8/7.
//

#include "list.h"
#include <QDebug>

void AbstractListView::wheelEvent(QWheelEvent *e) {
    int degree = e->delta();
    int cur = this->verticalScrollBar()->value();
    if (m_animation->state() == QAbstractAnimation::Stopped) {
        m_animation->setEndValue(cur - degree);
        m_animation->start();
    }
    e->accept();
}

AbstractListView::AbstractListView(QWidget *parent) : QListWidget(parent) {
    ScrollAnimation();
    setViewMode(QListView::ListMode);
    setFlow(QListView::TopToBottom);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

}

QWidget *ListItem::init() {
    //    m_gtoPx = Utils::LoadSvg(":/component/resource/gto.svg", 15, 15);
    m_w = new QWidget();
    m_layout = new QHBoxLayout(m_w);
    m_gto = new QLabel(m_w);
    m_index = new QLabel(m_w);
    m_title = new QLabel(m_w);
    m_w->setStyleSheet("border-bottom:1px solid white;");
    m_index->setMinimumSize(20, 20);
    m_index->setMaximumSize(20, 20);
    m_index->setText(QString::number(m_num));
    m_index->setStyleSheet("color:white;");
    m_title->setStyleSheet("color:white;");
    m_title->setText(m_titleCtx);
    m_gto->setMinimumSize(20, 20);
    m_gto->setMaximumSize(20, 20);
    m_gto->setPixmap(m_gtoPx);
    m_gto->setStyleSheet("border:none;background:transparent;");
    m_layout->addWidget(m_index);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_gto);
    m_w->setLayout(m_layout);
    return m_w;
}

void ListView::init() {
    this->setObjectName("list");
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setGeometry(QRect(10, 5, 250, 310));
    this->setStyleSheet("#list{background-color:transparent;border:none;}");
    this->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    this->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    for (int i = 0; i < 50; ++i) {
        ListItem *src = new ListItem(2, ",,,,,,,");
        QListWidgetItem *dst = new QListWidgetItem(this, 0);
        dst->setSizeHint(QSize(230, 40));
        this->setItemWidget(dst, src->init());
        this->addItem(dst);
    }
}

void AbstractListView::ScrollAnimation() {
    m_animation = new QPropertyAnimation(this->verticalScrollBar(), "value");
    m_animation->setEasingCurve(QEasingCurve::InOutQuad);
    m_animation->setDuration(300);

}