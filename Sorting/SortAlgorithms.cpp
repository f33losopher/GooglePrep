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
	for (int right = numElements; right > 0; --right) {
		bool swapped = false;
		for(int j=1; j<right; j++) {
			if(array[j] < array[j-1]) {
				swap(array[j], array[j-1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void Sort::insertion(int* array, int numElements) {
	for(int i=1; i < numElements; i++) {
		for(int k=i; k>0 && (array[k] < array[k-1]); k--) {
			swap(array[k], array[k-1]);
//			print(array, numElements);
		}
	}
}

void Sort::mergeSort::merge(int* array, int left, int right) {
	int mid;

	if (right > left) {
		mid = (left + right)/2;
		mergeSort::merge(array, left, mid);
		mergeSort::merge(array, mid+1, right);
		mergeSort::doMerge(array, left,  right);
	}
}

void Sort::mergeSort::doMerge(int* array, int left, int right) {
	int i, left_end, right_start, num_elements, tmp_pos;

	left_end = (left+right)/2;
	right_start = left_end + 1;
	tmp_pos = 0;
	num_elements = (right - left + 1);
	int temp[num_elements];

	while ((left <= left_end) && (right_start <= right)) {
		if (array[left] <= array[right_start])
			temp[tmp_pos++] = array[left++];
		else
			temp[tmp_pos++] = array[right_start++];
	}
	while (left <= left_end)
		temp[tmp_pos++] = array[left++];

	while (right_start <= right)
		temp[tmp_pos++] = array[right_start++];

	for(i=num_elements-1; i >= 0; --i, --right) {
		array[right] = temp[i];
	}
}

void Sort::merge(int* array, int size) {
	mergeSort::merge(array, 0, size-1);
}

void Sort::quick(int* array, int left, int right) {
	int index = quickSort::partition(array, left, right);
	if(left < index - 1)
		quick(array, left, index -1);
	if(right > index)
		quick(array, index, right);
}

int Sort::quickSort::partition(int* array, int left, int right) {
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
	}
}

void Sort::shell(int* array, int numElements) {
	for (int gap = numElements/2; gap > 0; gap /= 2) {
		for (int i=gap; i < numElements; i++) {
			for(int j=i-gap; j>=0 && (array[j] > array[j+gap]); j-=gap) {
				swap(array[j], array[j+gap]);
//				print(array, numElements);
			}
		}
	}
}

