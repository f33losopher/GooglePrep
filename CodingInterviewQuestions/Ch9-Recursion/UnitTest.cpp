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

void printGrid(vector <vector<int> > &grid, int idx, int idy) {
	for (int y = 0; y < idy; y++) {
		for (int x = 0; x < idx; x++) {
			cout << grid[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

TEST(Prob8, LongChain)  {
	LongChain* lcPtr = new LongChain();
	uint maxRange = 5;
	vector< vector<int> > grid ( maxRange, vector<int>(maxRange));

	// 1 1 0 0 0
	// 0 1 1 0 0
	// 0 0 1 0 1
	// 1 0 0 0 1
	// 0 1 0 1 1
	lcPtr->setXY(maxRange, maxRange);
	grid[0][0] = 1; grid[1][0] = 1; grid[2][0] = 0; grid[3][0] = 0; grid[4][0] = 0;
	grid[0][1] = 0; grid[1][1] = 1; grid[2][1] = 1; grid[3][1] = 0; grid[4][1] = 0;
	grid[0][2] = 0; grid[1][2] = 0; grid[2][2] = 1; grid[3][2] = 0; grid[4][2] = 1;
	grid[0][3] = 1; grid[1][3] = 0; grid[2][3] = 0; grid[3][3] = 0; grid[4][3] = 1;
	grid[0][4] = 0; grid[1][4] = 1; grid[2][4] = 0; grid[3][4] = 1; grid[4][4] = 1;
	printGrid(grid, maxRange, maxRange);
	EXPECT_EQ(5, lcPtr->longChain(grid));

	// 1 1 0 0 0
	// 0 1 1 0 0
	// 0 0 1 1 1
	// 1 0 0 0 1
	// 0 1 0 1 1
	lcPtr->setXY(maxRange, maxRange);
	grid[0][0] = 1; grid[1][0] = 1; grid[2][0] = 0; grid[3][0] = 0; grid[4][0] = 0;
	grid[0][1] = 0; grid[1][1] = 1; grid[2][1] = 1; grid[3][1] = 0; grid[4][1] = 0;
	grid[0][2] = 0; grid[1][2] = 0; grid[2][2] = 1; grid[3][2] = 1; grid[4][2] = 1;
	grid[0][3] = 1; grid[1][3] = 0; grid[2][3] = 0; grid[3][3] = 0; grid[4][3] = 1;
	grid[0][4] = 0; grid[1][4] = 1; grid[2][4] = 0; grid[3][4] = 1; grid[4][4] = 1;
	printGrid(grid, maxRange, maxRange);
	EXPECT_EQ(10, lcPtr->longChain(grid));

	// 0 0 1 0 0
	// 0 0 1 0 0
	// 1 1 1 1 1
	// 0 0 1 0 0
	// 0 0 1 0 0
	lcPtr->setXY(maxRange, maxRange);
	grid[0][0] = 0; grid[1][0] = 0; grid[2][0] = 1; grid[3][0] = 0; grid[4][0] = 0;
	grid[0][1] = 0; grid[1][1] = 0; grid[2][1] = 1; grid[3][1] = 0; grid[4][1] = 0;
	grid[0][2] = 1; grid[1][2] = 1; grid[2][2] = 1; grid[3][2] = 1; grid[4][2] = 1;
	grid[0][3] = 0; grid[1][3] = 0; grid[2][3] = 1; grid[3][3] = 0; grid[4][3] = 0;
	grid[0][4] = 0; grid[1][4] = 0; grid[2][4] = 1; grid[3][4] = 0; grid[4][4] = 0;
	printGrid(grid, maxRange, maxRange);
	EXPECT_EQ(7, lcPtr->longChain(grid));

	// 1 1 1 1 1 1
    // 1 0 0 0 0 1
	// 1 0 1 1 0 1
	// 1 0 1 1 0 1
	// 1 0 0 0 0 1
	// 1 1 1 1 1 1
	lcPtr->setXY(maxRange + 1, maxRange + 1);
	grid.resize(maxRange+1, vector<int>(maxRange+1, 0));
	grid[0][0] = 1; grid[1][0] = 1; grid[2][0] = 1; grid[3][0] = 1; grid[4][0] = 1; grid[5][0] = 1;
	grid[0][1] = 1; grid[1][1] = 0; grid[2][1] = 0; grid[3][1] = 0; grid[4][1] = 0; grid[5][1] = 1;
	grid[0][2] = 1; grid[1][2] = 0; grid[2][2] = 1; grid[3][2] = 1; grid[4][2] = 0; grid[5][2] = 1;
	grid[0][3] = 1; grid[1][3] = 0; grid[2][3] = 1; grid[3][3] = 1; grid[4][3] = 0; grid[5][3] = 1;
	grid[0][4] = 1; grid[1][4] = 0; grid[2][4] = 0; grid[3][4] = 0; grid[4][4] = 0; grid[5][4] = 1;
	grid[0][5] = 1; grid[1][5] = 1; grid[2][5] = 1; grid[3][5] = 1; grid[4][5] = 1; grid[5][5] = 1;
	printGrid(grid, maxRange+1, maxRange+1);
	EXPECT_EQ(20, lcPtr->longChain(grid));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
