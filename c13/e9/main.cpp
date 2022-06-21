#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"
#include "Regular_hexagon.h"

using namespace std;

int main ()
try
  {
	Graph_lib::Simple_window window(Graph_lib::Point {0, 0},
									Graph_lib::x_max(),
									Graph_lib::y_max(),
									"Exercise 8");

	Graph_lib::Vector_ref<Shapes::Regular_hexagon> hexagons;

	for (int i {0} ; i < 30 ; ++i)
	  {
		hexagons.push_back(new Shapes::Regular_hexagon {20 + i * 40, 20, 20, 0});
	  }

	for (int i {0} ; i < hexagons.size() ; ++i)
	  {
		hexagons[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 1));
		hexagons[i].set_color(Graph_lib::Color::black);
		window.attach(hexagons[i]);
	  }

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
