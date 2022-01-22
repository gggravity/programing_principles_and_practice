#include "../std_lib_facilities.h"

int main()
{
  int value{0};

  cout << "Please enter an value: " << endl;
  cin >> value;

  if (value % 2)
	cout << "The value " << value << " is an odd number." << endl;
  else
	cout << "The value " << value << " is an even number." << endl;


}