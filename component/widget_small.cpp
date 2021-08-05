//
// Created by zyx on 2021/8/4.
//

#include "widget_small.h"

QWidget *ListItem::init() {
    m_w = new QWidget();
    m_layout = new QHBoxLayout(m_w);
    m_gto = new QPushButton(m_w);
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
    m_layout->addWidget(m_index);
    m_layout->addWidget(m_title);
    m_layout->addWidget(m_gto);
    m_w->setLayout(m_layout);
    return m_w;
}

QPixmap SWidget::LoadSvg(QString url, int w, int h) {
    QPixmap *px = new QPixmap(QSize(w, h));
    px->scaled(15, 15, Qt::IgnoreAspectRatio);
    QSvgRenderer r(url);
    QPainter Painter;
    px->fill(Qt::transparent);
    Painter.begin(px);
    r.render(&Painter);
    Painter.end();
    return *px;
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
    m_btns->addWidget(m_refreshBtn);
    m_btns->addWidget(m_backBtn);
    m_btns->setSpacing(5);
    m_btns->setContentsMargins(0, 5, 10, 5);
}

void SWidget::RegList() {
    m_listContainer = new QWidget(m_sContent);
    m_listContainer->setObjectName("listContainer");
    m_listContainer->setGeometry(QRect(10, 40, 280, 350));
    m_listContainer->setStyleSheet("#listContainer{border-radius:24px;background-color:black;}");

    m_listLayout = new QVBoxLayout;
    m_listLayout->addWidget(m_listContainer);
    m_listLayout->setContentsMargins(5, 0, 5, 10);

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
    m_layout->addItem(m_btns);
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
    m_px = LoadSvg(":/component/resource/weibo.svg", 80, 80);
    m_px1 = LoadSvg(":/component/resource/1.svg", 15, 15);
    m_px2 = LoadSvg(":/component/resource/2.svg", 15, 15);
    m_px3 = LoadSvg(":/component/resource/3.svg", 15, 15);
    m_refreshIcon = LoadSvg(":/component/resource/refresh.svg", 15, 15);
    m_minimizedIcon = LoadSvg(":/component/resource/left-small-down.svg", 15, 15);
}
