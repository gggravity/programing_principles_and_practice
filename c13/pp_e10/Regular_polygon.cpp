//
// Created by martin on 25/01/2022.
//

#include "Regular_polygon.h"

namespace Shapes
  {
	using namespace std;

	Regular_polygon::Regular_polygon (int center_x, int center_y, int radius, int n_sides)
	  {
		if (n_sides <= 2)
		  {
			throw runtime_error("Number of sides <= 2 (" + to_string(n_sides) + ")");
		  }

		Graph_lib::Point point;

		double angle;
		double increment = 2.0f * std::numbers::pi / n_sides;

		for (int i = 0 ; i <= n_sides ; ++i)
		  {
			point.x = int(radius * cos(angle) + center_x);
			point.y = int(radius * sin(angle) + center_y);
			angle += increment;
			Shape::add(point);
		  }
	  }
  }