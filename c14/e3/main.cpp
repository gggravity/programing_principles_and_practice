#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

class Test
	  {
			string name;

			virtual void testing () = 0;
	  };

class Test2:
	Test
	  {
		public:
			void testing () override
			  {
				cout << "Hello world from test 2" << endl;
			  }

	  };

int main ()
try
  {
//	Test test;
	/**
	 * Variable type 'Test' is an abstract class unimplemented pure virtual method 'testing' in 'Test'
	 */

	Test2 test2;
	test2.testing();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



