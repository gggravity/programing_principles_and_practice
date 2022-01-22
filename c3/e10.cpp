#include "../std_lib_facilities.h"

int main ()
{
  char op;
  double value1 {0};
  double value2 {0};

  cout << "Input an operation followed by two numbers:";
  while (cin >> op >> value1 >> value2)
  {
	if (op == '+')
	{
	  cout << value1 + value2 << endl;
	}
	else if (op == '-')
	{
	  cout << value1 - value2 << endl;
	}
	else if (op == '*')
	{
	  cout << value1 * value2 << endl;
	}
	else if (op == '/')
	{
	  if (value2 == 0)
	  {
		cerr << "Division by zero error.";
		exit(EXIT_FAILURE);
	  }
	  cout << value1 / value2 << endl;
	}

	cout << "Input an operation followed by two numbers:";
  }

}