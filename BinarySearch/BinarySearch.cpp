/*
 * BinarySearch.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "BinarySearch.h"

#define RECURSION
int BinarySearch::intArray(int* array, int val, int sIdx, int eIdx) {
#ifdef RECURSION
	int idx = -1;
	if (sIdx > eIdx)
		return -1;
	int mid = (sIdx + eIdx) / 2;
	if(array[mid] == val)
		idx = mid;
	else {
		if ( val < array[mid])
			idx = intArray(array, val, sIdx, mid-1);
		else
			idx = intArray(array, val, mid+1, eIdx);
	}



	return idx;
#else
	int mid = 0;
	while (sIdx <= eIdx) {
		mid = (sIdx + eIdx) / 2;
		if (array[mid] == val)
			return mid;
		else if(val < array[mid])
			eIdx = mid -1;
		else
			sIdx = mid + 1;
	}
	return -1;

#endif
}

