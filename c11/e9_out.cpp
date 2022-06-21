//
// Created by martin on 19/01/2022.
//

#include "../std_lib.h"

using namespace std;

template<class T>
char *as_bytes (T &i)    // needed for binary I/O
  {

	void *addr = &i;    // get the address of the first byte
	// of memory used to store the object
	return static_cast<char *>(addr); // treat that memory as bytes
  }

int main ()
  {
	try
	  {
		string input_filename {"converted_Makefile"};
		string output_filename {"Makefile2"};
		fstream fs_in {input_filename, ios_base::in | ios_base::binary};
		fstream fs_out {output_filename, ios_base::out | ios_base::binary};

		if (!fs_in)
		  {
			throw runtime_error("can't open file '" + input_filename + "'");
		  }
		if (!fs_out)
		  {
			throw runtime_error("can't open file '" + output_filename + "'");
		  }

		vector<int> v;
		for (int i ; fs_in.read(as_bytes(i), sizeof(int)) ;)
		  {
			v.push_back(i);
		  }
		for (int i : v)
		  {
			fs_out.write(as_bytes(i), sizeof(int));
		  }
	  }
	catch (exception &e)
	  {
		cerr << "Error: " << e.what() << endl;
	  }
  }