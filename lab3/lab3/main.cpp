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
	//uppg1();
	uppg2();
	//uppg3a();
	//uppg3b();	//lambda function not working correctly
	//uppg4();
	_CrtDumpMemoryLeaks();
}