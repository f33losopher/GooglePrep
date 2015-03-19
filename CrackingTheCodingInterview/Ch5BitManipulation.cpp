/*
 * Ch5BitManipulation.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */

#include "Ch5BitManipulation.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

void Ch5BitManipulation::printBin(unsigned int num) {
	unsigned int mask = (1 << 31);
	for (int i=0; i < 32; ++i) {
		if (i > 0 && (i%8 == 0))
			cout << " ";
		if(num & mask)
			cout << "1";
		else
			cout << "0";
		num <<= 1;
	}
	cout << endl;
}

unsigned int Ch5BitManipulation::prob5_1(unsigned int N, unsigned int M,
		unsigned int i, unsigned int j) {
	unsigned int mask = (1 << (j+1)) - 1;
	mask = ((mask >> i) << i);
	mask = ~mask;

	unsigned int result = N & mask;
	result |= (M << i);
	return result;
}

void Ch5BitManipulation::prob5_2(string num) {
	string::size_type decimal = num.find('.');

	unsigned int whole = atoi(num.substr(0,decimal).data());
	double frac = atof(num.substr(decimal).data());

	const double half = 0.5;
	double sum = 0;
	string decimalS = "";
	for (int i=1; i <= 32; i++) {
		if (sum == frac)
			break;
		else if (sum + pow(half,i) <= frac) {
			sum += pow(half,i);
			decimalS += "1";
		} else {
			decimalS += "0";
		}
	}

	if (sum != frac)
		cout << "ERROR!\n";
	else {
		printBin(whole);
		cout << "." << decimalS << endl;
	}
}

unsigned int Ch5BitManipulation::prob5_3_larger(unsigned int num) {
	if (num == 0) return 1;

	unsigned int nextBigNum = 0;
	// This isolates the lowest 1 bit
	unsigned int lowest1Bit = num & (-num);
	unsigned int rightBits = 0;

	// Force the first 0 bit after the lowest 1 bit to 1
	nextBigNum = num + lowest1Bit;

	// Isolate the right bits and shift them right
	rightBits = num ^ nextBigNum;
	rightBits /= lowest1Bit;

	// Correction for doing x + lowest1Bit, account for overflow
	rightBits >>= 2;

	return (nextBigNum |= rightBits);
}

unsigned int Ch5BitManipulation::prob5_3_smaller(unsigned int num) {
	// Isolate the lowest bit
	unsigned int lowestBit = num & (-num);

	// Remove the lowest bit
	num &= (~lowestBit);

	if (lowestBit & 1) {
		// If the lowest bit is 1, we need to borrow from the next lowest bit
		// and fill in 2 bits next to it
		lowestBit = num & (-num);
		num &= (~lowestBit);
		num |= ((lowestBit >> 1) | (lowestBit >> 2));
	} else {
		// Move the lowest bit 1 position to the right
		num |= (lowestBit >> 1);
	}
	return num;
}

int Ch5BitManipulation::prob5_5(unsigned int A, unsigned int B) {
	cout << "A: " << A << " B: " << B << endl;
	int XOR = A ^ B;
	int diff = 0;
	while (XOR > 0) {
		diff++;
		XOR = (XOR & (XOR - 1));
	}
	return diff;
}

void Ch5BitManipulation::prob5_6(unsigned int num) {
	printBin(num);
	int mask = 0x55555555;
	unsigned int swap = ((num & mask) << 1) | ((num >> 1) & mask);
	printBin(swap);
}
