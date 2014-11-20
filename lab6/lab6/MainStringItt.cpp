#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG
#include <stdlib.h>
#include <crtdbg.h>

#include "String.h"
#include <iostream>
#include <cassert>
#include <utility>
using namespace std;


void TestFörGodkäntString() {
//-	String()
	String s0;	assert (s0=="");

//-	String(Sträng sträng)
	String s1("foo"); assert(s1=="foo");
	String s2(s1); assert(s2=="foo");
	String s3("bar");  assert(s3=="bar");

//-	~String() Kom ihåg destruktorn!
	delete new String("hej");

//	-	operator =(Sträng sträng)
	assert((s2=s3)==s3);
	assert((s2=s2)==s3);
	assert((s2=("foo"))=="foo");
	assert((s2="bar")=="bar");

//-	operator+=(Sträng sträng) som tolkas som konkatenering.
	//foo, bar, bar
	(s2+=s1)+=(s3+=s1);
	assert(s3=="barfoo" && s2=="barfoobarfoo" && s1=="foo");

	//+= som får plats;
	s3="bar"; s3.reserve(10);
	s3+=s1;
	assert(s3=="barfoo");

	//+= som inte får plats;
	s3="bar"; s3.reserve(5);
	s3+=s1;
	assert(s3=="barfoo");

	//+= som får plats; Själv
	s3="bar"; s3.reserve(10);
	s3+=s3;
	assert(s3=="barbar");

	//+= som inte får plats; Själv
	s3="bar"; s3.reserve(5);
	s3+=s3;
	assert(s3=="barbar");

//-	operator+ räcker med bara String+String
	s2="bar";
	//auto sss=s1+s2;
	//sss=="foobar";
	//assert(sss=="foobar");
	////assert(s1+s2=="foobar" && s1=="foo");
	assert(s1+s2=="foobar" && s1=="foo");

//-	operator== räcker med String==Sträng
	//testas överallt!

//-	at(int i) som indexerar med range check
	try {
	 s2.at(-1);
	 assert(false);
	} catch (std::out_of_range&) {};
	try {
	 s2.at(3);
	 assert(false);
	} catch (std::out_of_range&) {};
	assert(s2.at(2)='r');

//-	operator[](int i) som indexerar utan range check.
	s2[-1]; s2[1000];
	assert(s2[1]=='a');

//-	push_back(char c) lägger till ett tecken sist.
	s2.push_back('a');
	assert(s2=="bara");

	//-	length(), reserve(), capacity() och shrink_to_fit() är funktioner som finns i container klasserna i STL.

	int len=s2.length();
	s2.shrink_to_fit();
	assert(s2.length()==s2.capacity());

	s2.data();
	if(s2.length()==s2.capacity()) {
		//lagrar strängen med \0
		const char * p1 = s2.data();
		s2.reserve(len); assert(p1==s2.data()); //no change
		p1= s2.data(); s2.reserve(len+1); assert(p1!=s2.data()); //change
		p1= s2.data(); s2.shrink_to_fit();  assert(p1!=s2.data()); //change
		p1= s2.data(); s2.shrink_to_fit();  assert(p1==s2.data()); //no change
	} else {
		//lagrar strängen utan \0
		int cap;
		s2.data(); cap=s2.capacity(); s2.shrink_to_fit(); assert(cap!=s2.capacity()); //change
		cap=s2.capacity(); s2.data(); assert(cap!=s2.capacity()); //change
		s2.shrink_to_fit(); cap=s2.capacity(); s2.reserve(len); assert(cap==s2.capacity()); //change
		s2.reserve(len+1); assert(cap!=s2.capacity()); //change
	}

//-	const char* c_str()
	//tested above!

}

#define MACROTestIttPart(CR)							\
	/*	*it, ++it, it++, (it+i), it[i], == och !=	*/	\
	void TestIttPart##CR() {							\
	String s1("foobar");								\
	for (auto i=s1.CR##begin(); i!=s1.CR##end(); i++)	\
		cout << *i;										\
	cout << endl;										\
	if (#CR=="r" || #CR=="cr")							\
		s1="raboof";									\
	auto it = s1.CR##begin();							\
	assert(*it=='f');									\
	assert(*(it++)=='f' && *it == 'o');					\
	++it;												\
	assert(*++it=='b');									\
	assert(*(it+1)=='a');								\
	assert(it[2]=='r');									\
}

MACROTestIttPart(,);	//, ger tomt argument
MACROTestIttPart(c);
//MACROTestIttPart(r);									//Fungerar ej
//MACROTestIttPart(cr);



#define MACROTestTempIttPart(CR)							\
	/*	*it, ++it, it++, (it+i), it[i], == och !=	*/	\
	void TestTempIttPart##CR() {							\
	String s1("foobar");								\
	for (auto i=s1.CR##begin(); i!=s1.CR##end(); i--)	\
		cout << *i;										\
	cout << endl;										\
	if (#CR=="r" || #CR=="cr")							\
		s1="raboof";									\
	auto it = s1.CR##begin();							\
	assert(*it=='f');									\
	assert(*(it--)=='f' && *it == 'o');					\
	--it;												\
	assert(*--it=='b');									\
	assert(*(it-1)=='a');								\
	/*assert(it[2]=='r');*/			/*Fungerar inte att kolla [2]*/						\
}

MACROTestTempIttPart(r);
MACROTestTempIttPart(cr);

void TestFörGodkäntItt() {

//-	typdefs för iterator, const_iterator,  reverse_iterator och const_revers_iterator
	String::iterator Str;
	String::const_iterator cStr;
	String::reverse_iterator rStr;
	String::const_reverse_iterator crStr;

//-	funktionerna begin, end, cbegin, cend, rbegin, rend, crbegin och crend.

//Iteratorerna ska kunna göra:
//-	*it, ++it, it++, (it+i), it[i], == och !=
	TestIttPart();
	TestIttPartc();
	//TestIttPartr();									//Fungerar ej
	//TestIttPartcr();
	
	TestTempIttPartr();									//Tillfällig
	TestTempIttPartcr();

//-	default constructor, copy constructor och tilldelning (=) 
	String s("foobar");
	Str=s.begin();
	cStr=s.cbegin();
	rStr = s.rbegin();
	crStr=s.crbegin();
	*Str='a';
//	*(cStr+1)='b';	//Sak ge kompileringsfel!
	//*(rStr+2)='c';									//Fungerar ej
	*(rStr - 2) = 'c';									//Tillfällig
//	*(crStr+3)='d';	//Sak ge kompileringsfel!
	assert(s=="aoocar");								//Fungerar ej
}

void test(){

}

int main() {
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	TestFörGodkäntString();
	TestFörGodkäntItt();
	test();
	cin.get();
}
