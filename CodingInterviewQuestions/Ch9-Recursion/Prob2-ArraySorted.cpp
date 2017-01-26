/*
 * Prob2-ArraySorted.cpp
 *
 *  Created on: Jan 25, 2017
 *      Author: Felix
 */

#include "Prob2-ArraySorted.h"

#include <iostream>
using namespace std;

isArraySorted::isArraySorted() {
}

isArraySorted::~isArraySorted() {
}

int isArraySorted::isArrayInSortedOrder(int A[], int n) {
	if ((n-2) < 0) {
		return 1;
	} else {
		return (A[n-2] <= A[n-1])?isArrayInSortedOrder(A, n-1):0;
	}
}
