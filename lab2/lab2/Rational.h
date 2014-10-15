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

	friend std::istream& operator>> (std::istream & cin, Rational<Tint> R){
		R.P = cin.get();
		cin.get();
		R.Q = cin.get();
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

	Rational operator-(const Rational rhs) const {

		Tint g = GCD(Q, rhs.Q);
		Tint tempQ = Q/g;
		Tint tempP = P * (rhs.Q / g) - rhs.P * tempQ;
		
		g = GCD(tempP, g);
		tempP = tempP/g;
		tempQ = tempQ * (rhs.Q / g);
		return Rational(tempP, tempQ);
	}

	//Rational operator++() const {
	//	Tint P = P + Q;
	//	Reduce(P, Q);
	//}
};