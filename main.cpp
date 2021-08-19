#include "mainwindow.h"
#include <QApplication>
#include "component/auth.h"
#include "page/overview.h"
//#include "component/profile.h"
#include "component/button.h"
#include "component/popup.h"
#include "component/list.h"
#include "component/text_editor.h"
#include "page/chat_room.h"
#include "component/chat_content.h"

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
    WBPopup p(0,0);
    p.show();
#endif
#if 0
    WBListView lv;
    lv.show();
#endif
#if 0
    TextEditor t;
    t.show();
#endif
#if 1
    SingleChatRoom s;
    s.show();
#endif
#if 0
    //    ChatContent r;
    //    r.show();
    //    IconChatContent i;
    //    i.show();
    ChatContentTimeStamp t(0);
    t.show();
#endif
    return a.exec();
}
