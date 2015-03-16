/*
 * Ch2LinkedLists.h
 *
 *  Created on: Mar 14, 2015
 *      Author: Felix
 */

#ifndef CH2LINKEDLISTS_H_
#define CH2LINKEDLISTS_H_
#include <string>

class LinkedList {
public:
	typedef struct Node {
		Node(int data) : _data(data), _next(NULL) {}
		int _data;
		Node* _next;
	} Node;

	struct cmpNode {
		bool operator()(const Node& lhs, const Node& rhs) {
			return (lhs._data < rhs._data);
		}
	};

	LinkedList();

	inline const Node* const head() { return _head; }

	void print();
	void add(int d);
	Node* at(int idx);

	/* Prob 2.1 Write code to remove duplicates from an unsorted linked list
	 * FOLLOW UP: How would you solve this problem if a temporary buffer is
	 * not allowed
	 */
	void removeDups();

	/* Prob 2.2 Implement an algorithm to find the nth to last element of a
	 * singly linked list
	 */
	Node* nthToLast(unsigned int n);
	// Uses recursion
	const Node* nthToLast(const Node* const node, unsigned int n, unsigned int* stkCnt) const;

	/* Implement an algorithm to delete a node in the middle of a single,
	 * linked list, given only access to that node
	 * EXAMPLE
	 * Input: the node 'c' from the linked list a->b->c->d->e
	 * Result: nothing is returned, but the new linked list looks like
	 * a->b->d->e
	 */
	void removeMiddleNode(Node* node);

	/* You have two numbers represented by a linked list, ,where each node
	 * contains a single digit. The digits are stored in reverse order, such
	 * that the 1's digit is at the head of the list. Write a function that
	 * adds the two numbers and returns the sum as a linked list.
	 */
	static LinkedList* rAdd(LinkedList* lhs, LinkedList* rhs);

	/* Given a circular linked list, implement an algorithm which returns the
	 * node at the beginning of the loop
	 * Circular linked list: A (corrupt) linked list in which a node's next pointer
	 * to an earlier node, as to make a loop in the linked list
	 * Example:
	 * Input: A->B->C->D->E->C (The same C as before)
	 * Output: C
	 */
	Node* findBeginning(Node* head);

private:
	Node* _head;
};

namespace Ch2LinkedLists {

}



#endif /* CH2LINKEDLISTS_H_ */
