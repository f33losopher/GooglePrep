/*
 * Ch19Moderate_UnitTests.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: Felix
 */

#include <iostream>

#include "gtest/gtest.h"

#include "Ch19Moderate.h"

typedef Moderate::ticTacToe ticTacToe;

using namespace std;

void clearTTTgrid(ticTacToe** grid) {
	for(int row=0; row < 3; ++row) {
		for(int col=0; col < 3; ++col) {
			grid[row][col] = Moderate::EMPTY;
		}
	}
}

void printTTTGrid(ticTacToe** grid) {
	for(int r=0; r<3; ++r) {
		for(int c=0; c<3; ++c) {
			if(grid[r][c] == Moderate::X)      { cout << "X "; }
			else if(grid[r][c] == Moderate::O) { cout << "O "; }
			else { cout << "  "; }
		}
		cout << endl;
	}
}

TEST(Ch19_Moderate, prob19_1) {
	int x = 5;
	int y = 33;

	Moderate::prob19_1(x,y);
	EXPECT_EQ(x, 33);
	EXPECT_EQ(y, 5);
}

TEST(Ch19_Moderate, prob19_2) {
	ticTacToe** grid = new ticTacToe*[3];
	for (int i=0; i < 3; ++i) {
		grid[i] = new ticTacToe[3];
	}
	clearTTTgrid(grid);

	// Situation 1
	// x _ _
	// o o _
	// x _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[1][1] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_FALSE(Moderate::prob19_2(grid, Moderate::X));
	EXPECT_FALSE(Moderate::prob19_2(grid, Moderate::O));

	// Situation 2
	// x _ _
	// o o o
	// x _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[1][1] = Moderate::O;
	grid[1][2] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_FALSE(Moderate::prob19_2(grid, Moderate::X));
	EXPECT_TRUE(Moderate::prob19_2(grid, Moderate::O));

	// Situation 3
	// x _ _
	// o x _
	// o _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[1][1] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[2][0] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_TRUE(Moderate::prob19_2(grid, Moderate::X));
	EXPECT_FALSE(Moderate::prob19_2(grid, Moderate::O));

	// Situation 4
	// _ _ x
	// _ x _
	// x o o
	clearTTTgrid(grid);
	grid[0][2] = Moderate::X;
	grid[1][1] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][1] = Moderate::O;
	grid[2][2] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_TRUE( Moderate::prob19_2(grid, Moderate::X));
	EXPECT_FALSE(Moderate::prob19_2(grid, Moderate::O));
}

TEST(Ch19_Moderate, prob19_3) {
	EXPECT_EQ(Moderate::prob19_3(4), 0);
	EXPECT_EQ(Moderate::prob19_3(5), 1);
	EXPECT_EQ(Moderate::prob19_3(9), 1);
	EXPECT_EQ(Moderate::prob19_3(10), 2);
	EXPECT_EQ(Moderate::prob19_3(15), 3);
	EXPECT_EQ(Moderate::prob19_3(20), 4);
	EXPECT_EQ(Moderate::prob19_3(25), 6);
	EXPECT_EQ(Moderate::prob19_3(50), 12);
	EXPECT_EQ(Moderate::prob19_3(125), 31);
}

TEST(Ch19_Moderate, prob19_4) {
	EXPECT_EQ(Moderate::prob19_4(3,4), 4);
	EXPECT_EQ(Moderate::prob19_4(10,20), 20);
	EXPECT_EQ(Moderate::prob19_4(10,10), 10);
	EXPECT_EQ(Moderate::prob19_4(-1,1), 1);
	EXPECT_EQ(Moderate::prob19_4(-12,-18), -12);
}

TEST(Ch19_Moderate, prob19_5) {
	int hits;
	int pseudoHits;
	Moderate::prob19_5("RGGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 2);
	EXPECT_EQ(pseudoHits, 1);

	Moderate::prob19_5("BRGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 3);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("YRGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 4);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("RRGG", "BBYY", hits, pseudoHits);
	EXPECT_EQ(hits, 0);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("RGYB", "BYGR", hits, pseudoHits);
	EXPECT_EQ(hits, 0);
	EXPECT_EQ(pseudoHits, 4);

	Moderate::prob19_5("RRRR", "BYGR", hits, pseudoHits);
	EXPECT_EQ(hits, 1);
	EXPECT_EQ(pseudoHits, 0);
}
