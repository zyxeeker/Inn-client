//
// Created by zyx on 2021/10/13.
//

#ifndef INNCLIENT_BORDERLESS_WINDOW_H
#define INNCLIENT_BORDERLESS_WINDOW_H

#include <QMainWindow>

class BorderlessWindow : public QMainWindow {
Q_OBJECT
public:
    BorderlessWindow(QWidget *parent = nullptr);
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
    void moveEvent(QMoveEvent *event) override;
    virtual bool HitArea(const QPoint &gPos);
signals:
    void UpdateWindowState(bool);
};


#endif //INNCLIENT_BORDERLESS_WINDOW_H
