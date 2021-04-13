#include "Innclient.h"
#include "auth.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auth e;
    //Innclient w;
    e.show();
    //w.show();
    return a.exec();
}
