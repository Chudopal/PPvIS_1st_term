#include "stack.h"

stack::stack(const int numb) {
    stackIsEmpty = false;
    value = numb;
    prev = nullptr;
}


void stack::theFirstEl(const int numb) {
    stackIsEmpty = false;
    value = numb;
    prev = nullptr;
}


stack::stack() {}

void stack::print() {
    stack *buff = this;
    if(stackIsEmpty) {
        return;
    }
    while(buff != nullptr){
        cout << buff->value << endl;
        buff = buff->prev;
    }
}

/*void stack::add(const int numb) {
    //cout << numb << endl;
    if(stackIsEmpty){
        this->value = numb;
        stackIsEmpty = false;
        return;
    }
    stackIsEmpty = false;
    int arg = this->value;
    this->value = numb;
    if(this->prev != nullptr) {
        this->prev->stackIsEmpty = false;
        this->prev->add(arg);
    }
    else {
        //cout << "HEREREREER" << endl;
        stack *final = new stack;
        final -> value = arg;
        this->prev = final;
    }
}*/


void stack::add(const int numb) {
    //cout << numb << endl;
    if(stackIsEmpty){
        this->value = numb;
        stackIsEmpty = false;
        return;
    }
    vector <int> buffValue;
    stack *buff = this;
    buffValue.push_back(numb);
    while(buff != nullptr) {
        buffValue.push_back(buff->value);
        buff = buff->prev;
    }
    buff = this;
    while(buff->prev != nullptr){
        buff = buff->prev;
    }
    stack *end = new stack;
    end -> prev = nullptr;
    buff->prev = end;
    buff = this;
    int counter = 0;
    while(buff != nullptr) {
        buff->value = buffValue.at(counter);
        buff = buff->prev;
        counter++;
    }
}



int stack::take(){
    if(stackIsEmpty) {
        cout << "Stack is empty!\n";
        return 0;
    }
    stack *buff = this;
    int numb = buff->value;
    if(buff->prev == nullptr) {
        stackIsEmpty = true;
        return numb;
    }
    while(true){
        buff->value = buff->prev->value;
        if(buff->prev->prev == nullptr) {
            break;
        }
        else{
            buff= buff->prev;
        }
    }
    buff->prev = nullptr;
    return numb;
}

stack* stack::getPrev() const{
    return prev;
}

int stack::getValue() const{
    return value;
}

bool stack::getStackIsEmpty () const {
    return stackIsEmpty;
}
