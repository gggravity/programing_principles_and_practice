//
// Created by martin on 15/01/2022.
//

#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include <ostream>

class Rational
	  {
		public:
			Rational ();

			Rational (int numerator, int denominator);

			int get_numerator () const;

			void set_numerator (int numerator);

			int get_denominator () const;

			void set_denominator (int denominator);

			Rational &operator= (const Rational &rational);

		private:
			int numerator;
			int denominator;
	  };

Rational operator+ (const Rational &lhs, const Rational &rational);

Rational operator- (const Rational &lhs, const Rational &rhs);

Rational operator* (const Rational &lhs, const Rational &rhs);

Rational operator/ (const Rational &lhs, const Rational &rhs);

bool operator< (const Rational &lhs, const Rational &rhs);

bool operator> (const Rational &lhs, const Rational &rhs);

bool operator<= (const Rational &lhs, const Rational &rhs);

bool operator>= (const Rational &lhs, const Rational &rhs);

std::ostream &operator<< (std::ostream &os, const Rational &rational);

bool operator== (const Rational &lhs, const Rational &rhs);

bool operator!= (const Rational &lhs, const Rational &rhs);


int greatest_common_factor(int a, int b);

#endif //_RATIONAL_H_
