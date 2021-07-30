//
// Created by zyx on 2021/7/30.
//

#ifndef INNCLIENT_AUTH_H
#define INNCLIENT_AUTH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Auth; }
QT_END_NAMESPACE

class Auth : public QWidget {
Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);

    ~Auth() override;

private:
    Ui::Auth *ui;
};

#endif //INNCLIENT_AUTH_H
