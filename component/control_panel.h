//
// Created by zyx on 2021/8/30.
//

#ifndef INNCLIENT_CONTROL_PANEL_H
#define INNCLIENT_CONTROL_PANEL_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ControlPanel : public QWidget {
public:
    ControlPanel(QString name);

private:
    QLabel *m_userIcon;
    QLabel *m_userName;
    QLabel *m_userStatue;
    QPushButton *m_moreBtn;
    QHBoxLayout *m_layout;
    QVBoxLayout *m_userLayout;
};


#endif //INNCLIENT_CONTROL_PANEL_H
