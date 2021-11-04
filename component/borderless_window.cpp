//
// Created by zyx on 2021/10/13.
//

#include <windows.h>
#include <WinUser.h>
#include <windowsx.h>
#include <dwmapi.h>
#include "borderless_window.h"

#define GET_X_LPARAM(lParam) ((int)(short)LOWORD(lParam))
#define GET_Y_LPARAM(lParam) ((int)(short)HIWORD(lParam))

BorderlessWindow::BorderlessWindow(QWidget *parent) : QMainWindow(parent) {
    HWND hwnd = (HWND) this->winId();
    DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    ::SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
}

bool BorderlessWindow::nativeEvent(const QByteArray &eventType, void *message, long *result) {
    MSG *msg = reinterpret_cast<MSG *>(message);
    switch (msg->message) {
        case WM_NCCALCSIZE: {
            *result = 0;
            if (msg->wParam) {
                NCCALCSIZE_PARAMS *pncsp = reinterpret_cast<NCCALCSIZE_PARAMS *>(msg->lParam);

                RECT aRect;  // 获取改变前窗口 RECT
                CopyRect(&aRect, &pncsp->rgrc[1]);

                RECT bRect;  // 获取改变后窗口 RECT
                CopyRect(&bRect, &pncsp->rgrc[0]);

                // 改变后客户区大小
                RECT bcRect;
                if (this->isMaximized()) {
                    bcRect.left = bRect.left;
                    bcRect.top = bRect.top;
                    bcRect.right = bRect.right;
                    bcRect.bottom = bRect.bottom;
                } else {
                    int offset = 8;
                    bcRect.left = bRect.left + offset;
                    bcRect.top = bRect.top;
                    bcRect.right = bRect.right - offset;
                    bcRect.bottom = bRect.bottom - offset;
                }

                CopyRect(&pncsp->rgrc[0], &bcRect); // 设置改变后客户区大小
                CopyRect(&pncsp->rgrc[1], &bRect);  // 设置改变后窗口大小
                CopyRect(&pncsp->rgrc[2], &aRect);  // 设置改变后源矩形大小

                *result = WVR_REDRAW;
            }
        }
            return true;
        case WM_NCHITTEST: {
            const int offset = 4;
            RECT clientRect;
            GetWindowRect(HWND(this->winId()), &clientRect);
            long x = GET_X_LPARAM(msg->lParam);
            long y = GET_Y_LPARAM(msg->lParam);

            // 左上
            if (x >= clientRect.left && x < clientRect.left + offset
                && y >= clientRect.top && y < clientRect.top + offset) {
                *result = HTTOPLEFT;
                return true;
            }
            //上
            if (x >= clientRect.left + offset && x <= clientRect.right - offset
                && y >= clientRect.top && y < clientRect.top + offset) {
                *result = HTTOP;
                return true;
            }
            //右上
            if (x > clientRect.right - offset && x <= clientRect.right
                && y >= clientRect.top && y < clientRect.top + offset) {
                *result = HTTOPRIGHT;
                return true;
            }

            if (HitArea(QPoint(x, y))) {
                *result = HTCAPTION;
                return true;
            }
            // 其它位置默认处理
            return false;
        }
        case WM_NCRBUTTONDOWN: {
            auto xPos = GET_X_LPARAM(msg->lParam);
            auto yPos = GET_Y_LPARAM(msg->lParam);
            HMENU sysMenu = ::GetSystemMenu((HWND) winId(), FALSE);
            ::TrackPopupMenu(sysMenu, 0, xPos, yPos, NULL, (HWND) winId(), NULL);
        }
            break;
        case WM_GETMINMAXINFO: {
            if (::IsZoomed(msg->hwnd)) {
                RECT frame = {0, 0, 0, 0};
                AdjustWindowRectEx(&frame, WS_OVERLAPPEDWINDOW, FALSE, 0);
                this->setContentsMargins(abs(frame.left), abs(frame.bottom),
                                         abs(frame.right), abs(frame.bottom));
                emit UpdateWindowState(true);
            } else {
                this->setContentsMargins(0, 0, 0, 0);
                emit UpdateWindowState(false);
            }
            return false;
        }
        default:
            break;
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void BorderlessWindow::moveEvent(QMoveEvent *event) {
    QMainWindow::moveEvent(event);
}

bool BorderlessWindow::HitArea(const QPoint &gPos) {
    Q_UNUSED(gPos);
    return false;
}