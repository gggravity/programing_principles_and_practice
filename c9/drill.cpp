//
// Created by martin on 14/01/2022.
//

#include "../std_lib_facilities.h"

enum class Month
	{
		Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	};

vector<string> month_table = {"January", "February",
							  "Marts", "April",
							  "May", "June",
							  "July", "August",
							  "September", "October",
							  "November", "December"};

ostream &operator<< (ostream &os, Month m)
  {
	return os << month_table.at(int(m) - 1);
  }

Month &operator++ (Month &m)
  {
	return m = (m == Month::Dec) ? Month::Jan : Month(int(m) + 1);
  }

struct Date
	  {
		public:
			Date (int day, Month month, int year) : d {day},
													m {month},
													y {year}
			  {
				if (!is_valid())
				  {
					throw exception();
				  }
			  }

			void add_day (int n);

			[[nodiscard]] int day () const;

			[[nodiscard]] Month month () const;

			[[nodiscard]] int year () const;

		private:
			int y;
			Month m;
			int d;

			[[nodiscard]] bool is_valid () const;
	  };

ostream &operator<< (ostream &os, Date d)
  {
	return os << d.day() << "/" << d.month() << "/" << d.year();
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

int main ()
  {
	try
	  {
		Date today {25, Month::Jun, 1978};

		Date tomorrow = today;
		tomorrow.add_day(1);

		cout << "today: " << today << endl;
		cout << "tomorrow: " << tomorrow << endl;
	  }
	catch (...)
	  {
		cout << "Error";
	  }
  }