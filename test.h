//
// Created by zyx on 2021/8/26.
//

#include <gtest/gtest.h>
#include "component/user.h"
#include <QApplication>
#include <iostream>

ListUser *lu;

TEST(UI, DISPLAY) {
    lu = new ListUser;
    lu->show();
}

