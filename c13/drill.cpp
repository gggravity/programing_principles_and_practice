#include "Simple_window.h"
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

int main ()
try
  {
	Simple_window win(Point {0, 0}, 800, 800, "Chapter 13 - Drill");

	Graph_lib::Lines grid;
	for (int i {0} ; i < 8 ; ++i)
	  {
		grid.add(Point {0, i * 100}, Point {y_max(), i * 100});
		grid.add(Point {i * 100, 0}, Point {i * 100, x_max()});
	  }

//	// chess board
//	Vector_ref<Graph_lib::Rectangle> chess_board;
//	for (int i {1} ; i < 9 ; ++i)
//	  {
//		for (int j {1} ; j < 9 ; ++j)
//		  {
//			if ((i + j) % 2)
//			  {
//				auto *r = new Graph_lib::Rectangle {
//					Point {i * 100, j * 100},
//					Point {i * 100 + 100, j * 100 + 100}
//				};
//				r->set_fill_color(Color::black);
//				r->move(-100, -100);
//				chess_board.push_back(r);
//			  }
//		  }
//	  }

	Vector_ref<Graph_lib::Rectangle> reds;
	for (int i {0} ; i < 8 ; ++i)
	  {
		auto *r = new Graph_lib::Rectangle {
			Point {i * 100, i * 100},
			Point {i * 100 + 100, i * 100 + 100}
		};
		r->set_color(Color::invisible);
		r->set_fill_color(Color::red);
		reds.push_back(r);

	  }

	Vector_ref<Graph_lib::Image> iv;
	for (int i {0} ; i < 800 ; i += 200)
	  {
		auto *image = new Graph_lib::Image {Point {i, i}, "200x200.jpg", Suffix::jpg};
		iv.push_back(image);
	  }

	for (int i {0} ; i < iv.size() ; ++i)
	  {
		win.attach(iv[i]);
	  }

	Image image {Point {-100, -100}, "100x100.jpg", Suffix::jpg};
	win.attach(image);
	for (int i {0} ; i < 8 ; ++i)
	  {
		win.wait_for_button();
		image.move(100,100);
	  }
//	for (int i {0} ; i < reds.size() ; ++i)
//	  {
//		win.attach(reds[i]);
//	  }



//	win.attach(grid);
	win.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }