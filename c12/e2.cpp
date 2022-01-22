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

	Graph_lib::Rectangle rectangle {Point {200, 200}, 100, 30};
	rectangle.set_style(Line_style(Line_style::dashdotdot, 4));
	rectangle.set_color(Color::black);
	rectangle.set_fill_color(Color::yellow);

	Graph_lib::Text text {Point {220, 220}, "Howdy!"};
	text.set_font(Font::times_bold);
	text.set_font_size(20);

	win.attach(rectangle);
	win.attach(rectangle);
	win.attach(text);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }