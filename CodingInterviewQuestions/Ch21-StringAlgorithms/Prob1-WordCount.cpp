/*
 * Prob1-WordCount.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: felix
 */

#include "Prob1-WordCount.h"

using namespace std;
void WordCount::process(istream& ifs) {
	myWords.clear();
	myMax = 0;

	string word;
	int val;
	map<string, int>::iterator itr;
	while (ifs >> word) {
		itr = myWords.find(word);
		if (itr == myWords.end()) {
			myWords.insert(map<string, int>::value_type(word, 1));
			if (1 > myMax) {
				myMax = 1;
			}
		} else {
			val = itr->second + 1;
			itr->second = val;
			if (val > myMax) {
				myMax = val;
			}
		}
	}
}


const map<string, int>& WordCount::getMyWords() const {
	return myWords;
}

int WordCount::getMax() {
	return myMax;
}
