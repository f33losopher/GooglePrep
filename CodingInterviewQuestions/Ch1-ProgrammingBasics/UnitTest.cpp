/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"

#include <iostream>
using namespace std;

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
