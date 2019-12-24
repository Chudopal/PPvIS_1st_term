#include "cart.h"
#include <QDebug>
#include <sstream>

cart::cart(const string pass)
{
    check_pass(pass);
    search_amount();
}

void cart::check_pass(string pass){
    ifstream fin("passwords.txt");
    numb_str_of_amount = 0;
    if(fin.is_open()) {
        while(!fin.eof()){
            string buff;
            fin >> buff;

            if(buff == pass){
                is_pass_correct = true;
                break;
            }
            numb_str_of_amount++;
        }
    }
    fin.close();
}

bool cart::get_is_pass_correct() const {
    return is_pass_correct;
}

void cart::search_amount() {
    ifstream fin("balans.txt");
    if(fin.is_open()) {
        while(!fin.eof()){
            string buff;
            fin >> buff;
            stringstream ss;
            ss << buff;
            ss >> amount;
            info_of_amount.push_back(amount);
        }
    }
    amount = info_of_amount[numb_str_of_amount];
    fin.close();
}

void cart::write_amount() {
    ofstream fout("balans.txt");
    fout << "";
    std::fstream::app;
    int k[3] = {1,2,3};
    for(int i = 0; i < info_of_amount.size(); i++) {
        fout << info_of_amount[i] << "\n";
    }
    fout.close();
}

int cart::get_amount() {
    return amount;
}

void cart::put_money(int sum) {
    amount += sum;
    info_of_amount[numb_str_of_amount] = amount;
}

void cart::take_money(int dif) {
    amount -= dif;
    info_of_amount[numb_str_of_amount] = amount;
}

cart::cart (){}
