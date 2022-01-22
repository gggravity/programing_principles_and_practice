#include "../std_lib_facilities.h"

int main ()
{
  vector<int> v;

  for (int i = 0; i <= 100; ++i)
  {
	v.push_back(rand() % 30 );
  }

  for (auto number : v)
  {
	cout << number << " ";
  }

  cout << endl;

  int max = *max_element(v.begin(), v.end());
  vector<int> frequency (max + 1);

  for (auto number : v)
  {
	frequency[number]++;
  }

  for (auto freq : frequency)
  {
	cout << freq << " ";
  }

  int max_freq = *max_element(frequency.begin(), frequency.end());

  int mode {0};
  for (int i = 0; i < frequency.size(); ++i)
  {
	if (frequency[i] == max_freq)
	  mode = i;
  }

  cout << endl << "Mode: " << mode;

}
