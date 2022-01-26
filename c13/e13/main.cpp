#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	constexpr int box_size {50};
	Graph_lib::Simple_window window({0, 0}, x_max(), y_max(), "Exercise 13");

	Vector_ref<Graph_lib::Rectangle> color_boxes;

	for (int i {0} ; i < 16 ; ++i)
	  {
		for (int j {0} ; j < 16 ; ++j)
		  {
			color_boxes.push_back(new Graph_lib::Rectangle {
				{i * box_size,            j * box_size},
				{i * box_size + box_size, j * box_size + box_size}});
		  }
	  }

	for (int i {0} ; i < color_boxes.size() ; ++i)
	  {
		color_boxes[i].set_color(i);
		color_boxes[i].set_fill_color(i);
		window.attach(color_boxes[i]);
	  }

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
