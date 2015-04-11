/*
 * Ch5BitManipulation_UnitTests.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: Felix
 */


#include "Ch5BitManipulation.h"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;


TEST(Ch5BitManipulation, prob5_1) {
	unsigned int N = 1 << 10;
	unsigned int M = 21;
	int i = 2;
	int j = 6;
	Ch5BitManipulation::printBin(N);
	Ch5BitManipulation::printBin(M);
	unsigned int result = Ch5BitManipulation::prob5_1(N, M, i, j);
	Ch5BitManipulation::printBin(result);
	EXPECT_EQ(0x454, result);
}

TEST(Ch5BitManipulation, prob5_2) {
	// Prob 5.2
	cout << "1.625" << endl;
	Ch5BitManipulation::prob5_2("1.625");
	cout << "3.78125" << endl;
	Ch5BitManipulation::prob5_2("3.78125");
}

TEST(Ch5BitManipulation, prob5_3) {
	unsigned int num = 20;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_larger(num));

	cout << endl;

	num = 0xa0;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));
	cout << endl;
	num = 33;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));
}

TEST(Ch5BitManipulation, prob5_5) {
	cout << Ch5BitManipulation::prob5_5(31,14) << endl;
	cout << Ch5BitManipulation::prob5_5(14,31) << endl;
}

TEST(Ch5BitManipulation, prob5_6) {
	Ch5BitManipulation::prob5_6(523);
	Ch5BitManipulation::prob5_6(4653);
}
