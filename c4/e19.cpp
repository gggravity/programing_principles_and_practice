#include "../std_lib_facilities.h"

int main ()
{
  vector<string> names;
  vector<int> scores;

  cout << "Enter a name value pair like Joe 14, end input with nn 0:" << endl;

  string name;
  int score;
  while (cin >> name >> score)
  {
	if (name == "nn" && score == 0)
	{
	  break;
	}
	if (names.empty())
	{
	  names.push_back(name);
	  scores.push_back(score);
	}
	else
	{
	  auto it = find(names.begin(), names.end(), name);
	  if (it == names.end())
	  {
		names.push_back(name);
		scores.push_back(score);
	  }
	  else
	  {
		cerr << "Duplicated name error." << endl;
	  }
	}
  }

  cout << "Name\t\tScore\n";
  for (int i {0} ; i != names.size() ; ++i)
  {
	cout << names[i] << "\t\t" << scores[i] << endl;
  }

}