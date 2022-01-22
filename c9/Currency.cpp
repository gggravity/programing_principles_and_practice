//
// Created by martin on 15/01/2022.
//

#include <iostream>
#include "Currency.h"

using namespace std;

std::ostream &operator<< (std::ostream &os, const Currency &currency)
  {
	switch (currency)
	  {
		case Currency::USD:
		  os << "$";
		break;
		case Currency::DKK:
		  os << "DKK";
		break;
	  }
	return os;
  }

std::istream &operator>> (std::istream &is, Currency &currency)
  {
	string input;
	is >> input;

	for (auto &c: input)
	  {
		c = static_cast<char>(tolower(c));
	  }

	if (input == "usd")
	  {
		currency = Currency::USD;
	  }
	else if (input == "dkk")
	  {
		currency = Currency::DKK;
	  }

	return is;
  }