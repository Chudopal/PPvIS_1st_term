#ifndef STACK_H
#define STACK_H
#include "input.h"

class stack
{
public:
    stack(const int);
    stack();
    void theFirstEl(int);
    void print();
    void add(const int);
    int take();
    stack *getPrev() const;
    int getValue() const;
    bool getStackIsEmpty() const;
private:
    int value;
    stack *prev;
    bool stackIsEmpty = true;
};

#endif // STACK_H
