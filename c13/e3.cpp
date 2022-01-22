#include "Simple_window.h"
#include "Graph.h"
#include "Arrow.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Exercise 3");

	Graph_lib::Rectangle box = {Point {100, 100}, Point {400, 200}};
	box.set_color(Color::invisible);
	box.set_fill_color(Color::white);

	Shapes::Arrow a {Point {100, 100}, {400, 200}, 50};
	a.set_style(Line_style(Line_style::dot, 2));
	a.set_color(Color::dark_blue);
	a.move(100, 200);

	win.attach(box);
	win.attach(a);
	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }