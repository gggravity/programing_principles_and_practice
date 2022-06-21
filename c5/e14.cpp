#include "../std_lib_facilities.h"

// Tuesday 23 Friday 56 Tuesday -3 Thursday 99

int main ()
{
  vector<int> day_of_the_week (7);

  string s;
  int value;

  cout << "Enter (day-of-the-week, value) pairs (p to print and q to quit): " << endl;
  while (true)
  {
	cin >> s;
	for (auto &c: s)
	{
	  c = char(tolower(c));
	}

	if (s.front() == 'q')
	{
	  exit(EXIT_SUCCESS);
	}
	else if (s.front() == 'p')
	{
	  for (int i = 0 ; i < day_of_the_week.size(); ++i)
	  {
		cout << "day " << i + 1 << "\t\t" << day_of_the_week[i] << endl;
	  }
	  continue;
	}

	s.resize(3);

	cin >> value;

	if (s == "mon")
	{
	  day_of_the_week[0] += value;
	}
	else if (s == "tue")
	{
	  day_of_the_week[1] += value;
	}
	else if (s == "wed")
	{
	  day_of_the_week[2] += value;
	}
	else if (s == "thu")
	{
	  day_of_the_week[3] += value;
	}
	else if (s == "fri")
	{
	  day_of_the_week[4] += value;
	}
	else if (s == "sat")
	{
	  day_of_the_week[5] += value;
	}
	else if (s == "sun")
	{
	  day_of_the_week[6] += value;
	}
	else
	{
	  cout << "rejecting: " << s << ", " << value << endl;
	}
  }

}