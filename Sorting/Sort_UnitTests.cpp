/*
 * TestMain.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "SortAlgorithms.h"
#include <iostream>
#include <stdlib.h>

#include "gtest/gtest.h"

using namespace std;

const int numElements = 20;
int numbers[numElements];

void initialize(int* array, int n) {
	srand(10);
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 40;
	}
}

void print(int* array, int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void initAndPrint() {
	initialize(numbers, numElements);
	print(numbers, numElements);
}

TEST(Sort, Bubble) {
	initAndPrint();
	Sort::bubble(numbers, numElements);
	print(numbers, numElements);
	cout << endl;
}

TEST(Sort, Selection) {
	initAndPrint();
	Sort::selection(numbers, numElements);
	print(numbers, numElements);
	cout << endl;
}

TEST(Sort, Insertion) {
	initAndPrint();
	Sort::insertion(numbers, numElements);
	print(numbers, numElements);
	cout << endl;
}

TEST(Sort, Shell) {
	initAndPrint();
	Sort::shell(numbers, numElements);
	print(numbers, numElements);
	cout << endl;
}

TEST(Sort, Quick) {
	initAndPrint();
	Sort::quick(numbers, 0, numElements - 1);
	print(numbers, numElements);
	cout << endl;
}

TEST(Sort, Merge) {
	initAndPrint();
	Sort::merge(numbers, numElements);
	print(numbers, numElements);
	cout << endl;
}

