#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QtSvg/QSvgRenderer>
#include "./page/overview.h"

#ifdef Q_OS_WIN

#include <windows.h>

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lParam) ((int)(short)LOWORD(lParam))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lParam) ((int)(short)HIWORD(lParam))

#endif


#endif
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *e);

#if 0
    void mouseMoveEvent(QMouseEvent *e);

    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    void mouseDoubleClickEvent(QMouseEvent *e);
#endif

    //    eventType, message, result
    bool nativeEvent(const QByteArray &et, void *m, long *r);

private:
    Ui::MainWindow *ui;
    QPixmap *m_px;

    const int m_titleXMin = 0;
    const int m_titleYMin = 0;
    int m_titleXMax = 800;
    const int m_titleYMax = 20;

    bool m_mousePress;
    bool m_maximized = false;
    QPoint m_mousePosition;

private:
    void SetContentBackground();

    void ImportContentBackground();

    void SetMax2Min();

    void SetMin2Max();

private slots:

    void on_minimizedBtn_clicked();

    void on_maximizedBtn_clicked();

    void on_exitBtn_clicked();
//
//    void on_peopleBtn_clicked();

};
#endif // MAINWINDOW_H
