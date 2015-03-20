/*
 * Ch8Recursion.h
 *
 *  Created on: Mar 19, 2015
 *      Author: Felix
 */

#ifndef CH8RECURSION_H_
#define CH8RECURSION_H_

#include <string>
#include <set>

namespace Ch8Recursion {
/* Write a method to generate the nth fibonacci number
 */
unsigned long long prob8_1(int n);

/* Imagine a robot sitting on the upper left hand corner of an NxN grid. The
 * robot can only move in two directions: right and down. How many possible
 * paths are there for the robot?
 * FOLLOW UP: Imagine certain squares are "off limits", such that the robot
 * can not step on them. Design an algorithm to get all possible paths for
 * the robot.
 */
// Grid is an NxN matrix (0,0) being the upper left
// x and y are the destination x,y coordinates
// curX and curY is the current locations
int prob8_2(int** grid, int N, int r, int c, int curR, int curC);

/* Write a method that returns all subsets of a set
 */
//std::vector < std::vector<int>* >* prob8_3(std::vector<int> &set, int idx);

/* Write a method to compute all permutations of a string
 */
void swapChar(std::string& w, int idx1, int idx2);
void prob8_4(std::string w, unsigned int begin, std::set<std::string>& permutations);

/* Implement an algorithm to print all valid (e.g, properly opened and closed)
 * combinations of n-pairs parentheses
 */
bool validParens(const std::string& parens);
void prob8_5(int numParens);
}



#endif /* CH8RECURSION_H_ */
