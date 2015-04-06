/*
 * Ch1ArraysAndStrings.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */

#ifndef CH1ARRAYSANDSTRINGS_H_
#define CH1ARRAYSANDSTRINGS_H_
#include <string>

typedef std::string string;

class Ch1ArraysAndStrings {
public:
	Ch1ArraysAndStrings() {}

	/* Implement an algorithm to determine if a string has all unique
	 * characters. What if you can not use additional data structures?
	 */
	static bool prob1_1(const string& word);

	/* Write code to reverse a Cstyle string. (C-string means that "abcd"
	 * is represented as five characters, including the null character)
	 */
	static void prob1_2(char* cString);

	/* Design an algorithm and write code to remove the duplicate characters
	 * in a string without using any additional buffer. NOTE: One or two
	 * additional variables are fine. An extra copy of the array is not.
	 * FOLLOW UP
	 * Write the test cases for this method
	 */
	static void prob1_3(char* word);

	/* Write a method to decide if two strings are anagrams or not
	 */
	static bool prob1_4(const string& w1, const string& w2);

	/* Write a method to replace all spaces in a string with '%20'
	 */
	static void prob1_5(string& w);
	static void prob1_5(char* w);

	/* Given an image represented by an NxN matrix, where each pixel in the image is 4
	 * bytes, write a method to rotate the image by 90 degrees. Can you do this in place
	 */
	static void prob1_6(int** matrix, int dim);

	/* Write an algorithm such that if an element in an MxN matrix is 0, it's entire
	 * row and column is set to 0
	 */
	static void prob1_7(int** matrix, int row, int col);

	/* Assume you have a method isSubstring which checks if one word is a substring
	 * of another. Given two string s1 and s2, write code to check if s2 is a rotation
	 * of s1 using only 1 call to substring (ie: "waterbottle" is a rotation of "erbottlewat"
	 */
	static bool prob1_8(const string& s1, const string& s2);
};



#endif /* CH1ARRAYSANDSTRINGS_H_ */
