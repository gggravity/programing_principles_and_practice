//
// Created by martin on 14/01/2022.
//

#include "Date.h"

Date::Date (int day, Month month, int year) : d {day},
											  m {month},
											  y {year}
  {
	if (!is_valid())
	  {
		throw exception();
	  }
	if (is_leap_year())
	  {
		cout << "It's a leap year" << endl;
	  }
  }

ostream &operator<< (ostream &os, Date d)
  {
	return os << d.day() << " " << d.month() << " " << d.year();
  }

bool operator== (const Date &rhs, const Date &lhs)
  {
	if (rhs.day() != lhs.day())
	  {
		return false;
	  }
	if (rhs.month() != lhs.month())
	  {
		return false;
	  }
	if (rhs.year() != lhs.year())
	  {
		return false;
	  }
	return true;
  }

bool operator!= (const Date &rhs, const Date &lhs)
  {
	return !(lhs == rhs);
  }

void Date::add_day (int n)
  {
	d += n;
  }

Month Date::month () const
  {
	return m;
  }

int Date::day () const
  {
	return d;
  }

int Date::year () const
  {
	return y;
  }

bool Date::is_valid () const
  {
	if (int(m) < 1 || int(m) > 12)
	  {
		return false;
	  }
	if (d <= 0 || d > 31)
	  {
		return false;
	  }
	if (y <= 0 || y > 3000)
	  {
		return false;
	  }
	return true;
  }

bool Date::is_leap_year () const
  {
	if (y % 4)
	  {
		return false;
	  }
	else if (y % 100)
	  {
		return true;
	  }
	else if (y % 400)
	  {
		return false;
	  }
	else
	  {
		return true;
	  }
  }

Date Date::next_workday ()
  {
	Date date = *this;

	int day_of_week = this->day_of_week ();
	// TODO need to get day of date as int -> sunday == 0, monday == 1 etc.

	switch (day_of_week)
	  {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		  date.add_day(1);
		break;

		case 5:
		  date.add_day(3);
		break;

		case 6:
		  date.add_day(2);
		break;

		default:
		  cerr << "Error: wrong day in next_workday";
		break;
	  }
	return date;
  }

int Date::week_of_year ()
  {
	tm time_in = {0, 0, 0,
				  day(), int(month()) - 1, year() - 1900}; // 1-based day, 0-based month, year since 1900

	time_t time_temp = mktime(&time_in);

	const tm *time_out = localtime(&time_temp);

	char buffer[4];
	strftime (buffer,4,"%W",time_out);

	return stoi(buffer);
  }

int Date::day_of_year () const
  {
	vector<int> day_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int day_in_year {0};

	for (int i {0} ; i < int(month()) ; ++i)
	  {
		day_in_year += day_in_month.at(i);
	  }
	day_in_year += day();

	return day_in_year;
  }

int Date::day_of_week () const
  {
	tm time_in = {0, 0, 0,
				  day(), int(month()) - 1, year() - 1900}; // 1-based day, 0-based month, year since 1900

	time_t time_temp = mktime(&time_in);

	const tm *time_out = localtime(&time_temp);

	return (time_out->tm_wday); // Sunday == 0, Monday == 1, and so on ...
  }
