#include "human.h"

human::human(int beg)
{
    value = beg;
}

human::human()
{}

int human::getValue() const {
    return value;
}

bool human::operator > (human oper) {
    if(value > oper.getValue()){
        return true;
    }
    else{
        return false;
    }
}

bool human::operator < (human oper) {
    if(value < oper.getValue()){
        return true;
    }
    else{
        return false;
    }
}

bool human::operator == (human oper) {
    if(value == oper.getValue()){
        return true;
    }
    else{
        return false;
    }
}


void human::operator = (human &inp) {
    value = inp.getValue();
}

int human::operator + (human inp){
    return value + inp.getValue();
}

int human::operator [] (int numb) {
    return this->getValue();
}
