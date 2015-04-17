/*
 * Permutation.h
 *
 *  Created on: Apr 17, 2015
 *      Author: Felix
 */

#ifndef PERMUTATION_H_
#define PERMUTATION_H_

#include <string>

class Permutation {
public:

	static void permute(std::string& s, int beg);

	static void swap(std::string& s, int a, int b);
};



#endif /* PERMUTATION_H_ */
