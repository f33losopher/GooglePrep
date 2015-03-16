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
	unsigned int partition = 128;
	int numSpaces = 100;
	while(!printQ.empty()) {
		for (unsigned int i=0; i < rowPrint; ++i) {
			if (printQ.empty())
				break;

			node = printQ.front();
			printQ.pop();
			partition = (numSpaces + rowPrint + rowPrint) / (rowPrint + 1);
			char format[50];
			format[0] = '%';
			sprintf(&format[1], "%dd", partition);

			if (node != NULL)
				printf(format, node->_data);
			else
				printf(format, -1);
		}
		cout << endl;
		rowPrint <<= 1;
	}
}

void Ch4TreesAndGraphs::preOrderPrint(Node* head) {
	if (head == NULL)
		return;
	cout << head->_data << " ";
	preOrderPrint(head->_left);
	preOrderPrint(head->_right);
	cout << endl;
}

int Ch4TreesAndGraphs::maxDepth(Node* node) {
	if (node == NULL)
		return 0;

	int left = maxDepth(node->_left);
	int right = maxDepth(node->_right);

	return 1 + ((left > right) ? left:right);
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

	return node;
}

Node* Ch4TreesAndGraphs::createBTfromSortedArray(int* sArray, int sIdx, int eIdx) {
	if (sIdx > eIdx)
		return NULL;

	int mid = (sIdx + eIdx) / 2;
	Node* node = new Node(sArray[mid]);
	node->_left = createBTfromSortedArray(sArray, sIdx, mid - 1);
	node->_right = createBTfromSortedArray(sArray, mid + 1, eIdx);

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

