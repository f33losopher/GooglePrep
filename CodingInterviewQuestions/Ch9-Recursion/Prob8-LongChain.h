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
	int longChain(std::vector< std::vector <int> > &grid, int x, int y);

private:
	int myXrange;
	int myYrange;
};




#endif /* PROB8_LONGCHAIN_H_ */
