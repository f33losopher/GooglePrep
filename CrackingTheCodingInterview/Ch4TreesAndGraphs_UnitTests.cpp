/*
 * Ch4TreesAndGraphs_UnitTests.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: Felix
 */

#include "Ch4TreesAndGraphs.h"
#include "Ch2LinkedLists.h"
#include "gtest/gtest.h"

#include <iostream>
using namespace std;

typedef Ch4TreesAndGraphs::Node TNode;

TEST(Ch4TreesAndGraphs, test) {
	int size = 20;
	int* sortedArray = new int[size];
	for (int i=0; i < size; i++) {
		sortedArray[i] = i;
	}

	TNode* head = Ch4TreesAndGraphs::createBTfromSortedArray(sortedArray, 0, size - 1);
	Ch4TreesAndGraphs::bfsPrint(head);

	head = Ch4TreesAndGraphs::createBTfromSortedArray(sortedArray, size);
	Ch4TreesAndGraphs::bfsPrint(head);

	int depth = Ch4TreesAndGraphs::maxDepth(head);
	cout << "Depth: " << depth << endl;

	LinkedList** llists = Ch4TreesAndGraphs::listsFromDepth(head);
	for (int i=0; i < depth; i++) {
		llists[i]->print();
	}


	cout << "In order print\n";
	Ch4TreesAndGraphs::inOrderPrint(head);
	TNode* tmp = Ch4TreesAndGraphs::find(head, 13);
	cout << endl << "Node data: " << tmp->_data << endl;

	tmp = Ch4TreesAndGraphs::next(tmp);
	cout << "In order next: " << tmp->_data << endl;
}
