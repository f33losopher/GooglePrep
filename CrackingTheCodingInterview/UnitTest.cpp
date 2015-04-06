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
#include "Ch8Recursion.h"
#include "Ch19Moderate.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "gtest/gtest.h"

#include <iostream>
using namespace std;

typedef LinkedList::Node LNode;
typedef Ch4TreesAndGraphs::Node TNode;

typedef Moderate::ticTacToe ticTacToe;

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

void clearTTTgrid(ticTacToe** grid) {
	for(int row=0; row < 3; ++row) {
		for(int col=0; col < 3; ++col) {
			grid[row][col] = Moderate::EMPTY;
		}
	}
}

void printTTTGrid(ticTacToe** grid) {
	for(int r=0; r<3; ++r) {
		for(int c=0; c<3; ++c) {
			if(grid[r][c] == Moderate::X)      { cout << "X "; }
			else if(grid[r][c] == Moderate::O) { cout << "O "; }
			else { cout << "  "; }
		}
		cout << endl;
	}
}

TEST(Ch1StringsAndArrays, prob1_1) {
	EXPECT_EQ(false, Ch1ArraysAndStrings::prob1_1("FELIXLU"));
	EXPECT_EQ(true, Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	EXPECT_EQ(false, Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZZ"));
	EXPECT_EQ(false, Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}
TEST(Ch1StringsAndArrays, prob1_2) {
	char* word = new char[50];

	strcpy(word, "abcdefg");
	Ch1ArraysAndStrings::prob1_2(word);
	string after(word);
	EXPECT_EQ("gfedcba", after);

	strcpy(word, "FelixLuIsGreat!");
	Ch1ArraysAndStrings::prob1_2(word);
	after = word;
	EXPECT_EQ("!taerGsIuLxileF", after);
}
TEST(Ch1StringsAndArrays, prob1_3) {
	char* word = new char[50];
	string after;

	strcpy(word,"abc");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("abc", after);

	strcpy(word,"aabc");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("abc", after);

	strcpy(word, "abbc");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("abc", after);

	strcpy(word, "abcc");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("abc", after);

	strcpy(word,"aaaa");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("a", after);
}
TEST(Ch1StringsAndArrays, prob1_4) {
	string w1 = "Felix";
	string w2 = "lieFx";
	EXPECT_EQ(true, Ch1ArraysAndStrings::prob1_4(w1,w2));

	w1 = "ABBAc";
	w2 = "BAABd";
	EXPECT_EQ(false, Ch1ArraysAndStrings::prob1_4(w1,w2));

	w1 = "ABCDDDFELIX";
	w2 = "DDDBCAXIFEL";
	EXPECT_EQ(true, Ch1ArraysAndStrings::prob1_4(w1,w2));
}


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
//	// END CH1
//
//	// CH2
//
//	// Prob 2.1
//	LinkedList* LList = new LinkedList();
//	srand(1);
//	for (int i = 0; i < 40; ++i) {
//		LList->add(rand() % 10);
//	}
//	LList->print();
//	LList->removeDups();
//	LList->print();

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
//	// Prob 5.1
//	unsigned int N = 1 << 10;
//	unsigned int M = 21;
//	int i = 2;
//	int j = 6;
//	Ch5BitManipulation::printBin(N);
//	Ch5BitManipulation::printBin(M);
//	unsigned int result = Ch5BitManipulation::prob5_1(N, M, i, j);
//	Ch5BitManipulation::printBin(result);
//
//	cout << endl;
//
//	// Prob 5.2
//	cout << "1.625" << endl;
//	Ch5BitManipulation::prob5_2("1.625");
//	cout << "3.78125" << endl;
//	Ch5BitManipulation::prob5_2("3.78125");
//
//
//	unsigned int num = 20;
//	Ch5BitManipulation::printBin(num);
//	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_larger(num));
//
//	cout << endl;
//
//	num = 0xa0;
//	Ch5BitManipulation::printBin(num);
//	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));
//	cout << endl;
//	num = 33;
//	Ch5BitManipulation::printBin(num);
//	Ch5BitManipulation::printBin(Ch5BitManipulation::prob5_3_smaller(num));
//
//	cout << Ch5BitManipulation::prob5_5(31,14) << endl;
//	cout << Ch5BitManipulation::prob5_5(14,31) << endl;
//
//	cout << endl;
//
//	Ch5BitManipulation::prob5_6(523);
//	Ch5BitManipulation::prob5_6(4653);
//
//	// END CH5
//
//	cout << endl;
//
//
//	// CH8
//	cout << "7th fibonacci number:  " << Ch8Recursion::prob8_1(5) << endl;
//	cout << "10th fibonacci number: " << Ch8Recursion::prob8_1(10) << endl;
//	cout << "30th fibonacci number: " << Ch8Recursion::prob8_1(30) << endl;
//
//	cout << endl;
//
//	int gridDim = 10;
//	// Make the NxN grid
//	int** grid = new int*[gridDim];
//	for (int i=0; i < gridDim; ++i) {
//		grid[i] = new int[gridDim];
//	}
//
//	// Initialize grid to all 1's, meaning can walk on the square
//	for (int r=0; r<gridDim; ++r) {
//		for (int c=0; c<gridDim; ++c) {
//			grid[r][c] = 1;
//		}
//	}
//
//	cout << "Number of paths to (9,9): ";
//	cout << Ch8Recursion::prob8_2(grid, gridDim, 9, 9, 0, 0) << endl;
//
//	cout << endl;
//
//	string perm = "ABC";
//	set<string> perms;
//	Ch8Recursion::prob8_4(perm, 0, perms);
//
//	cout << endl;
//
//	Ch8Recursion::prob8_5(3);

	// END CH8

TEST(Ch19_Moderate, prob19_1) {
	int x = 5;
	int y = 33;

	Moderate::prob19_1(x,y);
	EXPECT_EQ(x, 33);
	EXPECT_EQ(y, 5);
}

TEST(Ch19_Moderate, prob19_2) {
	ticTacToe** grid = new ticTacToe*[3];
	for (int i=0; i < 3; ++i) {
		grid[i] = new ticTacToe[3];
	}
	clearTTTgrid(grid);

	// Situation 1
	// x _ _
	// o o _
	// x _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[1][1] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_EQ(false, Moderate::prob19_2(grid, Moderate::X));
	EXPECT_EQ(false, Moderate::prob19_2(grid, Moderate::O));

	// Situation 2
	// x _ _
	// o o o
	// x _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[1][1] = Moderate::O;
	grid[1][2] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_EQ(false, Moderate::prob19_2(grid, Moderate::X));
	EXPECT_EQ(true, Moderate::prob19_2(grid, Moderate::O));

	// Situation 3
	// x _ _
	// o x _
	// o _ x
	clearTTTgrid(grid);
	grid[0][0] = Moderate::X;
	grid[1][1] = Moderate::X;
	grid[2][2] = Moderate::X;
	grid[1][0] = Moderate::O;
	grid[2][0] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_EQ(true, Moderate::prob19_2(grid, Moderate::X));
	EXPECT_EQ(false, Moderate::prob19_2(grid, Moderate::O));

	// Situation 4
	// _ _ x
	// _ x _
	// x o o
	clearTTTgrid(grid);
	grid[0][2] = Moderate::X;
	grid[1][1] = Moderate::X;
	grid[2][0] = Moderate::X;
	grid[2][1] = Moderate::O;
	grid[2][2] = Moderate::O;
//	printTTTGrid(grid);
	EXPECT_EQ(true, Moderate::prob19_2(grid, Moderate::X));
	EXPECT_EQ(false, Moderate::prob19_2(grid, Moderate::O));
}

TEST(Ch19_Moderate, prob19_3) {
	EXPECT_EQ(Moderate::prob19_3(4), 0);
	EXPECT_EQ(Moderate::prob19_3(5), 1);
	EXPECT_EQ(Moderate::prob19_3(9), 1);
	EXPECT_EQ(Moderate::prob19_3(10), 2);
	EXPECT_EQ(Moderate::prob19_3(15), 3);
	EXPECT_EQ(Moderate::prob19_3(20), 4);
	EXPECT_EQ(Moderate::prob19_3(25), 6);
	EXPECT_EQ(Moderate::prob19_3(50), 12);
	EXPECT_EQ(Moderate::prob19_3(125), 31);
}

TEST(Ch19_Moderate, prob19_4) {
	EXPECT_EQ(Moderate::prob19_4(3,4), 4);
	EXPECT_EQ(Moderate::prob19_4(10,20), 20);
	EXPECT_EQ(Moderate::prob19_4(10,10), 10);
	EXPECT_EQ(Moderate::prob19_4(-1,1), 1);
	EXPECT_EQ(Moderate::prob19_4(-12,-18), -12);
}


TEST(Ch19_Moderate, prob19_5) {
	int hits;
	int pseudoHits;
	Moderate::prob19_5("RGGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 2);
	EXPECT_EQ(pseudoHits, 1);

	Moderate::prob19_5("BRGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 3);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("YRGB", "YRGB", hits, pseudoHits);
	EXPECT_EQ(hits, 4);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("RRGG", "BBYY", hits, pseudoHits);
	EXPECT_EQ(hits, 0);
	EXPECT_EQ(pseudoHits, 0);

	Moderate::prob19_5("RGYB", "BYGR", hits, pseudoHits);
	EXPECT_EQ(hits, 0);
	EXPECT_EQ(pseudoHits, 4);

	Moderate::prob19_5("RRRR", "BYGR", hits, pseudoHits);
	EXPECT_EQ(hits, 1);
	EXPECT_EQ(pseudoHits, 0);
}
