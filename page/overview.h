//
// Created by zyx on 2021/8/2.
//

#ifndef INNCLIENT_OVERVIEW_H
#define INNCLIENT_OVERVIEW_H

#include <QWidget>
#include <QLabel>
#include "./component/popup.h"
#include "./component/button.h"

class Overview : public QWidget {
Q_OBJECT

public:
    explicit Overview(std::string u, QWidget *parent = nullptr);
private:
    void InitUI();
private:
    void RegBanner();
    void SetBannerPosition();
protected:
    void resizeEvent(QResizeEvent *e);
private:
    std::string m_user;
    QLabel *m_banner;
    QLabel *m_icon;
    QLabel *m_title;
};


#endif //INNCLIENT_OVERVIEW_H
