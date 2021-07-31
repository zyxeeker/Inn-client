#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QMouseEvent>
#include <QtSvg/QSvgRenderer>

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

    void mouseMoveEvent(QMouseEvent *e);

    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::MainWindow *ui;
    QPixmap *m_px;

    const int m_titleXMin = 0;
    const int m_titleYMin = 0;
    int m_titleXMax = 800;
    const int m_titleYMax = 30;

    bool m_mousePress;
    QPoint m_mousePosition;

private:
    void SetContentBackground();

    void ImportContentBackground();
};
#endif // MAINWINDOW_H
