/*
 * Prob8-LongChain.h
 *
 *  Created on: Jan 30, 2017
 *      Author: felix
 */

#ifndef PROB8_LONGCHAIN_H_
#define PROB8_LONGCHAIN_H_

#include <sys/types.h>
#include <vector>

class LongChain {
public:
	LongChain();
	~LongChain();

	// Set the x,y max ranges of the incoming grid. Must be called before
	// longChain(...)
	void setXY(uint x, uint y);
	uint longChain(std::vector< std::vector <int> > &grid, uint x, uint y);

private:
	uint myXrange;
	uint myYrange;
};




#endif /* PROB8_LONGCHAIN_H_ */
