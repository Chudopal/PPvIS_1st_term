#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace   MyClass {

class animal {
    protected:
        string kind;
    public:
        void print() const;
        animal(const string);
        void setKind(const string);
        string getKind() const;
    };

}
#endif // ANIMAL_H
