//
// Created by martin on 21/01/2022.
//

#include "Arc.h"

using namespace std;

namespace Shapes
  {
	Arc::Arc (Graph_lib::Point point, int height, int width, double angle_1, double angle_2)
		: m_height {height},
		  m_width {width},
		  m_angle_1 {angle_1},
		  m_angle_2 {angle_2}
	  {
		if (height <= 0 || width <= 0)
		  {
			throw std::runtime_error("non-positive side");
		  }
		add(point);
	  }

	void Arc::draw_lines () const
	  {
//		cout << "Running draw lines." << endl;
//		cout << "point(x): " << point(0).x << ", point(y): " << point(0).y << endl;
//		cout << "width(): " << width() << ", height(): " << height() << endl;
//		cout << "angle_1(): " << angle_1() << ", angle_2(): " << angle_1() << endl;
//
//		void fl_arc(int x, int y, int w, int h, double a1, double a2)

		fl_arc(point(0).x, point(0).y, width(), height(), angle_1(), angle_2());
	  }

	double Arc::angle_1 () const
	  {
		return m_angle_1;
	  }

	void Arc::set_angle_1 (double angle)
	  {
		Arc::m_angle_1 = angle;
	  }

	double Arc::angle_2 () const
	  {
		return m_angle_2;
	  }

	void Arc::set_angle_2 (double angle)
	  {
		Arc::m_angle_2 = angle;
	  }

	int Arc::height () const
	  {
		return m_height;
	  }

	void Arc::set_height (int height)
	  {
		Arc::m_height = height;
	  }

	int Arc::width () const
	  {
		return m_width;
	  }

	void Arc::set_width (int width)
	  {
		Arc::m_width = width;
	  }
  }