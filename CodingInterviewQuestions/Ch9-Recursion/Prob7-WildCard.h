/*
 * Prob7-WildCard.h
 *
 *  Created on: Jan 30, 2017
 *      Author: Felix
 */

#ifndef PROB7_WILDCARD_H_
#define PROB7_WILDCARD_H_

#include <string>
#include <vector>

class WildCard {
public:
	WildCard();
	~WildCard();

	void replaceQMarks(std::string& s);

private:
	void findQMarks(std::string& s);
	void replace(std::string& s, unsigned int idx);

	std::vector<unsigned int> myQmarks;
};
#endif /* PROB7_WILDCARD_H_ */
