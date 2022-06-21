//
// Created by martin on 19/01/2022.
//

#include "../std_lib.h"

using namespace std;

vector<string> split (const string &s)
  {
	vector<string> vs;

	istringstream iss {s};
	for (string word ; iss >> word ;)
	  {
		vs.push_back(word);
	  }

	return vs;
  }

int main ()
  {
	string line {"der var mand en gang en mand"};

	vector<string> vs = split(line);

	cout << "input:" << line << endl;
	cout << setw(10) << left << "output:";
	for (int i {0} ; i < vs.size() ; ++i)
	  {
		cout << vs.at(i);
		if (i != vs.size() - 1)
		  {
			cout << ", ";
		  }
	  }
	cout << endl;

  }