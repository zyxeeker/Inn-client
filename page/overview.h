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
    explicit Overview(QWidget *parent = nullptr);

//    ~Overview() override;

private:
    void InitUI();

private:
    void RegBanner();

    void SetPopup(/*int px, int py*/);

    void SetBtns();

    void SetBannerPosition();

protected:
    void resizeEvent(QResizeEvent *e);

private:
    WBPopup *m_wbPopup;
    OverviewBtn *m_wbBtn;

    QWidget *widget;
    QWidget *m_popupContainer;
    QWidget *m_btn;

    QLabel *m_banner;
    QLabel *m_icon;
    QLabel *m_title;

    QHBoxLayout *m_popup;

private slots:

    void PopupTrans();

    void PopupShow();

    void PopupClose();

signals:

    void PopupPos(QRect);
};


#endif //INNCLIENT_OVERVIEW_H
