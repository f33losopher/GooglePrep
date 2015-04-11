/*
 * Ch8Recursion_UnitTests.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: Felix
 */
#include "Ch8Recursion.h"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;


TEST(Ch8Recursion, prob8_1) {
	EXPECT_EQ(3, Ch8Recursion::prob8_1(5));
	EXPECT_EQ(34, Ch8Recursion::prob8_1(10));
	EXPECT_EQ(514229, Ch8Recursion::prob8_1(30));
}

TEST(Ch8Recursion, prob8_2) {
	int gridDim = 10;
	// Make the NxN grid
	int** grid = new int*[gridDim];
	for (int i=0; i < gridDim; ++i) {
		grid[i] = new int[gridDim];
	}

	// Initialize grid to all 1's, meaning can walk on the square
	for (int r=0; r<gridDim; ++r) {
		for (int c=0; c<gridDim; ++c) {
			grid[r][c] = 1;
		}
	}

	cout << "Number of paths to (9,9): ";
	cout << Ch8Recursion::prob8_2(grid, gridDim, 9, 9, 0, 0) << endl;

	cout << endl;

}

TEST(Ch8Recursion, prob8_4) {
	string perm = "ABC";
	set<string> perms;
	Ch8Recursion::prob8_4(perm, 0, perms);
}

TEST(Ch8Recursion, prob8_5) {
	Ch8Recursion::prob8_5(3);
}


