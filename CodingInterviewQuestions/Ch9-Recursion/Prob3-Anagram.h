/*
 * Prob3-Anagram.h
 *
 *  Created on: Jan 25, 2017
 *      Author: Felix
 */

#ifndef PROB3_ANAGRAM_H_
#define PROB3_ANAGRAM_H_

#include <string>

class Anagram {
public:
	Anagram();
	~Anagram();

	void anagrams(std::string& s, unsigned int beg);

private:
	void swap(std::string& s, unsigned int x, unsigned int y);
};

#endif /* PROB3_ANAGRAM_H_ */
