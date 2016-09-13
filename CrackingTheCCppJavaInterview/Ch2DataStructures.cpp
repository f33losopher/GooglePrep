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
