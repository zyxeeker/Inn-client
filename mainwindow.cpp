#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ImportContentBackground();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ImportContentBackground() {
    QSvgRenderer r(QString(":/common/resource/content_bk.svg"));
    m_px = new QPixmap(ui->content->size());
    QPainter Painter;
    m_px->fill(Qt::transparent);
    Painter.begin(m_px);
    r.render(&Painter);
    Painter.end();
}

void MainWindow::SetContentBackground() {
    ui->content->setAutoFillBackground(true);
    QPalette palette = ui->content->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(m_px->scaled(ui->content->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    ui->content->setPalette(palette);
}

void MainWindow::resizeEvent(QResizeEvent *e) {
#if 0
    QSvgRenderer r(QString(":/common/resource/bk_test.svg"));
    QPixmap px(ui->content->size());
    QPainter Painter;

    px.fill(Qt::transparent);
    Painter.begin(&px);
    r.render(&Painter);
    Painter.end();

    ui->content->setAutoFillBackground(true);
    QPalette palette = ui->content->palette();
    palette.setBrush(QPalette::Window,QBrush(m_px->scaled(ui->content->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    ui->content->setPalette(palette);
#endif
    SetContentBackground();
}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    m_titleXMax = ui->title->width();
    if (e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
        if (m_mousePosition.x() <= m_titleXMin) return;
        if (m_mousePosition.x() >= m_titleXMax) return;
        if (m_mousePosition.y() <= m_titleYMin) return;
        if (m_mousePosition.y() >= m_titleYMax) return;
        m_mousePress = true;
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    if (m_mousePress) {
        QPoint position = e->globalPos();
        move(position - m_mousePosition);
        if (m_windowMax) m_windowMax = false;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    m_mousePress = false;
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e) {
    m_mousePosition = e->pos();
    if (m_mousePosition.x() <= m_titleXMin) return;
    if (m_mousePosition.x() >= m_titleXMax) return;
    if (m_mousePosition.y() <= m_titleYMin) return;
    if (m_mousePosition.y() >= m_titleYMax) return;
    if (!m_windowMax) {
        showMaximized();
        m_windowMax = true;
    } else {
        showNormal();
        m_windowMax = false;
    }
}

void MainWindow::on_hideBtn_clicked() {
    showMaximized();
}