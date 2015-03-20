/*
 * Ch8Recursion.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Felix
 */

#include "Ch8Recursion.h"
#include <iostream>
#include <stack>

using namespace std;

unsigned long long Ch8Recursion::prob8_1(int n) {
	if (n == 1)
		return 0ULL;
	else if (n == 2)
		return 1ULL;

	return (prob8_1(n-1) + prob8_1(n-2));
}

int Ch8Recursion::prob8_2(int** grid, int N, int r, int c, int curR, int curC) {
	if ((curR == r) && (curC == c))
		return 1;
	int pRight = 0;
	int pDown = 0;

	// Check if we can go down
	if (curR < (N-1))
		pDown = prob8_2(grid, N, r, c, curR+1, curC);
	// Check if we can go right
	if (curC < (N-1))
		pRight = prob8_2(grid, N, r, c, curR, curC+1);
	return (pRight + pDown);
}

//vector< vector<int>* >* Ch8Recursion::prob8_3(vector<int> &set, int idx) {
//	vector< vector<int>* >* allSubsets;
//	if(set.size() == idx) {
//		allSubsets = new vector< vector<int>* >();
//		allSubsets->push_back(new vector<int>);
//	} else {
//		allSubsets = prob8_3(set, idx+1);
//		int item = set.at(idx);
//		vector< vector<int>* >* moresubsets = new vector< vector<int>* >();
//		for(vector<int>::iterator subset = allSubsets->begin(); subset != allSubsets->end(); subset++) {
//			vector<int>* newsubset = new vector<int>();
//			newsubset->insert(subset->begin(), subset->begin(), subset->end());
//		}
//	}
//
//	return allSubsets;
//}

void Ch8Recursion::swapChar(string& w, int idx1, int idx2) {
	char tmp = w[idx1];
	w[idx1] = w[idx2];
	w[idx2] = tmp;
}
void Ch8Recursion::prob8_4(string w, unsigned int begin, set<string>& permutations) {
	if (begin == (w.length() - 1)) {
		cout << w << endl;
		permutations.insert(w);
	}
	else {
		for (unsigned int j=begin; j < w.length(); ++j) {
			swapChar(w, begin, j);
			prob8_4(w, begin+1, permutations);
			swapChar(w, begin, j);
		}
	}
}

bool Ch8Recursion::validParens(const string& parens) {
	bool valid = true;
	stack<char> openParens;
	for (unsigned int i=0; i < parens.length(); ++i) {
		if (parens[i] == '(')
			openParens.push(parens[i]);
		else {
			if (openParens.size() == 0) {
				valid = false;
				break;
			} else {
				openParens.pop();
			}
		}
	}
	return valid;
}

void Ch8Recursion::prob8_5(int numParens) {
	string parens;
	for (int i=0; i < numParens; ++i)
		parens += "()";

	set<string> permutations;
	prob8_4(parens, 0, permutations);


	set<string>::iterator itr = permutations.begin();
	while(itr != permutations.end()) {
		if(!validParens(*itr)) {
			set<string>::iterator tmp = itr;
			permutations.erase(tmp);
		}
		++itr;
	}

	cout << "VALID PERMUTATIONS:" << endl;
	for (itr=permutations.begin(); itr != permutations.end(); ++itr) {
		cout << *itr << endl;
	}
}
