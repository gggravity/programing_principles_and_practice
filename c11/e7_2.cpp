//
// Created by martin on 18/01/2022.
//

// Enter text ,,,,? whitespace- --- (? to quit) " - don't use,,,,,, the as-if rule."  ??!XXX,
// There are only two kinds of languages: languages that people complain about, and languages that people don't use.

#include "../std_lib.h"
#include "Punctuation_stream.h"

using namespace std;

int main ()
  {

	cout << "Enter text to replace_punctuation punctuation with whitespace (q to quit): " << endl;

	Punctuation_stream ps {cin};
	ps.whitespace(";:,.?!(){}<>/&$@#%^*|~-");

	vector<string> vs;
	for (string word ; ps >> word ;)
	  {
		if (word == "q")
		  {
			break;
		  }
		vs.push_back(word);
	  }

	for (int i {0} ; i < vs.size() ; ++i)
	  {
//		if (i == 0 || vs.at(i) != vs.at(i - 1))
//		  {
//			cout << vs.at(i) << " ";
//		  }
		cout << vs.at(i) << " ";
	  }

  }