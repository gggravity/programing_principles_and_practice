#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"
#include "Poly.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Simple_window window({0, 0}, x_max(), y_max(), "Exercise 18");
	Poly p1 {{100, 100},
			{200, 100},
			{150, 50},
			{150, 150}
	};

	Poly p2 {{100, 100},
			{150, 200},
			{200, 250},
			{150, 150}
	};
	p2.move(200,200);

	window.attach(p1);
	window.attach(p2);
	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



