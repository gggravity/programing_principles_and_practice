#include "../std_lib_facilities.h"

int main ()
{
  int value1 {0};
  int value2 {0};

  cout << "Please enter two values (q to quit):" << endl;

  while (cin >> value1 >> value2)
  {
	if (value1 < value2)
	{
	  cout << "The smallest value are: " << value1 << endl;
	  cout << "The largest value are: " << value2 << endl;
	}
	else if (value1 > value2)
	{
	  cout << "The smallest value are: " << value2 << endl;
	  cout << "The largest value are: " << value1 << endl;
	}
	else
	{
	  cout << "The values are equal." << endl;
	}

	cout << "The sum of the values are: " << value1 + value2 << endl;

	cout << "The difference of the values are: " << value1 - value2 << " or " << value2 - value1 << endl;

	cout << "The product of the values are: " << value1 * value2 << endl;

	cout << "The ration of the values are: " << double(value1) / value2 << " or " << double(value2) / value1 << endl;

	cout << "Please enter two values (q to quit):" << endl;
  }

}
