/*
 * Ch5BitManipulation.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */

#include "Ch5BitManipulation.h"
#include <iostream>
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

