#include "programm.h"

programm::programm(int argc, char *argv[])
   : input(argc, argv)
{
    interpritation(getCode(), getSizeOfText());
    code.print();
}

void programm :: interpritation(vector <vector<string>> text, int size){
    vector <string> name;
    vector <int> value;
    for(int k = 0; k < size; k++) {
        for(int h = 0; h < text.at(k).size(); h++) {
            if(text.at(k).at(h) == "push") {
                ifPush(text.at(k).at(h+1), name, value);
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "pop") {
                if(h == text.at(k).size() - 1){
                    ifPop();
                }
                else {
                    ifPop(text.at(k).at(h+1), name, value);
                }
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "peek") {
                ifPeek(text.at(k).at(h+1),name, value);
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "dup"){
                ifDup();
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "add") {
                ifAdd();
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "sub") {
                ifSub();
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "div"){
                ifDiv();
                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "mul") {
                ifMul();

                if(getArgument()) {
                    ifDebug(name, value);
                }
            }
            if(text.at(k).at(h) == "}") {
                return;
            }
            if(text.at(k).at(h) == "goto") {
                k = ifGoto(text.at(k).at(h+1), text, k);
            }
            if(text.at(k).at(h) == "call"){
                callfunc(text.at(k).at(h+1), text);
            }
            if(text.at(k).at(h) == "ifeq" && code.ifeq()){
                k = ifGoto(text.at(k).at(h+1), text, k);
            }
            if(text.at(k).at(h) == "ifgr" && code.ifgr()){
                k = ifGoto(text.at(k).at(h+1), text, k);
            }
            if(text.at(k).at(h) == "return") {
                return;
            }
        }
    }
    cout << endl;
    code.print();
    cout << endl;
    return;
}

void programm::ifPush(const string value, vector<string> &nameOfVariable, vector<int> &valueOfVariable ){
    stringstream ss;
    int numb;
    string str;
    ss << value;
    ss >> numb;
    if(!ss) {
        ss.clear();
        ss >> str;
        for(int u = 0; u < nameOfVariable.size(); u++){
            if(nameOfVariable.at(u) == str){
                numb = valueOfVariable.at(u);
            }
        }
        if(code.getStackIsEmpty()) {
            code.theFirstEl(numb);
        }
        else{
            code.add(numb);
        }
    }
    else {
        if(code.getStackIsEmpty()) {
            code.theFirstEl(numb);
        }
        else{
            code.add(numb);
        }
    }
}

void programm::ifPeek (const string argument, vector<string> &nameOfVariable, vector<int> &valueOfVariable) {
    for(int i = 0; i < nameOfVariable.size(); i++){
        if(nameOfVariable.at(i) == argument) {
            cout << "You have 2 same identifiers\n";
            return;
        }
    }
    nameOfVariable.push_back(argument);
    valueOfVariable.push_back(code.getValue());
}

void programm::ifPop() {
    code.take();
}

void programm::ifPop(const string argument, vector<string> &nameOfVariable, vector<int> &valueOfVariable) {
    for(int u =0; u < nameOfVariable.size(); u++){
        if(nameOfVariable.at(u) == argument) {
            cout << "You have 2 same identifiers\n";
            return;
        }
    }
    nameOfVariable.push_back(argument);
    valueOfVariable.push_back(code.take());
}

void programm::ifDup() {
    code.dup();
}

void programm::ifAdd() {
    code.sum();
}

void programm::ifSub () {
    code.sub();
}

void programm::ifDiv() {
    code.div();
}

void programm::ifMul() {
    code.mul();
}

void programm::ifDebug (vector<string> &nameOfVariable, vector<int> &valueOfVariable) {
    cout << endl << "*******************" << endl << "debug:\n";
    for(int i = 0; i < nameOfVariable.size(); i++ ) {
        cout <<  nameOfVariable.at(i) << " = " << valueOfVariable.at(i) << endl;
    }
    code.print();
    cout << "*******************" << endl << endl;
}

int programm:: ifGoto (const string label, vector<vector<string>> text, int numbStr) {
    string buff = label;
    buff += ":";
    int begin;
    for(int i = numbStr; i >= 0; i--){
        if(text.at(i).at(0) == "{"){
            begin = i + 1;
        }
    }
    while(text.at(begin).at(0) != "}") {

        if((text.at(begin).at(0) == buff) ) {
            return begin;
        }
        begin++;
    }
    return numbStr +1;
}

void programm::callfunc(const string nameOfFunc, vector<vector<string>> text) {
    vector <vector<string>> buff;
    buff.resize(10000);
    int size = 0;
    for(int k = 0; k < getSizeOfText(); k++) {
        for(int h = 0; h < text.at(k).size(); h++) {
            if(text.at(k).at(0) == "function" && text.at(k).at(h) == nameOfFunc){
                for(int i = k; i < getSizeOfText(); i++) {
                    buff.at(i - k) = text.at(i);

                }
                size = getSizeOfText() - k;
                /*for(int i = 0; i < size; i++){
                    for(int o = 0; o < buff.at(i).size(); o++){
                        cout << buff.at(i).at(o) << " ";
                    }
                    cout << endl;
                }*/
                interpritation(buff, size);
                break;
            }
        }
    }
}
