#pragma once


#include "RelOps.h"
#include <iostream>
#include <stdlib.h>
#include <string>

class String{
public:
	char *ptr;
	int size, cap;

	String(){
		ptr = new char[1];
		ptr[0] = '\n';
		size = 0;
		cap = 1;
	}

	String(const String& rhs){
		size = rhs.size;
		cap = rhs.cap;
		char* temp = new char[size+1];
		memcpy(temp, rhs.ptr, sizeof(rhs.ptr[0])* rhs.size);
		delete ptr;
		ptr = temp;
		ptr[size] = '\0';
		//delete temp;
	}

	String(const char* cstr)  {
		size = strlen(cstr);
		cap = size + 1;
		ptr = new char[cap];
		memcpy(ptr, cstr, sizeof(cstr)* size);
		ptr[size] = '\0';
	}

	bool operator== (const String &rhs){
		bool result(false);
		if (size == rhs.size){
			result = true;
			for (int i = 0; i < size; ++i){
				if (ptr[i] != rhs.ptr[i]){
					result = false;
				}
			}
		}
		return result;
	}

	String& operator=(const String& rhs){
		if (ptr != rhs.ptr){
			size = strlen(rhs.ptr);
			cap = size + 1;
			ptr = rhs.ptr;
		}
		return *this;
	}


	String& operator=(const char* cstr){
		if (ptr != cstr){
			size = strlen(cstr);
			cap = size + 1;
			ptr = (char*)cstr;
		}
		return *this;
	}

	String& operator=(char ch){
		if (*ptr != ch){
			size = 1;
			cap = size + 1;
			*ptr = ch;
		}
		return *this;
	}

	String& operator+=(const String& rhs){
		int temp_size = size + rhs.size;
		char* temp = new char[temp_size+1];
		memcpy(temp, ptr, sizeof(ptr[0])* size);
		memcpy(temp+size, rhs.ptr, sizeof(rhs.ptr[0])*rhs.size);
		delete ptr;
		ptr = temp;
		size = temp_size;
		cap = temp_size+1;
		ptr[temp_size] = '\0';
		return *this;


		//*ptr + *rhs.ptr;
		//return *this;
	}

	String& operator+=(char* cstr){
		//size += strlen(cstr);
		//cap = cap + size + 1;
		//char* temp = new char[size];
		//memcpy(temp, cstr, sizeof(rhs.ptr[0])* size);
		//delete ptr;
		//ptr = temp;
		//ptr[size] = '\0';
		//return *this;
		size += strlen(cstr);
		cap = size + 1;
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
		char* temp=new char[amnt];
		memcpy(temp, ptr, sizeof(ptr[0])* size<amnt?size:amnt );
		delete[] ptr;
		ptr = temp;
		//delete temp;
		}

	char& at(int i){
		if (i < 0 || i > size){
			throw out_of_range("error");
		}
		else{
			return ptr[i];
		}
	}

	char& operator[](int i){
		return ptr[i];
	}

	void push_back(char c){
		*ptr + c;
		size += 1;
		cap += 1;
	}

	int length() const{
		return size;		
	}

	void shrink_to_fit(){
		char* temp = new char[cap];
		memcpy(temp, ptr, sizeof(ptr[0])* size);
		//delete ptr;
		ptr = temp;
	}

	int capacity(){
		return cap;
	}

	const char* data() const{
		return ptr;
	}

	friend std::ostream& operator<< (std::ostream &cout, const String& rhs){
		string temp_string = (string)rhs.ptr;
		cout << temp_string << endl;
		return cout;
	}

	~String(){	}

};

