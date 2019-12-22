#include "cart.h"

cart::cart(const string pass)
{
    check_pass(pass);
    search_amount();
    if(is_pass_correct){
        search_amount();
    }
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
