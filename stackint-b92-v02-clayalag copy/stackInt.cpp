//
// Created by rarce on 03/27/20.
//

#include "stackInt.h"

stackInt::stackInt() {
    A = new int[4];
    allocationSize = 4;
    _top = -1;
}

bool stackInt::empty() const {
    return (_top == -1);
}

// Esta no está implementada! Implementala bien

stackInt::~stackInt()  {
    delete [] A;
}

// Implementa el resto de las member functions

void stackInt::push(int val) {
    // si el stack esta lleno, incrementa el tamaño
    if (_top == allocationSize - 1) resize(allocationSize * 2);

    A[++_top] = val;
}

void stackInt::pop() {
    _top --;
}

int stackInt::top() const {
    return A[_top];
}

void stackInt::resize(int newSize) {
    // crear nuevo arreglo
    int *tmp = new int[newSize];

    // copiar valores del viejo al nuevo
    int validLength = newSize < allocationSize ? newSize : allocationSize;
    for (int i = 0; i < validLength; i++)
        tmp[i] = A[i];

    delete [] A;

    // hacer que A apunte al nuevo arreglo
    A = tmp;

    allocationSize = newSize;
}