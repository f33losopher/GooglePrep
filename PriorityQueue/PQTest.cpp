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

struct Point {
	Point(int x, int y) : _x(x), _y(y) {
	}
	int _x;
	int _y;

	friend ostream& operator<<(ostream& o, const Point& p) {
		cout << "x: " << p._x << " y: " << p._y << endl;
		return o;
	}
};

struct cmpChar {
	bool operator() (const char a, const char b) {
		// Return true if a is ordered before b
		return a < b;
	}
};

struct cmpPt {
	bool operator() (const Point& p1, const Point& p2) {
		if(p1._x == p2._x) {
			return p1._y > p2._y;
		} else {
			return p1._x > p2._x;
		}
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
	cout << endl << endl;

	priority_queue<Point, vector<Point>, cmpPt> pq2;
	pq2.push(Point(3,6));
	pq2.push(Point(2,8));
	pq2.push(Point(7,5));
	pq2.push(Point(7,4));
	pq2.push(Point(7,7));
	pq2.push(Point(5,7));
	pq2.push(Point(1,8));
	pq2.push(Point(1,10));
	pq2.push(Point(3,1));
	pq2.push(Point(4,10));
	while(!pq2.empty()) {
		cout << pq2.top();
		pq2.pop();
	}
	return 0;
}


