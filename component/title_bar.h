//
// Created by zyx on 2021/10/13.
//

#ifndef INNCLIENT_TITLE_BAR_H
#define INNCLIENT_TITLE_BAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "model/define.h"

class AbstractTitleBar : public QWidget {
Q_OBJECT
public:
    AbstractTitleBar(QWidget *parent = nullptr, bool isAuth = false);
    void InitUi();
    bool HitArea(const QPoint &gPos);
private:
    QRectF BtnRect();
private:
    QHBoxLayout *m_layout;
    QLabel *m_name;
    QPushButton *m_closeBtn;
    QPushButton *m_minBtn;
    QPushButton *m_maximizedBtn;
    QSpacerItem *m_titleSpacer;
    QPoint m_pos;
    bool m_maximized = false;
    bool m_isAuth;
public slots:
    void SetMaximizedState(bool);
signals:
    void SwitchWindow(WINDOW_STATE);
};


#endif //INNCLIENT_TITLE_BAR_H
