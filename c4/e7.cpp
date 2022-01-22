#include "../std_lib_facilities.h"

int main ()
{
  vector<string> v {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  string i1, i2;
  char op;
  int v1 {0}, v2 {0};

  cout << "Please enter an single digit expression to calculate (e.g. 2 4 *):" << endl;

  cin >> i1 >> i2 >> op;

  if (i1.size() > 1 || i2.size() > 1)
  {
	for (int i = 0 ; i < v.size() ; ++i)
	{
	  if (i1.size() > 1 && i1 == v[i])
	  {
		v1 = i;
		cout << "v1 = " <<  v1 << endl;
	  }
	  else if (i2.size() > 1 && i2 == v[i])
	  {
		v2 = i;
		cout << "v2 = " <<  v2 << endl;
	  }
	}
  }

  if (i1.size() == 1 )
  {
	v1 = stoi(i1);
  }
  if (i2.size() == 1)
  {
	v2 = stoi(i2);
  }

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
	cout << "the division of " << v1 << " and " << v2 << " is " << double(v1) / v2;
	break;
  default:
	cerr << "Wrong input.";
	break;
  }

}