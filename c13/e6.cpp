#include "Simple_window.h"
#include "Graph.h"
#include "Textbox.h"
#include "Arrow.h"

using namespace std;

int main ()
try
  {
	Graph_lib::Simple_window win(Graph_lib::Point {0, 0},
								 Graph_lib::x_max(),
								 Graph_lib::y_max(),
								 "Exercise 5");

	Graph_lib::Vector_ref<Shapes::Textbox> text;

	text.push_back(new Shapes::Textbox {{100, 100}, "Point.h"});
	text.push_back(new Shapes::Textbox {{100, 200}, "Graph.h"});
	text.push_back(new Shapes::Textbox {{30, 300}, "Graph.cpp"});
	text.push_back(new Shapes::Textbox {{100, 400}, "Chapter12.cpp"});

	Graph_lib::Vector_ref<Graph_lib::Text> markers;
	markers.push_back(new Graph_lib::Text {text[0].north(), "N"});
	markers.push_back(new Graph_lib::Text {text[0].south(), "S"});
	markers.push_back(new Graph_lib::Text {text[0].east(), "E"});
	markers.push_back(new Graph_lib::Text {text[0].west(), "W"});
	markers.push_back(new Graph_lib::Text {text[0].center(), "C"});
	markers.push_back(new Graph_lib::Text {text[0].ne(), "NE"});
	markers.push_back(new Graph_lib::Text {text[0].se(), "SE"});
	markers.push_back(new Graph_lib::Text {text[0].sw(), "SW"});
	markers.push_back(new Graph_lib::Text {text[0].nw(), "NW"});

	for (int i {0} ; i < text.size() ; ++i)
	  {
		text[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
		text[i].set_font_size(20);
		text[i].set_font(Graph_lib::Font::Font_type::helvetica);
		text[i].set_fill_color(Graph_lib::Color::yellow);
		text[i].set_color(Graph_lib::Color::dark_blue);
		win.attach(text[i]);
	  }

	Graph_lib::Vector_ref<Shapes::Arrow> arrow;

	arrow.push_back(new Shapes::Arrow {{100, 100}, {200, 200}});

	for (int i {0} ; i < arrow.size() ; ++i)
	  {
		arrow[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
		arrow[i].set_color(Graph_lib::Color::dark_blue);
		win.attach(arrow[i]);
	  }

	for (int i {0} ; i < markers.size() ; ++i)
	  {
		win.attach(markers[i]);
	  }

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }