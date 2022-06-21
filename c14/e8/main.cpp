#include "Simple_window.h"
#include "std_lib.h"
#include "Octagon.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 8"};
	Octagon octagon {{400, 400}, 200};

	window.attach(octagon);
	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



