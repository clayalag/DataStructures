#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <queue>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d, Node* n = NULL): data(d), next(n) {}
};

int getLength(int val) {
    if (val == 0) return 1;
    int digits = 0;
    while (val != 0) {
        digits++;
        val = val/10;
    }
    return digits;
}

int getMaxLength(Node *front) {
    Node *tmp = front;
    int valtmp = tmp -> data;
    int maxDigits = 0;
    while(tmp  != NULL) {
        int digitCount = getLength(valtmp);
        tmp = tmp -> next;
        if (digitCount > maxDigits) maxDigits = digitCount;
    }
    return maxDigits;
}

Node* Buckets(Node* front, Node* f, int pow10) {
    bool found = false;
    Node* tmp = NULL;
    vector <Node*> buckets[10];

    while (f != NULL) {
        buckets[(f->data / pow10) % 10].push_back(f);
        tmp = f;
        f = f->next;
        tmp->next = NULL;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            front = f = buckets[i][j];
            found = true;
            break;
        }
        if (found) break;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            f->next = buckets[i][j];
            f = f->next;
        }
    }
    return front;

}
// function radixsort:
//    given pointers to the front and the back of a linked list
//    (that will be treated as a queue), orders the list in ascending
//    order using radix sort radix 10.
void radixsort(Node *front, Node *back) {
    Node *f = front;

    int maxDigits = getMaxLength(front);
    int pow10 = 1;

    for (int digitIndex = 0; digitIndex < maxDigits; digitIndex++) {
        f = Buckets(f, front, pow10);
        pow10 = pow10 * 10;
    }

}

// function inOrder:
//   given pointer to the front of a linked list, returns
//   true if the list is in ascending order.
bool inOrder(Node *front) {
    if (front == NULL) return true;
    while (front->next != NULL) {
        if (front->data  > front->next->data)
            return false;
        front = front->next;
    }
    return true;
}


TEST_CASE( "radixsort", "[rec]" ) {
    vector<int> v{46, 11, 48, 56, 81, 21, 43, 31, 91, 26};


    Node *front, *back, *tmp;

    // Crear linked list
    front = back = new Node(v[0]);

    for (int i = 1; i < v.size(); i++) {
        back->next =  new Node(v[i]);
        back = back->next;
    }

    radixsort(front,back);

    CHECK(inOrder(front));
}