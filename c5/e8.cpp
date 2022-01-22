#include "../std_lib_facilities.h"

int main()
{
  int N {0};
  int sum {0};
  vector<int> numbers;

  cout << "Please enter the number of values you want to sum: " << endl;
  cin >> N;

  cout << "Please enter some integers (press '|' to stop): " << endl;
  for (int temp; cin >> temp;)
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


  cout << "The sum of the first " << N << " numbers ( ";
  for (int i = 0 ; i < N; i++)
  {
	sum += numbers[i];
	cout << numbers[i] << " ";
  }
  cout << ") is " << sum << "." << endl;

}