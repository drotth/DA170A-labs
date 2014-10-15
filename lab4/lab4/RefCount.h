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

class RefCount{
private:
	int count;

public:
	void addRef(){
		count++;
	}

	int releaseRef(){
		// Decrement the reference count and return it
		return --count;
	}

	int currentCount(){
		return count;
	}
};