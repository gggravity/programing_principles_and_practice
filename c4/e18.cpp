#include "../std_lib_facilities.h"

int main ()
{

  cout << "Please insert the values a, b, c to the equation, a*x^2 + b*x + c = 0: " << endl;
  double a, b, c;
  cin >> a >> b >> c;

  double discriminant = b * b - 4 * a * c;

  if (discriminant < 0)
  {
	cout << "discriminant = " << discriminant << " -> a complex solution, sorry can't solve that.";
  }
  else
  {
	double x1 = 2 * c / (-b + sqrt(discriminant));
	double x2 = 2 * c / (-b - sqrt(discriminant));

	cout << "x1 = " << x1 << ", x2 = " << x2;
  }
}