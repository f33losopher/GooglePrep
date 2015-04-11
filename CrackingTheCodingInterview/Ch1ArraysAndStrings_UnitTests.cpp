/*
 * Ch1ArraysAndStrings_UnitTests.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: Felix
 */
#include "Ch1ArraysAndStrings.h"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;

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

TEST(Ch1StringsAndArrays, prob1_1) {
	EXPECT_FALSE(Ch1ArraysAndStrings::prob1_1("FELIXLU"));
	EXPECT_TRUE(Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	EXPECT_FALSE(Ch1ArraysAndStrings::prob1_1("ABCDEFGHIJKLMNOPQRSTUVWXYZZ"));
	EXPECT_FALSE(
			Ch1ArraysAndStrings::prob1_1(
					"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"));
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

	strcpy(word, "abc");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("abc", after);

	strcpy(word, "aabc");
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

	strcpy(word, "aaaa");
	Ch1ArraysAndStrings::prob1_3(word);
	after = word;
	EXPECT_EQ("a", after);
}
TEST(Ch1StringsAndArrays, prob1_4) {
	string w1 = "Felix";
	string w2 = "lieFx";
	EXPECT_TRUE(Ch1ArraysAndStrings::prob1_4(w1, w2));

	w1 = "ABBAc";
	w2 = "BAABd";
	EXPECT_FALSE(Ch1ArraysAndStrings::prob1_4(w1, w2));

	w1 = "ABCDDDFELIX";
	w2 = "DDDBCAXIFEL";
	EXPECT_TRUE(Ch1ArraysAndStrings::prob1_4(w1, w2));
}

TEST(Ch1StringsAndArrays, prob1_5) {
	char* word = new char[50];
	string w1;
	w1 = "Test this program and see";
	Ch1ArraysAndStrings::prob1_5(w1);
	EXPECT_EQ("Test%20this%20program%20and%20see", w1);

	strcpy(word, "ab cd ef");
	Ch1ArraysAndStrings::prob1_5(word);
	EXPECT_EQ('a', word[0]);
	EXPECT_EQ('b', word[1]);
	EXPECT_EQ('%', word[2]);
	EXPECT_EQ('2', word[3]);
	EXPECT_EQ('0', word[4]);
	EXPECT_EQ('c', word[5]);
	EXPECT_EQ('d', word[6]);
	EXPECT_EQ('%', word[7]);
	EXPECT_EQ('2', word[8]);
	EXPECT_EQ('0', word[9]);
	EXPECT_EQ('e', word[10]);
	EXPECT_EQ('f', word[11]);

	strcpy(word, "Felix Lu Vivian Nguyen ");
	Ch1ArraysAndStrings::prob1_5(word);
	EXPECT_EQ('F', word[0]);
	EXPECT_EQ('e', word[1]);
	EXPECT_EQ('l', word[2]);
	EXPECT_EQ('i', word[3]);
	EXPECT_EQ('x', word[4]);
	EXPECT_EQ('%', word[5]);
	EXPECT_EQ('2', word[6]);
	EXPECT_EQ('0', word[7]);
	EXPECT_EQ('L', word[8]);
	EXPECT_EQ('u', word[9]);
	EXPECT_EQ('%', word[10]);
	EXPECT_EQ('2', word[11]);
	EXPECT_EQ('0', word[12]);
	EXPECT_EQ('V', word[13]);
	EXPECT_EQ('i', word[14]);
	EXPECT_EQ('v', word[15]);
	EXPECT_EQ('i', word[16]);
	EXPECT_EQ('a', word[17]);
	EXPECT_EQ('n', word[18]);
	EXPECT_EQ('%', word[19]);
	EXPECT_EQ('2', word[20]);
	EXPECT_EQ('0', word[21]);
	EXPECT_EQ('N', word[22]);
	EXPECT_EQ('g', word[23]);
	EXPECT_EQ('u', word[24]);
	EXPECT_EQ('y', word[25]);
	EXPECT_EQ('e', word[26]);
	EXPECT_EQ('n', word[27]);
	EXPECT_EQ('%', word[28]);
	EXPECT_EQ('2', word[29]);
	EXPECT_EQ('0', word[30]);

	strcpy(word, "   ");
	Ch1ArraysAndStrings::prob1_5(word);
	EXPECT_EQ('%', word[0]);
	EXPECT_EQ('2', word[1]);
	EXPECT_EQ('0', word[2]);
	EXPECT_EQ('%', word[3]);
	EXPECT_EQ('2', word[4]);
	EXPECT_EQ('0', word[5]);
	EXPECT_EQ('%', word[6]);
	EXPECT_EQ('2', word[7]);
	EXPECT_EQ('0', word[8]);
}

TEST(Ch1StringsAndArrays, prob1_6) {

	int dim = 10;
	int matrix[dim][dim];
	for (int r=0; r < dim; r++) {
		for (int c=0; c < dim; c++) {
			matrix[r][c] =(r*10 + c);
		}
	}

	int** mPtr = new int*[dim];
	for (int r=0; r<dim; ++r) {
		mPtr[r] = &(matrix[r][0]);
	}
	pMatrix(mPtr, dim);
	Ch1ArraysAndStrings::prob1_6(mPtr, dim);
	pMatrix(mPtr, dim);
}

TEST(Ch1StringsAndArrays, prob1_7) {
	int M = 15;
	int N = 20;
	int mtx[M][N];
	srand(1);
	for (int r=0; r<M; ++r) {
		for (int c=0; c<N; ++c) {
			mtx[r][c] = rand() % 50;
		}
	}
	int** mPtr = new int*[M];
	for(int r=0; r<M; ++r) {
		mPtr[r] = &(mtx[r][0]);
	}

	pMatrix(mPtr, M, N);
	Ch1ArraysAndStrings::prob1_7(mPtr, M, N);
	pMatrix(mPtr, M, N);
}
