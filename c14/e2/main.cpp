#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Circle circle1 {{100, 100}, 100};

	Circle circle2 = circle1;
	/**
	Call to implicitly-deleted copy constructor of 'Graph_lib::Circle' copy constructor of 'Circle' is implicitly
	deleted because base class 'Graph_lib::Shape' has a deleted copy constructor 'Shape' has been explicitly
	marked deleted here
	*/
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



