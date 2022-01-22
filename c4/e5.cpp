#include "../std_lib_facilities.h"

int main ()
{
  double v1 {0}, v2 {0};
  char op;
  cout << "Please enter an expression to calculate (e.g. 13 4 *):" << endl;

  cin >> v1 >> v2 >> op;

  switch (op)
  {
  case '+':
	cout << "the sum of " << v1 << " and " << v2 << " is " << v1 + v2;
	break;
  case '-':
	cout << "the subtraction of " << v1 << " and " << v2 << " is " << v1 - v2;
	break;
  case '*':
	cout << "the multiplication of " << v1 << " and " << v2 << " is " << v1 * v2;
	break;
  case '/':
	cout << "the division of " << v1 << " and " << v2 << " is " << v1 / v2;
	break;
  default:
	cerr << "Wrong input.";
	break;
  }

}