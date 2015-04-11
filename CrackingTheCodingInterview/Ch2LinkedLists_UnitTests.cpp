/*
 * Ch2LinkedLists_UnitTests.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: Felix
 */
#include "Ch2LinkedLists.h"


#include "gtest/gtest.h"


#include <iostream>
using namespace std;

typedef LinkedList::Node LNode;

TEST(Ch2LinkedLists, prob2_1) {
	// Prob 2.1
	LinkedList* LList = new LinkedList();
	srand(1);
	for (int i = 0; i < 40; ++i) {
		LList->add(rand() % 10);
	}
	LList->print();
	LList->removeDups();
	LList->print();
}

TEST(Ch2LinkedLists, prob2_2) {
	LinkedList* LList = new LinkedList();
	srand(1);
	for (int i = 0; i < 10; ++i) {
		LList->add(rand() % 10);
	}
	LList->print();
	EXPECT_EQ(9, LList->nthToLast(1)->_data);
	EXPECT_EQ(6, LList->nthToLast(2)->_data);
	EXPECT_EQ(6, LList->nthToLast(3)->_data);

	unsigned int * stkCnt = new unsigned int;
	*stkCnt = 0;
	EXPECT_EQ(9, LList->nthToLast(LList->head(), 1, stkCnt)->_data);
	*stkCnt = 0;
	EXPECT_EQ(6, LList->nthToLast(LList->head(), 2, stkCnt)->_data);
	*stkCnt = 0;
	EXPECT_EQ(6, LList->nthToLast(LList->head(), 3, stkCnt)->_data);
}

TEST(Ch2LinkedLists, prob2_3) {
	LinkedList* LList = new LinkedList();
	srand(1);
	for (int i = 0; i < 10; ++i) {
		LList->add(rand() % 10);
	}

	LList->print();
	LNode* tmp = LList->at(2);
	LList->removeMiddleNode(tmp);
	LList->print();
}

TEST(Ch2LinkedLists, prob2_4) {
	LinkedList* list1 = new LinkedList();
	LinkedList* list2 = new LinkedList();
	list1->add(8);
	list1->add(4);
	list1->add(5);
	list2->add(5);
	list2->add(9);
	list2->add(2);
	LinkedList* sum = LinkedList::rAdd(list1, list2);
	list1->print();
	list2->print();
	sum->print();
}
