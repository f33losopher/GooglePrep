/*
 * Ch4TreesAndGraphs.h
 *
 *  Created on: Mar 15, 2015
 *      Author: Felix
 */

#ifndef CH4TREESANDGRAPHS_H_
#define CH4TREESANDGRAPHS_H_

#include <string>

class LinkedList;

namespace Ch4TreesAndGraphs {

	typedef struct Node {
		Node(int data) : _data(data), _left(NULL), _right(NULL) {}
		int _data;
		Node* _left;
		Node* _right;
	} Node;

	void bfsPrint(Node* head);
	void preOrderPrint(Node* head);
	int maxDepth(Node* node);

	/* Prob 4.3
	 * Given a sorted (increasing order) array, write an algorithm to create
	 * a binary tree with minimal height
	 */
	Node* createBTfromSortedArray(int* sArray, int size);
	Node* createBTfromSortedArray(int* sArray, int sIdx, int eIdx);

	/*Prob 4.3
	 * Given a binary search tree, design an algorithm which creates linked
	 * lists of all the nodes at each depth. (ie If you have a tree with depth
	 * D, you'll have D linked lists)
	 */
	LinkedList** listsFromDepth(Node* bstHead);
}


#endif /* CH4TREESANDGRAPHS_H_ */
