#include "hydrous.h"
using namespace MyClass;
    hydrous::hydrous(const string arg1, const string arg2)
        : animal(arg1),
        ocean(arg2) {
        cout << "hydrous comstructor;\n";
    }

    string hydrous::getOcean() const {
        return ocean;
    }

    void hydrous::setOcean(const string arg) {
        ocean = arg;
    }
