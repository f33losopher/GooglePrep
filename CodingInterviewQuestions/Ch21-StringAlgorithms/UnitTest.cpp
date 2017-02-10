/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

#include "Prob1-WordCount.h"

using namespace std;

TEST(Prob1, WordCount) {
	string file = "Prob1-WordCount.txt";
	WordCount* ptr = new WordCount();

	ifstream ifs(file.c_str());
	ptr->process(ifs);
	EXPECT_EQ(6, ptr->getMax());
	ifs.close();

	file = "Prob2-WordCount.txt";
	ifs.open(file.c_str());
	ptr->process(ifs);
	EXPECT_EQ(5, ptr->getMax());
	ifs.close();

	file = "Prob3-WordCount.txt";
	ifs.open(file.c_str());
	ptr->process(ifs);
	EXPECT_EQ(8, ptr->getMax());
	ifs.close();
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
