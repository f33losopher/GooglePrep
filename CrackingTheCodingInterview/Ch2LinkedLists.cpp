/*
 * Ch2LinkedLists.cpp
 *
 *  Created on: Mar 14, 2015
 *      Author: Felix
 */
#include "Ch2LinkedLists.h"

#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;
typedef LinkedList::Node Node;

LinkedList::LinkedList() :_head(NULL) {

}

void LinkedList::print() {
	Node* cur = _head;
	while (cur != NULL) {
		cout << cur->_data << "->";
		cur = cur->_next;
	}
	cout << "NULL" << endl;
}

void LinkedList::add(int d) {
	Node* end = new Node(d);
	Node* cur = _head;

	// If it's empty, make it the first node
	if (cur == NULL) {
		_head = end;
	} else {
		while (cur->_next != NULL) {
			cur = cur->_next;
		}
		cur->_next = end;
	}
}

Node* LinkedList::at(int idx) {
	if (_head == NULL)
		return NULL;

	Node* cur = _head;
	for (int i=0; i < idx; ++i) {
		if (cur == NULL)
			break;
		cur = cur->_next;
	}
	return cur;
}

void LinkedList::removeDups() {
	if ((_head == NULL) || (_head->_next == NULL))
		return;

	set<Node, cmpNode> dups;
	dups.insert(*_head);

	Node* prev = _head;
	Node* cur = _head->_next;
	while (cur != NULL) {
		if(dups.find(*cur) != dups.end()) {
			prev->_next = cur->_next;
			delete cur;
			cur = prev->_next;
			continue;
		} else {
			dups.insert(*cur);
			prev = cur;
			cur = cur->_next;
		}
	}
}

Node* LinkedList::nthToLast(unsigned int n) {
	Node* rtn = NULL;
	stack<Node*> ptrS; // Node* stack
	Node* cur = _head;
	while (cur != NULL) {
		ptrS.push(cur);
		cur = cur->_next;
	}

	// Define n=2 (2nd to last) as 1 from the last
	// n=1 the last one
	while(--n>0 && ptrS.size() > 0) {
		ptrS.pop();
	}
	if (!ptrS.empty())
		rtn = ptrS.top();
	return rtn;
}

const Node* LinkedList::nthToLast(const Node* const node, unsigned int n, unsigned int* stkCnt) const {
	if (node == NULL)
		return NULL;

	const Node* const rtn = nthToLast(node->_next, n, stkCnt);
	if(++(*stkCnt) == n)
		return node;

	return rtn;
}

void LinkedList::removeMiddleNode(Node* node) {
	Node* oldNext = node->_next;
	node->_data = oldNext->_data;
	node->_next = oldNext->_next;

	delete oldNext;
}

LinkedList* LinkedList::rAdd(LinkedList* lhs, LinkedList* rhs) {
	int carry = 0;
	const Node* const n1 = lhs->head();
	const Node* const n2 = rhs->head();
	LinkedList* newList = new LinkedList();

	int sum = n1->_data + n2->_data;
	carry = ((sum / 10) % 10);
	sum = (sum % 10);
	newList->add(sum);
	Node* next1 = n1->_next;
	Node* next2 = n2->_next;
	while (next1 != NULL && next2 != NULL) {
		sum = next1->_data + next2->_data + carry;
		carry = ((sum/10) % 10);
		sum = (sum % 10);
		newList->add(sum);
		next1 = next1->_next;
		next2 = next2->_next;
	}
	return newList;
}

Node* LinkedList::findBeginning(Node* head) {
	// Have ptr1 and ptr1 start at head
	// ptr1 travels in n increments, ptr2 and 2n increments
	// When ptr reaches the start of the loop, ptr2 will be k steps ahead
	// We know they will meet again k steps before the start
	// Now reset ptr1 to head
	// Increment both ptr1 and ptr2 by n steps
	// They will meet at the start

	return NULL;

}
