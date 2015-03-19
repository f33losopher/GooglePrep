/*
 * TestMain.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: Felix
 */
#include "Ch1ArraysAndStrings.h"
#include "Ch2LinkedLists.h"
#include "Ch4TreesAndGraphs.h"
#include "Ch5BitManipulation.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include <iostream>
using namespace std;

typedef LinkedList::Node LNode;
typedef Ch4TreesAndGraphs::Node TNode;

void pMatrix(int** matrix, int row, int col) {
	for (int r = 0; r < row; ++r) {
		for (int c = 0; c < col; ++c) {
			printf("%.2d ", matrix[r][c]);
		}
		cout << endl;
	}
	cout << endl;
}

void pMatrix(int** matrix, int dim) {
	pMatrix(matrix, dim, dim);
}

int main() {

	// CH 1
//	Ch1ArraysAndStrings::prob1_1("FELIXLU");
//	Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
//	Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZZ");
//	Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
//
//	char* word = new char[50];
//	strcpy(word, "abcdefg");
//	Ch1ArraysAndStrings::prob1_2(word);
//	cout << "Reversed: " << word << endl;
//	strcpy(word, "FelixLuIsGreat!");
//	Ch1ArraysAndStrings::prob1_2(word);
//	cout << "Reversed: " << word << endl;
//
//	strcpy(word,"abc");
//	Ch1ArraysAndStrings::prob1_3(word);
//	strcpy(word,"aabc");
//	Ch1ArraysAndStrings::prob1_3(word);
//	strcpy(word, "abbc");
//	Ch1ArraysAndStrings::prob1_3(word);
//	strcpy(word, "abcc");
//	Ch1ArraysAndStrings::prob1_3(word);
//	strcpy(word,"aaaa");
//	Ch1ArraysAndStrings::prob1_3(word);
//
//	string w1 = "Felix";
//	string w2 = "lieFx";
//	if (Ch1ArraysAndStrings::prob1_4(w1,w2))
//		cout << "Anagram: " << w1 << " " << w2 << endl;
//	else
//		cout << "NOT anagram: " << w1 << " " << w2 << endl;
//
//	w1 = "ABBAc";
//	w2 = "BAABd";
//	if (Ch1ArraysAndStrings::prob1_4(w1,w2))
//		cout << "Anagram: " << w1 << " " << w2 << endl;
//	else
//		cout << "NOT anagram: " << w1 << " " << w2 << endl;
//
//	w1 = "ABCDDDFELIX";
//	w2 = "DDDBCAXIFEL";
//	if (Ch1ArraysAndStrings::prob1_4(w1,w2))
//		cout << "Anagram: " << w1 << " " << w2 << endl;
//	else
//		cout << "NOT anagram: " << w1 << " " << w2 << endl;
//
//
//	w1 = "Test this program and see";
//	cout << w1 << endl;
//	Ch1ArraysAndStrings::prob1_5(w1);
//	cout << w1 << endl;
//
//	strcpy(word, "ab cd ef");
//	cout << word << endl;
//	Ch1ArraysAndStrings::prob1_5(word);
//	cout << word << endl;
//	strcpy(word, " Felix Lu Vivian Nguyen ");
//	cout << word << endl;
//	Ch1ArraysAndStrings::prob1_5(word);
//	cout << word << endl;
//	strcpy(word, "   ");
//	cout << word << endl;
//	Ch1ArraysAndStrings::prob1_5(word);
//	cout << word << endl<< endl;
//
//	int dim = 10;
//	int matrix[dim][dim];
//	for (int r=0; r < dim; r++) {
//		for (int c=0; c < dim; c++) {
//			matrix[r][c] =(r*10 + c);
//		}
//	}
//
//	int** mPtr = new int*[dim];
//	for (int r=0; r<dim; ++r) {
//		mPtr[r] = &(matrix[r][0]);
//	}
//	pMatrix(mPtr, dim);
//	Ch1ArraysAndStrings::prob1_6(mPtr, dim);
//	pMatrix(mPtr, dim);
//
//
//	int M = 15;
//	int N = 20;
//	int mtx[M][N];
//	srand(1);
//	for (int r=0; r<M; ++r) {
//		for (int c=0; c<N; ++c) {
//			mtx[r][c] = rand() % 50;
//		}
//	}
//	mPtr = new int*[M];
//	for(int r=0; r<M; ++r) {
//		mPtr[r] = &(mtx[r][0]);
//	}
//
//	pMatrix(mPtr, M, N);
//	Ch1ArraysAndStrings::prob1_7(mPtr, M, N);
//	pMatrix(mPtr, M, N);
	// END CH1

	// CH2

//	// Prob 2.1
//	LinkedList* LList = new LinkedList();
//	srand(1);
//	for (int i = 0; i < 40; ++i) {
//		LList->add(rand() % 10);
//	}
//	LList->print();
//	LList->removeDups();
//	LList->print();
//
//	// Prob 2.2
//	for (int i = 0; i < 10; ++i) {
//		LList->add(rand() % 10);
//	}
//	LList->print();
//	cout << LList->nthToLast(1)->_data << endl;
//	cout << LList->nthToLast(2)->_data << endl;
//	cout << LList->nthToLast(3)->_data << endl;
//	cout << LList->nthToLast(18)->_data << endl;
//	cout << LList->nthToLast(19)->_data << endl;
//	cout << LList->nthToLast(20)->_data << endl;
//	cout << endl;
//
//	unsigned int * stkCnt = new unsigned int;
//	*stkCnt = 0;
//	cout << LList->nthToLast(LList->head(), 1, stkCnt)->_data << endl;
//	*stkCnt = 0;
//	cout << LList->nthToLast(LList->head(), 2, stkCnt)->_data << endl;
//	*stkCnt = 0;
//	cout << LList->nthToLast(LList->head(), 3, stkCnt)->_data << endl;
//
//	// Prob 2.3
//	LList->print();
//	LNode* tmp = LList->at(2);
//	LList->removeMiddleNode(tmp);
//	LList->print();
//
//	// Prob 2.4
//	LinkedList* list1 = new LinkedList();
//	LinkedList* list2 = new LinkedList();
//	list1->add(8);
//	list1->add(4);
//	list1->add(5);
//	list2->add(5);
//	list2->add(9);
//	list2->add(2);
//	LinkedList* sum = LinkedList::rAdd(list1, list2);
//	list1->print();
//	list2->print();
//	sum->print();
	// END CH2

	// CH4
//	int size = 20;
//	int* sortedArray = new int[size];
//	for (int i=0; i < size; i++) {
//		sortedArray[i] = i;
//	}
//
//	TNode* head = Ch4TreesAndGraphs::createBTfromSortedArray(sortedArray, 0, size - 1);
//	Ch4TreesAndGraphs::bfsPrint(head);
//
//	head = Ch4TreesAndGraphs::createBTfromSortedArray(sortedArray, size);
//	Ch4TreesAndGraphs::bfsPrint(head);
//
//	int depth = Ch4TreesAndGraphs::maxDepth(head);
//	cout << "Depth: " << depth << endl;
//
//	LinkedList** llists = Ch4TreesAndGraphs::listsFromDepth(head);
//	for (int i=0; i < depth; i++) {
//		llists[i]->print();
//	}
//
//
//	cout << "In order print\n";
//	Ch4TreesAndGraphs::inOrderPrint(head);
//	TNode* tmp = Ch4TreesAndGraphs::find(head, 13);
//	cout << endl << "Node data: " << tmp->_data << endl;
//
//	tmp = Ch4TreesAndGraphs::next(tmp);
//	cout << "In order next: " << tmp->_data << endl;

	// END CH4

	// CH5
	// Prob 5.1
	unsigned int N = 1 << 10;
	unsigned int M = 21;
	int i = 2;
	int j = 6;
	Ch5BitManipulation::printBin(N);
	Ch5BitManipulation::printBin(M);
	unsigned int result = Ch5BitManipulation::prob5_1(N, M, i, j);
	Ch5BitManipulation::printBin(result);

	cout << endl;

	// Prob 5.2
	cout << "1.625" << endl;
	Ch5BitManipulation::prob5_2("1.625");
	cout << "3.78125" << endl;
	Ch5BitManipulation::prob5_2("3.78125");


	unsigned int num = 20;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_larger(num));

	cout << endl;

	num = 0xa0;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));
	cout << endl;
	num = 33;
	Ch5BitManipulation::printBin(num);
	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));

	cout << Ch5BitManipulation::prob5_5(31,14) << endl;
	cout << Ch5BitManipulation::prob5_5(14,31) << endl;

	cout << endl;

	Ch5BitManipulation::prob5_6(523);
	Ch5BitManipulation::prob5_6(4653);


	// END CH5


	return 0;
}

