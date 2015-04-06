/*
 * SortAlgorithms.h
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */

#ifndef SORTALGORITHMS_H_
#define SORTALGORITHMS_H_

namespace Sort {
void print(int* array, int n);

void swap(int&a, int& b);

// Swaps adjacent values until sorted
void bubble(int* array, int numElements);

// For each value, swaps with adjacent until it is
// in the correct location
void insertion(int* array, int numElements);

namespace mergeSort {
void merge(int* array, int left, int right);
void doMerge(int* array, int left, int right);
}
void merge(int* array, int numElements);

// Choose a pivot value. Smaller values to left and bigger values
// go to the right. Then recursively run quick sort on
// the two partitions
namespace quickSort {
int partition(int* array, int left, int right);
}
void quick(int* array, int left, int right);

// Searches for smallest value puts at Index=0
// Next smallest at Index=1...
void selection(int* array, int numElements);

// Takes the length of the array, divides in 2, then
// compares elements with that much distance. Divide
// distance and half, compare and swap till the distance
// is 1.
void shell(int* array, int numElements);



}


#endif /* SORTALGORITHMS_H_ */
