/*
 * Permutation_UnitTest.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: Felix
 */


#include "Permutation.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Permutation, tc1) {
	string a = "ABC";
	Permutation::permute(a, 0);

	a = "CBA";
	Permutation::permute(a, 0);
}
