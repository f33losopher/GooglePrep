/*
 * Prob5-ComboBits.h
 *
 *  Created on: Jan 27, 2017
 *      Author: Felix
 */

#ifndef PROB5_COMBOBITS_H_
#define PROB5_COMBOBITS_H_
#include<stdint.h>

class ComboBits {
public:
	ComboBits(int numBits);
	~ComboBits();

	// Book method
	void Binary(int numBits);

	// Number method
	void Binary2(int numbits);

private:
	int* myCombo;
	int myNumBits;

	void binary2(uint32_t num);
	void printCombo();
	void printBits(uint32_t num);
};

#endif /* PROB5_COMBOBITS_H_ */
