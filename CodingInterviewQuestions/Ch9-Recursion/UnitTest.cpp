/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"
#include "Prob1-TowersOfHanoi.h"
#include "Prob2-ArraySorted.h"

#include <iostream>
using namespace std;

TEST(Prob1, TowersOfHanoi) {
	int numDisks = 5;
	TowersOfHanoi::solve(numDisks,0,1,2);
}

TEST(Prob2, isArraySortedYES) {
	int size = 5;
	int arr1[size] = {1,2,3,4,5};
	int arr2[size] = {0,2,3,4,9};
	int arr3[size] = {0,1,1,2,2};

	isArraySorted* isasPtr = new isArraySorted();
	EXPECT_EQ(1, isasPtr->isArrayInSortedOrder(arr1,size));
	EXPECT_EQ(1, isasPtr->isArrayInSortedOrder(arr2,size));
	EXPECT_EQ(1, isasPtr->isArrayInSortedOrder(arr3,size));
}

TEST(Prob2, isArraySortedNO) {
	int size = 5;
	int arr1[size] = {1,2,0,4,5};
	int arr2[size] = {1,2,3,4,3};

	isArraySorted* isasPtr = new isArraySorted();
	EXPECT_EQ(0, isasPtr->isArrayInSortedOrder(arr1,size));
	EXPECT_EQ(0, isasPtr->isArrayInSortedOrder(arr2,size));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
