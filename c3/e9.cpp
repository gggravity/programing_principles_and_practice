#include "../std_lib_facilities.h"

int main ()
{
  string number;
  cout << "Enter a spelled-out number (q to quit):";
  while (cin >> number)
  {
	if (number == "zero")
	{
	  cout << "0" << endl;
	}
	else if (number == "one")
	{
	  cout << "1" << endl;
	}
	else if (number == "two")
	{
	  cout << "2" << endl;
	}
	else if (number == "three")
	{
	  cout << "3" << endl;
	}
	else if (number == "four")
	{
	  cout << "4" << endl;
	}
	else
	{
	  cout << "quit or wrong input... exiting.";
	  exit(EXIT_SUCCESS);
	}
	cout << "Enter a spelled-out number (q to quit): " << endl;
  }

}