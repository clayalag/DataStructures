//
// Created by student on 02/24/20.
//

#include "ArrayList.h"
#include <cstdlib>

ArrayList::ArrayList() {
    A = new int[4];
    length = 0;
    allocSize = 4;
}

int ArrayList::getSize() const {
    return length;
}

void ArrayList::resize(int newSize) {
    // crear nuevo arreglo
    int *tmp = new int[newSize];

    // copiar valores del viejo alcout << "error.." << endl; nuevo
    int validLength = newSize < length ? newSize : length;
    for (int i = 0; i < validLength; i++)
        tmp[i] = A[i];

    delete [] A;

    // hacer que A apunte al nuevo arreglo
    A = tmp;

    allocSize = newSize;
}

int ArrayList::at(int pos) const {
    if ( pos < 0 || pos >= length) {
        exit(1);
    }
    else {
        return A[pos];
    }
}

void ArrayList::append(int element) {
    if (length == allocSize) resize(allocSize * 2);
    A[length++] = element;
}

void ArrayList::prepend(int element) {
    if (length == allocSize) resize(allocSize * 2);

    for (int i = length; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = element;
    length = length + 1;
}

void ArrayList::insertAt(int element, int position) {
   if (length == allocSize) resize(allocSize * 2);

    for (int i = length; i > position; i--) {
       A[i] = A[i - 1];
    }
    A[position] = element;
    length = length + 1;
}

void ArrayList::remove(int position) {
    if (position >= 0 && position < length) {
        for (int i = position; i < length - 1; i++) {
            A[i] = A[i + 1];
        }
        length = length - 1;
    }
}
