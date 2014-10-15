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

#include "Node.h"

template <class T>
class List {
	friend class Node<T>;
private:
	Node<T> *last, *first;

public:
	Node<T>* First(){ return first; }
	Node<T>* Last(){ return last; }
	Node<T>* push_front(T data);
	Node<T>* push_back(T data);
	T pop_front();
	T pop_back();
	bool Check(int count);
	bool empty();
	List() :first(nullptr), last(nullptr){}
	~List();
};

template <class T>
Node<T>* List<T>::push_front(T data){
	if (first != nullptr){
		first = (first->insertBefore(this, data));
	}

	else{
		first = new Node<T>(nullptr, nullptr, data);
		last = first;
	}
	return first;
}

template <class T>
Node<T>* List<T>::push_back(T data){
	if (last != nullptr){
		last = (last->insertAfter(this, data));
	}

	else{
		last = new Node<T>(nullptr, nullptr, data);
		first = last;
	}
	return last;
}

template <class T>
T List<T>::pop_front(){
	T temp_data = first->data;
	Node<T>* temp_pointer = first;

	first = first->next;
	if (first != nullptr){
		first->prev = nullptr;
	}
	else last = nullptr;

	delete temp_pointer;
	return temp_data;
}

template <class T>
T List<T>::pop_back(){
	T temp_data = last->data;
	Node<T>* temp_pointer = last;

	last = last->prev;
	if (last != nullptr){
		last->next = nullptr;
	}
	else first = nullptr;

	delete temp_pointer;
	return temp_data;
}

template <class T>
bool List<T>::Check(int count) {
	//count anger hur många noder som förväntas i strukturen.
	//true betyder att allt var ok
	if ((count == 0) ^ (first == nullptr))
		return false; //tom lista ska ha first=null och tvärtom.
	if (first == nullptr)
		return (last == nullptr && count == 0);
	if ((last == nullptr) || count == 0)
		return false;
	//nu är first och last != null och count!=0)
	Node <T> * node = first;
	Node <T> * lastNode = nullptr;
	while (node != nullptr && count>0) {
		if (lastNode != node->prev)
			return false;
		count--;
		lastNode = node;
		node = node->next;
	}
	return (lastNode == last) && count == 0;
}

template <class T>
bool List<T>::empty(){
	if (first == nullptr){
		return true;
	}
	else return false;
}

template <class T>
List<T>::~List(){
	while (first != nullptr) {
		Node<T>* next = first->next;
		delete first;
		first = next;
	}
}