#include "../std_lib_facilities.h"

int main ()
{
  vector<string> v {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string input;
  cout << "Enter a single digit (q to quit): " << endl;

  while (cin >> input)
  {
	if (input == "q")
	{
	  cout << "Quitting...";
	  break;
	}

	if (input.size() == 1)
	{
	  switch (input[0])
	  {
	  case '0':
		cout << v[0] << endl;
		break;
	  case '1':
		cout << v[1] << endl;
		break;
	  case '2':
		cout << v[2] << endl;
		break;
	  case '3':
		cout << v[3] << endl;
		break;
	  case '4':
		cout << v[4] << endl;
		break;
	  case '5':
		cout << v[5] << endl;
		break;
	  case '6':
		cout << v[6] << endl;
		break;
	  case '7':
		cout << v[7] << endl;
		break;
	  case '8':
		cout << v[8] << endl;
		break;
	  case '9':
		cout << v[9] << endl;
		break;
	  default:
		cerr << "wrong input." << endl;
		break;
	  }
	}
	else
	{
	  bool found = false;
	  for (int i = 0 ; i < v.size() ; ++i)
	  {
		if (input == v[i])
		{
		  cout << i << endl;
		  found = true;
		}
	  }
	  if (!found)
	  {
		cerr << "wrong input." << endl;
	  }
	}
	cout << "Enter a single digit (q to quit): " << endl;
  }

}