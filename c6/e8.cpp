#include "../std_lib_facilities.h"

int main ()
{
  vector<string> secret;
  vector<string> guess;

  srand(time(nullptr));

  for (int i {0} ; i < 4 ; ++i)
  {
	string s= to_string(char('a' + rand() % 26));
	secret.push_back(s);
  }

  int bulls {0};
  int cows {0};
  int count {0};

  while (bulls != 4)
  {
	bulls = 0;
	cows = 0;

	cout << "Enter four numbers letter from a to z (0 to quit): " << endl;
	for (string input ; cin >> input ;)
	{
	  if (input == "0" || input.size() > 1 && input != "cheat")
	  {
		cerr << "Error";
		exit(EXIT_SUCCESS);
	  }
	  else if (input == "cheat")
	  {
		for (const auto &s: secret)
		{
		  cout << s << " ";
		}
		cout << endl;
	  }
	  else
	  {
		guess.push_back(input);
	  }
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