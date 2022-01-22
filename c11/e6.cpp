//
// Created by martin on 18/01/2022.
//

// Enter text ,,,,? whitespace (? to quit) " - don't use the as-if rule."  ??!XXX

#include "../std_lib.h"

using namespace std;

int main ()
  {
	cout << "Enter text to replace punctuation with whitespace (q to quit): " << endl;

	for (string line ; getline(cin, line) ;)
	  {
		if (line.size() == 1 && tolower(line.at(0) == 'q'))
		  {
			exit(EXIT_SUCCESS);
		  }

		bool in_quote = false;
		for (int i {0} ; i < line.size() ; ++i)
		  {
			switch (line.at(i))
			  {
				case '.':
				case ';':
				case ',':
				case '?':
				case '-':
				case '\'':
				  if (!in_quote)
					{
					  line.at(i) = ' ';
					}
				break;
				case '\"':
				  in_quote = !in_quote;
				break;
				default:
				  break;
			  }
		  }

		cout << line << endl;
	  }
  }