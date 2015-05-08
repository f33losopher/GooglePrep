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

void printGrid(int** grid, int N) {
	for(int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			cout << grid[r][c] << " ";
		}
		cout << endl;
	}
}

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


TEST(Ch8Recursion, prob8_6) {
	int N = 5;
	int** grid = new int*[N];
	for(int i=0; i < N; ++i) {
		grid[i] = new int[N];
	}

	// Initialize grid to look like
	// 2 2 2 2 2
	// 2 2 1 1 1
	// 2 1 3 3 1
	// 1 3 3 1 1
	// 2 1 1 1 2

	// First Row
	for(int c=0; c < N; ++c)
		grid[0][c] = 2;

	// Second Row
	grid[1][0] = 2;
	grid[1][1] = 2;
	grid[1][2] = 1;
	grid[1][3] = 1;
	grid[1][4] = 1;

	// Third Row
	grid[2][0] = 2;
	grid[2][1] = 1;
	grid[2][2] = 3;
	grid[2][3] = 3;
	grid[2][4] = 1;

	// Fourth Row
	grid[3][0] = 1;
	grid[3][1] = 3;
	grid[3][2] = 3;
	grid[3][3] = 1;
	grid[3][4] = 1;

	// Fifth Row
	grid[4][0] = 2;
	grid[4][1] = 1;
	grid[4][2] = 1;
	grid[4][3] = 1;
	grid[4][4] = 2;

	cout << "Before\n";
	printGrid(grid, N);

	Ch8Recursion::prob8_6(grid, N, 3, 0, 3);

	cout << endl << "After\n";
	printGrid(grid, N);
}
