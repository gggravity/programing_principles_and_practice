#include "../std_lib_facilities.h"

int main ()
{
  cout << "What number do you want to find all primes below?" << endl;
  int magic_number;
  cin >> magic_number;

  vector<int> primes {2, 3, 5};

  for (int i {6} ; i <= magic_number ; ++i)
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
	{
	  primes.push_back(i);
	}
  }

  for (auto prime: primes)
  {
	cout << prime << endl;
  }

  cout << "Found " << primes.size() << " primes below " << magic_number << endl;
}