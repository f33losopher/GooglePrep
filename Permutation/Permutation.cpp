/*
 * Permutation.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: Felix
 */

#include "Permutation.h"
#include <iostream>

using namespace std;

void Permutation::permute(string& s, int beg) {
	if(beg == (s.length() - 1)) {
		cout << s << endl;
	} else {
		for (int j = beg; j < s.length(); ++j) {
			swap(s, beg, j);
			permute(s, beg+1);
			swap(s, beg, j);
		}
	}
}

void Permutation::swap(string& s, int a, int b) {
	char tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}
