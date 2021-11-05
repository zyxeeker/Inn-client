//
// Created by zyx on 2021/8/30.
//

#include <QPainter>
#include <QPainterPath>
#include <windows.h>
#include "control_btn.h"
#include <QDebug>

#define PIX_SIZE 34

#define ONLINE_R 60
#define ONLINE_G 220
#define ONLINE_B 113
#define ONLINE_G_DST 179
#define BUSY_R 255
#define BUSY_G 185
#define BUSY_B 0
#define BUSY_G_DST 140
#define AWAY_R 255
#define AWAY_G 99
#define AWAY_B 71
#define AWAY_G_DST 40

CtrlBtn::CtrlBtn(QWidget *parent) : AbstractedBtn(parent) {
    m_menu = new QMenu;
    m_aWidget = new QWidgetAction(m_menu);
    m_menuContainer = new QWidget(this);
    m_menuLayout = new QHBoxLayout;
    m_menuBody = &CtrlMenu::Instance();

    m_enterAnimation = new QPropertyAnimation(this, "value");
    m_leaveAnimation = new QPropertyAnimation(this, "value");

    m_enterAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_enterAnimation->setDuration(180);

    m_leaveAnimation->setEasingCurve(QEasingCurve::OutQuad);
    m_leaveAnimation->setDuration(180);

    m_pix.load("D:\\program\\Inn-client\\test.png");
    m_pix = GeneratePixmap(m_pix);

    m_shadowEffect->deleteLater();
    m_upAnimation->deleteLater();
    m_downAnimation->deleteLater();

    this->setMaximumSize(50, 50);
    this->setMinimumSize(50, 50);

    onStatueChanged(ONLINE);

    InitMenu();
    connect(this, &QPushButton::clicked, [=]() {
        m_menu->exec(QPoint(QPoint(this->mapToGlobal(QPoint(0, 0)).x() + 16,
                                   this->mapToGlobal(QPoint(0, 0)).y() - 132)));
    });
    connect(m_menuBody, &CtrlMenu::StatueChanged, this, &CtrlBtn::onStatueChanged);
}

QPixmap CtrlBtn::ScaledIcon(const QPixmap &src) {
    return src.scaled(PIX_SIZE, PIX_SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void CtrlBtn::InitMenu() {
    m_menuLayout->setContentsMargins(0, 0, 0, 0);
    m_menuLayout->addWidget(m_menuBody);
    m_menuContainer->setLayout(m_menuLayout);
    m_menuContainer->setMinimumHeight(208);
    m_menuContainer->setMinimumWidth(200);

    m_aWidget->setDefaultWidget(m_menuContainer);
    m_menu->setWindowFlags(Qt::FramelessWindowHint);
    m_menu->setWindowFlag(Qt::Popup, true);
    m_menu->setAttribute(Qt::WA_TranslucentBackground);
    m_menu->setStyleSheet("background:transparent;");
    m_menu->addAction(m_aWidget);
#ifdef Q_OS_WIN
    HWND hwnd = (HWND) m_menu->winId();
    DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
    class_style &= ~CS_DROPSHADOW;
    ::SetClassLong(hwnd, GCL_STYLE, class_style);
#endif
}

QPixmap CtrlBtn::GeneratePixmap(const QPixmap &src) {
    if (src.isNull())
        return src;
    // 压缩图片
    QPixmap pixmap = ScaledIcon(src);

    QPixmap dest(PIX_SIZE, PIX_SIZE);
    dest.fill(Qt::transparent);
    QPainter painter(&dest);
    // 抗锯齿 + 平滑边缘处理
    painter.setRenderHints(QPainter::Antialiasing, true);
    painter.setRenderHints(QPainter::SmoothPixmapTransform, true);
    // 裁剪为圆角
    QPainterPath path;
    path.addEllipse(0, 0, PIX_SIZE, PIX_SIZE);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, PIX_SIZE, PIX_SIZE, pixmap);

    return dest;
}

void CtrlBtn::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPainterPath path;
    QRectF rect(5, 3, 40, 40);
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 背景色
    QColor bkStyle(m_r, m_value, m_b);
    painter.setBrush(QBrush(bkStyle));
    // 圆
    path.arcTo(rect, 0, 360);
    painter.setPen(Qt::NoPen);

    painter.drawPath(path);
    painter.drawPixmap(8, 6, PIX_SIZE, PIX_SIZE, m_pix);
}

void CtrlBtn::enterEvent(QEvent *event) {
    m_isHover = true;
    m_enterAnimation->setStartValue(m_value);
    m_enterAnimation->start();
}

void CtrlBtn::leaveEvent(QEvent *event) {
    m_isHover = false;
    m_leaveAnimation->setStartValue(m_value);
    m_leaveAnimation->start();
}

void CtrlBtn::SetRGB(int r, int gSrc, int b, int gDst) {
    m_leaveAnimation->setEndValue(gDst);
    m_enterAnimation->setEndValue(gSrc);
    m_r = r;
    m_value = gSrc;
    m_b = b;
}

void CtrlBtn::onStatueChanged(USER_ST st) {
    switch (st) {
        case ONLINE:
            SetRGB(ONLINE_R, ONLINE_G, ONLINE_B, ONLINE_G_DST);
            break;
        case BUSY:
            SetRGB(BUSY_R, BUSY_G, BUSY_B, BUSY_G_DST);
            break;
        case AWAY:
            SetRGB(AWAY_R, AWAY_G, AWAY_B, AWAY_G_DST);
            break;
    }
    m_menu->close();
}

int CtrlBtn::value() const {
    return m_value;
}

void CtrlBtn::SetValue(int value) {
    m_value = value;
    update();
}

//void CtrlBtn::mousePressEvent(QMouseEvent *event) {
//
//}
//
//void CtrlBtn::mouseReleaseEvent(QMouseEvent *event) {
//
//}