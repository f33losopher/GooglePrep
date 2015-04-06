/*
 * Ch19Moderate.h
 *
 *  Created on: Apr 4, 2015
 *      Author: Felix
 */

#ifndef CH19MODERATE_H_
#define CH19MODERATE_H_

#include <stdint.h>
#include <string>

typedef std::string string;

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

/* The Game of Master Mind is played as follows:
 * The computer has four slots containing balls that are red (R), yellow (Y),
 * Green (G), or blue (B). For example, the computer might have RGGB (e.g., Slot #1
 * is red, Slots #2 and 3 are green, Slot #4 is blue)
 *
 * You, the user, are trying to guess the solution. You might, for example, guess YRGB.
 * When you guess the correct color for the correct slot, you get a "hit". If you
 * guess a color that exists bus is in the wrong slot, you get a "pseudo-hit".
 * For example, the guess YRGB has 2 hits and one pseudo hit.
 * For each guess, you are told the number of hits and pseudo-hits.
 * Write a method, that given a guess and solution, returns the number of
 * hits and pseudo hits.
 */
void prob19_5(const string& guess, const string& solution,
		int& hits, int& pseudoHits);
}



#endif /* CH19MODERATE_H_ */
