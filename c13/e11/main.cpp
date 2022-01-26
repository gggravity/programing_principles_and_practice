#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()

try
  {
	Graph_lib::Simple_window window(Point {0, 0},
									x_max(),
									y_max(),
									"Exercise 11");

	Graph_lib::Ellipse ellipse {{x_max() / 2, y_max() / 2}, 300, 200};
	ellipse.set_style(Line_style(Line_style::dot, 2));
	ellipse.set_fill_color(Color::yellow);
	ellipse.set_color(Color::black);

	Mark focus1 {ellipse.focus1(), 'X'};
	Mark focus2 {ellipse.focus2(), 'X'};

	Axis x_axis {Axis::Orientation::x,
				 {0, y_max() / 2},
				 x_max(),
				 100,
				 "X axis"
	};
	Axis y_axis {Axis::Orientation::y,
				 {x_max() / 2, y_max()},
				 y_max(),
				 100,
				 "Y axis"};

	Line helper_line_1 {{(x_max() / 2) + 15 * 10, 0},
						{(x_max() / 2) + 15 * 10, y_max()}};
	helper_line_1.set_style(Line_style(Line_style::dashdot, 1));
	helper_line_1.set_color(Color::dark_yellow);

	Line helper_line_2 {{0,       ((y_max() / 2)) - 9 * 19},
						{x_max(), ((y_max() / 2)) - 9 * 19}};
	helper_line_2.set_style(Line_style(Line_style::dashdot, 1));
	helper_line_2.set_color(Color::dark_yellow);


	Line line_focus_1 {ellipse.focus1(),
					   {(x_max() / 2) + 15 * 10, ((y_max() / 2)) - 9 * 19}};

	Line line_focus_2 {ellipse.focus2(),
					   {(x_max() / 2) + 15 * 10, ((y_max() / 2)) - 9 * 19}};

	window.attach(ellipse);
	window.attach(helper_line_1);
	window.attach(helper_line_2);
	window.attach(line_focus_1);
	window.attach(line_focus_2);
	window.attach(x_axis);
	window.attach(y_axis);
	window.attach(focus1);
	window.attach(focus2);

	cout << "x notches: " << x_max() / 100 << endl;
	cout << "y notches: " << y_max() / 100 << endl;

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }