//
// Created by martin on 21/01/2022.
//

#include "Simple_window.h"
#include "Graph.h"
#include "Box.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Exercise 1");

	Shapes::Box box1 = {Point {100, 150}, Point {300, 350}, 10};

	box1.set_style(Line_style(Line_style::solid, 1));
	box1.set_color(Color::dark_blue);

	Shapes::Box box2 = {Point {200, 240}, Point {400, 600}, 20};

	box2.set_style(Line_style(Line_style::solid, 1));
	box2.set_color(Color::dark_yellow);
	box2.move(200, 200);

	Shapes::Box box3 = {Point {200, 240}, 400, 200, 20};

	box3.set_style(Line_style(Line_style::dot, 2));
	box3.set_color(Color::yellow);
	box3.move(500, 100);

	Shapes::Box box4 = {Point {200, 240}, 200, 400, 20};

	box4.set_style(Line_style(Line_style::dashdotdot, 3));
	box4.set_color(Color::blue);
	box4.move(300, -100);

	win.attach(box1);
	win.attach(box2);
	win.attach(box3);
	win.attach(box4);
	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }