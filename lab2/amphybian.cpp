#include "amphybian.h"
using namespace MyClass;
amphibian::amphibian(const string arg1, const string arg2, const string arg3)
        : ground(arg1, arg2), hydrous(arg1, arg3), animal(arg1) {
        cout << "Amphibian constructor;\n";
    }

    void amphibian::print() const {
        cout << animal::kind << std::endl;
        cout << ground::place << std::endl;
        cout << hydrous::ocean << std::endl;
    }
