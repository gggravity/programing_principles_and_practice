#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"
#include "Stripped_rectangle.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 4"};

	Stripped_rectangle stripped_rectangle {{200, 200}, 800, 400};
	stripped_rectangle.set_fill_color(Color::yellow);
//	stripped_rectangle.move(300,300);

	Stripped_rectangle another {{400, 700}, 800, 200};
	another.set_fill_color(Color::green);

	window.attach(stripped_rectangle);
	window.attach(another);
	window.wait_for_button();

  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



