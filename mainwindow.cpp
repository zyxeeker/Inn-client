//
// Created by zyx on 2021/9/22.
//

#include "service/logger_service.h"

#include "mainwindow.h"

#define TITLE_STYLE_1 "QPushButton{border-radius:none;background-color:rgba(65, 65, 65, 120);}"\
                    "QPushButton:hover {background-color:rgba(65, 65, 65, 200);}"\
                    "QPushButton:pressed {background-color:rgb(65, 65, 65);}"
#define TITLE_STYLE_2 "QPushButton{border-radius:none;background-color:rgba(65, 65, 65, 120);}"\
                    "QPushButton:hover {background-color:rgba(205, 45, 75, 240);color:white;}"\
                    "QPushButton:pressed {background-color:rgb(205, 45, 75);}"
#define NAV_STYLE_1 "QPushButton{background-color:rgb(36, 36, 36);border-radius:5px;margin:5px;}" \
                    "QPushButton:hover {background-color:rgb(52, 52, 52);}QPushButton:pressed {background-color:rgb(52, 52, 52);}" \
                    "QPushButton:checked {background-color:rgb(52, 52, 52);}"
#define NAV_STYLE_2 "QPushButton{background-color:rgb(36, 36, 36);border-radius:5px;margin:5px;}"\
                    "QPushButton:hover {background-color:rgb(195, 44, 73);}"\
                    "QPushButton:pressed {background-color:rgb(205, 45, 75);}"

MainWindow::MainWindow(Inn::NetConnService *s) : m_netService(s) {
    m_centerWidget = new QWidget(this);
    m_main = new QVBoxLayout(m_centerWidget);
    m_title = new QWidget(m_centerWidget);
    m_titleLayout = new QHBoxLayout(m_title);
    m_content = new QWidget(m_centerWidget);
    m_contentLayout = new QHBoxLayout(m_content);
    m_navigation = new QWidget(m_content);
    m_navLayout = new QVBoxLayout(m_navigation);
    m_titleName = new QLabel(m_title);
    m_homeBtn = new QPushButton(m_navigation);
    m_singleChatBtn = new QPushButton(m_navigation);
    m_groupChatBtn = new QPushButton(m_navigation);
    m_streamBtn = new QPushButton(m_navigation);
    m_settingBtn = new QPushButton(m_navigation);
    m_exitBtn = new QPushButton(m_navigation);
    m_closeBtn = new QPushButton(m_title);
    m_minBtn = new QPushButton(m_title);
    m_maxBtn = new QPushButton(m_title);
    m_stackedContent = new QStackedWidget(m_content);
    m_titleSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_uNavSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_dNavSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Preferred);
    m_overview = new Overview(m_netService->GetUser(), m_stackedContent);
    InitUI();
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(this->winId());
    DWORD style = GetWindowLong(hwnd, GWL_STYLE);
    SetWindowLongPtr(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
#endif
}

void MainWindow::InitUI() {
    this->setMinimumSize(800, 600);
    this->setCentralWidget(m_centerWidget);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    m_centerWidget->setObjectName("content");
    m_centerWidget->setStyleSheet("#content{background-color:rgb(23, 23, 23);}");
    m_main->addWidget(m_title);
    m_main->addWidget(m_content);
    m_main->setContentsMargins(0, 0, 0, 0);
    m_main->setSpacing(0);
    InitTitle();
    InitContent();
    connect(m_minBtn, &QPushButton::clicked, this, [=] {
        this->showMinimized();
    });
    connect(m_maxBtn, &QPushButton::clicked, this, [=]() {
        m_maximized ? this->showNormal() : this->showMaximized();
    });
    connect(m_closeBtn, &QPushButton::clicked, this, [=]() {
        this->hide();
    });
    connect(m_exitBtn, &QPushButton::clicked, this, [=]() {
        emit UserLogout();
    });
}

void MainWindow::InitTitle() {
    m_title->setMinimumSize(800, 25);
    m_title->setMaximumHeight(25);
    m_title->setStyleSheet("background:black;");
    m_titleLayout->setContentsMargins(5, 0, 0, 0);
    m_titleLayout->addWidget(m_titleName);
    m_titleLayout->addItem(m_titleSpacer);
    m_titleLayout->addWidget(m_minBtn);
    m_titleLayout->addWidget(m_maxBtn);
    m_titleLayout->addWidget(m_closeBtn);
    m_titleLayout->setSpacing(0);
    m_titleName->setText("Inn");
    m_titleName->setStyleSheet("font-family:'Microsoft YaHei UI';font-size:13px;color:lightgray;");
    InitBtn(m_minBtn, 25, 15, TITLE_STYLE_1, ":/common/resource/hide.svg");
    InitBtn(m_maxBtn, 25, 15, TITLE_STYLE_1, ":/common/resource/min.svg", ":/common/resource/max.svg");
    InitBtn(m_closeBtn, 25, 15, TITLE_STYLE_2, ":/common/resource/close.svg");
    m_maxBtn->setCheckable(true);
}

void MainWindow::InitContent() {
    m_contentLayout->setSpacing(0);
    m_contentLayout->setContentsMargins(0, 0, 0, 0);
    m_contentLayout->addWidget(m_navigation);
    m_contentLayout->addWidget(m_stackedContent);
    m_navLayout->addWidget(m_homeBtn);
    m_navLayout->addWidget(m_singleChatBtn);
    m_navLayout->addWidget(m_groupChatBtn);
    m_navLayout->addWidget(m_streamBtn);
    m_navLayout->addWidget(m_settingBtn);
    m_navLayout->addItem(m_uNavSpacer);
    m_navLayout->addWidget(m_exitBtn);
    m_navLayout->addItem(m_dNavSpacer);
    m_navLayout->setSpacing(0);
    m_navLayout->setContentsMargins(0, 0, 0, 0);
    InitBtn(m_homeBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/home.svg", ":/nav/resource/home_checked.svg");
    InitBtn(m_singleChatBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/people.svg", ":/nav/resource/people_checked.svg");
    InitBtn(m_groupChatBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/group.svg", ":/nav/resource/group_checked.svg");
    InitBtn(m_streamBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/live.svg", ":/nav/resource/live_checked.svg");
    InitBtn(m_settingBtn, 50, 20, NAV_STYLE_1, ":/nav/resource/setting.svg", ":/nav/resource/setting_checked.svg");
    InitBtn(m_exitBtn, 50, 20, NAV_STYLE_2, ":/auth/resource/exit.png");
    m_homeBtn->setChecked(true);
    m_stackedContent->setObjectName("stackedContent");
    m_stackedContent->setStyleSheet(
            "#stackedContent{margin-top:5px;border-top-left-radius:5px;background-color: rgb(0, 17, 34);}");
    m_stackedContent->addWidget(m_overview);
}

void MainWindow::InitBtn(QPushButton *b, int s1, int s2, QString s, QString url, QString ourl) {
    QIcon pIcon;
    pIcon.addPixmap(QPixmap(url), QIcon::Normal, QIcon::Off);
    if (!ourl.isEmpty()) {
        pIcon.addPixmap(QPixmap(ourl), QIcon::Active, QIcon::On);
        b->setCheckable(true);
        b->setAutoExclusive(true);
    }
    b->setMinimumSize(s1, s1);
    b->setMaximumSize(s1, s1);
    b->setIcon(pIcon);
    b->setIconSize(QSize(s2, s2));
    b->setStyleSheet(s);
}

bool MainWindow::nativeEvent(const QByteArray &et, void *m, long *r) {
#ifdef Q_OS_WIN
    MSG *msg = reinterpret_cast<MSG *>(m);
    switch (msg->message) {
        case WM_NCCALCSIZE: {
            *r = WVR_REDRAW;
            return true;
        }
        case WM_NCHITTEST: {
            *r = 0;
            const LONG border_width = 4;
            GetWindowRect(HWND(this->winId()), &m_winRect);
            long x = GET_X_LPARAM(msg->lParam);
            long y = GET_Y_LPARAM(msg->lParam);
            bool resizeWidth = minimumWidth() != maximumWidth();
            bool resizeHeight = minimumHeight() != maximumHeight();
            if (resizeWidth) {
                if (x >= m_winRect.left && x < m_winRect.left + border_width) *r = HTLEFT;
                if (x < m_winRect.right && x >= m_winRect.right - border_width) *r = HTRIGHT;
            }
            if (resizeHeight) {
                if (y < m_winRect.bottom && y >= m_winRect.bottom - border_width) *r = HTBOTTOM;
                if (y >= m_winRect.top && y < m_winRect.top + border_width) *r = HTTOP;
            }
            if (resizeWidth && resizeHeight) {
                if (x >= m_winRect.left && x < m_winRect.left + border_width && y < m_winRect.bottom &&
                    y >= m_winRect.bottom - border_width)
                    *r = HTBOTTOMLEFT;
                if (x < m_winRect.right && x >= m_winRect.right - border_width && y < m_winRect.bottom &&
                    y >= m_winRect.bottom - border_width)
                    *r = HTBOTTOMRIGHT;
                if (x >= m_winRect.left && x < m_winRect.left + border_width && y >= m_winRect.top &&
                    y < m_winRect.top + border_width)
                    *r = HTTOPLEFT;
                if (x < m_winRect.right && x >= m_winRect.right - border_width && y >= m_winRect.top &&
                    y < m_winRect.top + border_width)
                    *r = HTTOPRIGHT;
            }
            if (0 != *r) return true;
            if (!m_title) return false;
            m_pos = m_title->mapFromGlobal(QPoint(x, y));
            if (!m_title->rect().contains(m_pos)) return false;
            if (!m_title->childAt(m_pos)) {
                *r = HTCAPTION;
                return true;
            } else {
                if (m_title->childAt(m_pos) == m_titleName) {
                    *r = HTCAPTION;
                    return true;
                }
            }
            return false;
        }
        case WM_GETMINMAXINFO: {
            if (::IsZoomed(msg->hwnd)) {
                m_frame = {0, 0, 0, 0};
                AdjustWindowRectEx(&m_frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
                this->setContentsMargins(abs(m_frame.left), abs(m_frame.bottom),
                                         abs(m_frame.right), abs(m_frame.bottom));
                SwitchSizeBtn(MAX);
            } else {
                this->setContentsMargins(0, 0, 0, 0);
                SwitchSizeBtn(MIN);
            }
            return false;
        }
    }
#endif
    return false;
}

void MainWindow::SwitchSizeBtn(SIZE_STATE s) {
    switch (s) {
        case MIN: {
            m_maximized = false;
            m_maxBtn->setChecked(true);
            break;
        }
        case MAX: {
            m_maximized = true;
            m_maxBtn->setChecked(false);
            break;
        }
    }
}