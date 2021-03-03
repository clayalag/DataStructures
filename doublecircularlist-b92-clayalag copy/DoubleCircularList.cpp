//
// Created by rarce on 03/10/20.
//

#include "DoubleCircularList.h"


void DoubleCircularList::add(const Job &data) {
    DNode *a = new DNode(data);
    DNode *p = nullptr;

    if (head == NULL) {
        head = a;
        a -> next = a -> prev = a;
    }
    else {
        p = head -> prev;
        head -> prev = a;
        a -> prev = p;
        a -> next = head;
        p -> next = a;
    }
}

DNode* DoubleCircularList::removeCurrent() {
    if (head == NULL) return NULL;
    DNode *p = head -> prev;
    DNode *s = head -> next;
    DNode *x = head;
    if(s == head) {
        head = NULL;
        return s;
    }
    s -> prev = p;
    p -> next = s;
    head = s;
    head -> prev = p;
    return x;
}

DNode* DoubleCircularList::getCurrent() {
    if (head == NULL) return NULL;
    DNode *p = head -> prev;
    return p;
}

void DoubleCircularList::next() {
    if (head != NULL && head -> next != head) {
        DNode *p = head;
        head = head -> next;
        head -> prev = p;
    }
}

bool DoubleCircularList::isEmpty() {
    if (head == NULL) return true;
    else return false;
}

string DoubleCircularList::toString() const {
    if (head == NULL) return "empty";
    DNode *p = head;
    Job j = p -> data;
    string s;
    do {
        j = p -> data;
        p = p -> next;
        s += j.toString();
    } while (p != head);
    return s;
}