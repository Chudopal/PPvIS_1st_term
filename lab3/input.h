#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class input {
public:
    input(int argc, char *argv[]);
    void read();
    bool getArgument() const;
    vector <vector<string>> getCode() const;
    int getSizeOfText() const;
private:
    ifstream fin;
    bool argument = false;
    int i = 0;
    vector <vector<string>> code;
};

#endif // INPUT_H
