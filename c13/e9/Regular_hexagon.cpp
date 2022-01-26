//
// Created by martin on 25/01/2022.
//

#include "Regular_hexagon.h"

namespace Shapes
  {

	Regular_hexagon::Regular_hexagon (int center_x, int center_y, int radius, double angle)
	  {
		Graph_lib::Point point;

		const int n_sides = 6;

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