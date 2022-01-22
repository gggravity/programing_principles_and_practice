//
// Created by martin on 14/01/2022.
//

#include "Library.h"
#include "Book.h"

Library::Library ()
  {
	// add some books
	Date date_1 = {1, Month::Jan, 2022};
	Date date_2 = {11, Month::Nov, 2022};
	Date date_3 = {4, Month::Jun, 2022};

	ISBN isbn_1 = {11, 22, 33, 'A'};
	ISBN isbn_2 = {22, 33, 33, 'F'};
	ISBN isbn_3 = {32, 32, 33, 'G'};

	Book book1 = {isbn_1,
				  "In The Summer",
				  "Dave Summers",
				  Genre::Fiction,
				  date_1};

	Book book2 = {isbn_2,
				  "Alone In The Winter",
				  "Anna The Mother",
				  Genre::Children,
				  date_2};

	Book book3 = {isbn_3,
				  "The Night Sky",
				  "The Astronomer",
				  Genre::Periodical,
				  date_3};

	add_book(book1);
	add_book(book2);
	add_book(book3);

	// add some patrons
	Patron patron1 = {"Martin", 123456789, 2.99f};
	Patron patron2 = {"Anna", 123333789, 13.53f};
	Patron patron3 = {"Bob", 223333789, 2.98f};

	add_patron(patron1);
	add_patron(patron2);
	add_patron(patron3);

	// add some transactions.
	check_out(book1, patron1);
	check_out(book2, patron2);
	check_out(book3, patron3);

  }

bool Library::add_book (const Book &book)
  {
	for (const auto &b: books)
	  {
		if (b == book)
		  {
			return false;
		  }
	  }
	books.push_back(book);
	return true;
  }

bool Library::add_patron (const Patron &patron)
  {
	for (const auto &p: patrons)
	  {
		if (p == patron)
		  {
			return false;
		  }
	  }
	patrons.push_back(patron);
	return true;
  }

bool Library::check_out (const Book &book, const Patron &patron)
  {
	if (!is_patron(patron))
	  {
		cerr << "Error: can't check out, not a patron.";
		return false;
	  }

	for (auto &b: books)
	  {
		if (b == book)
		  {
			if (b.is_checked_in())
			  {
				b.check_out();
				transactions.push_back({b, patron, {4, Month::Jun, 2022}});
				return true;
			  }
			else
			  {
				cerr << "Error: book is checked in";
				return false;
			  }
		  }
	  }
	return false;
  }

bool Library::is_patron (const Patron &patron)
  {
	for (const auto &p: patrons)
	  {
		if (p == patron)
		  {
			return true;
		  }
	  }
	return false;
  }

void Library::print_books () const
  {
	cout << "--- Books in liberty ---" << endl;
	for (const auto &b: books)
	  {
		cout << b << endl;
	  }
  }

void Library::print_patrons () const
  {
	cout << "--- Liberty patrons ---" << endl;
	for (const auto &p: patrons)
	  {
		cout << p << endl;
	  }
  }

void Library::print_transactions () const
  {
	cout << "--- Liberty transactions ---" << endl;
	for (int i {0} ; i < transactions.size() ; ++i)
	  {
		cout << "Transaction: " << i + 1 << endl;
		cout << transactions[i] << endl;
	  }
  }

void Library::print_owned () const
  {
	cout << "--- Liberty patrons who owes money ---" << endl;
	double sum_owed;
	int num_patrons;
	for (const auto &p: patrons)
	  {
		if (p.is_owed())
		  {
			cout << setprecision(2) << fixed;
			cout << p.get_username() << " owes the liberty $" << p.get_fee() << endl;
			sum_owed += p.get_fee();
			++num_patrons;
		  }
	  }
	  cout << "In total the liberty are owed $" << sum_owed << " by " << num_patrons << " patrons." << endl;
  }

