#include "../std_lib_facilities.h"

int main ()
{
  vector<int> primes {2, 3, 5};

  for (int i {6} ; i <= 100 ; ++i)
  {
	bool is_prime = true;
	for (auto prime: primes)
	{
	  if (i % prime == 0)
	  {
		is_prime = false;
	  }
	}
	if (is_prime)
	  primes.push_back(i);
  }

  for (auto prime: primes)
  {
	cout << prime << endl;
  }

}