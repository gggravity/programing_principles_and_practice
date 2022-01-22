#include "../std_lib.h"

using namespace std;

int main ()
try
  {
	string filename {"../c11/e16.txt"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		throw runtime_error("can't open file '" + filename + "'");
	  }

	map<int, int> iimap;

	for (int i ; !ifs.eof() ;)
	  {
		ifs >> i;
		iimap[i]++;
	  }

	for (auto &item : iimap)
	  {
		cout << item.first << "\t";
		if (item.second > 1)
		  {
			cout << item.second << endl;
		  }
		else
		  {
			cout << endl;
		  }
	  }
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }