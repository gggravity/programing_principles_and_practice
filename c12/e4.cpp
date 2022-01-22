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
	Simple_window win(Point {200, 300}, 600, 400, "Tic tac toe");

	Graph_lib::Rectangle r {Point {100, 100}, 150, 150};
	Graph_lib::Rectangle s1 {Point {100, 100}, 50, 50};
	Graph_lib::Rectangle s2 {Point {100, 150}, 50, 50};
	Graph_lib::Rectangle s3 {Point {100, 200}, 50, 50};
	Graph_lib::Rectangle s4 {Point {150, 100}, 50, 50};
	Graph_lib::Rectangle s5 {Point {150, 150}, 50, 50};
	Graph_lib::Rectangle s6 {Point {150, 200}, 50, 50};
	Graph_lib::Rectangle s7 {Point {200, 100}, 50, 50};
	Graph_lib::Rectangle s8 {Point {200, 150}, 50, 50};
	Graph_lib::Rectangle s9 {Point {200, 200}, 50, 50};

	r.set_style(Line_style(Line_style::solid, 2));
	r.set_color(Color::black);

	s1.set_style(Line_style(Line_style::solid, 1));
	s1.set_color(Color::black);
	s1.set_fill_color(Color::white);

	s2.set_style(Line_style(Line_style::solid, 1));
	s2.set_color(Color::black);
	s2.set_fill_color(Color::red);

	s3.set_style(Line_style(Line_style::solid, 1));
	s3.set_color(Color::black);
	s3.set_fill_color(Color::white);

	s4.set_style(Line_style(Line_style::solid, 1));
	s4.set_color(Color::black);
	s4.set_fill_color(Color::red);

	s5.set_style(Line_style(Line_style::solid, 1));
	s5.set_color(Color::black);
	s5.set_fill_color(Color::white);

	s6.set_style(Line_style(Line_style::solid, 1));
	s6.set_color(Color::black);
	s6.set_fill_color(Color::red);

	s7.set_style(Line_style(Line_style::solid, 1));
	s7.set_color(Color::black);
	s7.set_fill_color(Color::white);

	s8.set_style(Line_style(Line_style::solid, 1));
	s8.set_color(Color::black);
	s8.set_fill_color(Color::red);

	s9.set_style(Line_style(Line_style::solid, 1));
	s9.set_color(Color::black);
	s9.set_fill_color(Color::white);

	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(s6);
	win.attach(s7);
	win.attach(s8);
	win.attach(s9);
	win.attach(r);

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }