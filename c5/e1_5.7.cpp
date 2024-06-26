#include <cfloat>
#include "../std_lib_facilities.h"

// -16.5 -23.2 -24.0 -25.7 -26.1 -18.6 -9.7 -2.4 7.5 12.6 23.8 25.3 28.0 34.8 36.7 41.5 40.3 42.6 39.7 35.4 12.6 6.5 -3.7 -14.3
// 76.5 73.5 71.0 73.6 70.1 73.5 77.6 85.3 88.5 91.7 95.9 99.2 98.2 100.6 106.3 112.4 110.2 103.6 94.9 91.7 88.4 85.2 85.4 87.7

int main ()
{
  vector<double> temps;

  for (double temp ; cin >> temp ;)
  {
	temps.push_back(temp);
  }

  double sum = {0};
  auto high_temp = DBL_MIN;
  auto low_temp = DBL_MAX;

  for (auto x: temps)
  {
	if (x > high_temp)
	{
	  high_temp = x;
	}
	if (x < low_temp)
	{
	  low_temp = x;
	}
	sum += x;
  }
  if (!temps.empty())
  {
	cout << setprecision(2) << fixed;
	cout << "High temperature: " << high_temp << '\n';
	cout << "Low temperature: " << low_temp << '\n';
	cout << "Average temperature: " << sum / double(temps.size()) << '\n';
  }
  else
  {
	cerr << "No temperature data found.";
  }
}