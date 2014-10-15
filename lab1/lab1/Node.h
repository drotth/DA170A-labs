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

template <class T>
class List;

template <class T>
class Node {
	friend class List<T>;
private:
	Node *prev, *next;

public:
	T data;
	Node* Prev(){ return prev; }
	Node* Next(){ return next; }
	Node* insertAfter(List<T> *list, T data);
	Node* insertBefore(List<T> *list, T data);
	Node(Node* prev, Node* next, T data) :prev(prev), next(next), data(data){}
};

template <class T>
Node<T>* Node<T>::insertAfter(List<T> *list, T data){
	Node* newNode = new Node(this, next, data);
	if (next != nullptr){
		next->prev = newNode;
	}
	else{
		list->last = newNode;
	}
	next = newNode;
	return newNode;
}

template <class T>
Node<T>* Node<T>::insertBefore(List<T> *list, T data){
	Node* newNode = new Node(prev, this, data);
	if (prev != nullptr){
		prev->next = newNode;
	}
	else{
		list->first = newNode;
	}

	prev = newNode;
	return newNode;
}