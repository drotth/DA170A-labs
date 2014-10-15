//http://www.boost.org/doc/libs/1_56_0/boost/rational.hpp
//http://www.boost.org/doc/libs/1_56_0/libs/rational/rational.html

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

	friend std::ostream& operator<< (std::ostream & cout, Rational<Tint> R){
		cout << R.P << '/' << R.Q;
		return cout;
	}

	friend std::istream& operator>> (std::istream & cin, Rational<Tint> & R){
		cin >> R.P;
		cout << '/';
		cin >> R.Q;
		return cin;
	}

	Rational(Tint P=0, Tint Q=1) :P(P), Q(Q) {
		Reduce(P, Q);
	}

	template <typename rat>
	Rational(Rational<rat> R) : P(R.P), Q(R.Q) {

	}

	bool operator==(const Rational rhs) const{
		if (P == rhs.P  && Q == rhs.Q){
			return true;
		}
		else
			return false;
	}

	Rational operator+(const Rational rhs) const {
		Tint tempP = rhs.Q*P + Q*rhs.P;
		Tint tempQ = Q*rhs.Q;
		return Rational(tempP, tempQ);
	}

	Rational operator+=(const Rational rhs) {
		P = rhs.Q*P + Q*rhs.P;
		Q = Q*rhs.Q;
		GCD(P, Q);
		return *this;
	}

	Rational operator-() {
		return Rational(-P,Q);
	}

	/*
	* Used as ++Rational
	*/
	Rational operator++() {
		P += Q;
		return *this;
	}

	/*
	* Used as Rational++
	*/
	Rational operator++(int) {
		Rational tempRat = *this;
		P += Q;
		return tempRat;
	}

	explicit operator int() const {
		return int(P / Q);
	};
};