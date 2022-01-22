// -Enter text ,,,,? whitespace- --- (? to quit) " - don't use,,,,,, the as-if rule."  ??!XXX-
// There are only two kinds of languages: languages that people complain about, and languages that people don't use.


#include "../std_lib.h"

using namespace std;

void replace_punctuation (string &s)
  {

	unordered_map<char, char> char_map = {
		{';',  ' '},
		{':',  ' '},
		{',',  ' '},
		{'.',  ' '},
		{'?',  ' '},
		{'!',  ' '},
		{'(',  ' '},
		{')',  ' '},
		{'\"', ' '},
		{'{',  ' '},
		{'}',  ' '},
		{'<',  ' '},
		{'>',  ' '},
		{'/',  ' '},
		{'&',  ' '},
		{'$',  ' '},
		{'@',  ' '},
		{'#',  ' '},
		{'%',  ' '},
		{'^',  ' '},
		{'*',  ' '},
		{'|',  ' '},
		{'~',  ' '},
//		{'-',  ' '},
	};

	for (auto &cm : char_map)
	  {
		replace(s.begin(), s.end(), cm.first, cm.second);
	  }

	for (int i {0} ; i < s.size() ; i++)
	  {
		if (s.at(i) == '-')
		  {
			if (i > 0 && i < s.size() - 1 && isalpha(s.at(i - 1)) && isalpha(s.at(i + 1)))
			  {
				continue;
			  }
			else
			  {
				s.at(i) = ' ';
			  }
		  }
	  }

  }

void replace_strings (string &s)
  {

	unordered_map<string, string> en_map = {
		{"don't", "do not"},
		{"can't", "cannot"},
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

		replace_strings(line);
		replace_punctuation(line);
		string_to_lowercase(line);

		cout << line << endl;
	  }
  }