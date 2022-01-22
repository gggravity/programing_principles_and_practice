//
// Created by martin on 20/01/2022.
//

#include "Simple_window.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Child house");


	Graph_lib::Rectangle house {Point {200, 400}, 1000, 400};

	Graph_lib::Lines roof;
	roof.add(Point {150, 450}, Point {400, 200});
	roof.add(Point {1250, 450}, Point {1000, 200});
	roof.add(Point {400, 200}, Point {1000, 200});

	Graph_lib::Polygon roof_filling;
	roof_filling.add(Point {200, 400});
	roof_filling.add(Point {400, 200});
	roof_filling.add(Point {1000, 200});
	roof_filling.add(Point {1200, 400});

	roof_filling.set_style(Line_style(Line_style::dashdotdot, 4));
	roof_filling.set_color(Color::blue);
	roof_filling.set_fill_color(Color::dark_blue);


	roof.set_style(Line_style(Line_style::solid, 4));
	roof.set_color(Color::black);

	house.set_style(Line_style(Line_style::solid, 2));
	house.set_color(Color::black);
	house.set_fill_color(Color::dark_cyan);

	win.attach(house);
	win.attach(roof);
	win.attach(roof_filling);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }