//
// Created by rarce on 03/27/20.
//

#ifndef STACKINT_STACKINT_H
#define STACKINT_STACKINT_H


class stackInt {
private:
    int *A;
    int _top;
    int allocationSize;
    void resize(int newSize);
public:
    stackInt();
    void push(int val);
    void pop();
    int top() const;
    bool empty() const;
    ~stackInt();
};


#endif //STACKINT_STACKINT_H
