#include "../std_lib_facilities.h"

int main ()
{
  cout << "How many primes do you want to find?" << endl;
  int magic_number;
  cin >> magic_number;

  vector<int> primes {2, 3, 5};

  for (int i {6} ; primes.size() < magic_number ; ++i)
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

  cout << "Found " << primes.size() << " primes." << endl;

  cout << "The primes are: ";

  for (auto prime: primes)
  {
	if (prime != primes.back())
	{
	  cout << prime << ", ";
	}
	else
	{
	  cout << prime << ".";
	}
  }

}