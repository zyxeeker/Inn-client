//
// Created by zyx on 2021/8/11.
//

#ifndef INNCLIENT_UTILS_H
#define INNCLIENT_UTILS_H

#include <QPixmap>
#include <QPainter>
#include <QSvgRenderer>
#include <QLabel>

class Utils {
public:
    static QPixmap LoadSvg(QString url, int w, int h);

    static QString ElideText(QLabel *l, QString strInfo);
};


#endif //INNCLIENT_UTILS_H
