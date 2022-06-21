//
// Created by martin on 18/01/2022.
//

// Enter text ,,,,? whitespace (? to quit) " - don't use the as-if rule."  ??!XXX

#include "../std_lib.h"

using namespace std;

void replace_punctuation (string &s)
  {
	bool in_quote = false;
	for (int i {0} ; i < s.size() ; ++i)
	  {
		switch (s.at(i))
		  {
			case '.':
			case ';':
			case ',':
			case '?':
			case '-':
			case '\'':
			  if (!in_quote)
				{
				  s.at(i) = ' ';
				}
			break;
			case '\"':
			  in_quote = !in_quote;
			break;
			default:
			  break;
		  }
	  }
  }

void replace_strings (string &s)
  {

	map<string, string> en_map = {
		{"don't", "do not"},
		{"can't", "cannot"}
	};
	for (auto &item : en_map)
	  {
		if (s.find(item.first) != string::npos)
		  {
			s.replace(s.find(item.first), item.first.size(), item.second);
		  }
	  }
  }

void string_to_lowercase (string &s)
  {
	for (char &c : s)
	  {
		c = char(tolower(c));
	  }
  }

int main ()
  {
	cout << "Enter text to replace_punctuation punctuation with whitespace (q to quit): " << endl;

	for (string line ; getline(cin, line) ;)
	  {
		if (line.size() == 1 && tolower(line.at(0) == 'q'))
		  {
			exit(EXIT_SUCCESS);
		  }

		replace_en_words(line);
		replace_punctuation(line);
		string_to_lowercase(line);

		cout << line << endl;
	  }
  }