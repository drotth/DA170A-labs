#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "PhoneRegister.h"

PhoneRegister::PhoneRegister(int maxCapacity){
	phoneReg = new PhoneNumber[maxCapacity];
	arrayPosition = 0;
}

void PhoneRegister::addNumber(string name_input, int num_input){
	phoneReg[arrayPosition] = PhoneNumber(name_input, num_input);
	arrayPosition++;
}

void PhoneRegister::deleteName(string name_input){
	for (int i = 0; i < arrayPosition; i++){
		if (phoneReg[i].getName() == name_input){
			for (int j = i; j < arrayPosition; j++){
				phoneReg[j] = phoneReg[j + 1];
			}
			arrayPosition--;
		}
	}
}

void PhoneRegister::deleteNumber(int num_input){
	for (int i = 0; i < arrayPosition; i++){
		if (phoneReg[i].getNumber() == num_input){
			for (int j = i; j < arrayPosition; j++){
				phoneReg[j] = phoneReg[j + 1];
			}
			arrayPosition--;
		}
	}
}

bool PhoneRegister::searchName(string name_input, int &num_input){
	int result = false;
	for (int i = 0; i < arrayPosition; i++){
		if (phoneReg[i].getName() == name_input){
			num_input = phoneReg[i].getNumber();
			result = true;
		}
	}
	return result;
}

void PhoneRegister::printRegister(){
	for (int i = 0; i < arrayPosition; i++){
		cout << phoneReg[i].getName() << "\t" << phoneReg[i].getNumber() << endl;
	}
}

PhoneRegister::~PhoneRegister(){
	delete[] phoneReg;
}
