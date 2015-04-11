/*
 * Ch1ArraysAndStrings.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "Ch1ArraysAndStrings.h"

#include <iostream>
#include <queue>
#include <set>
using namespace std;

bool Ch1ArraysAndStrings::prob1_1(const std::string& word) {
	bool unique = true;

	unsigned int letters = 0;
	unsigned int duplicates = 0;
	unsigned int A = 'A';

	const char* w = word.data();
	for (unsigned int i=0; i < word.length(); i++) {
		char letter = w[i];
		unsigned int mask = (1 << (letter - A));
		if (letters & mask) {
			unique = false;
			duplicates |= mask;
		}
		else
			letters |= mask;
	}

//	if (unique)
//		cout << word << " has all unique letters\n";
//	else {
//		cout << word << " DOES NOT have unique letters\n";
//		cout << "Duplicate letters: ";
//		for (int i=0; i < 26; i++) {
//			if ((1 << i) & duplicates) {
//				char tmp = A + i;
//				cout << tmp << " ";
//			}
//		}
//		cout << endl;
//	}
	return unique;
}

void Ch1ArraysAndStrings::prob1_2(char* cString) {
	char* end = cString;

	while (*(end+1) != '\0') {
		end++;
	}

	while(cString < end) {
		if (*cString != *end) {
			*cString ^= *end;
			*end ^= *cString;
			*cString ^= *end;
		}
		cString++;
		end--;
	}
}

void Ch1ArraysAndStrings::prob1_3(char* word) {
	char* rPtr = word; // Replace Pointer
	char* sPtr = word; // Search Pointer
	unsigned long long alphabet[2] = {0,0};

	unsigned long long mask = 0;
	while (*sPtr != '\0') {
		mask = 1ULL << (*sPtr % 64); // only 64 bits in a long. Must use 1ULL
		if (alphabet[(*sPtr)/64] & mask) {
			// This character already exists
			sPtr++;
		} else {
			// Character has not been encountered
			alphabet[(*sPtr)/64] |= mask;
			if (sPtr != rPtr)
				*rPtr = *sPtr;
			sPtr++;
			rPtr++;
		}
	}
	// Move the Null pointer to the current location
	*rPtr = '\0';

//	cout << "Word with no duplicates: " << word << endl;
}

bool Ch1ArraysAndStrings::prob1_4(const std::string& w1, const std::string& w2) {
	bool isAnagram = true;
	if(w1.length() != w2.length())
		return false;

	const char* c1 = w1.c_str();
	const char* c2 = w2.c_str();
	std::priority_queue<char> pq1;
	std::priority_queue<char> pq2;

	// Since we know they are the same length, our stopping conditions can
	// be based of the first word
	while (*c1 != '\0') {
		pq1.push(*c1);
		pq2.push(*c2);
		c1++;
		c2++;
	}

	while(pq1.size() > 0) {
		if (pq1.top() != pq2.top()) {
			isAnagram = false;
			break;
		}
		pq1.pop();
		pq2.pop();
	}

	return isAnagram;
}

void Ch1ArraysAndStrings::prob1_5(string& w) {
	string p20 = "%20";
	string::size_type idx = w.find(' ');
	while (idx != string::npos) {
		w.replace(idx, 1, p20);
		idx = w.find(' ', idx);
	}
}

void Ch1ArraysAndStrings::prob1_5(char* w) {
	int nSp = 0; // Number of spaces
	int len = 0;
	char* newC = w;

	while (*w != '\0') {
		if(*w == ' ')
			++nSp;
		++len; ++w;	++newC;
	}

	// Each space will get replaced plus add 2 characters
	newC += (2*nSp);
	*newC = *w;
	--newC;	--w; --len;

	while (len >= 0) {
		if (*w == ' ') {
			*newC = '0'; --newC;
			*newC = '2'; --newC;
			*newC = '%'; --newC;
		} else {
			*newC = *w; --newC;
		}
		--w; --len;
	}
}

void Ch1ArraysAndStrings::prob1_6(int** matrix, int dim) {
	int curDim = dim;
	int N = 0; // N is the farthest index
	int save = 0;
	for (int layer = 0; layer < (dim/2); ++layer) {
		N = layer + curDim - 1;
		// rot is the current rotation
		for (int rot = 0; rot < (curDim - 1); ++rot) {
			// Save the top row
			save = matrix[layer][layer+rot];

			// Replace top row with left column
			matrix[layer][layer+rot] = matrix[N-rot][layer];

			// Replace left column with bottom row
			matrix[N-rot][layer] = matrix[N][N-rot];

			// Replace bottom row with right column
			matrix[N][N-rot] = matrix[layer+rot][N];

			// Replace right column with save
			matrix[layer+rot][N] = save;
		}
		curDim -= 2;
	}
}

void Ch1ArraysAndStrings::prob1_7(int** matrix, int row, int col) {
	set<int> zeroR;
	set<int> zeroC;
	for (int r=0; r < row; ++r) {
		for (int c=0; c < col; ++c) {
			if(matrix[r][c] == 0) {
				zeroR.insert(r);
				zeroC.insert(c);
			}
		}
	}

	set<int>::iterator itr = zeroR.begin();
	set<int>::iterator end = zeroR.end();
	while(itr != end) {
		int r = *itr;
//		cout << "Zero out row: " << r << endl;
		for (int c=0; c<col; ++c)
			matrix[r][c] = 0;
		++itr;
	}

	itr = zeroC.begin();
	end = zeroC.end();
	while(itr != end) {
		int c = *itr;
//		cout << "Zero out col: " << c << endl;
		for (int r=0; r<row; ++r)
			matrix[r][c] = 0;
		++itr;
	}
}

bool Ch1ArraysAndStrings::prob1_8(const string& s1, const string& s2) {
//	bool isSub = false;
//	if (s2.length() != s1.length())
//		return isSub;
//
//	string tmp = s2 + s2;
//	if(isSubstring(tmp, s1)) {
//		cout << s2 << " is a rotation of " << s1;
//	} else {
//		cout << s2 << " is NOT a rotation of " << s1;
//	}
	return true;
}

