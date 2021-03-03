//
// Created by rarce on 04/01/20.
//

#ifndef MODESTACK_MODESTACK_H
#define MODESTACK_MODESTACK_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
class modeStack {
private:
    // tu provees los data members
    int *A;
    vector <int> dat;
    int _top;
    int maxidx;
    int max;
    bool repeated;

public:
    // constructor
    modeStack(int range = 100);

    // destructor
    ~modeStack();

    // just a normal push
    void push(int val);

    // returns of the mode of the current elements in the stack
    int mode() const;

    // just a normal pop
    void pop();

    // just a normal empty
    bool empty();

    // just a normal top
    int top();
};


#endif //MODESTACK_MODESTACK_H
