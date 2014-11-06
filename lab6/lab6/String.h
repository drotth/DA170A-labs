#pragma once


#include "RelOps.h"
#include <iostream>
#include <stdlib.h>
#include <string>

class String{
public:
	char *ptr;

	String(char *input = ""){	
		const size_t length = strlen(input);
		ptr = new char[length];
		*ptr = *input;
	}

	String(const String& rhs){
		const size_t length = strlen(rhs.ptr);
		//delete ptr;
		ptr = new char[length];
		ptr = rhs.ptr;
	}

	String(const char* cstr) : ptr((char*)cstr)  {
		const size_t length = strlen(cstr);
		//delete ptr;
		ptr = new char[length];
		ptr = (char*)cstr;
	}

	bool operator== (const String &rhs){
		return (*ptr == *rhs.ptr);
	}

	String& operator=(const String& rhs){
		if (ptr != rhs.ptr){
			const size_t length = strlen(rhs.ptr);
			ptr = new char[length];
			//delete ptr;
			ptr = rhs.ptr;
		}
		return *this;
	}


	String& operator=(const char* cstr){
		if (ptr != cstr){
			const size_t length = strlen(cstr);
			ptr = new char[length];
			//delete ptr;
			ptr = (char*)cstr;
		}
		return *this;
	}

	String& operator=(char ch){
		if (*ptr != ch){
			ptr = new char[1];
			delete ptr;
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
		*ptr = *temp;
	}

	char& at(int i){
		char ret = ptr[i];
		return ret;
	}

	char& operator[](int i){
		char ret;
		if (i < 0){
			ret = '\0';
		}
		else {
			ret = ptr[i];
		}
		return ret;
	}

	void push_back(char c){
		&ptr + c;
	}

	int length() const{
		//int i = 0;
		//while (ptr[i] != '\0'){
		//	++i;
		//}
		//return i+1;
		
		
		string temp = (string)ptr;
		int i = temp.length();
		return temp.length();
		
	}

	void shrink_to_fit(){
		string temp_string = (string)ptr;
		int length = temp_string.size();

		//delete ptr;
		ptr = new char[length];
		for (int i = 0; i < length; ++i){
			ptr[i] = temp_string[i];
		}
		//char temp_char[(length+1)];
		//temp_string.shrink_to_fit();
		//ptr = *temp;
	}

	int capacity(){
		
		string temp = (string)ptr;
		int i = temp.capacity();
		return temp.capacity();
	}

	const char* data() const{
		char temp = *ptr;
		return &temp;
	}
	
	friend std::ostream& operator<< (std::ostream &cout, const String& rhs){
		string temp_string = (string)rhs.ptr;
		cout << temp_string << endl;
		return cout;

	~String(){ 
		//int i = 0;
		//while (ptr[i] != '\0')
		//	++i;
		//for (int j = 0; j < i; ++j)
		//	delete &ptr[j];
		
		//delete[] ptr;
	}






	////////////////////////////////////////////////////////
	////////				Lab6					////////
	////////////////////////////////////////////////////////
	typedef int iterator;
	typedef int const_iterator;
	typedef int reverse_iterator;
	typedef int const_reverse_iterator;

	int begin(){
		int i = 0;
		return i;
	}

	int end(){
		int i = 0;
		return i;
	}

	const int cbegin(){
		int i = 0;
		return i;
	}

	const int cend(){
		int i = 0;
		return i;
	}

	int rbegin(){
		int i = 0;
		return
	}

	int rend(){
		int i = 0;
		return
	}

	const int crbegin(){
		int i = 0;
		return
	}

	const int crend(){
		int i = 0;
		return
	}

};

