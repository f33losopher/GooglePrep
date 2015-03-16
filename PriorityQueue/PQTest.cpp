/*
 * PQTest.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Felix
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmpChar {
	bool operator() (const char a, const char b) {
		// Return true if a is ordered before b
		return a > b;
	}
};

int main() {
	priority_queue<char, vector<char>, cmpChar> pq;
	pq.push('a');
	pq.push('b');
	pq.push('c');
	pq.push('a');
	pq.push('z');
	pq.push('b');
	pq.push('y');
	pq.push('c');

	while (pq.size() > 0) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}


