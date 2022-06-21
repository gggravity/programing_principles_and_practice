//
// Created by martin on 14/01/2022.
//

#include "Book.h"

#include <utility>

Book::Book (ISBN isbn, string title, string author, Genre genre, Date date) :
	isbn {isbn},
	title {std::move(title)},
	author {std::move(author)},
	genre {genre},
	date {date},
	checked_in {true}
  {

  }

bool operator== (const Book &rhs, const Book &lhs)
  {
	if (rhs.get_ISBN() != lhs.get_ISBN())
	  {
		return false;
	  }
	if (rhs.get_title() != lhs.get_title())
	  {
		return false;
	  }
	if (rhs.get_author() != lhs.get_author())
	  {
		return false;
	  }
	if (rhs.get_genre() != lhs.get_genre())
	  {
		return false;
	  }
	if (rhs.get_date() != lhs.get_date())
	  {
		return false;
	  }
	if (rhs.is_checked_in() != lhs.is_checked_in())
	  {
		return false;
	  }
	return true;
  }

bool operator!= (const Book &rhs, const Book &lhs)
  {
	return !(rhs == lhs);
  }

ostream &operator<< (ostream &os, const Book &book)
  {
	os << "TITLE: ";
	os << book.get_title();
	os << ", AUTHOR: ";
	os << book.get_author();
	os << ", GENRE: ";
	os << book.get_genre();
	os << ", STATUS: ";
	if (book.is_checked_in())
	  {
		cout << "checked in";
	  }
	else
	  {
		cout << "checked out";
	  }
	return os;
  }

ISBN Book::get_ISBN () const
  {
	return isbn;
  }

string Book::get_title () const
  {
	return title;
  }

string Book::get_author () const
  {
	return author;
  }

Date Book::get_date () const
  {
	return date;
  }

bool Book::is_checked_in () const
  {
	return checked_in;
  }

bool Book::check_in ()
  {
	if (!is_checked_in())
	  {
		checked_in = true;
	  }
	return false;
  }

bool Book::check_out ()
  {
	if (is_checked_in())
	  {
		checked_in = false;
		return true;
	  }
	return false;
  }

Genre Book::get_genre () const
  {
	return genre;
  }
