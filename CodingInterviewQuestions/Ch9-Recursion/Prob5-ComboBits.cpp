/*
 * Prob5-ComboBits.cpp
 *
 *  Created on: Jan 27, 2017
 *      Author: Felix
 */

#include "Prob5-ComboBits.h"

#include <math.h>
#include <iostream>
using namespace std;

ComboBits::ComboBits(int numBits): myNumBits(numBits) {
	myCombo = new int[numBits];
}

ComboBits::~ComboBits() {
}

void ComboBits::Binary(int numBits) {
	if (numBits < 1) {
		printCombo();
		return;
	}

	myCombo[numBits-1] = 0;
	Binary(numBits - 1);
	myCombo[numBits-1] = 1;
	Binary(numBits - 1);
}

void ComboBits::Binary2(int numBits) {
	uint32_t num = pow(2,numBits) - 1;
	binary2(num);
}

void ComboBits::binary2(uint32_t num) {
	if (num == 0) {
		printBits(num);
		return;
	}

	printBits(num);
	binary2(num-1);
}

void ComboBits::printCombo() {
	for (int i=0; i < myNumBits; ++i) {
		cout << myCombo[i];
	}
	cout << endl;
}

void ComboBits::printBits(uint32_t num) {
	uint32_t mask = 0x1 << 31;
	for (int i=0; i < 32; ++i) {
		((num << i) & mask)?(cout << "1"):(cout << "0");
	}
	cout << endl;
}
