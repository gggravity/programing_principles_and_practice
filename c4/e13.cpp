#include "../std_lib_facilities.h"

struct Primes
{
	int number;
	bool prime;
};

int main ()
{
  constexpr int max {300};

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
  for (auto prime: primes)
  {
	printf("%3s ", prime.prime ? to_string(prime.number).c_str() : " ");
  }

}