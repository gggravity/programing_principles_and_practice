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

	enum labels
		{
			Point_h = 0,
			Graph_h,
			Graph_cpp,
			Chapter12_cpp,
			FLTK_headers,
			Window_h,
			Window_cpp,
			Simple_window,
			FLTK_code,
			GUI_h,
			GUI_cpp
		};

	text.push_back(new Shapes::Textbox {{100, 50}, "Point.h"});           // 0
	text.push_back(new Shapes::Textbox {{100, 200}, "Graph.h"});           // 1
	text.push_back(new Shapes::Textbox {{30, 300}, "Graph.cpp"});          // 2
	text.push_back(new Shapes::Textbox {{100, 450}, "Chapter12.cpp"});     // 3
	text.push_back(new Shapes::Textbox {{300, 50}, "FLTK headers"});       // 4
	text.push_back(new Shapes::Textbox {{300, 150}, "Window.h"});          // 5
	text.push_back(new Shapes::Textbox {{200, 250}, "Window.cpp"});        // 6
	text.push_back(new Shapes::Textbox {{300, 350}, "Simple_window.h"});   // 7
	text.push_back(new Shapes::Textbox {{500, 50}, "FLTK code"});         // 8
	text.push_back(new Shapes::Textbox {{500, 250}, "GUI.h"});             // 9
	text.push_back(new Shapes::Textbox {{500, 350}, "GUI.cpp"});           // 10

	for (int i {0} ; i < text.size() ; ++i)
	  {
		text[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::dot, 2));
		text[i].set_font_size(20);
		text[i].set_font(Graph_lib::Font::Font_type::helvetica);
		text[i].set_fill_color(Graph_lib::Color::yellow);
		text[i].set_color(Graph_lib::Color::black);
		win.attach(text[i]);
	  }

	/*
  Graph_lib::Vector_ref<Graph_lib::Text> markers;
  markers.push_back(new Graph_lib::Text {Shapes::north(text[0]), "N"});
  markers.push_back(new Graph_lib::Text {Shapes::south(text[0]), "S"});
  markers.push_back(new Graph_lib::Text {Shapes::east(text[0]), "E"});
  markers.push_back(new Graph_lib::Text {Shapes::west(text[0]), "W"});
  markers.push_back(new Graph_lib::Text {Shapes::center(text[0]), "C"});
  markers.push_back(new Graph_lib::Text {Shapes::ne(text[0]), "NE"});
  markers.push_back(new Graph_lib::Text {Shapes::se(text[0]), "SE"});
  markers.push_back(new Graph_lib::Text {Shapes::sw(text[0]), "SW"});
  markers.push_back(new Graph_lib::Text {Shapes::nw(text[0]), "NW"});
*/
	Graph_lib::Vector_ref<Shapes::Arrow> arrow;

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Window_h]),
		Shapes::south(text[FLTK_headers]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Simple_window]),
		Shapes::south(text[Window_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Simple_window]),
		Shapes::south(text[GUI_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Window_cpp]),
		Shapes::sw(text[Window_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Chapter12_cpp]),
		Shapes::south(text[Simple_window]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[GUI_cpp]),
		Shapes::se(text[GUI_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[GUI_h]),
		Shapes::se(text[Window_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[GUI_h]),
		Shapes::se(text[FLTK_headers]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::west(text[FLTK_code]),
		Shapes::ne(text[FLTK_headers]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Window_h]),
		Shapes::se(text[Point_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::ne(text[Graph_h]),
		Shapes::sw(text[FLTK_headers]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Graph_h]),
		Shapes::south(text[Point_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Graph_cpp]),
		Shapes::south(text[Graph_h]),
	});

	arrow.push_back(new Shapes::Arrow {
		Shapes::north(text[Chapter12_cpp]),
		Shapes::south(text[Graph_h]),
	});

	for (int i {0} ; i < arrow.size() ; ++i)
	  {
		arrow[i].set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 2
		));
		arrow[i].set_color(Graph_lib::Color::black);
		win.attach(arrow[i]);
	  }

//	for (int i {0} ; i < markers.size() ; ++i)
//	  {
//		win.attach(markers[i]);
//	  }

	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
