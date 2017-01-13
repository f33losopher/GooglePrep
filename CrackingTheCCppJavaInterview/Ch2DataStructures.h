/*
 * Ch2DataStructures.h
 *
 *  Created on: Sep 8, 2016
 *      Author: felix
 */

#ifndef CH2DATASTRUCTURES_H_
#define CH2DATASTRUCTURES_H_

struct LinkedList {
    LinkedList(int val) : _val(val), _next(0) {}

    LinkedList* _next;
    int _val;
};

class Ch2DataStructures {
public:
    Ch2DataStructures();
    ~Ch2DataStructures();

    /**
     *  Write code to reverse a linked list
     */
    static LinkedList* prob28(LinkedList* start);

    /**
     * Write code to find the middle node of a singly linked list
     */
    static LinkedList* prob29(LinkedList* start);

    /**
     * How to determine if a singly linked list has a loop
     */
    static LinkedList* prob30(LinkedList* start);

    /**
     * How would you find the (n-k)th node in a singley linked list, where n
     * is the number of nodes and k < n
     */
    static LinkedList* prob31(LinkedList* start, int k);

    /**
     * Given a pointer to a node in a Singley Linked List, how do you delete
     * that node
     */
    static void prob32(LinkedList* delNode);

    /**
     * Reverse a singly linked list using recursion
     */
    static LinkedList* prob33(LinkedList* prev, LinkedList* cur);

private:

};

#endif /* CH2DATASTRUCTURES_H_ */
