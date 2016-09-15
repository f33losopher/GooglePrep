/*
 * Ch2UnitTest.cpp
 *
 *  Created on: Sep 8, 2016
 *      Author: felix
 */

#include "Ch2DataStructures.h"
#include "gtest/gtest.h"

#include <iostream>

using namespace std;

void print(LinkedList* list) {
    LinkedList* node = list;
    while (node != 0) {
        cout << node->_val << " ";
        node = node->_next;
    }
    cout << endl;
}

/**
 * Build an ordered linked list of "numNodes"
 */
LinkedList* buildList(int numNodes) {
    LinkedList* root = new LinkedList(1);
    LinkedList* node = root;

    for (int i = 2; i <= numNodes; ++i) {
        node->_next = new LinkedList(i);
        node = node->_next;
    }
    return root;
}

TEST(Ch2, reverseLinkedList_NULL) {
    LinkedList* root = 0;
    root = Ch2DataStructures::prob28(root);

    EXPECT_EQ(0, root);
}

TEST(Ch2, reverseLinkedList_OneElement) {
    LinkedList* root = new LinkedList(5);
    root = Ch2DataStructures::prob28(root);

    EXPECT_EQ(5, root->_val);
}

TEST(Ch2, reverseLinkedList) {
    LinkedList* root = buildList(4);
    print(root);

    root = Ch2DataStructures::prob28(root);
    print(root);
    EXPECT_EQ(4, root->_val);
    root = root->_next;
    EXPECT_EQ(3, root->_val);
    root = root->_next;
    EXPECT_EQ(2, root->_val);
    root = root->_next;
    EXPECT_EQ(1, root->_val);
}

TEST(Ch2, middleOfList) {
    LinkedList* root;
    LinkedList* mid;

    root = buildList(1);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(1, mid->_val);

    root = buildList(2);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(1, mid->_val);

    root = buildList(3);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(2, mid->_val);

    root = buildList(4);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(2, mid->_val);

    root = buildList(5);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(3, mid->_val);

    root = buildList(6);
    mid = Ch2DataStructures::prob29(root);
    EXPECT_EQ(3, mid->_val);
}

TEST(Ch2, circularList_yes) {
    LinkedList* root = buildList(10);

    // Link 10 to 4 to make a circle
    LinkedList* p1 = root;
    for (int i=1; i <= 4; ++i) {
        p1 = p1->_next;
    }

    LinkedList* p2 = p1;
    while (p2->_next != 0) {
        p2 = p2->_next;
    }
    p2->_next = p1;

    LinkedList* loopPtr = Ch2DataStructures::prob30(root);
    LinkedList* nullPtr = 0;
    EXPECT_NE(nullPtr, loopPtr);
}

TEST(Ch2, circularList_no) {
    LinkedList* root = buildList(10);

    root = Ch2DataStructures::prob30(root);
    EXPECT_EQ(0, root);
}

TEST(Ch2, nMinusKthNode) {
    LinkedList* root = buildList(10);

    LinkedList* kPtr = Ch2DataStructures::prob31(root, 0);
    EXPECT_EQ(10, kPtr->_val);

    kPtr = Ch2DataStructures::prob31(root, 1);
    EXPECT_EQ(9, kPtr->_val);

    kPtr = Ch2DataStructures::prob31(root, 4);
    EXPECT_EQ(6, kPtr->_val);
}

TEST(Ch2, deleteNode) {
    LinkedList* root = buildList(10);

    LinkedList* delNode = root;
    for (int i=1; i < 5; ++i) {
        delNode = delNode->_next;
    }

    print(root);
    Ch2DataStructures::prob32(delNode);
    print(root);

    root = buildList(10);

    delNode = root;
    for (int i=1; i < 10; ++i) {
        delNode = delNode->_next;
    }

    print(root);
    Ch2DataStructures::prob32(delNode);
    print(root);
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
