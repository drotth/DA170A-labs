#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class ConstMyRevIt{
public:
	char *pointer;

	ConstMyRevIt(){
		pointer = nullptr;
	}

	ConstMyRevIt(char *incoming_pointer){
		pointer = incoming_pointer;
	}

	const char& operator*(){
		return *pointer;
	}

	ConstMyRevIt& operator++(){
		--pointer;
		return *this;
	}

	ConstMyRevIt operator++(int){
		ConstMyRevIt temp = pointer;
		pointer -= 1;
		return temp;
	}

	ConstMyRevIt operator+(const int value){
		ConstMyRevIt temp(pointer - value);
		return temp;
	}

	bool operator==(const ConstMyRevIt &rhs){
		return pointer == rhs.pointer;
	}

	bool operator!=(const ConstMyRevIt &rhs){
		return pointer != rhs.pointer;
	}

	const char& operator[](int i){
		return pointer[-i];
	}
};
