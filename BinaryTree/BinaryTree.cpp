/*
 * BinaryTree.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Felix
 */
#include "BinaryTree.h"

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define RECURSION_DFS

BinaryTree::BinaryTree() : _root(NULL) {

}

BinaryTree::BinaryTree(int key) {
	_root = new Node(key);
}

void BinaryTree::add(int key) {
	// 2 cases
	// Root Node does not exist
	//   Make a new node as root
	// Root Node exists
	//   Compare key, right=bigger or equal, left=less
	//   Traverse down till you can add a leaf
	Node* newNode = new Node(key);
	if(NULL == _root) {
		_root = newNode;
	} else {
		Node* cur = _root;
		while (true) {
			if (key < cur->_key) {
				if (NULL == cur->_lChild) {
					cur->_lChild = newNode;
					break;
				} else {
					cur = cur->_lChild;
				}
			} else {
				if (NULL == cur->_rChild) {
					cur->_rChild = newNode;
					break;
				} else {
					cur = cur->_rChild;
				}
			}
		}
	}
}

bool BinaryTree::remove(int key) {
	// 3 cases
	// 1- Key node has no child nodes, just delete it, set parent pointing
	//    to it be NULL
	// 2- Key node has 1 child, set the parent node to point to it's child
	// 3- Key node has 2 children nodes. Pick the next biggest node to replace
	//    it
	//    Things for replacement node. Have it's parent point to NULL.
	//    The node to replace, have it' parent point to replacement node, and
	//    replacement node to point to deleted node's children
	bool removed = false;
	Node* toRemove = find(key, _root, Breadth);

	if (toRemove != NULL) {
		removed = true;
		Node* parent = findParent(toRemove);
		// Case 1: Leaf node, just need to delete and set parent to NULL
		if ((toRemove->_lChild == NULL) && (toRemove->_rChild == NULL)) {
			if (parent->_lChild == toRemove)
				parent->_lChild = NULL;
			else
				parent->_rChild = NULL;

			if (toRemove == _root)
				_root = NULL;

			delete toRemove;
		} else if ((toRemove->_lChild != NULL) && (toRemove->_rChild != NULL)) {
			// Case 2: The node to remove has 2 children. Find the next biggest
			// node to replace it with
			Node* nextBig = NULL;
			Node* nextBigParent = NULL;
			findNextBig(toRemove, nextBig, nextBigParent);

			// Remove the next big from it's parent
			if (nextBigParent->_lChild == nextBig)
				nextBigParent->_lChild = nextBig->_rChild;
			else
				nextBigParent->_rChild = NULL;

			// Point the replacement node to what the delete node points to
			// Special case if toRemove and nextBigParent are the same
			nextBig->_lChild = toRemove->_lChild;
			if (toRemove != nextBigParent) {
				nextBig->_rChild = toRemove->_rChild;
			}

			// Point the parent to the new node
			if (parent->_lChild == toRemove)
				parent->_lChild = nextBig;
			else
				parent->_rChild = nextBig;

			// Is toRemove the root node?
			if(toRemove == _root) {
				_root = nextBig;
			}

			// Finally delete the node
			delete toRemove;
		} else {
			// Case 3: The node to delete has only 1 child node. Find out which one
			Node* replacement = toRemove->_lChild;
			if (replacement == NULL)
				replacement = toRemove->_rChild;

			if (parent->_lChild == toRemove)
				parent->_lChild = replacement;
			else
				parent->_rChild = replacement;

			if (toRemove == _root)
				_root = replacement;

			delete toRemove;
		}
	}

	return removed;
}

void BinaryTree::findNextBig(Node* head, Node*& nextBig, Node*& nextBigParent) {
	// If we are in this method it is because head has 2 nodes
	// Given a head node get the right node, then try to search most left
	// If the first right has no left nodes, then it is the most left node
	nextBigParent = head;
	nextBig = head->_rChild;
	while (NULL != nextBig->_lChild) {
		nextBigParent = nextBig;
		nextBig = nextBig->_lChild;
	}
}

Node* BinaryTree::find(int key, Node* node, SEARCH s) {
	Node* rtn = NULL;
	switch(s) {
	case Breadth:
		rtn = BFSfind(key, node);
		break;
	case Depth:
		rtn = DFSfind(key, node);
		break;
	}
	return rtn;
}

Node* BinaryTree::findParent(Node* child) {
	Node* parent = _root;
	if (child != parent) {
		queue<Node *> searchQ;
		searchQ.push(_root);
		while (searchQ.empty() == false) {
			parent = searchQ.front();
			searchQ.pop();
			if (NULL == parent)
				continue;

			if (parent->_lChild == child)
				break;
			else if (parent->_rChild == child)
				break;
			searchQ.push(parent->_lChild);
			searchQ.push(parent->_rChild);
		}
	}
	return parent;
}

Node* BinaryTree::DFSfind(int key, Node* node) {
	Node* rtn = NULL;
#ifdef RECURSION_DFS
	if (NULL != node) {
		if (node->_key == key) {
			rtn = node;
		} else {
			Node* left = DFSfind(key, node->_lChild);
			Node* right =DFSfind(key, node->_rChild);

			if (NULL != left) rtn = left;
			else if (NULL != right) rtn = right;
		}
	}
#else
	stack<Node *> searchStk;
	searchStk.push(node);
	Node* cur = NULL;
	while(searchStk.empty() == false) {
		cur = searchStk.top();
		searchStk.pop();
		if (NULL == cur) continue;

		if (cur->_key == key) {
			rtn = cur;
			break;
		}
		else {
			searchStk.push(cur->_rChild);
			searchStk.push(cur->_lChild);
		}
	}
#endif

	return rtn;
}

Node* BinaryTree::BFSfind(int key, Node* node) {
	Node* rtn = NULL;
	queue<Node *> searchQ;
	searchQ.push(node);

	Node* cur = NULL;
	while (searchQ.empty() == false) {
		cur = searchQ.front();
		searchQ.pop();
		if (NULL == cur) continue;

		if (cur->_key == key) {
			rtn = cur;
			break;
		} else {
			searchQ.push(cur->_lChild);
			searchQ.push(cur->_rChild);
		}
	}

	return rtn;
}

void BinaryTree::printSearch(SEARCH s) {
	switch (s) {
	case (Breadth):
		BFSprint(_root);
		break;
	case (Depth):
		DFSprint(_root);
		break;
	}
}

void BinaryTree::BFSprint(Node* node) {
	queue<Node *> searchQ;
	searchQ.push(node);
	Node* cur = NULL;

	while (searchQ.empty() == false) {
		cur = searchQ.front();
		searchQ.pop();
		if (NULL == cur)
			continue;

		cout << cur->_key << " ";

		if (cur->_lChild != NULL) searchQ.push(cur->_lChild);
		if (cur->_rChild != NULL) searchQ.push(cur->_rChild);
	}
}

void BinaryTree::DFSprint(Node* node) {
#ifdef RECURSION_DFS
	if (NULL != node) {
		cout << node->_key << " ";
		DFSprint(node->_lChild);
		DFSprint(node->_rChild);
	}
#else
	stack<Node *> searchStk;
	searchStk.push(node);
	Node* cur = NULL;
	while(searchStk.empty() == false) {
		cur = searchStk.top();
		searchStk.pop();
		if (NULL == cur) continue;

		cout << cur->_key << " ";

		// Note: Since we're using a stack if we want to search left
		// side first, we have to push that last. In recursion we push
		// the left side first because the program doesn't execute the
		// next step until the recursive call returns
		searchStk.push(cur->_rChild);
		searchStk.push(cur->_lChild);
	}
#endif
}

int BinaryTree::minDepth(Node* node) {
	int depth = NULL;
	if (NULL != node){
		int left = minDepth(node->_lChild);
		int right = minDepth(node->_rChild);

		depth = (left < right) ? (1 + left) : (1 + right);
	}
	return depth;
}

int BinaryTree::maxDepth(Node* node) {
	int depth = NULL;
	if (NULL != node) {
		int left = maxDepth(node->_lChild);
		int right = maxDepth(node->_rChild);

		depth = (left > right) ? (1 + left) : (1 + right);
	}
	return depth;
}

bool BinaryTree::isBalanced(Node* node) {
	bool balanced = false;
	if (maxDepth(_root) - minDepth(_root) <= 1) {
		balanced = true;
	}
	return balanced;
}
