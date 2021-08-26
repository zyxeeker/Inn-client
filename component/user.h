//
// Created by zyx on 2021/8/25.
//

#ifndef INNCLIENT_USER_H
#define INNCLIENT_USER_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QResizeEvent>
#include "./model/utils.h"

class AbstractUser : public QWidget {
public:
    AbstractUser();

protected:
    void resizeEvent(QResizeEvent *e);

protected:
    QLabel *m_userName;
    QLabel *m_userIcon;
    QLabel *m_userDes;
    QLabel *m_userStatue;
};

class ListUser : public AbstractUser {
public:
    ListUser();

private:
    QHBoxLayout *m_content;
    QHBoxLayout *m_ds;
    QVBoxLayout *m_inside;
};


#endif //INNCLIENT_USER_H
