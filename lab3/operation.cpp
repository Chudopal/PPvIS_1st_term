#include "operation.h"

operation::operation(int k) :
    stack(k)
{
}

operation::operation(){}

void operation::dup () {
    if(!getStackIsEmpty()){

        int k = getValue();
        add(k);
    }
    else {
        cout << "The stack is empty\n";
    }
}

void operation::sum () {
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){
        int s = take() + take();
        add(s);
    }
    else {
        cout << "The stack has few arguments\n";
    }
}

void operation::sub(){
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){

        int s = take() - take();
        add(s);
    }
    else {
        cout << "The stack has few arguments\n";
    }
}

void operation::div(){
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){

        int s = take() / take();
        add(s);
    }
    else {
        cout << "The stack has few arguments\n";
    }
}

void operation::mul(){
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){

        int s = take() * take();
        add(s);
    }
    else {
        cout << "The stack has few arguments\n";
    }
}

bool operation::ifeq(){
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){

        if(take() == take())
            return true;
        else {
            return false;
        }
    }
    else {
        cout << "The stack has few arguments\n";
    }
    return false;
}

bool operation::ifgr(){
    if((this->getPrev() != nullptr) && !getStackIsEmpty()){

        if(take() > take())
            return true;
        else {
            return false;
        }
    }
    else {
        cout << "The stack has few arguments\n";
    }
    return false;
}
