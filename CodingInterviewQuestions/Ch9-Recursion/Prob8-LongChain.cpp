/*
 * Prob8-LongChain.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: felix
 */

#include "Prob8-LongChain.h"

#include <iostream>
using namespace std;


LongChain::LongChain() : myXrange(0), myYrange(0) {

}

LongChain::~LongChain() {

}

void LongChain::setXY(uint x, uint y) {
	myXrange = x;
	myYrange = y;
}

uint LongChain::longChain(vector< vector<int> > &grid, uint x, uint y) {
cout << "Call longChain with x: " << x << " y: " << y << endl;

	if (x < 0 || x >= myXrange) {
		return 0;
	} else if (y < 0 || y >= myYrange) {
		return 0;
	}

	int oneOrZero = 0;
	if (grid[x][y] == 1) {
		oneOrZero = 1;
	}

cout << "oneOrZero: " << oneOrZero << endl;

	uint UL, UP, UR, LT, RT, LL, LW, LR = 0;

	UL = oneOrZero + longChain(grid, x-1, y-1);
	UP = oneOrZero + longChain(grid, x,   y-1);
	UR = oneOrZero + longChain(grid, x+1, y-1);
	LT = oneOrZero + longChain(grid, x-1, y);
	RT = oneOrZero + longChain(grid, x+1, y);
	LL = oneOrZero + longChain(grid, x-1, y+1);
	LW = oneOrZero + longChain(grid, x,   y+1);
	LR = oneOrZero + longChain(grid, x+1, y+1);

	uint max = 0;
	if (UL > max) max = UL;
	if (UP > max) max = UP;
	if (UR > max) max = UR;
	if (LT > max) max = LT;
	if (RT > max) max = RT;
	if (LL > max) max = LL;
	if (LW > max) max = LW;
	if (LR > max) max = LR;

	return max;
}
