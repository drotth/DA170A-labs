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

#include <iostream>
#include "GCD.h"
#include "RelOps.h"

template<typename Tint>
class Rational {
public:
	Tint P, Q;

	Rational(Tint P = 0, Tint Q = 1) :P(P), Q(Q) {
		Reduce(P, Q);
	}

	//template <typename rat>
	//Rational(Rational<rat> R) : P(R.P), Q(R.Q) {}

	bool operator== (const Rational rhs) const{
		return (P == rhs.P && Q == rhs.Q);
	}

	Rational operator+ (const Rational rhs) const {
		Tint newP = rhs.Q*P + Q*rhs.P;
		Tint newQ = Q*rhs.Q;
		return Rational(newP, newQ);
	}

	Rational operator+= (const Rational rhs) {
		P = rhs.Q*P + Q*rhs.P;
		Q = Q*rhs.Q;
		Reduce(P, Q);
		return *this;
	}

	Rational operator- () {
		return Rational(-P,Q);
	}

	// Used as ++Rational
	Rational operator++ () {
		P += Q;
		Reduce(P, Q);
		return *this;
	}


	// Used as Rational++
	Rational operator++ (int) {
		Rational tempRat = *this;
		P += Q;
		Reduce(P, Q);
		return tempRat;
	}

	template <typename rat>
	explicit operator rat () const {
		return rat (P / Q);
	};

	friend std::ostream& operator<< (std::ostream &cout, Rational<Tint> R){
		cout << R.P << '/' << R.Q;
		return cout;
	}

	friend std::istream& operator>> (std::istream &cin, Rational<Tint> & R){
		cin >> R.P;
		cout << '/';
		cin >> R.Q;
		return cin;
	}
};