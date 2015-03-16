/*
 * SortAlgorithms.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "SortAlgorithms.h"

#include <iostream>
using namespace std;

void Sort::swap(int& a, int& b) {
	if (a == b) return;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void Sort::print(int* array, int n) {
	for (int i=0; i < n; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void Sort::bubble(int* array, int numElements) {
	for (int i=0; i < numElements; i++) {
		bool swapped = false;
		for(int j=1; j<numElements; j++) {
			if(array[j] < array[j-1]) {
				swap(array[j], array[j-1]);
				swapped = true;
			}
			print(array, numElements);
		}
		if (!swapped) break;
	}
}

void Sort::insertion(int* array, int numElements) {
	for(int i=1; i < numElements; i++) {
		for(int k=i; k>0 && (array[k] < array[k-1]); k--) {
			swap(array[k], array[k-1]);
			print(array, numElements);
		}
	}
}

void Sort::quick(int* array, int left, int right) {
	int index = PRIVATE::partition(array, left, right);
	if(left < index - 1)
		quick(array, left, index -1);
	if(right > index)
		quick(array, index, right);
}

int Sort::PRIVATE::partition(int* array, int left, int right) {
	int pivot = array[(left+right)/2];
	int beg = left;
	int end = right;
	while (beg <= end) {
		while (array[beg] < pivot)
			beg++;
		while (array[end] > pivot)
			end--;
		if(beg <= end) {
			swap(array[beg], array[end]);
			print(array, 10);
			beg++;
			end--;
		}
	}

	return beg;
}

void Sort::selection(int* array, int numElements) {
	for(int i=0; i <numElements; i++) {
		int toSwap = i;
		for (int j=i+1; j<numElements; j++) {
			if (array[j] < array[toSwap])
				toSwap=j;
		}
		swap(array[i], array[toSwap]);
		print(array, numElements);
	}
}

void Sort::shell(int* array, int numElements) {
	for (int gap = numElements/2; gap > 0; gap /= 2) {
		for (int i=gap; i < numElements; i++) {
			for(int j=i-gap; j>=0 && (array[j] > array[j+gap]); j-=gap) {
				swap(array[j], array[j+gap]);
				print(array, numElements);
			}
		}
	}
}

