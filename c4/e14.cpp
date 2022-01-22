#include "../std_lib_facilities.h"

struct Primes
{
	int number;
	bool prime;
};

int main ()
{
  int max {0};

  cout << "Enter e number to find all primes below with the Sieve of Eratosthenes method:" << endl;
  cin >> max;

  // initializing
  vector<Primes> primes;
  for (int i {2} ; i <= max ; ++i)
  {
	primes.push_back({i, true});
  }

  // calculating
  for (int i = 0 ; i * i < max ; ++i)
  {
	for (int j = primes[i].number ; j + i < primes.size() ; j += primes[i].number)
	{
	  primes[j + i].prime = false;
	}
  }

  // printing
  int total_primes {0};
  for (auto prime: primes)
  {
	if (prime.prime)
	{
	  ++total_primes;
	}
  }
  cout  << "There are " << total_primes << " primes, under " << max << "."<< endl;

  cout << "The primes are: ";

  for (int i = 0, cnt = 0; i != primes.size(); ++i)
  {
	if (primes[i].prime)
	{
	  ++cnt;
	  cout << primes[i].number;
	  if (cnt < total_primes)
	  {
		cout << ", ";
	  }
	  else if (cnt == total_primes)
	  {
		cout << ".";
	  }
	}
  }

}