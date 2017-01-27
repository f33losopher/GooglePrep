/*
 * Prob4-StrCombos.cpp
 *
 *  Created on: Jan 26, 2017
 *      Author: Felix
 */

#include "Prob4-StrCombos.h"
#include <string.h>

#include <iostream>
using namespace std;

StringCombos::StringCombos(char* original) : myOriginal(original) {
	myLength = strlen(original);
	myCombination = new char[myLength];
}

StringCombos::~StringCombos() {
	delete myOriginal;
}

void StringCombos::Combinations(int depth, int start) {
	cout << "NEW CALL depth: " << depth << " start: " << start << " length: " << myLength << endl;

	for (int i = start; i < myLength; ++i) {

		cout << "  depth: " << depth << " start: " << start << endl;
		cout << "  i: " << i << endl;

		myCombination[depth] = myOriginal[i];
		myCombination[depth+1] = '\0';
		cout << "  " << myCombination << endl;
		if (i < myLength - 1) {
			Combinations(depth + 1, i + 1);
		}
		cout << "  Bottom of loop" << endl;
	}
	cout << "  RETURN" << endl;
}
