/*
 * Ch19Moderate.h
 *
 *  Created on: Apr 4, 2015
 *      Author: Felix
 */

#ifndef CH19MODERATE_H_
#define CH19MODERATE_H_

#include <stdint.h>

namespace Moderate {
/* Write a function to swap a number in place without temporary variables*/
void prob19_1(int& x, int& y);

/* Design an algorithm to figure out if someone has won in a game of
 * tic-tac-toe
 */
enum ticTacToe {
	X,
	O,
	EMPTY
};
bool prob19_2(ticTacToe** grid, ticTacToe player);

/* Write an algorithm which computes the number of trailing zeros in n
 * factorial
 */
uint64_t factorial(uint64_t n);
uint64_t prob19_3(uint64_t n);

/* Write a method which finds the maximum of two numbers. You should not use
 * if-else or any other comparison operator
 * EXAMPLE: Input:5,10  Output: 10
 */
int prob19_4(int a, int b);

}



#endif /* CH19MODERATE_H_ */
