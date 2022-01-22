//
// Created by martin on 19/01/2022.
//

#include "../std_lib.h"

using namespace std;

vector<string> split (const string &s, const string &whitespaces)
  {
	vector<string> vs;
	string s_copy = s;

	for (char w : whitespaces)
	  {
		for (char &c : s_copy)
		  {
			if (c == w)
			  {
				c = ' ';
			  }
		  }
	  }

	istringstream iss {s_copy};
	for (string word ; iss >> word ;)
	  {
		vs.push_back(word);
	  }

	return vs;
  }

int main ()
  {
	string whitespaces {":|+"};
	string line {"der:var|en gang+en mand."};

	vector<string> vs = split(line, whitespaces);

	cout << setw(10) << left << "input:" << line << endl;
	cout << setw(10) << left << "output:";
	for (auto &s : vs)
	  {
		cout << s << " ";
	  }
	cout << endl;

  }