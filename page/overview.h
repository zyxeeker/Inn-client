//
// Created by zyx on 2021/8/2.
//

#ifndef INNCLIENT_OVERVIEW_H
#define INNCLIENT_OVERVIEW_H

#include <QWidget>
#include <QLabel>

class Overview : public QWidget {
Q_OBJECT

public:
    explicit Overview(QWidget *parent = nullptr);

//    ~Overview() override;

private:
    void InitUI();

private:
    void RegBanner();

    void SetBannerPosition();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    QLabel *m_banner;
    QLabel *m_icon;
    QLabel *m_title;
    QWidget *widget;

};


#endif //INNCLIENT_OVERVIEW_H
