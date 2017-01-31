/*
 * UnitTest.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: Felix
 */

#include "gtest/gtest.h"
#include "Prob1-TowersOfHanoi.h"
#include "Prob2-ArraySorted.h"
#include "Prob3-Anagram.h"
#include "Prob4-StrCombos.h"
#include "Prob5-ComboBits.h"
#include "Prob7-WildCard.h"
#include "Prob8-LongChain.h"

#include <iostream>
#include <string>
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

TEST(Prob3, Anagram) {
	Anagram* aPtr = new Anagram();
	string s = "abc";

	aPtr->anagrams(s, 0);
}

TEST(Prob4, StrCombos) {
	char original[5] = {'a', 'b', 'c'};
	StringCombos* strCmbPtr = new StringCombos(original);
	strCmbPtr->Combinations(0,0);
}

TEST(Prob5, ComboBits) {
	int numBits = 5;
	ComboBits* cbPtr = new ComboBits(numBits);
	cbPtr->Binary(numBits);
	cout << "=====" << endl;
	cbPtr->Binary2(numBits);
}

TEST(Prob7, WildCard) {
	WildCard* wcPtr = new WildCard();
	string s = "10?";
	wcPtr->replaceQMarks(s);

	cout << "=====" << endl;
	s = "1??";
	wcPtr->replaceQMarks(s);

	cout << "=====" << endl;
	s = "1???";
	wcPtr->replaceQMarks(s);

	cout << "=====" << endl;
	s = "111";
	wcPtr->replaceQMarks(s);
}

TEST(Prob8, LongChain) {
	LongChain* lcPtr = new LongChain();
	uint maxRange = 5;
	lcPtr->setXY(maxRange, maxRange);
	int grid[][maxRange] = {{1,1,0,0,0},
			                {0,1,1,0,0},
			                {0,0,1,0,1},
			                {1,0,0,0,1},
			                {0,1,0,1,1}};

	cout << lcPtr->longChain(&grid[0][0], 0, 0) << endl;
//	EXPECT_EQ(5, lcPtr->longChain(grid, 0, 0));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
