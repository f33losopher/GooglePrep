/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"
#include "Prob1-TowersOfHanoi.h"

#include <iostream>
using namespace std;

TEST(Hanoi, one) {
	int numDisks = 5;
	TowersOfHanoi::solve(numDisks,0,1,2);
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
