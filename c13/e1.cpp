#include "Simple_window.h"
#include "Graph.h"
#include "Arc.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Exercise 1");

	Shapes::Arc arc1 = {Point {300, 300}, 200, 200, 0, 180};
	Shapes::Arc arc2 = {Point {300, 300}, 200, 200, 0, 180};

	arc1.set_style(Line_style(Line_style::dot, 5));
	arc1.set_color(Color::dark_blue);

	arc2.move(0,200);

	win.attach(arc1);
	win.attach(arc2);
	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }