#include "Simple_window.h"
#include "Graph.h"
#include "Circle.h"
#include "Ellipse.h"

using namespace std;

int main ()
try
  {
	Graph_lib::Simple_window win(Graph_lib::Point {0, 0},
								 Graph_lib::x_max(),
								 Graph_lib::y_max(),
								 "Exercise 5");

	Shapes::Circle circle {Graph_lib::Point {400, 400}, 100};
	circle.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
	circle.set_color(Graph_lib::Color::dark_blue);

	Shapes::Ellipse ellipse1 {Graph_lib::Point {800, 400}, 100, 200};
	ellipse1.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 4));
	ellipse1.set_color(Graph_lib::Color::dark_blue);

	Shapes::Ellipse ellipse2 {Graph_lib::Point {1200, 400}, 200, 100};
	ellipse2.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
	ellipse2.set_color(Graph_lib::Color::red);


	Graph_lib::Vector_ref<Graph_lib::Text> text;

	text.push_back(new Graph_lib::Text {circle.n(), "N"});
	text.push_back(new Graph_lib::Text {circle.s(), "S"});
	text.push_back(new Graph_lib::Text {circle.e(), "E"});
	text.push_back(new Graph_lib::Text {circle.w(), "W"});
	text.push_back(new Graph_lib::Text {circle.center(), "C"});
	text.push_back(new Graph_lib::Text {circle.ne(), "NE"});
	text.push_back(new Graph_lib::Text {circle.se(), "SE"});
	text.push_back(new Graph_lib::Text {circle.sw(), "SW"});
	text.push_back(new Graph_lib::Text {circle.nw(), "NW"});

	text.push_back(new Graph_lib::Text {ellipse1.n(), "N"});
	text.push_back(new Graph_lib::Text {ellipse1.s(), "S"});
	text.push_back(new Graph_lib::Text {ellipse1.e(), "E"});
	text.push_back(new Graph_lib::Text {ellipse1.w(), "W"});
	text.push_back(new Graph_lib::Text {ellipse1.center(), "C"});
	text.push_back(new Graph_lib::Text {ellipse1.ne(), "NE"});
	text.push_back(new Graph_lib::Text {ellipse1.se(), "SE"});
	text.push_back(new Graph_lib::Text {ellipse1.sw(), "SW"});
	text.push_back(new Graph_lib::Text {ellipse1.nw(), "NW"});

	text.push_back(new Graph_lib::Text {ellipse2.n(), "N"});
	text.push_back(new Graph_lib::Text {ellipse2.s(), "S"});
	text.push_back(new Graph_lib::Text {ellipse2.e(), "E"});
	text.push_back(new Graph_lib::Text {ellipse2.w(), "W"});
	text.push_back(new Graph_lib::Text {ellipse2.center(), "C"});
	text.push_back(new Graph_lib::Text {ellipse2.ne(), "NE"});
	text.push_back(new Graph_lib::Text {ellipse2.se(), "SE"});
	text.push_back(new Graph_lib::Text {ellipse2.sw(), "SW"});
	text.push_back(new Graph_lib::Text {ellipse2.nw(), "NW"});

	win.attach(circle);
	win.attach(ellipse1);
	win.attach(ellipse2);

	for (int i {0} ; i < text.size() ; ++i)
	  {
		win.attach(text[i]);
	  }

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }