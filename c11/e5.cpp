//
// Created by martin on 18/01/2022.
//


#include "../std_lib.h"

using namespace std;

int main ()
  {
	cout << "Enter a string to get its characters classification (q to quit): " << endl;

	for (string s ; getline(cin, s) ;)
	  {
		if (s.size() == 1 && tolower(s.at(0) == 'q'))
		  {
			exit(EXIT_SUCCESS);
		  }

		set<char> sc;
		for (char &c : s)
		  {
			sc.insert(c);
		  }

		for (char c : sc)
		  {
			cout << c << ": ";
			if (isspace(c))
			  {
				cout << "isspace ";
			  }
			if (isalpha(c))
			  {
				cout << "isalpha ";
			  }
			if (isdigit(c))
			  {
				cout << "isdigit ";
			  }
			if (isxdigit(c))
			  {
				cout << "isxdigit ";
			  }
			if (isupper(c))
			  {
				cout << "isupper ";
			  }
			if (isalnum(c))
			  {
				cout << "isalnum ";
			  }
			if (iscntrl(c))
			  {
				cout << "iscntrl ";
			  }
			if (ispunct(c))
			  {
				cout << "ispunct ";
			  }
			if (isprint(c))
			  {
				cout << "isprint ";
			  }
			if (isgraph(c))
			  {
				cout << "isgraph ";
			  }
			cout << endl;
		  }
	  }
  }