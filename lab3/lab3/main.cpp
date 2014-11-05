#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "lab3.h"


int main() {
	srand(time(0));
	cout << "Uppgift 1" << endl << endl << endl;
	uppg1();
	
	cout << endl << "Uppgift 2" << endl << endl << endl;
	uppg2();
	
	cout << endl << "Uppgift 3a" << endl << endl << endl;
	uppg3a();
	
	cout << endl << "Uppgift 3b" << endl << endl << endl;
	uppg3b();
	
	cout << endl << "Uppgift 4" << endl << endl << endl;
	uppg4();
	cin.get();
	_CrtDumpMemoryLeaks();
}