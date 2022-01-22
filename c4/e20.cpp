#include "../std_lib_facilities.h"

void print (vector<string> &names, vector<int> &scores);

void update (Vector<string> &names, Vector<int> &scores, const string &name, int score);

void duplicated_entry (vector<string> &names, vector<int> &scores, int score, string name);

int main ()
{
  vector<string> names;
  vector<int> scores;

  cout << "Enter a name value pair like Joe 14, end input q to quit:" << endl;

  string name;
  int score;
  while (true)
  {
	score = -1;
	cin >> name;

	if (name == "q")
	{
	  exit(EXIT_SUCCESS);
	}
	if (name == "p")
	{
	  print(names, scores);
	}
	else
	{
	  auto it = find(names.begin(), names.end(), name);
	  if (it != names.end() && !names.empty() && score != -1)
	  {
		auto i = distance(names.begin(), it);
		cout << names[i] << "\t\t" << scores[i] << endl;
	  }

	  cin >> score;

	  if (names.empty())
	  {
		update(names, scores, name, score);
	  }
	  else
	  {
		if (it == names.end())
		{
		  update(names, scores, name, score);
		}
		else
		{
		  duplicated_entry(names, scores, score, name);
		}
	  }
	}
  }
}
void update (Vector<string> &names, Vector<int> &scores, const string &name, int score)
{
  names.push_back(name);
  scores.push_back(score);
}

void print (vector<string> &names, vector<int> &scores)
{
  cout << "Name\t\tScore\n";
  for (int i {0} ; i != names.size() ; ++i)
  {
	cout << names[i] << "\t\t" << scores[i] << endl;
  }
}

void duplicated_entry (vector<string> &names, vector<int> &scores, int score, string name)
{
  auto it = find(names.begin(), names.end(), name);
  cout << "Do you want to update the entry? [y/n]:" << endl;
  char answer;
  cin >> answer;
  if (answer == 'y')
  {
	auto i = distance(names.begin(), it);
	scores[i] = score;
  }
}