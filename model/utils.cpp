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
