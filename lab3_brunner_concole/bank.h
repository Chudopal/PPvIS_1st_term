#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class session
{
public:
	session(vector<cart>,vector<base>);
	void beg();
	void end(string);

private:
	vector<cart> car;
	vector<base> bas;
	
};