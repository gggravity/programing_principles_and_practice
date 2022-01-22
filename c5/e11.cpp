#include "../std_lib_facilities.h"

int main ()
{
  vector<int> fibs = {1, 1, 2, 3, 5, 8, 13, 21, 34};

  for (int i = int(fibs.size()) - 2, current_fib {0} ; current_fib < INT_MAX && current_fib >= 0 ; ++i)
  {
	current_fib = fibs[i] + fibs[i + 1];
	if (current_fib > 0)
	{
	  fibs.push_back(current_fib);
	}
  }

  cout << "Largest fibonacci number that can fit in an int are: " << fibs.back() << endl;
  cout << "There are " << fibs.size() - 1 << " fibonacci numbers below that number." << endl;

}