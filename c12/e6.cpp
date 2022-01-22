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
	Simple_window win(Point {10000, 10000}, 800, 600, "out of screen");
	Graph_lib::Rectangle r {Point {-100, -100}, 50, 50}; // outside the screen

	r.set_style(Line_style(Line_style::solid, 2));
	r.set_color(Color::black);

	win.attach(r);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }