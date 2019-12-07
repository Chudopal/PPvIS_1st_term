#ifndef AMPHYBIAN_H
#define AMPHYBIAN_H
#include "ground.h"
#include "hydrous.h"

namespace  MyClass {
class amphibian : private ground, protected hydrous {
    public:
        amphibian(const string = "", const string = "", const string = "");
        void print() const;

};
}

#endif // AMPHYBIAN_H
