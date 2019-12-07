#ifndef HYDROUS_H
#define HYDROUS_H
#include "animal.h"

namespace   MyClass {
class hydrous : virtual public animal {
    protected:
        string ocean;
    public:
        hydrous(const string, const string);
        void setOcean(const string);
        string getOcean() const;
    };
}
#endif // HYDROUS_H
