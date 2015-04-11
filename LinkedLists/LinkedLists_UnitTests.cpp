/*
 * Test.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Felix
 */

#include "Node.h"
#include <stdexcept>
#include <iostream>

#include "gtest/gtest.h"
using namespace std;

// 1 - count()
int Count(Node* head, int searchFor) {
	int hits = 0;
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if (searchFor == cur->data)
			hits++;
	}
	return hits;
}
int CountTest(int searchFor) {
	Node* head = Node::BuildRandom(30);
	int count = Count(head, searchFor);
//	Node::print(head);
	return count;
}

// 2 GetNth()
int GetNth(Node* head, int index) {
	Node* cur = head;
	for (int i = 0; i < index; i++) {
		if (cur != NULL) {
			cur = cur->next;
		} else {
			break;
		}
	}
	if (NULL == cur) {
		throw range_error("Index out of range");
	}

	return cur->data;
}
int GetNthTest(int ind) {
	Node* myList = Node::BuildRandom(10);
//	Node::print(myList);
	int data = 0;

	try {
		data = GetNth(myList, ind);
//		cout << "Data: " << data << endl;
	} catch (std::range_error& oor) {
		cout << "Out of range: " << oor.what() << endl;
	} catch (...) {
		cout << "In ..." << endl;
	}
	return data;
}

// 3 DeleteList()
void DeleteList(Node*& headRef) {
	if (NULL != headRef) {
		Node* cur = headRef;
		Node* next = cur->next;

		// When next is NULL, it means cur is on the last node
		while (NULL != next) {
			delete cur;
			cur = next;
			next = cur->next;
		}
		delete cur;
	}

	headRef = NULL;
}
void DeleteListTest(Node* list) {
	DeleteList(list);
}

// 4 Pop()
int Pop(Node*& headRef) {
	int data = 0;
	if (NULL == headRef) {
		throw runtime_error("Nothing to pop");
	} else {
		Node* next = headRef->next;
		data = headRef->data;
		delete headRef;
		headRef = next;
	}
	return data;
}

TEST(LinkedList, Count) {
	EXPECT_EQ(4, CountTest(9));

}
TEST(LinkedList, getNth) {
	EXPECT_EQ(12, GetNthTest(3));
}
TEST(LinkedList, Delete) {
	Node* myList = Node::BuildRandom(10);
	// TODO How to test pointer??
//	EXPECT_NE(NULL, myList);
	EXPECT_EQ(myList->length(myList), 10);

	DeleteListTest(myList);
	// TODO How to test pointer??
//	EXPECT_EQ(NULL, myList);
}
TEST(LinkedList, Pop) {
	Node* head = Node::BuildRandom(10);
//	Node::print(head);

	int len = Node::length(head);
	EXPECT_EQ(10, len);

	int a = Pop(head);
	int b = Pop(head);
	int c = Pop(head);
	int d = Pop(head);

	EXPECT_EQ(a,19);
	EXPECT_EQ(b,16);
	EXPECT_EQ(c,16);
	EXPECT_EQ(d,12);

	len = Node::length(head);
	EXPECT_EQ(6, len);
}
