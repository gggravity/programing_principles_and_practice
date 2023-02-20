//
// Created by martin on 22/01/2022.
//

#include "Arrow.h"

using namespace std;

namespace Shapes
  {
	Shapes::Arrow::Arrow (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		add(p1, p2);
	  }

	void Arrow::draw_lines () const
	  {
		Shape::draw_lines();

		Graph_lib::Point pd = find_arrow_length(point(0), point(1));

		pd = {pd.x - point(1).x, pd.y - point(1).y};

		Graph_lib::Point pr1 = rotate(pd, 30);
		Graph_lib::Point pr2 = rotate(pd, -30);

		fl_line(
			pr1.x + point(1).x,
			pr1.y + point(1).y,
			point(1).x,
			point(1).y
		);

		fl_line(
			pr2.x + point(1).x,
			pr2.y + point(1).y,
			point(1).x,
			point(1).y
		);
	  }

	Graph_lib::Point
	Arrow::find_arrow_length (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		int px = p2.x - (p2.x - p1.x) / 10;
		int py = p2.y - (p2.y - p1.y) / 10;

		return {px, py};
	  }

	void Arrow::add (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		Shape::add(p1);
		Shape::add(p2);
	  }

	double Arrow::magnitude (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		return sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
	  }

	double Arrow::angle (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		Graph_lib::Point p = get_vector(p1, p2);
		return to_degree(atan(double(p.y) / double(p.x)));
	  }

	Graph_lib::Point Arrow::get_vector (Graph_lib::Point p1, Graph_lib::Point p2)
	  {
		return {p2.x - p1.x, p2.y + p1.y};
	  }

	Graph_lib::Point Arrow::rotate (Graph_lib::Point p, int angle)
	  {
		Graph_lib::Point point_rotated;

		point_rotated.x = int(p.x * cos(to_radian(angle)) - p.y * sin(to_radian(angle)));
		point_rotated.y = int(p.x * sin(to_radian(angle)) + p.y * cos(to_radian(angle)));

		return point_rotated;
	  }

	double Arrow::to_radian (double degree)
	  {
		return 2 * std::numbers::pi * (degree / 360);
	  }

	double Arrow::to_degree (double radian)
	  {
		return radian * (180.0 / std::numbers::pi);
	  }
  }