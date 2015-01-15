#pragma once


#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


class MyRevIt{
public:
	char *pointer;

	MyRevIt(){
		pointer = nullptr;
	}

	MyRevIt(char *incoming_pointer){
		pointer = incoming_pointer;
	}

	char& operator*(){
		return *pointer;
	}

	MyRevIt& operator++(){
		--pointer;
		return *this;
	}

	MyRevIt operator++(int){
		MyRevIt temp = pointer;
		pointer -= 1;
		return temp;
	}

	MyRevIt operator+(const int value){
		MyRevIt temp(pointer - value);
		return temp;
	}

	bool operator==(const MyRevIt &rhs){
		return pointer == rhs.pointer;
	}

	bool operator!=(const MyRevIt &rhs){
		return pointer != rhs.pointer;
	}

	char& operator[](int i){
		return pointer[-i];
	}

	MyRevIt operator=(char* ch){
		pointer = ch;
		return *this;
	}
};
