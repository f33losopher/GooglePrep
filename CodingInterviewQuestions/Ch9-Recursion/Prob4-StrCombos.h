/*
 * Prob4-StrCombos.h
 *
 *  Created on: Jan 26, 2017
 *      Author: Felix
 */

#ifndef PROB4_STRCOMBOS_H_
#define PROB4_STRCOMBOS_H_

class StringCombos {
public:
	StringCombos(char* original);
	~StringCombos();

	void Combinations(int depth, int start);

private:
	char* myOriginal;
	char* myCombination;
	int myLength;
};

#endif /* PROB4_STRCOMBOS_H_ */
