#include "Simple_window.h"
#include "Graph.h"
#include "../std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {

	Graph_lib::Point tl(100, 100);

	Simple_window win(tl, 600, 400, "My window");

	Text t {Point {150, 150}, "Hello, graphical world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Axis xa {Axis::x, Point {20, 350}, 280, 10, "x axis"};
	Axis ya {Axis::y, Point {20, 350}, 280, 10, "y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);

	Function sine(sin, 0, 100, Point {20, 150}, 1000, 50, 50);

	Graph_lib::Polygon poly;
	poly.add(Point {300, 200});
	poly.add(Point {350, 100});
	poly.add(Point {400, 200});
	poly.set_color(Color::red);
	poly.set_style(Line_style(Line_style::dash, 4));

	Graph_lib::Rectangle r {Point {200, 200}, 100, 50};
	r.set_fill_color(Color::yellow);

	Circle c {Point {100, 200}, 50};

	Graph_lib::Ellipse e {Point {100, 200}, 75, 25};
	e.set_color(Color::dark_red);

	Mark m {Point {100, 200}, 'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; windows size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point {100, 20}, oss.str()};

	Image cal {Point {225, 225}, "snow_cpp.gif"};
	cal.set_mask(Point {40, 40}, 200, 150);
	cal.move(150,0);

	Graph_lib::Closed_polyline poly_rect;
	poly_rect.add(Point {100, 50});
	poly_rect.add(Point {200, 50});
	poly_rect.add(Point {200, 100});
	poly_rect.add(Point {100, 100});
	poly_rect.add(Point {50, 75});
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	Image ii {Point {100, 50}, "image.jpg"};
	ii.move(50, 50);

	win.attach(ii);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(poly);
	win.attach(r);
	win.attach(poly_rect);
	win.attach(t);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(cal);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }