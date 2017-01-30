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
	replace(s, 0);
}

void WildCard::replace(string& s, unsigned int idx) {
	if (idx >= s.length()) {
		cout << s << endl;
		return;
	}

	string tmp = s;
	if (tmp[idx] == '?') {
		tmp[idx] = '0';
		replace(tmp, idx+1);
		tmp[idx] = '1';
		replace(tmp, idx+1);
	} else {
		replace(tmp, idx+1);
	}
}
