//
// Created by martin on 14/01/2022.
//

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <ostream>
#include "../../std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Date.h"
#include "Transaction.h"

class Library
	  {
		public:
			Library ();

			bool add_book (const Book &book);

			bool add_patron (const Patron &patron);

			bool check_out (const Book& book, const Patron& patron);

			bool is_patron(const Patron& patron);

			void print_books() const;

			void print_patrons() const;

			void print_transactions() const;

			void print_owned() const;

		private:
			vector<Book> books;
			vector<Patron> patrons;
			vector<Transaction> transactions;
	  };

#endif //_LIBRARY_H_
