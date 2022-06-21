//
// Created by martin on 14/01/2022.
//

#ifndef _PATRON_H_
#define _PATRON_H_

#include <ostream>
#include "../../std_lib_facilities.h"

class Patron
	  {
		public:
			Patron (string username, int card_number, double credit);

			[[nodiscard]] const string &get_username () const;

			[[nodiscard]] int get_card_number () const;

			[[nodiscard]] double get_fee () const;

			void set_fee (double fee);

			[[nodiscard]] bool is_owed() const;

		private:
			string username;
			int card_number;
			double fee;
	  };

ostream &operator<< (ostream &os, const Patron &patron);

bool operator== (const Patron &lhs, const Patron &rhs);

bool operator!= (const Patron &lhs, const Patron &rhs);

#endif //_PATRON_H_
