#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"
#include "Regular_polygon.h"

using namespace std;

int main ()
try
  {
	Graph_lib::Simple_window window(Graph_lib::Point {0, 0},
									Graph_lib::x_max(),
									Graph_lib::y_max(),
									"Exercise 8");

	Graph_lib::Vector_ref<Shapes::Regular_polygon> polygons;

	for (int i {1} ; i < 13 ; ++i)
	  {
		polygons.push_back(new Shapes::Regular_polygon {i * 110, 100, 50, i + 2});
	  }

	for (int i {0} ; i < polygons.size() ; ++i)
	  {
		polygons[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 2));
		polygons[i].set_color(Graph_lib::Color::dark_blue);
		window.attach(polygons[i]);
	  }

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
