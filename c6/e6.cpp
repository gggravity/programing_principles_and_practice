#include "../std_lib_facilities.h"

// birds fly but fish swim .

bool contains (string &str, vector<string> &vec);

bool sentence ();

vector<string> nouns {"birds", "fish", "C++"};
vector<string> verbs {"rules", "fly", "swim"};
vector<string> conjunctions {"and", "or", "but"};

int main ()
  {
	try
	  {
		while (cin)
		  {
			bool b = sentence();
			if (b)
			  {
				cout << "OK" << endl;
			  }
			else
			  {
				cout << "not OK" << endl;
				cin.clear();
				fflush(stdin);
			  }
			cout << "Try again: ";
		  }
	  }
	catch (runtime_error &e)
	  {
		cerr << e.what() << endl;
	  }

  }

bool sentence ()
  {
	string w;
	cin >> w;
	if (!contains(w, nouns))
	  {
		return false;
	  }

	string w2;
	cin >> w2;
	if (!contains(w2, verbs))
	  {
		return false;
	  }

	string w3;
	cin >> w3;
	if (w3 == ".")
	  {
		return true;
	  }
	if (!contains(w3, conjunctions))
	  {
		return false;
	  }
	return sentence();
  }

bool contains (string &str, vector<string> &vec)
  {
	for (const auto &item: vec)
	  {
		if (item == str)
		  {
			return true;
		  }
	  }
	return false;
  }
