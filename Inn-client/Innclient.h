#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Innclient.h"

class Innclient : public QMainWindow
{
    Q_OBJECT

public:
    Innclient(QWidget *parent = Q_NULLPTR);

private:
    Ui::InnclientClass ui;
};
