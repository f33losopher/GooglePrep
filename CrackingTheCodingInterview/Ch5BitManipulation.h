/*
 * Ch5BitManipulation.h
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */

#ifndef CH5BITMANIPULATION_H_
#define CH5BITMANIPULATION_H_
#include <string>

namespace Ch5BitManipulation {
void printBin(unsigned int num);

/* Prob 5.1
 * You are given two 32-bit numbers, N and M, and two bit positions, i and j.
 * Write a method to set all bits between i and j in N equal to M (eg M becomes
 * a substring of N located at i and starting at j)
 * EXAMPLE
 * Input: N = 10000000000, M = 10101, i=2, j=6
 * Output: N = 10001010100
 */
unsigned int prob5_1(unsigned int N, unsigned int M, unsigned int i, unsigned int j);

/* Prob 5.2
 * Given a (decimal - eg 3.72) number that is passed in as a string, print the binary
 * representation. If the number can not be represented accurately in binary, print "ERROR"
 */
void prob5_2(std::string num);

/* Prob 5.3
 * Given an integer, print the next smallest and next largest number that have the
 * same number of 1 bits in their binary representation
 */
unsigned int prob5_3_larger(unsigned int num);
unsigned int prob5_3_smaller(unsigned int numb);

/* Prob 5.4
 * Explain what the following code does ((n & (n-1)) == 0)
 * My answer: If this is in some kind of while loop, it is saying that if
 * remove the lowest bit, is the result 0?
 * If it's a 1 shot thing, it's saying if removing the lowest bit makes it zero,
 * possibly to test if it is a power of 2, since any power of 2 uses only 1 bit
 */

/* Prob 5.5
 * Write a function to determine the number of bits required to convert integer A
 * to integer B
 * Input: 31, 14
 * Output: 2
 */
int prob5_5(unsigned int A, unsigned int B);

/* Prob 5.6
 * Write a program to swap odd and even bits in an integer with as few instructions as
 * possible (eg bit 0 and 1 are swapped, bit 2 and 3 are swapped, etc)
 */
void prob5_6(unsigned int num);


}


#endif /* CH5BITMANIPULATION_H_ */
