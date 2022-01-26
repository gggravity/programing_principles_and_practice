#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Simple_window window({0, 0}, x_max(), y_max(), "Exercise X");

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
