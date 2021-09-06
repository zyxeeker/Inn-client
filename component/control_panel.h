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
#include <QWidgetAction>

#ifdef Q_OS_WIN

#include <windows.h>

#endif

#include "context_menu.h"

class ControlPanel : public QWidget {
public:
    ControlPanel(QString name);

private:
    void InitMenu();

private:
    QLabel *m_userIcon;
    QLabel *m_userName;
    QLabel *m_userStatue;
    QPushButton *m_moreBtn;
    QHBoxLayout *m_layout;
    QVBoxLayout *m_userLayout;

    QMenu *m_menu;
    QWidgetAction *m_aWidget;
    QWidget *m_menuContainer;
    QHBoxLayout *m_menuLayout;
    ControlPanelContextMenu *m_menuBody;

};


#endif //INNCLIENT_CONTROL_PANEL_H
