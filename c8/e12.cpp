//
// Created by martin on 13/01/2022.
//

#include "../std_lib_facilities.h"

void print_until_s (vector<string> &v, const string &quit)
  {
	for (const auto &s: v)
	  {
		if (s == quit)
		  {
			return;
		  }
		cout << s << '\n';
	  }
  }

void print_until_ss (vector<string> &v, const string &quit)
  {
	int seen {0};

	for (const auto &s: v)
	  {
		if (s == quit)
		  {
			if (seen == 1)
			  {
				return;
			  }
			else
			  {
				++seen;
			  }
		  }

		cout << s << '\n';
	  }
  }

int main ()
  {
	vector<string> sv {"Peter", "Poul", "Bo", "James", "Zoom", "Bike", "James", "Bo", "Tv", "Top"};

	print_until_s(sv, "XXX");
	cout << "-----------------" << endl;
	print_until_s(sv, "James");

	cout << "--- ss ---" << endl;

	print_until_ss(sv, "XXX");
	cout << "-----------------" << endl;
	print_until_ss(sv, "James");

  }