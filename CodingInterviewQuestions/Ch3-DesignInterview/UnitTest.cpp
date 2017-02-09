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

	const vector<Student*> students = gcPtr->getStudents();

	EXPECT_EQ("Gates", students[0]->getName());
	EXPECT_EQ(47, students[0]->getMidterm());
	EXPECT_EQ(83, students[0]->getFinal());
	EXPECT_EQ("Jobs", students[1]->getName());
	EXPECT_EQ(36, students[1]->getMidterm());
	EXPECT_EQ(20, students[1]->getFinal());
	EXPECT_EQ("Zion", students[2]->getName());
	EXPECT_EQ(25, students[2]->getMidterm());
	EXPECT_EQ(88, students[2]->getFinal());
	EXPECT_EQ("Alice", students[3]->getName());
	EXPECT_EQ(44, students[3]->getMidterm());
	EXPECT_EQ(99, students[3]->getFinal());
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
