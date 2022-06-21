//
// Created by martin on 18/01/2022.
//

#include "../std_lib.h"

using namespace std;

int main ()
  {
	string to_find;
	cout << "Please enter string to find: " << endl;
	cin >> to_find;

	string filename {"Makefile"};
	fstream fs {filename, ios_base::in};

	if (!fs)
	  {
		throw runtime_error("can't open file '" + filename + "'.");
	  }

	string line;
	for (int i {1}; !fs.eof(); getline(fs,line), ++i)
	  {
		if (line.find(to_find) != string::npos)
		  {
			cout << i << " " <<  line << endl;
		  }
	  }
  }
