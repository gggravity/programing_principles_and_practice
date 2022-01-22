#include "../std_lib_facilities.h"

int main ()
{
  double a, b, c;
  cout << "Please enter a b and c in the quadratic equation ax^2 + b*x + c = 0:" << endl;
  cin >> a >> b >> c;

  double discriminant = pow(b, 2) - 4 * a * c;
  if (discriminant < 0)
  {
	error("No real roots.");
  }
  else
  {
	double x1 = (-b + sqrt(discriminant)) / (2 * a);
	double x2 = (-b - sqrt(discriminant)) / (2 * a);

	cout << showpos;
	cout << "The solution to the equation " << a << "*x^2" << b << "*x" << c << "=0:" << endl;
	cout << "(x1, x2) = (" << x1 << ", " << x2 << ")";
  }
}