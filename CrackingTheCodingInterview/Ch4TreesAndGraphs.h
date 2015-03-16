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
		Node(int data) : _data(data), _parent(NULL), _left(NULL), _right(NULL) {}
		int _data;
		Node* _parent;
		Node* _left;
		Node* _right;
	} Node;

	void bfsPrint(Node* head);
	void preOrderPrint(Node* head);
	void inOrderPrint(Node* head);
	int maxDepth(Node* node);
	int minDepth(Node* node);
	Node* find(Node* node, int data);

	/* Prob 4.1
	 * Implement a function to check if a tree is balanced. For the purposes of this question,
	 * a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
	 * from the root by more than 1
	 */
	// Just take maxDepth(node) - minDepth(node) >= 1




	/* Prob 4.3
	 * Given a sorted (increasing order) array, write an algorithm to create
	 * a binary tree with minimal height
	 */
	Node* createBTfromSortedArray(int* sArray, int size);
	Node* createBTfromSortedArray(int* sArray, int sIdx, int eIdx);

	/*Prob 4.4
	 * Given a binary search tree, design an algorithm which creates linked
	 * lists of all the nodes at each depth. (ie If you have a tree with depth
	 * D, you'll have D linked lists)
	 */
	LinkedList** listsFromDepth(Node* bstHead);

	/* Prob 4.5
	 * Write an algorithm to find the 'next' node (ie in order successor) of a given
	 * node in a binary search tree where each node has a link to it's parent.
	 */
	Node* next(Node* node, Node* child = NULL);
}


#endif /* CH4TREESANDGRAPHS_H_ */
