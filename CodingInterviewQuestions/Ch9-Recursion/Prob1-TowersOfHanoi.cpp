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

void TowersOfHanoi::solve(int disk, int source, int dest, int temp) {
	cout << "CALL==> disk: " << disk << " source: " << source << " dest: "
			<< dest << " temp: " << temp << endl;
	if (disk == 1) {
		cout << "Move disk: " << disk << " from tower: " << source
				<< " to tower: " << dest << endl;
		return;
	}

	solve(disk - 1, source, temp, dest);
	cout << "Move disk: " << disk << " from tower: " << source << " to tower: "
			<< dest << endl;
	solve(disk - 1, temp, dest, source);
}

