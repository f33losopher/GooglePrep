/*
 * Ch5BitManipulation.h
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */

#ifndef CH5BITMANIPULATION_H_
#define CH5BITMANIPULATION_H_


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
}


#endif /* CH5BITMANIPULATION_H_ */
