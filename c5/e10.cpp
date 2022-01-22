#include "../std_lib_facilities.h"

int main ()
{
  int N {0};
  string input;
  double sum {0};
  vector<double> numbers;
  vector<double> differences;

  cout << "Please enter the number of values you want to sum: " << endl;
  cin >> input;

  if (stoi(input))
  {
	N = stoi(input);
  }

  cout << "Please enter some integers (press '|' to stop): " << endl;
  for (double temp ; cin >> temp ;)
  {
	numbers.push_back(temp);
  }

  if (numbers.empty())
  {
	error("No numbers found.");
  }
  else if (N > numbers.size())
  {
	error("Numbers to sum is larger then available numbers.");
  }

  if (numbers.size() == 1)
  {
	cout << "There are one number ( " << numbers.front() << " )." << endl;
  }
  else
  {
	cout << "The sum of the first " << N << " numbers ( ";
	for (int i = 0 ; i < N ; i++)
	{
	  sum += numbers[i];
	  cout << numbers[i] << " ";
	  if (numbers[i] != numbers[N - 1])
	  {
		differences.push_back(numbers[i] - numbers[i + 1]);
	  }
	}
	cout << ") is " << sum << "." << endl;

	cout << "The differences between adjacent values are:" << endl;
	for (auto d : differences)
	{
	  cout << d << " ";
	}
  }
}