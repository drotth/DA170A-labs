#pragma once

#include <iostream>
#include "PhoneNumber.h"

using namespace std;

class PhoneRegister{
private:
	PhoneNumber *phoneReg;
	int arrayPosition;
public:
	PhoneRegister(int maxCapacity);
	void addNumber(string name_input, int num_input);
	void deleteName(string name_input);
	void deleteNumber(int num_input);
	bool searchName(string name_input, int &num_input);
	void printRegister();
	~PhoneRegister();
};

