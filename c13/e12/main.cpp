#include "../GUI/Simple_window.h"
#include "../GUI/std_lib.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Graph_lib::Simple_window window(Point {0, 0},
									x_max(),
									y_max(),
									"Exercise 12");

	Circle circle {{x_max() / 2, y_max() / 2}, 400};
	circle.set_style(Line_style(Line_style::dashdot, 4));
	circle.set_fill_color(Color::yellow);
	circle.set_color(Color::dark_yellow);

	Vector_ref<Circle> circles;
	for (int i {0} ; i < 360 ; i += 10)
	  {
		int x = int(circle.center().x + circle.radius() * sin(i * std::numbers::pi / 180));
		int y = int(circle.center().y - circle.radius() * cos(i * std::numbers::pi / 180));
		circles.push_back(new Circle {{x, y}, 10});
	  }

	window.attach(circle);
	window.wait_for_button();

	for (int i {0} ; i < circles.size() ; ++i)
	  {
		circles[i].set_style(Line_style(Line_style::dashdot, 4));
		circles[i].set_fill_color(Color::dark_yellow);
		circles[i].set_color(Color::black);
		window.attach(circles[i]);
		window.wait_for_button();
	  }
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
