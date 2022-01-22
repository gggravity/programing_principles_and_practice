//
// Created by martin on 14/01/2022.
//

#include "Month.h"

Month &operator++ (Month &m)
  {
	return m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1);
  }

ostream &operator<< (ostream &os, Month m)
  {
	vector<string> month_table = {"January", "February",
								  "Marts", "April",
								  "May", "June",
								  "July", "August",
								  "September", "October",
								  "November", "December"};

	return os << month_table.at(int(m) - 1);
  }