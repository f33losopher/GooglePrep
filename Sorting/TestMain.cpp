/*
 * TestMain.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "SortAlgorithms.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

void initialize(int* array, int n) {
	srand(10);
	for (int i=0; i < n; i++) {
		array[i] = rand() % 40;
	}
}

void print(int* array, int n) {
	for (int i=0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	int numElements = 10;
	int numbers[numElements];

//	initialize(numbers, numElements);
//	print(numbers, numElements);
//	Sort::bubble(numbers, numElements);
//	print(numbers, numElements);
//	cout << endl;

//	initialize(numbers, numElements);
//	print(numbers, numElements);
//	Sort::selection(numbers, numElements);
//	print(numbers, numElements);
//	cout << endl;

//	initialize(numbers, numElements);
//	print(numbers, numElements);
//	Sort::insertion(numbers, numElements);
//	print(numbers, numElements);
//	cout << endl;

//	initialize(numbers, numElements);
//	print(numbers, numElements);
//	Sort::shell(numbers, numElements);
//	print(numbers, numElements);
//	cout << endl;

	initialize(numbers, numElements);
	print(numbers, numElements);
	Sort::quick(numbers, 0, numElements-1);
	print(numbers, numElements);
	cout << endl;

	return 0;
}



