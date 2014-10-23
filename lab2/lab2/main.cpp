#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include <assert.h>
#include "Rational.h"

using namespace std;

typedef Rational<short> Rshort;
typedef Rational<int> Rint;
typedef Rational<long long> RLL;

void TestFörGodkänt() {

	Rshort rs0, rs1(1), rs2(2, 1), rs3(3);
	Rint ri0;
	RLL rll0, rll1(1), rll2(2, 1), rll3(3);

	//Konstrueras från ”Tal” dvs. Rtal rtal(tal);
	RLL rllx(1);
	RLL rlly(rs0);

	//Jämföras med == dvs. if (rtal == tal) …
	assert(rs1 == rs1);
	assert(rs2 == 2);
	assert(rs1 == rll1);

	//Jämföras med !=
	assert(rs2 != rll1);

	//Tilldelas (=) från ”Tal” dvs. rtal=tal;
	rs3 = Rint(13, 3);
	assert(rs3 == Rshort(13, 3));
	rs3 = rll3 = -17;
	assert(rs3 == Rshort(-17));

	//+= med ”Tal” dvs. rtal += tal;
	assert((rs3 += 4) == Rshort(-13));

	//+  dvs. (rtal + tal)
	rs3=Rshort(13,3);
	assert(rs3+rll2 == Rshort(19,3));
	assert(rs3+2 == Rshort(19,3));

	//unärt ”–” dvs. rtal1 = -rtal2;
	assert((rs0 = -1) == -1);
	assert((rs0=-rs1) == Rshort(-1));

	////båda ++ operatorerna, dvs. ++rtal; rtal++;
	rll3 = RLL(1,6);
	assert(++rll3 == RLL(7,6));
	assert(rll3++ == RLL(7,6));
	assert(rll3 == RLL(13,6));

	// explicit konvertering till Tal. (Kräver VS2012 och kompilator CTP november 12.
	int i = static_cast<int>(rll3);
	assert(i==2);
	

	// Overloading av << och >> (ut och in matning)
	std::cout << "Utmatning>" << rs3 << "< skriv in texten mellan > och < + retur\n";
	std::cin >> rs2;
	std::cout << "This rational was typed in: " << rs2 << endl;
	assert(rs3==rs2);


	cin.get();
	cin.get();

}

//void TestFörVälGodkänt() {
//	Rshort as0, as1(1), as2(2,1), as3(3);
//	RLL all0, all1(1), all2(2,1), all3(3);
//	assert (1000000+Rshort(1,2) == Rint(2000001,2));	//blir bara rätt om man man räknar med int
//	assert (Rshort(1,2)+1000000 == Rint(2000001,2));	//blir bara rätt om man man räknar med int
//	assert (RLL(10000000LL)+Rshort(1,2) == RLL(20000001,2));	//blir bara rätt om man man räknar med int
//
//	assert (Rshort(10000, 81)+Rshort(10000, 81) == Rshort(20000, 81));	//blir bara rätt om man man räknar med int
//
//	assert ((Rshort(1)+(short)SHRT_MAX)==SHRT_MIN);
//	assert ((Rshort(1)+(int)INT_MAX)==INT_MIN);
//}

int main() {
	TestFörGodkänt();
	//TestFörVälGodkänt();
	_CrtDumpMemoryLeaks();
}
