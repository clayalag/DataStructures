//
// Created by rarce on 04/01/20.
//

#include "modeStack.h"

// constructor
modeStack::modeStack(int range) {
    A = new int[range+1];
    dat.resize(range, 0) ;
    _top = -1;
    maxidx = 0;
    max = 0;
    repeated = true;
}

// destructor
modeStack::~modeStack() {
    delete [] A;
    dat.clear();
}

// just a normal push
void modeStack::push(int val) {
    A[++_top] = val;
    dat[val]++;
    if(dat[val] > max) {
        max = dat[val];
        repeated = false;
        maxidx = A[_top];
    }
    else if(dat[val] == max) repeated = true;
}

// returns of the mode of the current elements in the stack
int modeStack::mode() const {
    if (repeated) return -1;
    else return maxidx;
}

// just a normal pop
void modeStack::pop() {
    /*int t=_top;
    t=t-1;
    int z= dat[A[t]];
    int x = A[_top] + A[t];
    int y = maxidx*2;
    cout<<z<< "  "<< dat[A[_top]]<<endl;
     */
    if (A[_top] == maxidx) {
        max--;
    }
    /*
    if (dat[A[_top]] == z) {
        dat[A[_top]]--;
        _top--;
        repeated = true;
        cout<<"fuck"<<endl;
        return;
    }
     */
    dat[A[_top]]--;
    _top--;
    if (A[_top] != maxidx && dat[A[_top]] == max) repeated = true;
    else if (A[_top] != maxidx && dat[A[_top]] > max) {
        maxidx = A[_top];
        max = dat[A[_top]];
        repeated = false;
    }
    else if (A[_top] == maxidx && dat[A[_top]] == max) repeated = false;
}

// just a normal empty
bool modeStack::empty() {
    return (_top == -1);
}

// just a normal top
int modeStack::top() {
    return A[_top];
}