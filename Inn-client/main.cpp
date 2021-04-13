#include "Innclient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Innclient w;
    w.show();
    return a.exec();
}
