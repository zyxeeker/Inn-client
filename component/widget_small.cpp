//
// Created by zyx on 2021/8/4.
//

#include "widget_small.h"
#include "../model/utils.hpp"

QWidget *ListItem::init() {
    m_gtoPx = Utils::LoadSvg(":/component/resource/gto.svg", 15, 15);
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

SWidget::SWidget() {
    InitUI();
    connect(m_backBtn, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation *animation = new QPropertyAnimation(m_sContent, "geometry");
        animation->setEasingCurve(QEasingCurve::InOutSine);
        animation->setDuration(200);
        animation->setStartValue(m_sContent->geometry());
        animation->setEndValue(QRect(0, 250, 150, 150));
        animation->start();
        m_banner->show();
    });
    connect(m_btn, &QPushButton::clicked, this, [=]() {
        QPropertyAnimation *animation = new QPropertyAnimation(m_sContent, "geometry");
        animation->setEasingCurve(QEasingCurve::InOutSine);
        animation->setDuration(200);
        animation->setStartValue(m_sContent->geometry());
        animation->setEndValue(QRect(0, 0, 300, 400));
        animation->start();
        m_banner->hide();
    });
}

void SWidget::InitUI() {
    load();
    RegBk();

}

void SWidget::RegBanner() {
    m_banner = new QWidget(this);
    m_banner->setGeometry(QRect(0, 250, 150, 150));

    m_bk = new QLabel(m_banner);
    m_bk->setGeometry(QRect(0, 0, 150, 150));
    m_bk->setStyleSheet(
            "border-radius:20px;background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(121, 74, 255, 255), stop:0.59887 rgba(154, 75, 255, 255), stop:1 rgba(174, 76, 255, 255));");

    m_icon = new QLabel(m_banner);
    m_icon->setGeometry(QRect(35, 25, 85, 85));
    m_icon->setPixmap(m_px);

    m_title = new QLabel(m_banner);
    m_title->setGeometry(QRect(0, 110, 150, 18));
    m_title->setText(QString("WB"));
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:18px;");
    m_title->setAlignment(Qt::AlignCenter);
    m_btn = new QPushButton(m_banner);
    m_btn->setGeometry(QRect(0, 110, 150, 18));

}

void SWidget::RegSContent() {
    m_sContent = new QWidget(this);
    m_sBanner = new QWidget(m_sContent);
    m_titleCtx = new QLabel(m_sBanner);
    m_sBanner->setObjectName("title");
    m_sBanner->setMinimumSize(150, 100);
    m_sBanner->setMaximumSize(300, 100);
    m_sBanner->setStyleSheet(
            "#title{border-top-left-radius:24px;border-top-right-radius:24px;background:url(:/component/resource/weibo_banner.png);}");

    QLabel *name = new QLabel(m_sBanner);
    name->setText("今天");
    name->setMaximumHeight(50);
    name->setMinimumHeight(50);
    name->setStyleSheet("padding-top:20px;color:white;font-family:'Microsoft YaHei UI';font-size:30px;");

    m_titleCtx->setText("2021-8-5");
    m_titleCtx->setMaximumHeight(30);
    m_titleCtx->setMinimumHeight(30);
    m_titleCtx->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:15px;");

    m_sContent->setObjectName("bk");
    m_sContent->setGeometry(QRect(0, 250, 100, 100));
#if 0
    m_sContent->setGeometry(QRect(0, 0, 300, 400));
#endif
    m_sContent->setStyleSheet("#bk{border-radius:24px;background-color:rgb(28, 28, 30);}");

    m_refreshBtn = new QPushButton(m_sContent);
    m_backBtn = new QPushButton(m_sContent);

    m_refreshBtn->setIcon(QIcon(m_refreshIcon));
    m_refreshBtn->setMinimumSize(25, 25);
    m_refreshBtn->setMaximumSize(25, 25);
    m_refreshBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                                "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                                "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_backBtn->setObjectName("backBtn");
    m_backBtn->setIcon(QIcon(m_minimizedIcon));
//    m_backBtn->setGeometry(QRect(250, 10, 25, 25));
    m_backBtn->setMinimumSize(25, 25);
    m_backBtn->setMaximumSize(25, 25);
    m_backBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                             "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                             "QPushButton:pressed{background-color: rgb(10, 132, 255);}");
    m_btns = new QHBoxLayout;
    m_ctxBanner = new QVBoxLayout;
    m_btns->addWidget(m_titleCtx);
    m_btns->addWidget(m_refreshBtn);
    m_btns->addWidget(m_backBtn);
    m_btns->setSpacing(5);
    m_btns->setContentsMargins(10, 5, 10, 0);
    m_ctxBanner->addWidget(name);
    m_ctxBanner->addItem(m_btns);
//    m_ctxBanner->setContentsMargins(5,20,5,5);
    m_sBanner->setLayout(m_ctxBanner);
}

void SWidget::RegList() {
    m_listContainer = new QWidget(m_sContent);
    m_listContainer->setObjectName("listContainer");
    m_listContainer->setGeometry(QRect(10, 40, 280, 350));
    m_listContainer->setStyleSheet("#listContainer{border-radius:24px;background-color:black;}");

    m_listLayout = new QVBoxLayout;
    m_listLayout->addWidget(m_listContainer);
    m_listLayout->setContentsMargins(10, 5, 10, 10);

    m_list = new QListWidget(m_listContainer);
    m_list->setObjectName("list");
    m_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_list->setGeometry(QRect(10, 5, 250, 310));
    m_list->setStyleSheet("#list{background-color:transparent;border:none;}");
}

void SWidget::RegBk() {
    RegSContent();
    RegBanner();
    RegList();
    m_layout = new QVBoxLayout(m_sContent);
    m_layout->addWidget(m_sBanner);
    m_layout->setContentsMargins(0, 0, 0, 0);
//    m_layout->addItem(m_btns);
    m_layout->addItem(m_listLayout);
    m_sContent->setLayout(m_layout);
    for (int i = 0; i < 50; ++i) {
        ListItem *src = new ListItem(2, ",,,,,,,");
        QListWidgetItem *dst = new QListWidgetItem(m_list, 0);
        dst->setSizeHint(QSize(230, 40));
        m_list->setItemWidget(dst, src->init());
        m_list->addItem(dst);
    }

}
void SWidget::load() {
    m_px = Utils::LoadSvg(":/component/resource/weibo.svg", 80, 80);
    m_px1 = Utils::LoadSvg(":/component/resource/1.svg", 15, 15);
    m_px2 = Utils::LoadSvg(":/component/resource/2.svg", 15, 15);
    m_px3 = Utils::LoadSvg(":/component/resource/3.svg", 15, 15);
    m_refreshIcon = Utils::LoadSvg(":/component/resource/refresh.svg", 15, 15);
    m_minimizedIcon = Utils::LoadSvg(":/component/resource/left-small-down.svg", 15, 15);
}
