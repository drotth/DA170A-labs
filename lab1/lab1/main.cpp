#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

using namespace std;

#include <iostream>
#include <assert.h>
#include "List.h"

void testLinkedList(){
	List<float> myList;
	assert(myList.Check(0));
	myList.push_back(3.4f);
	assert(myList.Check(1));
	myList.push_back(3.5f);
	assert(myList.Check(2));
	if (!myList.empty()) myList.pop_back();
	if (!myList.empty()) myList.pop_back();
	if (!myList.empty()) myList.pop_back();
	assert(myList.Check(0));

	myList.push_front(3.7f);
	myList.push_front(3.8f);
	assert(myList.Check(2));
	if (!myList.empty()) myList.pop_front();
	assert(myList.Check(1));
	myList.push_front(3.8f);
	myList.push_front(3.8f);
	assert(myList.Check(3));

	myList.Last()->insertBefore(&myList, 3.6f);
	Node<float> *p_temp = myList.First()->insertAfter(&myList, 3.6f);
	assert(myList.Check(5));

	p_temp->insertAfter(&myList, 3.9f);
	assert(myList.Check(6));

	myList.First()->insertBefore(&myList, 4.0f);
	assert(myList.Check(7));

	myList.Last()->insertAfter(&myList, 4.1f);
	assert(myList.Check(8));

	if (!myList.empty()) myList.pop_front();
	assert(myList.Check(7));
}

int main(){
	testLinkedList();
	_CrtDumpMemoryLeaks();
	return 0;
}