#include "input.h"

input::input(int argc , char *argv[]) {
    string path = argv[1];
    if(argc == 3){
        string buff = argv[2];
        if(buff == "-debug") {
            argument = true;
        }
        else {
            cout << "you've entered uncorrect arguments\n";
        }
    }
    fin.open(path);
    this->read();
}

void input::read() {
    string inp;
    code.resize(10000);
    string buff;
    while(!fin.eof()) {
        getline(fin, inp);
        stringstream ss;
        ss << inp;
        while(ss >> buff){
            code.at(i).push_back(buff);
        }
        i++;
    }
    /****************print vector*****************/
    /*for(int k = 0; k < i; k++) {
        for(int h = 0; h < code.at(k).size(); h++) {
            cout << code.at(k).at(h) << " ";
        }
        cout << endl;
    }*/
    /****************print vector*****************/

}

bool input::getArgument() const {
    return argument;
}

vector <vector<string>> input::getCode() const {
    return code;
}

int input::getSizeOfText() const{
    return i;
}
