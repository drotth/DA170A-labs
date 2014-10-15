#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(){

}

PhoneNumber::PhoneNumber(string name_input, int num_input) {
	number = num_input;
	name = name_input;
}

void PhoneNumber::setName(int name_input) {
	name = name_input;
}

void PhoneNumber::setNumber(int num_input) {
	number = num_input;
}

string PhoneNumber::getName() {
	return name;
}

int PhoneNumber::getNumber() {
	return number;
}