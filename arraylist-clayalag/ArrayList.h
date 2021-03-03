//
// Created by student on 02/24/20.
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H


class ArrayList {
private:
    int *A;
    int length, allocSize;
    void resize(int newSize);
public:
    ArrayList();
    int getSize() const;
    int at(int pos) const;
    void append(int element);
    void prepend(int element);
    void insertAt(int element, int position);
    void remove(int position);
};


#endif //ARRAYLIST_ARRAYLIST_H
