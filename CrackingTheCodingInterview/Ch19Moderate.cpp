/*
 * Ch19Moderate.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: Felix
 */
#include "Ch19Moderate.h"

#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

void Moderate::prob19_1(int& x, int& y) {
	cout << "Before x:" << x << " y:" << y << endl;
	x ^= y;
	y ^= x;
	x ^= y;
	cout << "After  x:" << x << " y:" << y << endl;
}

bool Moderate::prob19_2(ticTacToe** grid, ticTacToe player) {
	int gridSize = 3;
	bool won = false;

	// Check Rows
	for (int r = 0; r < gridSize && !won; ++r) {
		if (grid[r][0] == player) {
			if (grid[r][1] == player && grid[r][2] == player) {
				won = true;
				break;
			}
		}
	}

	// Check Columns
	for (int c = 0; c < gridSize && !won; ++c) {
		if (grid[0][c] == player) {
			if (grid[1][c] == player && grid[2][c] == player) {
				won = true;
				break;
			}
		}
	}

	// Check diagonals
	if (grid[0][0] == player && !won) {
		if (grid[1][1] == player && grid[2][2] == player) {
			won = true;
		}
	}
	if (grid[0][2] == player && !won) {
		if (grid[1][1] == player && grid[2][0] == player) {
			won = true;
		}
	}
	return won;
}

uint64_t Moderate::factorial(uint64_t n) {
	uint64_t num = 1;
	while (n > 1) {
		num *= n--;
	}

	return num;
}

uint64_t Moderate::prob19_3(uint64_t n) {
	// Contribution of 5's and 2 give a trailing 0. Just count the
	// number of contributing 5's
	uint64_t contribute5 = 0;
	while (n != 0) {
		contribute5 += (n / 5);
		n /= 5;
	}
	return contribute5;
}

int Moderate::prob19_4(int a, int b) {
	int c = a - b;
	int signBit = (c >> 31) & 1;

	return (a - (signBit*c));
}

void Moderate::prob19_5(const string& guess, const string& solution,
		int& hits, int& pseudoHits) {
	// First we have to get all the hits, then take those out of play for
	// the pseudo hits.
	// Error checking cases. Inputs are from set {RYGB}, 4 slots only

	unsigned int search = 0xf;
	hits = 0;
	pseudoHits = 0;

	for (int i=0; i < 4; ++i) {
		if (guess[i] == solution[i]) {
			++hits;
			search &= ~(1 << i);
		}
	}

	for (int sol=0; sol < 4; ++sol) {
		if ((1 << sol) & search) {
			for(int gue=0; gue < 4; ++gue) {
				if((1 << gue) & search) {
					if(solution[sol] == guess[gue]) {
						++pseudoHits;
					}
				}
			}
		}
	}
}
