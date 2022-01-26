#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib.h"
#include "Regular_hexagon.h"

using namespace std;

int main ()
try
  {
	Graph_lib::Simple_window window(Graph_lib::Point {0, 0},
									Graph_lib::x_max(),
									Graph_lib::y_max(),
									"Exercise 8");

	Shapes::Regular_hexagon hexagon1 {400, 400, 100, 30};
	hexagon1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 4));
	hexagon1.set_fill_color(Graph_lib::Color::yellow);
	hexagon1.set_color(Graph_lib::Color::dark_green);

	Shapes::Regular_hexagon hexagon2 {600, 600, 150};
	hexagon2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dashdotdot, 4));
	hexagon2.set_fill_color(Graph_lib::Color::green);
	hexagon2.set_color(Graph_lib::Color::dark_cyan);

	hexagon1.move(400,0);

	window.attach(hexagon1);
	window.attach(hexagon2);

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
