//
// Created by zyx on 2021/10/13.
//

#ifndef INNCLIENT_NAVIGATION_H
#define INNCLIENT_NAVIGATION_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "component/button.h"
#include "model/define.h"

class Navigation : public QWidget {
Q_OBJECT
public:
    Navigation(QWidget *parent = nullptr);
private:
    void InitUi();
private:
    QVBoxLayout *m_layout;
    NavBtn *m_homeBtn;
    NavBtn *m_chatBtn;
    NavBtn *m_streamBtn;
    NavBtn *m_settingBtn;
    QPushButton *m_exitBtn;
    QSpacerItem *m_uSpacer;
    QSpacerItem *m_dSpacer;
signals:
    void SwitchNav(NAVIGATION);
};


#endif //INNCLIENT_NAVIGATION_H
