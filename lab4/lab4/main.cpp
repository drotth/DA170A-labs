#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include <iostream>
#include <cassert>
#include <assert.h>
#include "SharedPtr.h"
//#include "WeakPtr.h"

using namespace std;

struct C{
	float value;
	C(float value) :value(value){}
};

void TestG() {
	//-	Konstruktor som tar:	
	//	o	inget	G
	//	o	En SharedPtr	G
	//	o	En pekare	G

	SharedPtr<C> p11;
	assert(!p11);
	SharedPtr<C> p15(nullptr);
	assert(!p15);
	SharedPtr<C> p12(new C(12));
	assert(p12);
	SharedPtr<C> p13(p11);
	assert(!p13);

	assert(p12.unique());
	SharedPtr<C> p14(p12);
	assert(p14);
	assert(!p12.unique());


	//-	Destruktor	G
	//It will test itself
	//-	Tilldelning från en	
	//	o	En SharedPtr	G
	p14 = p12;
	assert(p14);
	p14 = p14;
	assert(p14);

	//-	Jämförelse med (== och <)
	SharedPtr<C> p31(new C(31));
	//	o	En SharedPtr	G
	assert(p11 == nullptr);
	assert(p11 < p12);
	assert(!(p12 < p11));
	assert(p14 == p12);
	assert(!(p14 == p31));
	assert((p14 < p31) || (p31 < p14));

	//get, * och ->
	SharedPtr<C> p41(new C(41));
	SharedPtr<C> p42(new C(42));
	assert((p41->value) == (p41.get()->value));
	assert((p41->value) != (p42.get()->value));
	assert(&(*p41) == (p41.get()));

	p41.reset();
	assert(!p41);
}

//void TestVG(){
//	//Weak pointer skall ha det som det står VG på nedan
//	//-	Konstruktor som tar:		
//	//	o	inget	G	VG
//	//	o	En SharedPtr	G	VG
//	//	o	En WeakPtr	VG	VG
//
//	WeakPtr<C> wp11;
//	assert(wp11.expired());
//	SharedPtr<C> sp12(new C(12));
//	WeakPtr<C> wp13(wp11);
//	assert(wp13.expired());
//	WeakPtr<C> wp14(sp12);
//	assert(!wp14.expired());
//
//	SharedPtr<C> sp17(wp14);
//	assert(sp17);
//
//	//-	Destruktor	G	VG
//	//	It will test itself
//	//-	Tilldelning från en		
//	//	o	En SharedPtr	G	VG
//	//	o	En WeakPtr			VG
//	WeakPtr<C> wp15;
//	wp14 = wp11;
//	assert(wp14.expired());
//
//	SharedPtr<C> sp33(new C(33));
//	wp14 = sp33;
//	assert(!wp14.expired());
//	wp14 = wp14;
//	assert(!wp14.expired());
//
//	sp33.reset();
//	assert(!sp33);
//	assert(wp14.expired());
//
//	//-	funktioner:		
//	//	o	lock()		VG
//	auto sp51 = wp11.lock();
//	assert(!sp51);
//
//	SharedPtr<C>  sp55(new C(55));
//	wp14 = sp55;
//	sp51 = wp14.lock();
//	assert(sp51);
//	////	o	expired()		VG	Redan testat
//}

int main() {
	TestG();
	//TestVG();
	//	system("Pause");
	_CrtDumpMemoryLeaks();
}