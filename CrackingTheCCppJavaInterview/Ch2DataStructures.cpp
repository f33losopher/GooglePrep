/*
 * Ch2DataStructures.cpp
 *
 *  Created on: Sep 8, 2016
 *      Author: felix
 */

#include "Ch2DataStructures.h"

#include <iostream>

using namespace std;

Ch2DataStructures::Ch2DataStructures() {

}

Ch2DataStructures::~Ch2DataStructures() {

}

LinkedList* Ch2DataStructures::prob28(LinkedList* start) {
    if (start == 0) {
        return start;
    }
    if (start->_next == 0) {
        return start;
    }

    LinkedList* present = 0;
    LinkedList* temporary;

    while (start != 0) {
        temporary = start;
        start = start->_next;
        temporary->_next = present;
        present = temporary;
    }
    return present;
}

LinkedList* Ch2DataStructures::prob29(LinkedList* start) {
    LinkedList* p1 = start;
    LinkedList* p2 = start->_next;
    while ((p2 != 0) && (p2->_next != 0)) {
        p1 = p1->_next;

        p2 = p2->_next;
        if (p2 != 0) {
            p2 = p2->_next;
        }
    }

    return p1;
}

// Return of a real pointer means there is a loop
// Return of 0 means there is no loop
LinkedList* Ch2DataStructures::prob30(LinkedList* start) {
    LinkedList* p1 = start;
    LinkedList* p2 = start;

    while (p1 && p2) {
        p1 = p1->_next;
        p2 = (p2 == 0) ? 0:p2->_next;
        if (p2 != 0) {
            p2 = p2->_next;
        } else {
            return 0;
        }

        if (p1 == p2) {
            std::cout << "Circular List" << std::endl;
            return p1;
        }
    }

    return 0;
}

LinkedList* Ch2DataStructures::prob31(LinkedList* start, int k) {
    LinkedList* p1 = start;
    LinkedList* p2 = start;
    for (int i=0; i < k; ++i) {
        p1 = p1->_next;
    }

    while (p1->_next) {
        p1 = p1->_next;
        p2 = p2->_next;
    }

    return p2;
}

void Ch2DataStructures::prob32(LinkedList* delNode) {
    if (delNode->_next == 0) {
        return;
    }

    LinkedList* next = 0;

    next = delNode->_next;
    delNode->_val = next->_val;

    delNode->_next = next->_next;

    delete(next);
}

LinkedList* Ch2DataStructures::prob33(LinkedList* prev, LinkedList* cur) {
    if (cur == 0) {
        return prev;
    }

    LinkedList* next = cur->_next;
    cur->_next = prev;
    return prob33(cur, next);
}
