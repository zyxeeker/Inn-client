//
// Created by zyx on 2021/8/19.
//

#ifndef INNCLIENT_SMOOTH_SCROLL_AREA_H
#define INNCLIENT_SMOOTH_SCROLL_AREA_H

#include <QWidget>
#include <QScrollArea>
#include <QTimer>
#include <QQueue>
#include <QDateTime>
#include <QWheelEvent>
#include <QResizeEvent>
#include <QApplication>

class SmoothScrollArea : public QScrollArea {
Q_OBJECT
public:
    SmoothScrollArea();

    void SetContentLayout(QLayout *l);

protected:
    virtual void wheelEvent(QWheelEvent *e);

    void resizeEvent(QResizeEvent *e);

private:
    double SubDelta(double delta, int stepsLeft);

    void SetContentSize();

private slots:

    void SmoothMove();

private:
    int m_fps = 60;
    int m_duration = 400;
    int m_stepsTotal = 0;
    int m_acceleration = 1;
    QWidget *m_content;
    QWheelEvent *m_lastWheelEvent;
    QTimer *m_smoothMoveTimer;
    QList<QPair<double, int>> m_stepsLeftQueue;

};


#endif //INNCLIENT_SMOOTH_SCROLL_AREA_H
