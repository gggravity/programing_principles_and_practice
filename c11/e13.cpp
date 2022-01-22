//
// Created by martin on 19/01/2022.
//

#include "../std_lib.h"

using namespace std;

int main ()
try
  {
	string filename {"../c11/e13.txt"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		throw runtime_error("can't open file '" + filename + "'");
	  }

	vector<string> vs;
	for (string s ; ifs >> s ;)
	  {
		vs.push_back(s);
	  }

	reverse(vs.begin(), vs.end());

	for (auto &s : vs)
	  {
		cout << s << " ";
	  }
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }