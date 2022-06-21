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
	Simple_window win(Point {200, 300}, 600, 400, "My initials");

	Graph_lib::Lines m;
	m.add(Point {50, 50}, Point {50, 150});
	m.add(Point {150, 50}, Point {150, 150});
	m.add(Point {50, 50}, Point {100, 100});
	m.add(Point {100, 100}, Point {150, 50});
	m.set_style(Line_style(Line_style::dashdotdot, 4));
	m.set_color(Color::dark_blue);

	Graph_lib::Lines e;
	e.add(Point {200, 50}, Point {200, 150});
	e.add(Point {200, 50}, Point {280, 50});
	e.add(Point {200, 100}, Point {250, 100});
	e.add(Point {200, 150}, Point {280, 150});
	e.set_style(Line_style(Line_style::dashdotdot, 4));
	e.set_color(Color::dark_red);

	win.attach(m);
	win.attach(e);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }