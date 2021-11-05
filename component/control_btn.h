//
// Created by zyx on 2021/8/30.
//

#ifndef INNCLIENT_CONTROL_BTN_H
#define INNCLIENT_CONTROL_BTN_H

#include <QPixmap>
#include <QWidgetAction>
#include "component/button.h"
#include "component/context_menu.h"
#include "model/define.h"

class CtrlBtn : public AbstractedBtn {
Q_OBJECT
    Q_PROPERTY(int value READ value WRITE SetValue);
public:
    CtrlBtn(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
//    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    QPixmap ScaledIcon(const QPixmap &src);
    QPixmap GeneratePixmap(const QPixmap &src);
    int value() const;
    void SetValue(int Value);
    void SetRGB(int r, int gSrc, int b, int gDst);
    void InitMenu();
private:
    QPixmap m_pix;
    int m_value;
    int m_r;
    int m_b;
    QMenu *m_menu;
    QWidgetAction *m_aWidget;
    QWidget *m_menuContainer;
    QHBoxLayout *m_menuLayout;
    CtrlMenu *m_menuBody;
private slots:
    void onStatueChanged(USER_ST st);
};

#endif //INNCLIENT_CONTROL_BTN_H
