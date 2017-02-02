/*
 * Prob8-LongChain.h
 *
 *  Created on: Jan 30, 2017
 *      Author: felix
 */

#ifndef PROB8_LONGCHAIN_H_
#define PROB8_LONGCHAIN_H_

#include <vector>

class LongChain {
public:
	LongChain();
	~LongChain();

	// Set the x,y max ranges of the incoming grid. Must be called before
	// longChain(...)
	void setXY(int x, int y);

	// Call this to search for a 1. If there is a 1, recursively search
	int longChain(std::vector< std::vector <int> > &grid);

private:
	int myXrange;
	int myYrange;

	// Max value of longest chain of 1's
	int myMax;

	// The searched spaces so recursion doesn't become infinite
	std::vector< std::vector<int> > mySearched;

	// Compares against myXrange, myYrange
	bool validRange(int x, int y);

	// Continue down all directions as long as the adjacent cell=1
	void findOnes(std::vector < std::vector<int> > &grid, int x, int y, int max);
};

#endif /* PROB8_LONGCHAIN_H_ */
