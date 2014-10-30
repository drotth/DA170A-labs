#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "RelOps.h"
#include <iostream>

class String{
public:
	char *word;
	String();
	//String(const String& rhs);
	//String(const char* cstr);
	//String& operator=(const String& rhs);
	//String& operator=(const char* cstr);
	//String& operator=(char ch);

	/*
	indexerar med range check “Bounds checking is
	performed, exception of type std::out_of_range will be
	thrown on invalid access.”
	*/
	//char& at(int i);


	/*
	indexerar utan range check
	*/
	//char& operator[](int i);


	/*
	gives a reference to the internal array holding the string,
	it must also be null character terminated (meaning that
	there must be an extra null character last in your array)*/
	//const char* data() const;

	/*
	finns i container klasserna i STL, se basic_string
	*/
	//int length() const;

	/*
	finns i container klasserna i STL, se basic_string
	*/
	//void reserve(int);

	/*
	finns i container klasserna i STL, se basic_string
	*/
	//int capacity() const;

	/*
	till skillnad från std så krävs här att utrymmet krymps
	maximalt så String tar så lite utrymme som möjligt.
	*/
	//void shrink_to_fit();

	/*
	lägger till ett tecken sist
	*/
	//void push_back(char c);

	/*
	Ändrar antalet tecken till n, om n>length så fylls det på
	med ”char()”
	*/
	//void resize(int n);

	/*
	tolkas som konkatenering.
	*/
	//String& operator+=(const String& rhs);

	/*
	tolkas som konkatenering.
	*/
	//String& operator+=(char* cstr);

	/*
	ok med medlemsfunktion
	*/
	//String operator+();

	/*
	global function
	*/
	//friend bool operator==(const String& lhs, const String& rhs);

	/*
	För test: Görs enklast genom att konvertera till
	std::string och skriva ut den.
	*/
	//friend std:: ostream& operator<< (std::ostream&cout, String in);


	~String();

};

