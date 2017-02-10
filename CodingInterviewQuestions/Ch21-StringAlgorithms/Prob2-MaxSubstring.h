/*
 * Prob2-MaxSubstring.h
 *
 *  Created on: Feb 9, 2017
 *      Author: felix
 */

#ifndef PROB2_MAXSUBSTRING_H_
#define PROB2_MAXSUBSTRING_H_

#include <map>
#include <string>

class MaxSubstring {
public:

	void maxSubstring(std::string s1, std::string s2);

private:
	std::map<std::string, std::string> mySubstrings;

};




#endif /* PROB2_MAXSUBSTRING_H_ */
