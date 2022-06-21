#include "Simple_window.h"
#include "Graph.h"
#include "e4_source.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, x_max(), y_max(), "Exercise 4");

	Graph_lib::Rectangle r {Point {100, 100}, {500, 800}};
	r.set_style(Line_style(Line_style::dot, 4));
	r.set_color(Color::dark_blue);

//	a.move(400, -200);

	Vector_ref<Text> texts;
	texts.push_back(new Text {Shapes::n(r), "N"});
	texts.push_back(new Text {Shapes::s(r), "S"});
	texts.push_back(new Text {Shapes::e(r), "E"});
	texts.push_back(new Text {Shapes::w(r), "W"});
	texts.push_back(new Text {Shapes::center(r), "center"});
	texts.push_back(new Text {Shapes::ne(r), "NE"});
	texts.push_back(new Text {Shapes::se(r), "SE"});
	texts.push_back(new Text {Shapes::sw(r), "SW"});
	texts.push_back(new Text {Shapes::nw(r), "NW"});

	for (int i {0} ; i < texts.size() ; ++i)
	  {
		texts[i].set_font_size(24);
	  }

	cout << "n() " << Shapes::n(r) << endl;
	cout << "s() " << Shapes::s(r) << endl;
	cout << "e() " << Shapes::e(r) << endl;
	cout << "w() " << Shapes::w(r) << endl;
	cout << "center() " << Shapes::center(r) << endl;
	cout << "ne() " << Shapes::ne(r) << endl;
	cout << "se() " << Shapes::se(r) << endl;
	cout << "sw() " << Shapes::sw(r) << endl;
	cout << "nw() " << Shapes::nw(r) << endl;

	win.attach(r);

	for (int i {0} ; i < texts.size() ; ++i)
	  {
		win.attach(texts[i]);
	  }

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }