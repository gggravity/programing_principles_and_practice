#include "../std_lib_facilities.h"


double kelvin_to_celsius(double kelvin)
{
  if (kelvin < 0)
	error("Temperature below absolute zero.");

  auto celsius = kelvin - 273.15;

  return celsius;
}

int main ()
{
  double kelvin {0};
  auto celsius = kelvin_to_celsius(kelvin);

  cout << setprecision(2) << fixed;

  cout << "kelvin = " << kelvin << endl;
  cout << "celsius = " << celsius << endl;
}