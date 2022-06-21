//
// Created by martin on 17/01/2022.
//

#include "../std_lib_facilities.h"

int main ()
  {
	string filename1 {"../c10/e9_1.txt"};
	string filename2 {"../c10/e9_2.txt"};
	string filename3 {"../c10/e9_3.txt"};
	ifstream ifs1 {filename1};
	ifstream ifs2 {filename2};
	ofstream ofs {filename3};

	if (!ifs1)
	  {
		cerr << "Error: opening file ('" << filename1 << "')" << endl;
		exit(EXIT_FAILURE);
	  }

	if (!ifs2)
	  {
		cerr << "Error: opening file ('" << filename2 << "')" << endl;
		exit(EXIT_FAILURE);
	  }

	if (!ofs)
	  {
		cerr << "Error: opening file ('" << filename3 << "')" << endl;
		exit(EXIT_FAILURE);
	  }
	vector<string> words;

	while (!ifs1.eof())
	  {
		string s;
		ifs1 >> s;
		words.push_back(s);
	  }

	while (!ifs2.eof())
	  {
		string s;
		ifs2 >> s;
		words.push_back(s);
	  }

	sort(words.begin(), words.end());

	for (auto &word : words)
	  {
		ofs << word << endl;
	  }

	ifs1.close();
	ifs2.close();
	ofs.close();
  }