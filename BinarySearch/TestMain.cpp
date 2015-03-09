/*
 * TestMain.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */

#include "BinarySearch.h"

#include <iostream>
using namespace std;

int main() {
	int aSize = 100;
	int* array = new int[aSize];
	for (int i=0; i < aSize; i++) {
		array[i] = 2*i;
	}

	for (int i=0; i < aSize; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	int index = BinarySearch::intArray(array, 35, 0, aSize-1);
	cout << "Index for 35: " << index << endl;

	index = BinarySearch::intArray(array, 36, 0, aSize-1);
	cout << "Index for 36: " << index << endl;

	index = BinarySearch::intArray(array, 99, 0, aSize-1);
	cout << "Index for 99: " << index << endl;

	index = BinarySearch::intArray(array, 102, 0, aSize-1);
	cout << "Index for 102: " << index << endl;
	return 0;
}


