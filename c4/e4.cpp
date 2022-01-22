#include "../std_lib_facilities.h"

int main ()
{
  cout << "Think of a number between 1 and 100" << endl;

  int min_number {0};
  int max_number {100};
  int num_guesses {0};
  int median, number;
  char answer;

  do
  {
//	cout << "min_number = " << min_number << endl;
//	cout << "max_number = " << max_number << endl;
//	cout << "num_guesses = " << num_guesses << endl;
	int diff = max_number - min_number;
	median = min_number + diff / 2;

	if (diff > 1)
	{
	  if (diff % 2 == 1)
	  {
		++median;
	  }
	  cout << "Is the number you are thinking of larger or equal to " << median << "?" << endl;
	  cin >> answer;
	  ++num_guesses;

	  if (answer == 'n')
	  {
		max_number = median - 1;
	  }
	  else if (answer == 'y')
	  {
		min_number = median;
	  }
	}
	else
	{
	  cout << "It the number you are thinking about " << min_number << "?" << endl;
	  cin >> answer;
	  ++num_guesses;

	  if (answer == 'y')
	  {
		number = min_number;
		break;
	  }
	  else if (answer == 'n')
	  {
		number = max_number;
		break;
	  }
	}
  }
  while (min_number != max_number);

  cout << "The number you are thinking about is: " << number << endl;
  cout << "The number was guessed in " << num_guesses << " tries." << endl;

}