#include "../std_lib.h"

using namespace std;

static map<string, int> classify_map;

void classify (char c)
  {
	if (isspace(c))
	  {
		classify_map["isspace"]++;
	  }
	if (isalpha(c))
	  {
		classify_map["isalpha"]++;
	  }
	if (isdigit(c))
	  {
		classify_map["isdigit"]++;
	  }
	if (isxdigit(c))
	  {
		classify_map["isxdigit"]++;
	  }
	if (isupper(c))
	  {
		classify_map["isupper"]++;
	  }
	if (isalnum(c))
	  {
		classify_map["isalnum"]++;
	  }
	if (iscntrl(c))
	  {
		classify_map["iscntrl"]++;
	  }
	if (ispunct(c))
	  {
		classify_map["ispunct"]++;
	  }
	if (isprint(c))
	  {
		classify_map["isprint"]++;
	  }
	if (isgraph(c))
	  {
		classify_map["isgraph"]++;
	  }
  }

int main ()
try
  {
	string filename {"Makefile"};
	ifstream ifs {filename};

	if (!ifs)
	  {
		throw runtime_error("can't open file '" + filename + "'");
	  }
	char c;
	while (!ifs.eof())
	  {
		ifs.get(c);
		classify(c);
	  }

	for (auto &m : classify_map)
	  {
		cout << setw(10) << left << m.first + ":"  << m.second << endl;
	  }
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }