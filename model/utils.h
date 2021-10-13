//
// Created by zyx on 2021/8/11.
//

#ifndef INNCLIENT_UTILS_H
#define INNCLIENT_UTILS_H

#include <QPixmap>
#include <QPainter>
#include <QSvgRenderer>
#include <QLabel>
#include <QPushButton>

class Utils {
public:
    static QPixmap LoadSvg(QString url, int w, int h);
    static QString ElideText(QLabel *l, QString strInfo);
    static void InitBtn(QPushButton *b, int s1, int s2, QString s, QString url, QString ourl = nullptr);
};


#endif //INNCLIENT_UTILS_H
