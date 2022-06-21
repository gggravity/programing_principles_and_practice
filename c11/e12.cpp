//
// Created by martin on 19/01/2022.
//

#include "../std_lib.h"

using namespace std;

int main ()
try
  {
	string filename {"Makefile"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		throw runtime_error("can't open file '" + filename + "'");
	  }

	stringstream ss;
	ss << ifs.rdbuf();
	string content {ss.str()};

	reverse(content.begin(), content.end());

	cout << content;
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }