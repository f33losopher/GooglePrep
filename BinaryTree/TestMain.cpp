/*
 * TestMain.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Felix
 */
#include "BinaryTree.h"
#include <iostream>
using namespace std;
int main() {
	BinaryTree bt;

	bt.add(50);
	bt.add(30);
	bt.add(60);
	bt.add(20);
	bt.add(40);
	bt.add(45);
	bt.add(55);
	bt.add(35);
	bt.add(80);
	bt.add(70);
	bt.add(19);
	bt.add(18);
	bt.add(10);
	bt.add(15);
	bt.add(43);
	bt.add(33);
	bt.add(82);
	bt.add(85);

	cout << "Breadth First Search: ";
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Depth First Search: ";
	bt.printSearch(BinaryTree::Depth);
	cout << endl;

	cout << "Max Depth: " << bt.maxDepth(bt.root()) << endl;
	cout << "Min Depth: " << bt.minDepth(bt.root()) << endl;
	cout << "Balanced?  " << (bt.isBalanced(bt.root()) ? "Balanced" : "Not Balanced") << endl;

	int numbers[10] = { 50, 30, 15, 18, 55, 70, 80, 22, 99, 0 };
	for (int i = 0; i < 10; i++) {
		int num = numbers[i];
		Node* searchFor = bt.find(num, bt.root(), BinaryTree::Depth);
		if (NULL != searchFor)
			cout << "Found " << num << endl;
		else
			cout << "Did not find " << num << endl;

	}

	cout << endl;

	for (int i = 0; i < 10; i++) {
		int num = numbers[i];
		Node* searchFor = bt.find(num, bt.root(), BinaryTree::Breadth);
		if (NULL != searchFor)
			cout << "Found " << num << endl;
		else
			cout << "Did not find " << num << endl;

	}

	cout << "Deleting 15" << endl;
	bt.remove(15);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Deleting 85" << endl;
	bt.remove(85);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Deleting 33" << endl;
	bt.remove(33);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Deleting 60" << endl;
	bt.remove(60);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Deleting the root 50" << endl;
	bt.remove(50);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Deleting 45" << endl;
	bt.remove(45);
	bt.printSearch(BinaryTree::Breadth);
	cout << endl;

	cout << "Max Depth: " << bt.maxDepth(bt.root()) << endl;
	cout << "Min Depth: " << bt.minDepth(bt.root()) << endl;
	cout << "Balanced?  " << (bt.isBalanced(bt.root()) ? "Balanced" : "Not Balanced") << endl;

	return 0;
}



