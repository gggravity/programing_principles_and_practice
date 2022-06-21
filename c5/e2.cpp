#include "../std_lib_facilities.h"

double celsius_to_kelvin(double celsius)
{
  auto kelvin = celsius + 273.15;
  return kelvin;
}

int main ()
{
  double celsius {0.0f};
  cout << "Please enter temperature in degrees celsius to be convert to degrees kelvin:" << endl;
  cin >> celsius;

  auto kelvin = celsius_to_kelvin(celsius);

  cout << setprecision(2) << fixed;
  cout << celsius << " degrees celsius equal " << kelvin << " degrees kelvin." << endl;

}