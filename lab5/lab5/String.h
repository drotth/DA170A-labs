#pragma once


#include "RelOps.h"
#include <iostream>
#include <stdlib.h>

class String{
public:
	char *ptr;

	String(char *input = "") : ptr(input){	}

	String(const String& rhs) : ptr(rhs.ptr){	}

	String(const char* cstr) : ptr((char*)cstr)  {	}

	bool operator== (const String &rhs){
		return (*ptr == *rhs.ptr);
	}

	String& operator=(const String& rhs){
		if (ptr != rhs.ptr){
			ptr = rhs.ptr;
		}
		return *this;
	}


	String& operator=(const char* cstr){
		if (ptr != cstr){
			ptr = (char*)cstr;
		}
		return *this;
	}

	String& operator=(char ch){
		if (*ptr != ch){
			*ptr = ch;
		}
		return *this;
	}

	String& operator+=(const String& rhs){
		*ptr + *rhs.ptr;
		return *this;
	}

	String& operator+=(char* cstr){
		*ptr + cstr;
		return *this;
	}

	String& operator+(const String& rhs){
		return operator+=(rhs);
	}

	String& operator+(char* cstr){
		return operator+=(cstr);
	}

	void reserve(int amnt){
		char temp[10];
		int i = 0;
		for (i; (i < amnt && ptr[i] != '\0') ; ++i){
			temp[i] = ptr[i];
		}
		if (i < amnt){
			temp[i] = '\0';
		}


		//temp[0] += *ptr;
		//*temp += *rhs.ptr;
		////*ptr += *rhs.ptr;
		ptr = temp;
	}

	~String(){
		//delete ptr;
	}

};

