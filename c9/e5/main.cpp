//
// Created by martin on 14/01/2022.
//
#include "../../std_lib_facilities.h"
#include "Library.h"

int main ()
  {
//	Library library;
//
//	library.print_books();
//
//	library.print_patrons();
//
//	library.print_transactions();
//
//	library.print_owned();
	Date date_1 = {15, Month::Jan, 2022};
	Date date_2 = {31, Month::Dec, 2022};
	Date date_3 = {4, Month::Jun, 2022};

//	cout << date_1.day_of_year() << endl;
//	cout << date_2.day_of_year() << endl;
//	cout << date_3.day_of_year() << endl;


	cout << date_1.week_of_year() << endl;

  }