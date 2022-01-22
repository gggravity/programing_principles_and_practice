#include "../std_lib_facilities.h"

double celsius_to_kelvin(double celsius)
{
  auto kelvin = celsius + 273.15;

  if (kelvin < 0)
	error("Temperature below absolute zero.");

  return kelvin;
}

double kelvin_to_celsius(double kelvin)
{
  if (kelvin < 0)
	error("Temperature below absolute zero.");

  auto celsius = kelvin - 273.15;

  return celsius;
}

int main ()
{
  double kelvin1 {0};
  auto celsius = kelvin_to_celsius(kelvin1);


  auto kelvin2 = celsius_to_kelvin(celsius);

  cout << setprecision(2) << fixed;

  cout << "kelvin1 = " << kelvin1 << endl;
  cout << "celsius = " << celsius << endl;
  cout << "kelvin2 = " << kelvin2 << endl;

}