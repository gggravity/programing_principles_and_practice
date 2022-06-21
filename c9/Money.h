//
// Created by martin on 15/01/2022.
//

#ifndef _MONEY_H_
#define _MONEY_H_

#include "Currency.h"
#include <ostream>

class Money
	  {
		public:
			// constructors

			Money ();

			Money (long amount, Currency currency);

			// getters and setters

			[[nodiscard]] long get_amount () const;

			Currency get_currency () const;

			void set_amount (long amount);

			// overloading

			friend std::ostream &operator<< (std::ostream &os, const Money &money);

			friend Money operator+ (const Money &money, int value);

			friend Money operator+ (const Money &lhs, const Money &rhs);

			friend Money operator- (const Money &lhs, const Money &rhs);

			friend std::ostream &operator<< (std::ostream &os, const Money &money);

			friend std::istream &operator>> (std::istream &is, Money &money);

		private:
			long int cents;
			Currency currency;
	  };

#endif //_MONEY_H_
