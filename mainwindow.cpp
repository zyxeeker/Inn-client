#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
//    setWindowFlag(Qt::WindowMinimizeButtonHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ImportContentBackground();
#if 0
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
#endif

#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(winId());
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
#endif
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
                     QBrush(m_px->scaled(ui->content->size(),
                                         Qt::KeepAspectRatioByExpanding/*, Qt::FastTransformation*//*Qt::IgnoreAspectRatio*/,
                                         Qt::SmoothTransformation)));
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

#if 0
void MainWindow::mousePressEvent(QMouseEvent *e) {
    m_titleXMax = this->width();
    if (e->button() == Qt::LeftButton) {
        m_mousePosition = e->pos();
//        if (m_mousePosition.x() < m_titleXMin) return;
//        if (m_mousePosition.x() > m_titleXMax) return;
//        if (m_mousePosition.y() < m_titleYMin) return;
//        if (m_mousePosition.y() > m_titleYMax) return;
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
//    if (!m_windowMax) {
//        showMaximized();
//        m_windowMax = true;
//    } else {
//        showNormal();
//        m_windowMax = false;
//    }
}
#endif

void MainWindow::on_hideBtn_clicked() {
    showMaximized();
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result) {
#ifdef Q_OS_WIN
    MSG *msg = reinterpret_cast<MSG *>(message);
    switch (msg->message) {
        case WM_NCCALCSIZE: {
            *result = WVR_REDRAW;
            return true;
        }
        case WM_NCHITTEST: {
            *result = 0;
            const LONG border_width = 4;
            RECT winrect;
            GetWindowRect(HWND(winId()), &winrect);

            long x = GET_X_LPARAM(msg->lParam);
            long y = GET_Y_LPARAM(msg->lParam);

            bool resizeWidth = minimumWidth() != maximumWidth();
            bool resizeHeight = minimumHeight() != maximumHeight();

            if (resizeWidth) {
                //left border
                if (x >= winrect.left && x < winrect.left + border_width) *result = HTLEFT;
                //right border
                if (x < winrect.right && x >= winrect.right - border_width) *result = HTRIGHT;
            }
            if (resizeHeight) {
                //bottom border
                if (y < winrect.bottom && y >= winrect.bottom - border_width) *result = HTBOTTOM;
                //top border
                if (y >= winrect.top && y < winrect.top + border_width) *result = HTTOP;
            }
            if (resizeWidth && resizeHeight) {
                //bottom left corner
                if (x >= winrect.left && x < winrect.left + border_width && y < winrect.bottom &&
                    y >= winrect.bottom - border_width)
                    *result = HTBOTTOMLEFT;
                //bottom right corner
                if (x < winrect.right && x >= winrect.right - border_width && y < winrect.bottom &&
                    y >= winrect.bottom - border_width)
                    *result = HTBOTTOMRIGHT;
                //top left corner
                if (x >= winrect.left && x < winrect.left + border_width && y >= winrect.top &&
                    y < winrect.top + border_width)
                    *result = HTTOPLEFT;
                //top right corner
                if (x < winrect.right && x >= winrect.right - border_width && y >= winrect.top &&
                    y < winrect.top + border_width)
                    *result = HTTOPRIGHT;
            }
            if (0 != *result) return true;

            //*result still equals 0, that means the cursor locate OUTSIDE the frame area
            //but it may locate in titlebar area
            if (!ui->title) return false;

            //support highdpi
            double dpr = this->devicePixelRatioF();
            QPoint pos = ui->title->mapFromGlobal(QPoint(x / dpr, y / dpr));

            if (!ui->title->rect().contains(pos)) return false;
            QWidget *child = ui->title->childAt(pos);
            if (!child) {
                *result = HTCAPTION;
                return true;
            } else {
                if (child == ui->icon || child == ui->text) {
                    *result = HTCAPTION;
                    return true;
                }
            }
            return false;
        }
        case WM_GETMINMAXINFO: {
            if (::IsZoomed(msg->hwnd)) {
                RECT frame = {0, 0, 0, 0};
                AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);

                //record frame area data
                double dpr = this->devicePixelRatioF();
                this->setContentsMargins(abs(frame.left) / dpr + 0.5, abs(frame.bottom) / dpr + 0.5,
                                         abs(frame.right) / dpr + 0.5, abs(frame.bottom) / dpr + 0.5);
            } else {
                this->setContentsMargins(0, 0, 0, 0);
            }
            return false;
        }
        default:
            return QMainWindow::nativeEvent(eventType, message, result);
    }
#endif
}