//
// Created by martin on 14/01/2022.
//

#include "../std_lib_facilities.h"

struct ISBN
	{
		int n1;
		int n2;
		int n3;
		char c;
	};

class Book
	  {
		public:
			ISBN get_ISBN ();

			string get_title ();

			string get_author ();

			string get_date ();

			bool is_checked_in ();

			bool check_in ();

			bool check_out ();

		private:
			ISBN isbn;
			string title;
			string author;
			string date;
			bool checked_in;

	  };

ISBN Book::get_ISBN ()
  {
	return isbn;
  }

string Book::get_title ()
  {
	return title;
  }

string Book::get_author ()
  {
	return author;
  }

string Book::get_date ()
  {
	return date;
  }

bool Book::is_checked_in ()
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
