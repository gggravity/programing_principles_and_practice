//
// Created by martin on 17/01/2022.
//

#include "../std_lib_facilities.h"

int main ()
  {
	string filename {"../c10/e11.txt"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		cerr << "Error: opening file ('" << filename << "')" << endl;
		exit(EXIT_FAILURE);
	  }

	int sum {0};

	while (!ifs.eof())
	  {
		string s;
		ifs >> s;
		bool is_int = true;
		for (auto &c : s)
		  {
			if (!isdigit(c))
			  {
				is_int = false;
			  }
		  }
		if (is_int)
		  {
			sum += stoi(s);
		  }
	  }

	cout << "sum: " << sum << endl;
  }