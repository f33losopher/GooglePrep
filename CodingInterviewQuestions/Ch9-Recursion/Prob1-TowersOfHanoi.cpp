/*
 * Prob1-TowersOfHanoi.cpp
 *
 *  Created on: Jan 24, 2017
 *      Author: felix
 */

#include "Prob1-TowersOfHanoi.h"

#include <iostream>
using namespace std;

TowersOfHanoi::TowersOfHanoi() {

}
TowersOfHanoi::~TowersOfHanoi() {

}

void TowersOfHanoi::Debug(ostringstream& ss) {
	cout << ss.str() << endl;
}

void TowersOfHanoi::solve(int disk, int source, int dest, int temp) {
	ostringstream ss;
	ss.str("");
	ss << "CALL==> disk: " << disk << " source: " << source << " dest: " << dest << " temp: " << temp;
	Debug(ss);
	if (disk == 1) {
		ss.str("");
		ss << "DISK 1 " << " from tower: " << source
				<< " to tower: " << dest;
		Debug(ss);
		return;
	}

	solve(disk - 1, source, temp, dest);
	ss.str("");
	ss << "Move disk: " << disk << " from tower: " << source << " to tower: "
			<< dest;
	Debug(ss);
	solve(disk - 1, temp, dest, source);
}

