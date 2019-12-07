#include "amphybian.h"

using namespace MyClass;
int main() {
    animal j ("kind");
    cout << j.getKind() << endl;
    j.print();
    cout << endl << endl;

    ground h("kind", "ground");
    cout << "Its kind is - " << h.getKind() << endl;
    h.print();
    cout << "Its habitat is - " << h.getPlace() << endl << endl;

    hydrous d("kind", "ocean");
    cout << "Its kind is - " << d.getKind() << endl;
    cout << "Its habitat is - " << d.getOcean() << endl << endl;

    amphibian k("kind", "place", "ocean");
    k.print();
    system("pause");
    return 0;
}
