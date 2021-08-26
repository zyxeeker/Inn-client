#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
//    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    ImportContentBackground();
#if 1
    Overview *overview = new Overview;
    GroupChatRoom *groupChatRoom = new GroupChatRoom;
    SingleChatRoom *singleChatRoom = new SingleChatRoom;
    ui->stackedContent->addWidget(overview);
    ui->stackedContent->addWidget(singleChatRoom);
    ui->stackedContent->addWidget(groupChatRoom);
    qDebug() << ui->stackedContent->currentWidget();
    ui->stackedContent->setCurrentIndex(0);
//    ui->stackedContent->setCurrentWidget(&oo);
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
#if 0
    ui->content->setAutoFillBackground(true);
    QPalette palette = ui->content->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(m_px->scaled(ui->content->size(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    ui->content->setPalette(palette);
#endif
}

void MainWindow::SetMax2Min() {
    m_maximized = true;
    ui->maximizedBtn->setIcon(QIcon(":/common/resource/min.svg"));
}

void MainWindow::SetMin2Max() {
    m_maximized = false;
    ui->maximizedBtn->setIcon(QIcon(":/common/resource/max.svg"));
}

void MainWindow::resizeEvent(QResizeEvent *e) {
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
//            double dpr = this->devicePixelRatioF();
            QPoint pos = ui->title->mapFromGlobal(QPoint(x, y));

            if (!ui->title->rect().contains(pos)) return false;
            QWidget *child = ui->title->childAt(pos);
            if (!child) {
                *result = HTCAPTION;
                return true;
            } else {
                if (child == ui->text) {
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
//                double dpr = this->devicePixelRatioF();
                this->setContentsMargins(abs(frame.left), abs(frame.bottom),
                                         abs(frame.right), abs(frame.bottom));
                SetMax2Min();

            } else {
                this->setContentsMargins(0, 0, 0, 0);
                SetMin2Max();
            }
            return false;
        }
        default:
            return QMainWindow::nativeEvent(eventType, message, result);
    }
#endif
}

void MainWindow::on_minimizedBtn_clicked() {
    this->showMinimized();
}

void MainWindow::on_exitBtn_clicked() {
    this->close();
}

void MainWindow::on_maximizedBtn_clicked() {
    if (m_maximized) {
        this->showNormal();
        SetMin2Max();
    } else {
        this->showMaximized();
        SetMax2Min();
    }
}

void MainWindow::on_homeBtn_clicked() {
    ui->stackedContent->setCurrentIndex(0);
}

void MainWindow::on_peopleBtn_clicked() {
    ui->stackedContent->setCurrentIndex(1);
}

void MainWindow::on_groupBtn_clicked() {
    ui->stackedContent->setCurrentIndex(2);
}