//
// Created by zyx on 2021/7/30.
//

#ifndef INNCLIENT_AUTH_H
#define INNCLIENT_AUTH_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Auth; }
QT_END_NAMESPACE

class Auth : public QWidget {
Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);

    ~Auth() override;

protected:
    void mousePressEvent(QMouseEvent *m);

    void mouseMoveEvent(QMouseEvent *m);

    void mouseReleaseEvent(QMouseEvent *m);

private:
    Ui::Auth *ui;
    QString m_username;
    QString m_pwd;
    QPoint m_mousePosition;
    bool m_mousePress;

private slots:

    void on_loginBtn_clicked();

};

#endif //INNCLIENT_AUTH_H
