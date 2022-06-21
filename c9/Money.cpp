//
// Created by martin on 15/01/2022.
//

#include <iomanip>
#include <iostream>
#include "Money.h"

Money::Money () :
	cents {0},
	currency {Currency::DKK}
  { }

Money::Money (long amount, Currency currency) : cents(amount),
												currency(currency)
  { }

long Money::get_amount () const
  {
	return cents;
  }

Currency Money::get_currency () const
  {
	return currency;
  }

void Money::set_amount (long amount)
  {
	Money::cents = amount;
  }

Money operator+ (const Money &money, int value)
  {
	return {money.get_amount() + value, money.get_currency()};
  }

std::ostream &operator<< (std::ostream &os, const Money &money)
  {
	os << std::setprecision(2) << std::fixed;
	if (money.get_amount() < 0)
	  {
		os << "amount: -"<< money.get_currency() << " " << std::abs(money.get_amount() / double(100));
	  }
	else
	  {
		os << "amount: "<< money.get_currency() << " " << money.get_amount() / double(100);
	  }

	return os;
  }

std::istream &operator>> (std::istream &is, Money &money)
  {
	is >> money.cents >> money.currency;
	return is;
  }


Money operator+ (const Money &lhs, const Money &rhs)
  {
	if (lhs.get_currency() != rhs.get_currency())
	  {
		std::cerr << "Error: Wrong currency's (" << lhs.get_currency() << " and " << rhs.get_currency() << ")";
		exit(EXIT_FAILURE);
	  }

	return {lhs.get_amount() + rhs.get_amount(), lhs.get_currency()};
  }

Money operator- (const Money &lhs, const Money &rhs)
  {
	if (lhs.get_currency() != rhs.get_currency())
	  {
		std::cerr << "Error: Wrong currency's (" << lhs.get_currency() << " and " << rhs.get_currency() << ")";
		exit(EXIT_FAILURE);
	  }

	return {lhs.get_amount() - rhs.get_amount(), lhs.get_currency()};
  }