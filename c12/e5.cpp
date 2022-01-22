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
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Tic tac toe");
	int max_x = x_max() - 100; // 200 for toolbar etc.
	int max_y = y_max() - 200;
	Graph_lib::Rectangle r {Point {100, 100},
							(1 * max_x / 3) / 2 + (2 * max_x / 3),
							(1 * max_y / 4) / 2 + (3 * max_y / 4)};

	r.set_style(Line_style(Line_style::solid, 2));
	r.set_color(Color::black);

	win.attach(r);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }