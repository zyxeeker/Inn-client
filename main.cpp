#include "mainwindow.h"
#include <QApplication>
#include "component/auth.h"
#include "page/overview.h"
#include "component/profile.h"
#include "component/button.h"
#include "component/popup.h"
#include "component/list.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
#if 0
    Auth aa;
    aa.show();
#endif
#if 0
    MainWindow w;
    w.show();
#endif
#if 0
    Overview o;
    o.show();
#endif
#if 0
    Profile p;
    p.show();
#endif
#if 0
    SWidget sw;
    sw.show();
#endif
#if 0
    OverviewBtn ob(":/component/resource/weibo.svg","WB");
    ob.show();
#endif
#if 0
    Popup p;
    p.show();
#endif
#if 1
    ListView lv;
    lv.show();
#endif

    return a.exec();
}
