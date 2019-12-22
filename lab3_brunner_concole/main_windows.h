#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include "base.h"

class main_windows
{   
public:

	main_windows(vector<cart>,vector<base>);
	int print();
    void card_choose();
    bool continu();

	int value;
	vector<cart> carte;
	vector<base> bas;
};
#endif // MAIN_WINDOW_H
