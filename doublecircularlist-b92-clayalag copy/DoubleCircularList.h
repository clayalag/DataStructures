//
// Created by rarce on 03/10/20.
//

#ifndef DOUBLECIRCULARLIST_DOUBLECIRCULARLIST_H
#define DOUBLECIRCULARLIST_DOUBLECIRCULARLIST_H

#include "Job.h"

class DNode {
public:
    Job data;
    DNode *next;
    DNode *prev;
    DNode(Job d, DNode *n = NULL, DNode *p = NULL): data(d), next(n), prev(p) {}

};
class DoubleCircularList {
private:
    DNode *head;
public:

    // Creates an empty List
    DoubleCircularList(): head(NULL) {}

    // Places a new object at the end of the list. The end of the list is
    // defined as the node immidiately preceeding the current node.
    void add(const Job &data);

    // Removes the current node, moves the current pointer to the next node, and returns a pointer to
    // the recently removed node. If the list is empty, this should return null. If there is only
    // one item in the list, it should be removed and current should refer to null.
    DNode* removeCurrent();


    // Returns a pointer to the current node. It does not remove the node from the
    // list or move the current pointer. If the list is empty, null is returned.
    DNode* getCurrent();

    // Simply moves the current pointer to the next object in the list. If there is only one item
    // in the list or the list is empty, nothing happens.
    void next();

    // Returns true if the list is empty, false otherwise
    bool isEmpty();

    // Goes through every node in the list, retrieves the data stored in the node, returns a string
    // with information about each node.
    string toString() const;

};



#endif //DOUBLECIRCULARLIST_DOUBLECIRCULARLIST_H
