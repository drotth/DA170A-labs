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
	
	cout << "Uppgift 1: ---------------------------------------------------------" << endl;
	uppg1();
	
	cout << "Uppgift 2: ---------------------------------------------------------" << endl;
	uppg2();
	
	cout << "Uppgift 3a: ---------------------------------------------------------" << endl;
	uppg3a();
	
	cout << "Uppgift 3b: ---------------------------------------------------------" << endl;
	uppg3b();
	
	cout << "Uppgift 4: ---------------------------------------------------------" << endl;
	uppg4();

	cin.get();
	_CrtDumpMemoryLeaks();
}