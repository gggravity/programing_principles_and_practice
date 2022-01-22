//
// Created by martin on 15/01/2022.
//

#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational () :
	numerator {0},
	denominator {0}
  { }

Rational::Rational (int numerator, int denominator) : numerator(numerator),
													  denominator(denominator)
  { }

std::ostream &operator<< (std::ostream &os, const Rational &rational)
  {
	os << "numerator: " << rational.get_numerator() << " denominator: " << rational.get_denominator();
	return os;
  }

Rational operator+ (const Rational &lhs, const Rational &rhs)
  {
	int a = lhs.get_numerator();
	int b = lhs.get_denominator();
	int c = rhs.get_numerator();
	int d = rhs.get_denominator();
	int numerator = a * d + b * c;
	int denominator = b * d;
	int gcf = greatest_common_factor(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
	return {numerator, denominator};
  }

Rational operator- (const Rational &lhs, const Rational &rhs)
  {
	int a = lhs.get_numerator();
	int b = lhs.get_denominator();
	int c = rhs.get_numerator();
	int d = rhs.get_denominator();
	int numerator = a * d + b * c;
	int denominator = b * d;
	int gcf = greatest_common_factor(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
	return {numerator, denominator};
  }

Rational operator* (const Rational &lhs, const Rational &rhs)
  {
	int a = lhs.get_numerator();
	int b = lhs.get_denominator();
	int c = rhs.get_numerator();
	int d = rhs.get_denominator();
	int numerator = a * c;
	int denominator = b * d;
	int gcf = greatest_common_factor(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
	return {numerator, denominator};
  }

Rational operator/ (const Rational &lhs, const Rational &rhs)
  {
	int a = lhs.get_numerator();
	int b = lhs.get_denominator();
	int c = rhs.get_numerator();
	int d = rhs.get_denominator();
	int numerator = a * d;
	int denominator = b * c;
	int gcf = greatest_common_factor(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
	return {numerator, denominator};
  }

bool operator< (const Rational &lhs, const Rational &rhs)
  {
	double num_l = double(lhs.get_numerator()) / lhs.get_denominator();
	double num_r = double(rhs.get_numerator()) / rhs.get_denominator();
	return num_l < num_r;
  }

bool operator> (const Rational &lhs, const Rational &rhs)
  {
	return rhs < lhs;
  }

bool operator<= (const Rational &lhs, const Rational &rhs)
  {
	return !(rhs < lhs);
  }

bool operator>= (const Rational &lhs, const Rational &rhs)
  {
	return !(lhs < rhs);
  }

Rational &Rational::operator= (const Rational &rational)
  {
	numerator = rational.get_numerator();
	denominator = rational.get_denominator();
	return *this;
  }

bool operator== (const Rational &lhs, const Rational &rhs)
  {
	return lhs.get_numerator() == rhs.get_numerator() &&
		   lhs.get_denominator() == rhs.get_denominator();
  }

bool operator!= (const Rational &lhs, const Rational &rhs)
  {
	return !(rhs == lhs);
  }

int Rational::get_numerator () const
  {
	return numerator;
  }

void Rational::set_numerator (int numerator)
  {
	this->numerator = numerator;
  }

int Rational::get_denominator () const
  {
	return denominator;
  }

void Rational::set_denominator (int denominator)
  {
	this->denominator = denominator;
  }

int greatest_common_factor (int a, int b)
  {
	return b == 0 ? a : greatest_common_factor(b, a % b);
  }


