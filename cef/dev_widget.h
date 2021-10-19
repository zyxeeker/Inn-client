//
// Created by zyx on 2021/10/18.
//

#ifndef INNCLIENT_DEV_WIDGET_H
#define INNCLIENT_DEV_WIDGET_H

#include <QMainWindow>
#include <QDockWidget>
#include <QVBoxLayout>
#include "cef/cef_widget.h"

class DevWidget : public QMainWindow {
Q_OBJECT
public:
    DevWidget(QWidget *parent = nullptr);
private:
    void InitUi();
private:
    QWidget *m_app;
    CefWidget *m_cef;
    QDockWidget *m_devTool;
    QVBoxLayout *m_layout;
    CefDevTools *m_tools;
    bool m_hasDevTools = false;
private slots:
    void OnDevTools();
};


#endif //INNCLIENT_DEV_WIDGET_H
