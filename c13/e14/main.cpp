#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"
#include "Right_triangle.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Simple_window window({0, 0}, x_max(), y_max(), "Exercise 14");

	int center_x = x_max() / 2;
	int center_y = y_max() / 2;

	Right_triangle rt1 {{center_x,       center_y},
						{center_x,       center_y + 400},
						{center_x + 300, center_y}};

	rt1.set_style(Line_style(Line_style::dash, 4));
	rt1.move(-150,-200);

	window.attach(rt1);
	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
