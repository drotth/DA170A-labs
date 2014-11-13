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

#include <algorithm>
#include <vector>
#include <iostream>
//#include <iterator>
#include <ctime>

using namespace std;

template <int N> struct C {
	float value; //det är denna som används
	int a[N]; //bara en placeholder för att det ska ta tid att kopiera ett C objekt.
};

void uppg1() {
	vector<float> vec;
	C<10> c_obj;

	for (int i = 0; i < 10; ++i) {
		c_obj.value = (float) rand();
		vec.push_back(c_obj.value);
	}

	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(original)" << endl << endl;

	vec.erase(
		remove_if(
			vec.begin(), vec.end(), [](float x){
			return fmod(x, 2) == 0; }
		), vec.end()
	);
	
	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(uneven numbers remaning)" << endl << endl;
}

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end) {
	bool done(false);

	while (begin != end && done != true) {
		done = true;
		ForwardIterator iter(begin);

		while ((iter+1) != end) {
			if (*(iter + 1) < *iter) {
				swap(*(iter + 1), *iter);
				done = false;
			}
			++iter;
		}
		--end;
	}
}

void uppg2() {
	vector<float> vec;
	C<10> c_obj;

	for (int i = 0; i < 10; ++i) {
		c_obj.value = (float) rand();
		vec.push_back(c_obj.value);
	}

	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(original)" << endl << endl;

	ForwardSort(vec.begin(), vec.end());
	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(forward-sorted)" << endl << endl;
}

void uppg3a() {
	vector<float> vec;
	C<10> c_obj;

	for (int i = 0; i < 10; ++i) {
		c_obj.value = (float) rand();
		vec.push_back(c_obj.value);
	}

	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(original)" << endl << endl;

	// algorithm sort med reverse_iterator
	sort(vec.rbegin(), vec.rend());
	
	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(reverse-sorted)" << endl << endl;
}

void uppg3b() {
	vector<float> vec;
	C<10> c_obj;

	for (int i = 0; i < 10; ++i) {
		c_obj.value = (float) rand();
		vec.push_back(c_obj.value);
	}

	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(original)" << endl << endl;

	sort(vec.begin(), vec.end(), [](float a, float b) {
		return a > b; 
	});

	for (vector<float>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(reverse-sorted)" << endl << endl;

}

// Använder float-objekt (pointers)
//void uppg4() {
//	vector<float*> vec;
//	float point;
//
//	for (int i = 0; i < 10; ++i) {
//		point = (float) rand();
//		vec.push_back(new float(point));
//	}
//
//	for (vector<float*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
//		cout << **itr << " ";
//	}
//
//	cout << "(original)" << endl << endl;
//
//	sort(vec.begin(), vec.end(), [](float *a, float *b){
//		return (*a < *b);
//	});
//
//	for (vector<float*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
//		cout << **itr << " ";
//	}
//
//	cout << "(forward-sorted)" << endl;
//
//	for (int i = 0; i < vec.size(); ++i) delete vec[i];
//}

// Använder faktiska C-objekt (pointers) enligt uppgiften
void uppg4() {
	vector<C<10>*> vec;

	for (int i = 0; i < 10; ++i) {
		C<10>* vecPtr = new C<10>;
		vecPtr->value = (float)rand();
		vec.push_back(vecPtr);
	}

	for (vector<C<10>*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << (*itr)->value << " ";
	}

	cout << "(original)" << endl << endl;

	sort(vec.begin(), vec.end(), [](C<10> *a, C<10> *b){
		return ((*a).value < (*b).value);
	});

	for (vector<C<10>*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << (*itr)->value << " ";
	}

	cout << "(sorted)" << endl;

	for (int i = 0; i < vec.size(); ++i)
		delete vec[i];
}