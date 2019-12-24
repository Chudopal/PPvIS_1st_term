#ifndef CART_H
#define CART_H
#include <QMainWindow>
#include <fstream>
#include <string>
#include <vector>
#include <QDebug>
#include <sstream>
#include <iostream>
using namespace std;
class cart
{
public:
    cart(string);
    cart();
    void search_amount();
    void check_pass(const string);
    void write_amount();
    bool get_is_pass_correct() const;
    int get_amount();
    void put_money(int sum);
    void take_money(int dif);
private:
    int amount;
    int numb_str_of_amount = 0;
    bool is_pass_correct = false;
    vector <int> info_of_amount;
};

#endif // CART_H
