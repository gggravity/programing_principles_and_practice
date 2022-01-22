//
// Created by martin on 21/01/2022.
//

#include "Arc.h"
#include "Box.h"

using namespace std;

namespace Shapes
  {
	Box::Box (Graph_lib::Point point_1, Graph_lib::Point point_2, int corners)
	  {
		add(point_1);
		add(point_2);
		set_height(abs(point_1.y - point_2.y));
		set_width(abs(point_1.x - point_2.x));
		set_corners(corners);
	  }

	Box::Box (Graph_lib::Point point, int height, int width, int corners)
	  {
		// TODO need to fix the height, width and corners.
//		add(point);
//		add({point.x + width, point.y + height});
		add(point);
		set_corners(corners);
	  }

	void Box::draw_lines () const
	  {
		if (corners() > 0 && corners() < height() / 2 && corners() < width() / 2)
		  {
			// add lines
			fl_line(
				point(0).x,
				point(0).y + corners(),
				point(0).x,
				point(1).y - corners()
			);
			fl_line(
				point(0).x + corners(),
				point(1).y,
				point(1).x - corners(),
				point(1).y
			);
			fl_line(
				point(1).x - corners(),
				point(0).y,
				point(0).x + corners(),
				point(0).y
			);
			fl_line(
				point(1).x,
				point(0).y + corners(),
				point(1).x,
				point(1).y - corners()
			);

			// add the arcs
			fl_arc(
				point(0).x,
				point(0).y,
				corners() * 2,
				corners() * 2, 90, 180
			);
			fl_arc(
				point(0).x,
				point(0).y + height() - corners() * 2,
				corners() * 2,
				corners() * 2,
				180, 270
			);
			fl_arc(
				point(0).x + width() - 2 * corners(),
				point(0).y + height() - corners() * 2,
				corners() * 2, corners() * 2,
				270, 0
			);
			fl_arc(
				point(0).x + width() - 2 * corners(),
				point(0).y,
				corners() * 2,
				corners() * 2, 0, 90
			);
		  }
		else
		  {
			throw runtime_error("corners to large");
		  }
	  }

	int Box::height () const
	  {
		return m_height;
	  }

	void Box::set_height (int height)
	  {
		Box::m_height = height;
	  }

	int Box::width () const
	  {
		return m_width;
	  }

	void Box::set_width (int width)
	  {
		Box::m_width = width;
	  }

	int Box::corners () const
	  {
		return m_corners;
	  }

	void Box::set_corners (int corners)
	  {
		Box::m_corners = corners;
//		set_width();
//		set_height();
	  }

  }