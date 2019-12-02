#ifndef PROGRAMM_H
#define PROGRAMM_H
#include "operation.h"

class programm : public input
{
public:
    programm(int argc, char *argv[]);
private:
    void interpritation(vector <vector <string>>, int);
    void ifFunction(const string);
    int ifGoto(const string, vector<vector<string>>, int);
    void ifPush(const string, vector <string> &, vector <int> &);
    void ifPop();
    void ifPop(const string,  vector <string> &, vector <int> &);
    void ifPeek(const string, vector <string> &, vector <int> &);
    void ifDup();
    void ifAdd();
    void ifSub();
    void ifDiv();
    void ifMul();
    void ifDebug( vector <string> &, vector <int> &);
    int findLabel(const string);
    void callfunc(const string, vector <vector<string>>);
    operation code;
    vector <string> name;
};

#endif // PROGRAMM_H
