#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "PhoneRegister.h"

using namespace std;

void testProgram(){
	int num_input;
	string name_input;
	string line = string(20, '-');
	PhoneRegister regget(10);
	regget.addNumber("Magnus", 123);
	regget.addNumber("Annika", 456);
	regget.addNumber("Kalle", 789);
	regget.addNumber("Mattias", 321);
	regget.addNumber("Soded", 654);

	regget.printRegister();
	cout << line << endl;

	cout << "Radera med nummer: ";
	cin >> num_input;
	regget.deleteNumber(num_input);
	cout << endl;
	regget.printRegister();
	cout << line << endl;

	cout << "Radera med namn: ";
	cin >> name_input;
	regget.deleteName(name_input);
	cout << endl;
	regget.printRegister();
	cout << line << endl;

	for (int i = 0; i < 2; i++){
		cout << "Sök med namn: ";
		cin >> name_input;
		if (regget.searchName(name_input, num_input)){
			cout << endl << name_input << " har nummer: " << num_input;
		}
		else cout << endl << name_input << " har inget nummer i registret";
		cout << endl << line << endl;
	}

	cin.get();
	cin.get();
	//_CrtDumpMemoryLeaks(); // will show memory leak
}

int main(){
	testProgram();
	_CrtDumpMemoryLeaks(); // no memory leak
	return 0;
}