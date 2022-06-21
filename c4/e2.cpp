#include "../std_lib_facilities.h"

int main ()
{
  vector<double> temperatures;

  cout << "Please, enter some temperatures:" << endl;

  for (double temperature ; cin >> temperature ;)
  {
	temperatures.push_back(temperature);
  }

  double sum {0};
  for (auto temperature: temperatures)
  {
	sum += temperature;
  }
  cout << setprecision(2) << fixed;
  cout << "Average temperature: " << sum / double(temperatures.size()) << endl;

  sort(temperatures);

  double median {0};


  if (temperatures.size() % 2 == 1)
  {
	// if number of elements is odd, just take middle element
	median = temperatures[(temperatures.size() - 1) / 2];
  }
  else
  {
	// if number of elements is even, calculate average of two middle elements
	median = (temperatures[temperatures.size() / 2] + temperatures[temperatures.size() / 2 - 1]) / 2;
  }

  cout << "Median temperature: " << median << endl;

}
