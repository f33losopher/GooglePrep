/*
 * TestMain.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Felix
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void pMatrix(int** matrix , int dim) {
	for (int row=0; row < dim; ++row) {
		for (int col=0; col < dim; ++col) {
			printf("%.2d ", matrix[row][col]);
		}
		cout << endl;
	}
}

int main(int argc, char** argv) {
	const int dim = atoi(argv[1]);

//	int matrix[dim][dim];
//	for (int row=0; row<dim; row++) {
//		for (int col=0; col<dim; col++) {
//			matrix[row][col] = row*10 + col;
//		}
//	}
//
//	int** mPtr = new int*[dim];
//	for (int row=0; row < dim; row++) {
//		mPtr[row] = &(matrix[row][0]);
//	}
//
//	pMatrix(mPtr, dim);


	int** matrix = new int*[dim];
	for (int row=0; row<dim; ++row) {
		matrix[row] = new int[dim];
	}

	for (int row=0; row<dim; ++row) {
		for (int col=0; col<dim; ++col) {
			matrix[row][col] = row*10 + col;
		}
	}
	pMatrix(matrix, dim);

	return 0;
}



