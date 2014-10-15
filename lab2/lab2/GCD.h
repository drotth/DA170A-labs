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

template<typename Tint>
Tint GCD(Tint A, Tint B) {
	if (A<B)
		return GCD(B, A);
	while (B != 0) {
		Tint temp = A%B;
		A = B;
		B = temp;
	}
	if (A>0)	//behövs testen?????
		return A;
	else
		return 1;
}

template<typename Tint>
void Reduce(Tint& A, Tint& B) {
	Tint gcd = GCD(A, B);
	A /= gcd;
	B /= gcd;
}
