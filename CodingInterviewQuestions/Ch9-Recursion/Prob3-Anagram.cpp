/*
 * Prob3-Anagram.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: Felix
 */

#include "Prob3-Anagram.h"

#include <string>
#include <iostream>
using namespace std;

Anagram::Anagram() {

}

Anagram::~Anagram() {

}

void Anagram::anagrams(string& s, unsigned int beg) {
	if (beg == (s.size() - 1)) {
		cout << s << endl;
		return;
	}

	for (unsigned int i = beg; i < s.size(); ++i) {
		swap(s, beg, i);
		anagrams(s, beg+1);
		swap(s, beg, i);
	}
}

void Anagram::swap(string& s, unsigned int x, unsigned int y) {
	char cx = s[x];
	char cy = s[y];

	s[x] = cy;
	s[y] = cx;
}
