#include <QApplication>
#include <iostream>

#if _DEBUG

#include "test.h"

#endif

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
#if _DEBUG
    ::testing::InitGoogleTest();
    RUN_ALL_TESTS();
#endif
    return a.exec();
}
