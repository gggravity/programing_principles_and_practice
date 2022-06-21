#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Exercise 3");

	Shapes::Arrow a {Point {400, 400}, {200, 600}};
	a.set_style(Line_style(Line_style::dot, 4));
	a.set_color(Color::dark_blue);
//	a.move(400, -200);

	win.attach(a);
	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }