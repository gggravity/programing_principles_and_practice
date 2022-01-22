#include "../std_lib_facilities.h"

int main ()
{
  constexpr double miles_to_km = 1.609f;
  double result{0.0f};

  cout << "Please enter length in miles (q to quit):" << endl;

  while (cin >> result)
  {
	result *= miles_to_km;
	cout << "The corresponding length in km are: " << result << endl;
	cout << "Please enter length in miles (q to quit):" << endl;
  }

}
