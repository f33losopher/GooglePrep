/*
 * Node.h
 *
 *  Created on: Mar 7, 2015
 *      Author: Felix
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>
#include <iostream>
#include <string>

struct Node {
	Node() : data(0), next(NULL) {}
	~Node() {
//		std::cout << "Destroy: Data = " << data << std::endl;
	}
	int data;
	Node* next;

	static int length(struct Node* head) {
		int count = 0;
		struct Node* current = head;

		while (current != NULL) {
			count++;
			current = current->next;
		}
		return count;
	}

	static void Push(struct Node*& headRef, int newData) {
		Node* newNode = new Node();
		newNode->data = newData;
		newNode->next = headRef;
		headRef = newNode;
	}

	static Node* BuildOneTwoThree() {
		Node* head = NULL;
		Push(head, 3);
		Push(head, 2);
		Push(head, 1);

		return(head);
	}

	/*
	 * Builds a random linked list of length numElements
	 * Values 0 - 19
	 */
	static Node* BuildRandom(int numElements) {
		srand(1);
		Node* head = NULL;
		for (int i=0; i < numElements; i++) {
			Push(head, rand() % 20);
		}
		return head;
	}

	static void print(Node* head) {
		for (Node* cur = head; cur != NULL; cur = cur->next) {
			std::cout<< cur->data << " ";
		}
		std::cout << std::endl;
	}
};


#endif /* NODE_H_ */
