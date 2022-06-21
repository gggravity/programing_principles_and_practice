#include "Simple_window.h"
#include <bits/stdc++.h>
#include "Pseudo_window.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
    Simple_window window {{0, 0}, x_max(), y_max(), "Exercise 10"};

    Pseudo_window pseudo_window {{100, 100}, 600, 800, 20};
    pseudo_window.set_style(Line_style(Line_style::dot, 4));
    pseudo_window.set_color(Color::dark_blue);
    Image image {{200, 200}, "image.jpg"};

    window.attach(image);
    window.attach(pseudo_window);

    window.wait_for_button();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }



