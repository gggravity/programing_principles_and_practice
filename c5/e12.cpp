#include "../std_lib_facilities.h"

int main ()
{
  vector<int> secret;
  vector<int> guess;

  srand(time(NULL));

  for (int i {0} ; i < 4 ; ++i)
  {
	secret.push_back(rand() % 10);
  }

  int bulls {0};
  int cows {0};
  int count {0};

  while (bulls != 4)
  {
	bulls = 0;
	cows = 0;

	cout << "Enter four numbers between 0 and 9 (q to quit): " << endl;
	for (string temp ; cin >> temp ;)
	{
	  if (temp == "q")
	  {
		exit(EXIT_SUCCESS);
	  }

	  int temp_int = stoi(temp);
	  guess.push_back(temp_int);

	  if (guess.size() == 4)
	  {
		break;
	  }
	}

	for (int i {0} ; i != guess.size() ; ++i)
	{
	  if (guess[i] == secret[i])
	  {
		++bulls;
	  }
	  else
	  {
		++cows;
	  }
	}

	cout << "Bulls: " << bulls << " Cows: " << cows << endl;
	++count;
	guess.clear();
  }
  cout << "You finished in " << count << " Tries." << endl;
}