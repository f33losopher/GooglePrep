/*
 * Test.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Felix
 */

#include "Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// 1 - count()
int Count(Node* head, int searchFor) {
	int hits = 0;
	for (Node* cur = head; cur != NULL; cur = cur->next) {
		if(searchFor == cur->data) hits++;
	}
	return hits;
}
void CountTest() {
	int searchFor = 9;
	Node* head = Node::BuildRandom(30);
	int count = Count(head, searchFor);
	Node::print(head);
	cout <<"Found (" << searchFor << ") " << count << " times" << endl;
}

// 2 GetNth()
int GetNth(Node* head, int index) {
	Node* cur = head;
	for(int i=0; i < index; i++) {
		if(cur != NULL) {
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
void GetNthTest() {
	Node* myList = Node::BuildRandom(10);
	Node::print(myList);

	try {
		int data = GetNth(myList, 10);
		cout << "Data: " << data << endl;
	} catch (std::range_error& oor) {
		cout << "Out of range: " << oor.what() << endl;
	} catch(...) {
		cout << "In ..." << endl;
	}
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
void DeleteListTest() {
	Node* myList = Node::BuildRandom(10);
	cout << "myList address: " << myList << endl;

	DeleteList(myList);
	cout << "myList address: " << myList << endl;
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
void PopTest() {
	Node* head = Node::BuildRandom(10);
	Node::print(head);

	int len = Node::length(head);
	cout << "Length: " << len << endl;

	try {
		int a = Pop(head);
		int b = Pop(head);
		int c = Pop(head);
		int d = Pop(head);

		len = Node::length(head);
		cout << "Length: " << len << endl;

		cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
	} catch (runtime_error& e) {
		cout << e.what() << endl;
	}


}


int main () {
//	CountTest();
//	GetNthTest();
//	DeleteListTest();
	PopTest();

	return 0;
}

