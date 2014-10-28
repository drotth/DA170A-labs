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
	cout << "(Only uneven number, unsorted)" << endl;
}

template <class ForwardIterator>
void ForwardSort(ForwardIterator begin, ForwardIterator end) {
	vector<int>::iterator it1, it2 = end;
	for (it1 = begin; it1 != it2; ++it1) {
		std::sort(begin, end);
	}
}
void uppg2() {
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
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(Forward sorted)" << endl;
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

	for (reverse_iterator<vector<int>::iterator> itr = vec.rbegin(); itr != vec.rend(); ++itr) {
		//cout << *itr << " ";
		sort(vec.rbegin(), vec.rend());
	}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}

	cout << "(Reversed sorted)" << endl;
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

	sort(vec.begin(), vec.end(), [](const int &a, int const &b) {
		return a > b; 
	});

	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(Reversed sorted)" << endl;

}

void uppg4() {
	vector<int*> vec;
	C<10> arr;
	for (int i = 0; i < 10; ++i) {
		arr.value = rand();
		vec.push_back(&arr.value);
	}
	for (vector<int*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(original)";
	cout << endl << endl;

	sort(vec.begin(), vec.end(), [](int *a, int *b)->bool{
		return (a > b);
	});

	for (vector<int*>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << "(reversed)";
}