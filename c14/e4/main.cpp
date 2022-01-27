#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"
#include "Immobile_Circle.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 4"};

	Circle circle {{100, 100}, 100};
	Immobile_Circle immobile_circle {{100, 100}, 100};

	circle.move(100, 100);
	immobile_circle.move(100, 100);

	window.attach(circle);
	window.attach(immobile_circle);

	window.wait_for_button();

  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



