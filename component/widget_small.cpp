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


SWidget::SWidget() {
    InitUI();
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
            "border-radius:24px;background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(121, 74, 255, 255), stop:0.59887 rgba(154, 75, 255, 255), stop:1 rgba(174, 76, 255, 255));");

    m_icon = new QLabel(m_banner);
    m_icon->setGeometry(QRect(35, 25, 85, 85));
    m_icon->setPixmap(*m_px);

    m_title = new QLabel(m_banner);
    m_title->setGeometry(QRect(0, 110, 150, 18));
    m_title->setText(QString("微博"));
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:18px;");
    m_title->setAlignment(Qt::AlignCenter);
}

void SWidget::RegSContent() {
    RegBanner();
    m_sContent = new QWidget(this);
    m_sContent->setObjectName("bk");
    m_sContent->setGeometry(QRect(0, 0, 300, 400));
    m_sContent->setStyleSheet("#bk{border-radius:24px;background-color:rgb(28, 28, 30);}");

    m_refreshBtn = new QPushButton(m_sContent);
    m_backBtn = new QPushButton(m_sContent);

    m_refreshBtn->setGeometry(QRect(220, 10, 25, 25));
    m_refreshBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                                "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                                "QPushButton:pressed{background-color: rgb(10, 132, 255);}");

    m_backBtn->setGeometry(QRect(250, 10, 25, 25));
    m_backBtn->setStyleSheet("QPushButton{border-radius:5px;background-color: rgb(10, 132, 255);}"
                             "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                             "QPushButton:pressed{background-color: rgb(10, 132, 255);}");


}

void SWidget::RegList() {
    m_listContainer = new QWidget(m_sContent);
    m_listContainer->setObjectName("listContainer");
    m_listContainer->setGeometry(QRect(10, 40, 280, 350));
    m_listContainer->setStyleSheet("#listContainer{border-radius:24px;background-color:black;}");

    m_list = new QListWidget(m_listContainer);
    m_list->setObjectName("list");
    m_list->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_list->setGeometry(QRect(10, 10, 260, 330));
    m_list->setStyleSheet("#list{background-color:transparent;border:none;}");

}

void SWidget::RegBk() {
    RegBanner();
    RegSContent();
    RegList();
    for (int i = 0; i < 50; ++i) {
        ListItem *src = new ListItem(2, ",,,,,,,");
        QListWidgetItem *dst = new QListWidgetItem(m_list, 0);
        dst->setSizeHint(QSize(230, 40));
        m_list->setItemWidget(dst, src->init());
        m_list->addItem(dst);
    }

}

void SWidget::RegBk_2() {
    m_bk = new QLabel(this);
    m_bk->setGeometry(QRect(0, 0, 124, 150));
    m_bk->setStyleSheet(QString::fromUtf8("border-top-left-radius:24px;border-bottom-left-radius:24px;"
                                          "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(121, 74, 255, 255), stop:0.59887 rgba(154, 75, 255, 255), stop:1 rgba(174, 76, 255, 255));"));

    m_icon = new QLabel(this);
    m_icon->setGeometry(QRect(24, 25, 80, 80));
    m_icon->setPixmap(*m_px);
//    m_icon->setStyleSheet(QString::fromUtf8("background-image:url(:/common/resource/weibo.svg);"));

    m_title = new QLabel(this);
    m_title->setGeometry(QRect(0, 110, 124, 18));
    m_title->setText(QString("微博"));
    m_title->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:18px;");
    m_title->setAlignment(Qt::AlignCenter);

    m_content = new QWidget(this);
    m_content->setGeometry(QRect(124, 0, 200, 150));
    m_content->setStyleSheet(
            "border-top-right-radius:24px;border-bottom-right-radius:24px;background-color: rgb(28, 28, 30);");

    load_1();

    m_btn = new QPushButton(m_content);
    m_btn->setGeometry(QRect(50, 120, 100, 20));
    m_btn->setIcon(QIcon(QString(":/common/resource/hide.svg")));
    m_btn->setStyleSheet("QPushButton{border-radius:10px;background-color: rgb(10, 132, 255);}"
                         "QPushButton:hover{background-color: rgb(132, 194, 255);}"
                         "QPushButton:pressed{background-color: rgb(10, 132, 255);}");
}

void SWidget::load() {
    QSvgRenderer r(QString(":/common/resource/weibo.svg"));
    m_px = new QPixmap(QSize(80, 80));
    QPainter Painter;
    m_px->fill(Qt::transparent);
    Painter.begin(m_px);
    r.render(&Painter);
    Painter.end();

    QSvgRenderer r1(QString(":/common/resource/1.svg"));
    m_px1 = new QPixmap(QSize(15, 15));
    QPainter Painter1;
    m_px1->fill(Qt::transparent);
    Painter1.begin(m_px1);
    r1.render(&Painter1);
    Painter1.end();

    QSvgRenderer r2(QString(":/common/resource/2.svg"));
    m_px2 = new QPixmap(QSize(15, 15));
    QPainter Painter2;
    m_px2->fill(Qt::transparent);
    Painter2.begin(m_px2);
    r2.render(&Painter2);
    Painter2.end();

    QSvgRenderer r3(QString(":/common/resource/3.svg"));
    m_px3 = new QPixmap(QSize(15, 15));
    QPainter Painter3;
    m_px3->fill(Qt::transparent);
    Painter3.begin(m_px3);
    r3.render(&Painter3);
    Painter3.end();

    QSvgRenderer r4(QString(":/common/resource/hide.svg"));
    m_t = new QPixmap(QSize(15, 15));
    QPainter Painter4;
    m_t->fill(Qt::transparent);
    Painter4.begin(m_t);
    r4.render(&Painter4);
    Painter4.end();
}

void SWidget::load_1() {
    m_no1 = new QLabel(m_content);
    m_no2 = new QLabel(m_content);
    m_no3 = new QLabel(m_content);

    m_hotTitle1 = new QLabel(m_content);
    m_hotTitle2 = new QLabel(m_content);
    m_hotTitle3 = new QLabel(m_content);

    m_no1->setGeometry(QRect(20, 30, 15, 15));
    m_no1->setPixmap(*m_px1);

    QString t = "TEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETESTTEST TSETEST";
    m_hotTitle1->setGeometry(QRect(40, 30, 150, 15));
    QFontMetrics fontWidth1(m_hotTitle1->font());//得到每个字符的宽度
    QString elideNote1 = fontWidth1.elidedText(t, Qt::ElideRight, 100);
    m_hotTitle1->setText(elideNote1);
    m_hotTitle1->setStyleSheet("color:rgb(152, 152, 159);font-family:'Microsoft YaHei UI';font-size:15px;");

    m_no2->setGeometry(QRect(20, 60, 15, 15));
    m_no2->setPixmap(*m_px2);
    m_hotTitle2->setGeometry(QRect(40, 60, 150, 15));
    QFontMetrics fontWidth2(m_hotTitle1->font());//得到每个字符的宽度
    QString elideNote2 = fontWidth2.elidedText(t, Qt::ElideRight, 100);
    m_hotTitle2->setText(elideNote2);
    m_hotTitle2->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:15px;");

    m_no3->setGeometry(QRect(20, 90, 15, 15));
    m_no3->setPixmap(*m_px3);
    m_hotTitle3->setGeometry(QRect(40, 90, 150, 15));
    QFontMetrics fontWidth3(m_hotTitle1->font());//得到每个字符的宽度
    QString elideNote3 = fontWidth3.elidedText(t, Qt::ElideRight, 100);
    m_hotTitle3->setText(elideNote3);
    m_hotTitle3->setStyleSheet("color:white;font-family:'Microsoft YaHei UI';font-size:15px;");
}