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
	Simple_window win(Point {200, 300}, 600, 400, "My window");

	Graph_lib::Rectangle r {Point {200, 200}, 100, 100};
	r.set_color(Color::red);

	Graph_lib::Polygon p;
	p.add(Point {100, 100});
	p.add(Point {100, 200});
	p.add(Point {200, 200});
	p.add(Point {200, 100});
	p.set_color(Color::blue);

	win.attach(r);
	win.attach(p);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }