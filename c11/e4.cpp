//
// Created by martin on 18/01/2022.
//

#include "../std_lib.h"

using namespace std;

bool isodigit (char C)
  {
	string o_digits {"01234567"};
	for (auto &c : o_digits)
	  {
		if (c == C)
		  {
			return true;
		  }
	  }
	return false;
  }

int main ()
  {

	cout << "Enter a digit prefix with 0x for hex and 0 for octal (q to quit): " << endl;

	string s;
	while (true)
	  {
		cin >> s;

		if (s.size() == 1 && tolower(s.at(0)) == 'q')
		  {
			exit(EXIT_SUCCESS);
		  }

		istringstream iss {s};
		iss.unsetf(ios::dec);
		iss.unsetf(ios::hex);
		iss.unsetf(ios::oct);

		if (!iss)
		  {
			throw runtime_error("Input format error: " + s);
		  }

		int num;
		iss >> num;

		if (s.at(0) == '0' && s.at(1) == 'X' || s.at(1) == 'x')
		  {
			for (int i {2} ; i < s.size() ; ++i)
			  {
				if (!isxdigit(s.at(i)))
				  {
					throw runtime_error("Not a hex value");
				  }
			  }
			cout << "0x" << hex << num << " are 0" << oct << num << " in octal and " << dec << num << " in decimal."
				 << endl;
		  }
		else if (s.at(0) == '0')
		  {
			for (int i {1} ; i < s.size() ; ++i)
			  {
				if (!isodigit(s.at(i)))
				  {
					throw runtime_error("Not a octal value");
				  }
			  }
			cout << "0" << oct << num << " are 0x" << hex << num << " in hex and " << dec << num << " in decimal."
				 << endl;
		  }
		else if (isdigit(s.at(0)))
		  {
			for (int i {1} ; i < s.size() ; ++i)
			  {
				if (!isdigit(s.at(i)))
				  {
					throw runtime_error("Not a decimal value");
				  }
			  }
			cout << dec << num << " are 0x" << hex << num << " in hex and 0" << oct << num << " in octal." << endl;
		  }
		else
		  {
			cerr << "Wrong input try again." << endl;
		  }
	  }
  }