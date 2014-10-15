// http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c

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

#include "RefCount.h"

template<typename Tint>
class SharedPtr {
	Tint* pData;
	RefCount* references;
public:
	SharedPtr(Tint* pValue = nullptr, RefCount* rc = new RefCount()) :pData(pValue), references(rc){
		references->addRef();
	}

	SharedPtr(SharedPtr<Tint> &sp) :pData(sp.pData), references(sp.references){
		references->addRef();
	}

	Tint& operator* (){
		return *pData;
	}

	Tint* operator-> (){
		return pData;
	}

	Tint* get(){
		return pData;
	}

	bool unique(){
		if (references->currentCount() == 1) return true;
		else return false;
	}

	void reset(){
		if (references->releaseRef() == 0)
		{
			delete pData;
		}

		pData = nullptr;
	}

	SharedPtr& operator= (const SharedPtr& sp){
		// Avoid self assignment
		if (this != &sp){
			
			// If this SharedPtr is the only reference to a 
			// specific object, then delete that and the previous
			// reference counter
			if (references->releaseRef() == 0)
			{
				delete pData;
				delete references;
			}

			pData = sp.pData;
			references = sp.references;
			references->addRef();
		}
		return *this;
	}

	bool operator== (const SharedPtr& sp) const {
		if (pData == sp.pData){
			return true;
		}
		else return false;
	}

	bool operator< (const SharedPtr& sp) const {
		if (pData < sp.pData){
			return true;
		}
		else return false;
	}

	operator bool() const {
		if (pData == nullptr){
			return false;
		}
		else return true;
	}

	~SharedPtr(){
		if (references->releaseRef() <= 0)
		{
			delete pData;
			delete references;
		}
	}
};