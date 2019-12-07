#ifndef GROUND_H
#define GROUND_H
#include "animal.h"

namespace   MyClass {
class ground : virtual public animal {
    protected:
        string place;
    public:
        virtual void print() const;
        ground(const string, const string);
        string getPlace() const;
        void setPlace(const string);
    };
}
#endif // GROUND_H
