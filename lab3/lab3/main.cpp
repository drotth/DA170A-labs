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

void printline(int number)
{
	if (number == 3){
		cout << endl << "Uppgift 3a:";
	} 
	else if (number == 4){
		cout << endl << "Uppgift 3b:";
	}
	else if (number == 5){
		cout << endl << "Uppgift 4";
	}
	else{
		cout << endl << "Uppgift " << number << " :";
	}
	
	cout << endl<< "-------------------------------------------------------------------" << endl;
}

int main() {
	int number = 0;
	srand(time(0));
	/*printline(++number);
	
	uppg1();
	
	printline(++number);*/
	uppg2();
	
	//printline(++number);
	//uppg3a();
	//
	//printline(++number);
	//uppg3b();	//lambda function not working correctly
	//
	//printline(++number);
	//uppg4();
	cin.get();
	_CrtDumpMemoryLeaks();
}