//
// Created by martin on 18/01/2022.
//

#include "../std_lib.h"

using namespace std;

bool is_vowel (char c)
  {
	string vowels {"aeiouAEIOU"};
	return any_of(vowels.begin(),
				  vowels.end(),
				  [c] (char v)
					{
						return v == tolower(c);
					}
	);
  }

int main ()
  {

	string filename {"Makefile"};

	fstream fs {filename, ios_base::in};

	if (!fs)
	  {
		throw runtime_error("can't open file \"" + filename + "\"");
	  }

	for (char ch ; !fs.eof() ; fs.get(ch))
	  {
		if (!is_vowel(ch))
		  {
			cout << ch;
		  }
	  }
  }