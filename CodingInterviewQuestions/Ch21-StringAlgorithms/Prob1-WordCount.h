/*
 * Prob1-WordCount.h
 *
 *  Created on: Feb 9, 2017
 *      Author: felix
 */

#ifndef PROB1_WORDCOUNT_H_
#define PROB1_WORDCOUNT_H_

#include <istream>
#include <map>
#include <string>

class WordCount {
public:

	void process(std::istream& ifs);

	const std::map<std::string, int>& getMyWords() const;

	int getMax();

private:
	std::map<std::string, int> myWords;
	int myMax;
};




#endif /* PROB1_WORDCOUNT_H_ */
