#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"
#include "Right_triangle.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Simple_window window({0, 0}, x_max(), y_max(), "Exercise 15");

	constexpr int box_size {50};
	constexpr int margin_x {50};
	constexpr int margin_y {50};

	Vector_ref<Right_triangle> tiles;

	for (int i {0} ; i < (x_max() - margin_x - box_size) / box_size; ++i)
	  {
		for (int j {0} ; j < (y_max() - margin_y - box_size) / box_size ; ++j)
		  {
			tiles.push_back(new Right_triangle {{margin_x + box_size * i,      margin_y + box_size * j},
												{margin_x + box_size * i,      margin_y + 40 + box_size * j},
												{margin_x + 30 + box_size * i, margin_y + box_size * j}});
		  }
	  }

	for (int i {0} ; i < tiles.size() ; ++i)
	  {
		int color = (i < 256) ? i : i - 255;
		tiles[i].set_color(color);
		window.attach(tiles[i]);
	  }

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



