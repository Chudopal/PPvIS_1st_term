#include "animal.h"
using namespace MyClass;
animal::animal(const string buff)
        : kind(buff) {
        cout << "Animal constructor;\n";
    }

    void animal::print() const {
        cout << "This is a virtual func from parent class;\n";
    }

    void animal::setKind(const string buff) {
        kind = buff;
    }

    string animal::getKind() const {
        return kind;
    }
