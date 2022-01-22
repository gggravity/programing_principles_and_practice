//
// Created by martin on 14/01/2022.
//

#ifndef _DATE_H_
#define _DATE_H_

#include "../../std_lib_facilities.h"
#include "Month.h"

class Date
	  {
		public:
			Date (int day, Month month, int year);

			void add_day (int n);

			[[nodiscard]] int day () const;

			[[nodiscard]] Month month () const;

			[[nodiscard]] int year () const;

			bool is_leap_year () const;

			Date next_workday ();

			int week_of_year ();

			int day_of_year () const;

			int day_of_week () const;

		private:
			int y;
			Month m;
			int d;

			[[nodiscard]] bool is_valid () const;
	  };

ostream &operator<< (ostream &os, Date d);

bool operator== (const Date &rhs, const Date &lhs);

bool operator!= (const Date &rhs, const Date &lhs);

#endif //_DATE_H_
