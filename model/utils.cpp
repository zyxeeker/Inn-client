//
// Created by zyx on 2021/8/11.
//

#include "utils.h"

QPixmap Utils::LoadSvg(QString url, int w, int h) {
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

QString Utils::ElideText(QLabel *l, QString strInfo) {
    QFontMetrics fontMetrics(l->font());
    //如果当前字体下，字符串长度大于指定宽度
    if (fontMetrics.width(strInfo) > l->width())
        strInfo = QFontMetrics(l->font()).elidedText(strInfo, Qt::ElideRight, l->width() - 20);
    return strInfo;
}

void Utils::InitBtn(QPushButton *b, int s1, int s2, QString s, QString url, QString ourl) {
    QIcon pIcon;
    pIcon.addPixmap(QPixmap(url), QIcon::Normal, QIcon::Off);
    if (!ourl.isEmpty()) {
        pIcon.addPixmap(QPixmap(ourl), QIcon::Active, QIcon::On);
        b->setCheckable(true);
        b->setAutoExclusive(true);
    }
    b->setMinimumSize(s1, s1);
    b->setMaximumSize(s1, s1);
    b->setIcon(pIcon);
    b->setIconSize(QSize(s2, s2));
    b->setStyleSheet(s);
}