#pragma once

#include <string>

using namespace std;

class PhoneNumber{
private:
	string name;
	int number;
public:
	PhoneNumber();
	PhoneNumber(string name_input, int num_input);
	void setName(int name_input);
	void setNumber(int num_input);
	string getName();
	int getNumber();
};