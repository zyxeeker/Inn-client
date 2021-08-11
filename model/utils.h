//
// Created by zyx on 2021/8/11.
//

#ifndef INNCLIENT_UTILS_H
#define INNCLIENT_UTILS_H

#include <QPixmap>
#include <QPainter>
#include <QSvgRenderer>

class Utils {
public:
    static QPixmap LoadSvg(QString url, int w, int h);
};


#endif //INNCLIENT_UTILS_H
