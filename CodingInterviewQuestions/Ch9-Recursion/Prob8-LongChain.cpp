/*
 * Prob8-LongChain.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: felix
 */

#include "Prob8-LongChain.h"

#include <iostream>
using namespace std;


LongChain::LongChain() : myXrange(0), myYrange(0), myMax(0) {

}

LongChain::~LongChain() {

}

void LongChain::setXY(int x, int y) {
	myXrange = x;
	myYrange = y;

	mySearched.resize(x, vector<int>(y,0));

	myMax = 0;
}

int LongChain::longChain(vector< vector<int> > &grid) {
	// Search each cell, if there is a 1, then proceed to search for number
	// of adjacent 1 cells
	for (int y = 0; y < myYrange; y++) {
		for (int x = 0; x < myXrange; x++) {
			if (validRange(x,y) && grid[x][y] == 1) {
				findOnes(grid, x, y, 0);
			}
		}
	}

	return myMax;
}

void LongChain::findOnes(vector< vector<int> > &grid, int x, int y, int max) {
	mySearched[x][y] = 1;

	max++;
	if (max > myMax) {
		myMax = max;
	}

	// Search the eight directions
	int direction[][2] = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};
	for (int i=0; i < 8; ++i) {
		int srcX = x + direction[i][0];
		int srcY = y + direction[i][1];

		if (validRange(srcX, srcY) && mySearched[srcX][srcY] == 0 && grid[srcX][srcY] == 1) {

			findOnes(grid, srcX, srcY, max);
		}
	}

	mySearched[x][y] = 0;
}

bool LongChain::validRange(int x, int y) {
	bool isValid = true;
	if (x < 0 || x >= myXrange) {
		isValid = false;
	}

	if (y < 0 || y >= myYrange) {
		return false;
	}
	return isValid;
}
