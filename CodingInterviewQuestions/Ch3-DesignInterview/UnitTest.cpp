/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"
#include <iostream>
#include <string>

#include "Prob23-GradingClass.h"

using namespace std;

TEST(Prob23, GradingClass) {
	GradingClass* gcPtr = new GradingClass();

	gcPtr->readFile("Grades.txt");
	gcPtr->writeFile("AnalyzedGrades.txt");
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
