/*
 * Ch4TreesAndGraphs.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */
#include "Ch4TreesAndGraphs.h"
#include "Ch2LinkedLists.h"
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

typedef Ch4TreesAndGraphs::Node Node;

void Ch4TreesAndGraphs::bfsPrint(Node* head) {
	queue<Node*> Q;
	Q.push(head);

	queue<Node*> printQ;

	Node* node;
	while(!Q.empty()) {
		node = Q.front();
		Q.pop();

		printQ.push(node);

		if (node != NULL)
			Q.push(node->_left);
		if (node != NULL)
			Q.push(node->_right);
	}

	// Number of elements to print on each row
	unsigned int rowPrint = 1;
	unsigned int partition = 0;
	unsigned int printSpace = 128;
	unsigned int divisor = 2;
	unsigned int addToDivisor = 1;
	char format[50];
	char format2[50];
	format[0] = '%';
	format2[0] = '%';
	while (!printQ.empty()) {
		for (unsigned int i = 0; i < rowPrint; ++i) {
			if (printQ.empty())
				break;

			node = printQ.front();
			printQ.pop();
//			partition = (numSpaces + rowPrint + rowPrint) / (rowPrint + 1);
			partition = printSpace / (divisor);

			sprintf(&format[1], "%dd", partition);
			sprintf(&format2[1], "%dc", partition);

			if (node != NULL)
				printf(format, node->_data);
			else
				printf(format2, ' ');
		}
		cout << endl << endl;
		rowPrint <<= 1;
		divisor += addToDivisor;
		printSpace += addToDivisor;
		addToDivisor <<= 1;
	}
}

void Ch4TreesAndGraphs::preOrderPrint(Node* head) {
	if (head == NULL)
		return;
	cout << head->_data << " ";
	preOrderPrint(head->_left);
	preOrderPrint(head->_right);
}

void Ch4TreesAndGraphs::inOrderPrint(Node* head) {
	if(head == NULL)
		return;

	inOrderPrint(head->_left);
	cout << head->_data << " ";
	inOrderPrint(head->_right);
}

int Ch4TreesAndGraphs::maxDepth(Node* node) {
	if (node == NULL)
		return 0;

	int left = maxDepth(node->_left);
	int right = maxDepth(node->_right);

	return 1 + ((left > right) ? left:right);
}

int Ch4TreesAndGraphs::minDepth(Node* node) {
	if (node == NULL)
		return 0;
	int left = minDepth(node->_left);
	int right = minDepth(node->_right);

	return 1 + ((left < right) ? left:right);
}

Node* Ch4TreesAndGraphs::find(Node* node, int data) {
	Node* rtn = NULL;
	if (node == NULL)
		return NULL;
	else if(node->_data == data)
		rtn = node;
	else {
		Node* l = find(node->_left, data);
		Node* r = find(node->_right, data);
		if (l != NULL && l->_data == data)
			rtn = l;
		else if (r != NULL && r->_data == data)
			rtn = r;
	}

	return rtn;
}

Node* Ch4TreesAndGraphs::createBTfromSortedArray(int* array, int size) {
	if (size <= 0)
		return NULL;

	int sIdx = 0;
	int eIdx = size - 1;
	int mid = (sIdx + eIdx) / 2;

	Node* node = new Node(array[mid]);
	int* left = &array[0];
	int* right = &array[mid+1];
	node->_left = createBTfromSortedArray(left, (mid-1) - sIdx + 1);
	node->_right = createBTfromSortedArray(right, eIdx - (mid+1) + 1);
	if (node->_left != NULL)
		node->_left->_parent = node;
	if (node->_right != NULL)
		node->_right->_parent = node;

	return node;
}

Node* Ch4TreesAndGraphs::createBTfromSortedArray(int* sArray, int sIdx, int eIdx) {
	if (sIdx > eIdx)
		return NULL;

	int mid = (sIdx + eIdx) / 2;
	Node* node = new Node(sArray[mid]);
	node->_left = createBTfromSortedArray(sArray, sIdx, mid - 1);
	node->_right = createBTfromSortedArray(sArray, mid + 1, eIdx);
	if (node->_left != NULL)
		node->_left->_parent = node;
	if (node->_right != NULL)
		node->_right->_parent = node;

	return node;
}

LinkedList** Ch4TreesAndGraphs::listsFromDepth(Node* bstHead) {
	// First find the depth of the tree
	int depth = maxDepth(bstHead);
	LinkedList** lists = new LinkedList*[depth];
	for (int i=0; i < depth; ++i)
		lists[i] = new LinkedList();

	// Do a BFS grabbing all elements including NULL
	queue<Node*> nodeQ;

	// toAdd multiplied by 2 at each level, includes NULLS and elements
	int toAdd = 1;
	int added = 0;
	int llIdx = 0;

	nodeQ.push(bstHead);
	while(!nodeQ.empty()) {
		Node* node = nodeQ.front();
		nodeQ.pop();

		if (added < toAdd) {
			++added;
		} else {
			added = 1;
			toAdd <<= 1;
			++llIdx;
		}

		// llIdx controlled by (added < toAdd)
		if (node != NULL) {
			lists[llIdx]->add(node->_data);
			nodeQ.push(node->_left);
			nodeQ.push(node->_right);
		}
	}

	return lists;
}

Node* Ch4TreesAndGraphs::next(Node* node, Node* child) {
	Node* rtn = NULL;

	// Need to guard against going up the parent and then going right
	// back down the right path
	if(node->_right != NULL && node->_right != child) {
		rtn = node->_right;
		while (rtn->_left != NULL)
			rtn = rtn->_left;
	} else {
		Node* parent = node->_parent;
		if (parent->_left == node)
			rtn = parent;
		else
			rtn = next(parent, node);
	}

	return rtn;
}
