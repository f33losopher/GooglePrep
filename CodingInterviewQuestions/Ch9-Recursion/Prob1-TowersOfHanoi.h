/*
 * Prob1-TowersOfHanoi.h
 *
 *  Created on: Jan 24, 2017
 *      Author: felix
 */

#ifndef PROB1_TOWERSOFHANOI_H_
#define PROB1_TOWERSOFHANOI_H_

#include <sstream>

class TowersOfHanoi {
public:
	TowersOfHanoi();
	~TowersOfHanoi();

	static void solve(int disk, int source, int dest, int temp);
	static void Debug(std::ostringstream& ss);
};

#endif /* PROB1_TOWERSOFHANOI_H_ */
