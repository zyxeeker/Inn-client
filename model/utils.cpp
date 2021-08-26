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