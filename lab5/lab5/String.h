#pragma once
#include "RelOps.h"

class String{

public:
	char *string_ptr;
	int size, cap;

	String(){
		size = 0;
		cap = 0;

		string_ptr = new char[1];
		string_ptr[0] = '\0';
	}

	String(const String &rhs){
		size = rhs.size;
		cap = rhs.cap;

		string_ptr  = new char[size +1];
		memcpy(string_ptr, rhs.string_ptr, sizeof(*string_ptr) * (size +1));
		string_ptr[size] = '\0';
	}

	String(const char* cstr){
		size = strlen(cstr);
		cap = size;

		string_ptr = new char[size +1];
		memcpy(string_ptr, cstr, sizeof(*string_ptr) * (size +1));
		string_ptr[size] = '\0';
	}

	~String(){
		delete[] string_ptr;
	}

	bool operator==(const String &rhs){
		bool result = false;

		if (size == rhs.size){
			for (int i = 0; i < size; ++i){
				if (string_ptr[i] != rhs.string_ptr[i]){
					return false;
				}
			}
			result = true;
		}

		return result;
	}

	String& operator= (const String& rhs){
		if (string_ptr != rhs.string_ptr){
			size = rhs.size;
			cap = rhs.cap;

			char* temp = new char[size +1];
			delete[] string_ptr;
			memcpy(temp, rhs.string_ptr, sizeof(*string_ptr) * (size +1));
			string_ptr = temp;
			string_ptr[size] = '\0';
		}

		return *this;
	}

	String& operator= (const char* cstr){
		if (string_ptr != cstr){
			size = strlen(cstr);
			cap = size;

			char* temp = new char[size +1];
			delete[] string_ptr;
			memcpy(temp, cstr, sizeof(*string_ptr) * (size +1));
			string_ptr = temp;
			string_ptr[size] = '\0';
		}

		return *this;
	}

	String& operator= (char ch){
		if (string_ptr[0] != ch && size > 1){
			size = 1;
			cap = 1;

			delete[] string_ptr;
			string_ptr = new char[size +1];
			string_ptr[0] = ch;
			string_ptr[1] = '\0';
		}

		return *this;
	}

	String& operator += (const String& rhs){
		int temp_size = size + rhs.size;
		char* temp = new char[temp_size +1];

		memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));
		memcpy((temp + size), rhs.string_ptr, sizeof(*string_ptr) * (temp_size +1));

		delete[] string_ptr;
		string_ptr = temp;
		size = temp_size;
		cap = cap + rhs.cap;
		string_ptr[size] = '\0';

		return *this;
	}

	String& operator+=(char* cstr){
		int temp_size = size + strlen(cstr);
		char* temp = new char[temp_size + 1];

		memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));
		memcpy((temp + size), cstr, sizeof(*string_ptr) * (temp_size +1));

		delete[] string_ptr;
		string_ptr = temp;
		size = temp_size;
		cap = cap + strlen(cstr);
		string_ptr[size] = '\0';

		return *this;
	}

	String operator+(String const rhs) const{
		//int temp_size = size + rhs.size;
		//char* temp = new char[temp_size + 1];

		//memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));
		//memcpy((temp + size), rhs.string_ptr, sizeof(*string_ptr) * (temp_size +1));

		String s = String(*this);
		//delete[] temp;

		return s+=rhs;
	}

	String& operator+(char* cstr){
		int temp_size = size + strlen(cstr);
		char* temp = new char[temp_size +1];

		memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));
		memcpy((temp + size), cstr, sizeof(*string_ptr) * (temp_size +1));

		String s = String(temp);
		delete[] temp;

		return s;
	}

	void reserve(int amount){
		if (amount > cap){
			char* temp = new char[amount];

			memcpy(temp, string_ptr, sizeof(*string_ptr) * amount);

			delete[] string_ptr;
			string_ptr = temp;
			string_ptr[size] = '\0';
			cap = amount;
		}
	}

	char& at(int i){
		if (i < 0 || i >= size){
			throw out_of_range("Out-of-range error");
		}
		else{
			return string_ptr[i];
		}
	}

	char& operator[](int i){
		return string_ptr[i];
	}

	void push_back(const char c){
		char* temp = new char[size + 2];

		memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));
		
		temp[size] = c;
		delete[] string_ptr;
		string_ptr = temp;

		size += 1;
		cap += 1;

		string_ptr[size] = '\0';
	}

	int length() const{
		return size;
	}

	int capacity() const{
		return cap;
	}

	void shrink_to_fit(){
		if (size < cap){
			char* temp = new char[size+1];

			memcpy(temp, string_ptr, sizeof(*string_ptr) * (size +1));

			delete[] string_ptr;
			string_ptr = temp;
			string_ptr[size] = '\0';
			cap = size;
		}
	}

	const char* data() const{
		return string_ptr;
	}

	friend std::ostream& operator<< (std::ostream &cout, const String& rhs){
		string temp_string = (string) rhs.string_ptr;
		cout << temp_string << endl;

		return cout;
	}
};