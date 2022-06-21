//
// Created by martin on 14/01/2022.
//

#include "Patron.h"

#include <utility>

Patron::Patron (string username, int card_number, double credit) : username(std::move(username)),
																   card_number(card_number),
																   fee(credit)
  { }

ostream &operator<< (ostream &os, const Patron &patron)
  {
	os << "USERNAME: " << patron.get_username() << ", CARD_NUMBER: " << patron.get_card_number() << ", FEE: " << patron.get_fee();
	return os;
  }


bool operator== (const Patron &lhs, const Patron &rhs)
  {
	return lhs.get_username() == rhs.get_username() &&
		   lhs.get_card_number() == rhs.get_card_number() &&
		   lhs.get_fee() == rhs.get_fee();
  }

bool operator!= (const Patron &lhs, const Patron &rhs)
  {
	return !(rhs == lhs);
  }

const string &Patron::get_username () const
  {
	return username;
  }

int Patron::get_card_number () const
  {
	return card_number;
  }

double Patron::get_fee () const
  {
	return fee;
  }

[[maybe_unused]] void Patron::set_fee (double fee)
  {
	Patron::fee = fee;
  }

bool Patron::is_owed () const
  {

	return fee > 0;
  }

