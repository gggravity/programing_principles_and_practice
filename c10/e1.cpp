//
// Created by martin on 16/01/2022.
//

#include "../std_lib_facilities.h"

void skip_to_int (ifstream &ifs)
  {
	if (ifs.fail())
	  {
		ifs.clear();
		for (char ch ; ifs >> ch ;)
		  {
			if (isdigit(ch))
			  {
				ifs.unget();
				return;
			  }
		  }
	  }
  }

int main ()
  {
	string filename = "../c10/e1.txt";
	ifstream ifs {filename};

	if (!ifs)
	  {
		cerr << "Error: can't open file";
		exit(EXIT_FAILURE);
	  }

	int sum {0};
	int i;
	while (!ifs.eof())
	  {
		skip_to_int(ifs);
		ifs >> i;
		sum += i;
	  }

	cout << "The sum: " << sum << endl;
  }