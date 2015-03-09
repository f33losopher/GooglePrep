/*
 * BinaryTree.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Felix
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <string>

struct Node {
	Node(int key) : _key(key), _lChild(0), _rChild(0) {}
	~Node() {}

	int _key;
	Node* _lChild;
	Node* _rChild;
};

class BinaryTree {
public:
	enum SEARCH {
		Breadth,
		Depth
	};

	// Constructor, _root=NULL
	BinaryTree();

	// Constructor, _root = key
	BinaryTree(int key);

	// Adds a new Node given key
	void add(int key);

	// Removes the Node given key. True on remove, False if DNE
	bool remove(int key);

	// Returns a Node* given the key. Returns NULL if key DNE
	Node* find(int key, Node* node, SEARCH s);

	// Returns the Parent node given a child node
	Node* findParent(Node* child);

	void printSearch(SEARCH s);

	int minDepth(Node* node);
	int maxDepth(Node* node);
	bool isBalanced(Node* node);

	inline Node* root() { return _root; }

private:
	// Prints Depth First Search
	void DFSprint(Node* node);

	// Prints Breadth First Search
	void BFSprint(Node* node);

	// Returns Node* given key using Depth First Search
	Node* DFSfind(int key, Node* node);

	// Returns Node* given key using Breadth First Search
	Node* BFSfind(int key, Node* node);

	void findNextBig(Node* head, Node*& nextBig, Node*& nextBigParent);

	Node* _root;
};


#endif /* BINARYTREE_H_ */
