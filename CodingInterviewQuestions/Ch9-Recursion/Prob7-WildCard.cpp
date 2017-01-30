/*
 * Prob7-WildCard.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: Felix
 */

#include "Prob7-WildCard.h"

#include <iostream>
using namespace std;

WildCard::WildCard() {

}
WildCard::~WildCard() {

}
void WildCard::replaceQMarks(string& s) {
	findQMarks(s);

	if (myQmarks.size() == 0) {
		cout << s << endl;
	} else {
		replace(s, 0);
	}
}

void WildCard::findQMarks(string& s) {
	myQmarks.clear();
	for (unsigned int i = 0; i < s.length(); ++i) {
		if (s[i] == '?') {
			cout << "Found ? at i=" << i << endl;
			myQmarks.push_back(i);
		}
	}
}

void WildCard::replace(string& s, unsigned int idx) {
	string tmp = s;

	if (idx >= myQmarks.size()) {
		cout << tmp << endl;
	} else {
		tmp[myQmarks.at(idx)] = '0';
		replace(tmp, idx+1);
		tmp[myQmarks.at(idx)] = '1';
		replace(tmp, idx+1);
	}
}
