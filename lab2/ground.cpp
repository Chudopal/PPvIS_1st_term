#include "ground.h"
using namespace MyClass;
ground::ground(const string arg1, const string arg2)
        : animal(arg1),
        place(arg2) {
        cout << "Ground constructor;\n";
    }

    void ground::print() const {
        cout << "This is a virtual func from child class ground;\n";
    }

    void ground::setPlace(const string arg) {
        place = arg;
    }

    string ground::getPlace() const {
        return place;
    }
