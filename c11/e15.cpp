#include "../std_lib.h"

using namespace std;

int main ()
try
  {
	string filename {"../c11/e15.txt"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		throw runtime_error("can't open file '" + filename + "'");
	  }

	vector<double> vd;
	for (double d ; !ifs.eof() ;)
	  {
		ifs >> d;
		vd.push_back(d);
	  }

	cout << setprecision(8) << scientific;

	for (int i {0} ; i < vd.size() ; ++i)
	  {
		if (i % 4 == 0 && i != 0)
		  {
			cout << endl;
		  }
		cout << setw(20) << vd.at(i);
	  }
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }