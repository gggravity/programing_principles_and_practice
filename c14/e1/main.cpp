#include "../../GUI/Simple_window.h"
#include "../../GUI/std_lib.h"
#include "Smiley.h"
#include "Frowny.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 1"};

	Smiley smiley1 {{400, y_max() / 2}, 100};
	smiley1.set_fill_color(Color::yellow);
	smiley1.set_style(Line_style(Line_style::dashdot, 4));

	Smiley smiley2 {{700, y_max() / 2}, 300};
	smiley2.set_fill_color(Color::yellow);
	smiley2.set_style(Line_style(Line_style::dashdot, 4));

	Frowny frowny1 {{800, y_max() / 2}, 100};
	frowny1.set_fill_color(Color::red);
	frowny1.set_style(Line_style(Line_style::dashdot, 4));

	Frowny frowny2 {{800, y_max() / 4}, 200};
	frowny2.set_fill_color(Color::red);
	frowny2.set_style(Line_style(Line_style::dashdot, 4));


	smiley1.move(-100, 200);
	frowny1.move(300, -100);
	frowny2.move(-550, 0);

	window.attach(smiley1);
	window.attach(smiley2);
	window.attach(frowny1);
	window.attach(frowny2);
	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }



