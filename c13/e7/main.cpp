#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib.h"

using namespace std;

class Rect
	:
		public Graph_lib::Rectangle
	  {
		public:

			Rect (Graph_lib::Point point) : Rectangle(point, 5, 5)
			  {

			  }

			void set_color (unsigned char red, unsigned char green, unsigned char blue)
			  {
				m_red = red;
				m_green = green;
				m_blue = blue;
			  }

			[[nodiscard]] unsigned char red () const
			  {
				return m_red;
			  }

			[[nodiscard]] unsigned char green () const
			  {
				return m_green;
			  }

			[[nodiscard]] unsigned char blue () const
			  {
				return m_blue;
			  }

			void draw_lines () const override
			  {
				fl_color(red(), green(), blue());
				fl_rectf(point(0).x, point(0).y, width, height);
			  }

		private:
			unsigned char m_red {0};
			unsigned char m_green {0};
			unsigned char m_blue {0};
			int height {5};
			int width {5};
	  };

int main ()
try
  {
	Graph_lib::Simple_window window(Graph_lib::Point {0, 0},
									Graph_lib::x_max(),
									Graph_lib::y_max(),
									"Exercise 7");

	cout << Graph_lib::x_max() << ", " << Graph_lib::y_max() << endl;

	Graph_lib::Vector_ref<Rect> rectangles;
	for (int i {0} ; i <= 140 * 2 ; ++i)
	  {
		for (int j {0} ; j <= 80 * 2 ; ++j)
		  {
			rectangles.push_back(new Rect {{i * 5, j * 5}});
		  }
	  }

	for (int i {0} ; i < rectangles.size() ; ++i)
	  {
		rectangles[i].set_color(i, i + 85, i + 171);
		window.attach(rectangles[i]);
	  }

	for (int red = 0 ; red < 265 ; red += 1)
	  {
		for (int green = 0 ; green < 265 ; green += 1)
		  {
			for (int blue = 0 ; blue < 265 ; blue += 1)
			  {
				int index = 65536 * red + 256 * green + blue;
//				cout << "index: " << int(index) << " r: " << red << "g: " << green << "b: " << blue << endl;
				if (index >= rectangles.size())
				  {
					break;
				  }
				else
				  {
					rectangles[index].set_color(red, green, blue);
				  }
			  }
		  }
	  }

	window.wait_for_button();
  }
catch (exception &e)
  {
	cerr << "Error: " << e.what() << endl;
  }
