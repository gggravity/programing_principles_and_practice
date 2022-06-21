//
// Created by martin on 14/01/2022.
//

#ifndef _BOOK_H_
#define _BOOK_H_

#include "../../std_lib_facilities.h"
#include "ISBN.h"
#include "Genre.h"
#include "Date.h"

class Book
	  {
		public:
			Book (ISBN isbn, string title, string author, Genre genre, Date date);

			[[nodiscard]] ISBN get_ISBN () const;

			[[nodiscard]] string get_title () const;

			[[nodiscard]] string get_author () const;

			[[nodiscard]] Genre get_genre () const;

			[[nodiscard]] Date get_date () const ;

			[[nodiscard]] bool is_checked_in () const;

			bool check_in ();

			bool check_out ();

		private:
			ISBN isbn;
			string title;
			string author;
			Date date;
			Genre genre;
			bool checked_in {};
	  };

bool operator== (const Book &rhs, const Book &lhs);

bool operator!= (const Book &rhs, const Book &lhs);

ostream &operator<< (ostream &os, const Book &book);

#endif //_BOOK_H_
