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
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ctime>
using namespace std;

template <int N> struct C {
	int value; //det är denna som används
	int a[N]; //bara en placeholder för att det ska ta tid att kopiera ett C objekt.
};

void uppg1() {
	vector<int> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(arr.value);
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << endl;

	vec.erase(remove_if(vec.begin(), vec.end(), [](int x){return x % 2 == 0; }), vec.end());

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(only uneven number)" << endl;
}

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end) {


	/*Den ska bara använda forward iterator funktionerna
		(dvs.man kan göra 
		*it, ++it, it1 != it2 
		och inte så mycket mera) och sortera containerna den används för.*/
}
void uppg2() {
	//p507 c++-book
	vector<int> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(arr.value);
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << endl << endl;
	ForwardSort(vec.begin(), vec.end());

}

void uppg3a() {
	vector<int> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(arr.value);
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(original)";
	cout << endl << endl;
	reverse_iterator<vector<int>::iterator> rev_from(vec.end());
	reverse_iterator<vector<int>::iterator> rev_until(vec.begin());

	while (rev_from != rev_until) {
		cout << *rev_from++ << " ";
	}
	cout << "(reversed)" << endl;
}

void uppg3b() {
	vector<int> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(arr.value);
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(original)" << endl << endl;

	/*for_each(vec.begin(), vec.end(), [](const int &a){
		
	});*/
	sort(vec.begin(), vec.end(), [](const int &a, int const &b) {
		return b > a; 
	});

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(reversed)" << endl;

}

void uppg4() {
	vector<int> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(arr.value);
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(original)";
	cout << endl << endl;

	sort(vec.begin(), vec.end(), [](const int &a, const int &b){
		return (a > b);
	});

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(reversed)";
}