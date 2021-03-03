//
// Created by rarce on 04/28/20.
//

#include "superDeque.h"
#include <iostream>


superDeque::superDeque() {
    A = new int[4];
    allocSize = 4;
    _front = -1;
    _back = -1;

}

superDeque::~superDeque() {
    delete [] A;
}

void superDeque::resize(int newSize) {
    int *tmp = new int[newSize];

    int validLength = newSize < allocSize ? newSize : allocSize;

    for (int i = 0; i < validLength; i++) {
        tmp[i] = A[i];
    }
    delete [] A;

    A = tmp;

    allocSize = newSize;
}

void superDeque::push_front(int val){

    if ((_front + 1) % allocSize == _back) resize(allocSize * 2);

    if (_front == -1) _front = _back = 0;

    else _front = (_front - 1) % allocSize;

    A[_front] = val ;
}

void superDeque::push_back(int val) {
    if ((_back + 1) % allocSize == _front) resize(allocSize * 2);

    if (_front == -1) _front = _back = 0;

    else if (_back == allocSize-1) _back = 0;

    else _back = (_back + 1) % allocSize;

    A[_back] = val ;
}

void superDeque::pop_front() {
    if (_front == _back) _front = _back = -1;

    else _front = (_front + 1) % allocSize;
}

void superDeque::pop_back() {
    if (_front == _back) _front = _back = -1;

    else if (_back == 0) _back = allocSize-1;

    else _back = (_back - 1) % allocSize;
}

int superDeque::front() const {
    return A[_front];
}

int superDeque::back() const {
    return A[_back];
}

void superDeque::insert(int pos, int val) {
    if (pos < 0 || pos > allocSize) {
        cout << "Error en posicion." << endl;
        exit(1);
    }
    if ((_back + 1) % allocSize == _front) resize(allocSize * 2);
    for (int i = _back; i >= pos; i=(i + 1) % allocSize)
         A[i+1] = A[i];
    A[pos] = val;
    _back = (_back + 1) % allocSize;
}
void superDeque::remove(int pos) {
    if (pos < 0 || pos > _back) {
        cout << "Error durante remocion" << endl;
        exit(1);
    }
    for (int i = pos; i < _back ; i=(i + 1) % allocSize)
        A[i] = A[i + 1];
    _back = (_back - 1) % allocSize;
}
