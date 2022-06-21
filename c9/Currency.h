//
// Created by martin on 15/01/2022.
//

#ifndef _CURRENCY_H_
#define _CURRENCY_H_

#include <ostream>
#include <istream>

enum class Currency
	{
		USD, DKK
	};

std::ostream &operator<< (std::ostream &os, const Currency &currency);

std::istream &operator>> (std::istream &is, Currency &currency);


#endif //_CURRENCY_H_
