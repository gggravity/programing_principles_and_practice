//
// Created by martin on 25/01/2022.
//

#ifndef _REGULAR_POLYGON_H_
#define _REGULAR_POLYGON_H_

#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

namespace Shapes
  {
	struct Regular_polygon
		:
			public Graph_lib::Shape
		{
			Regular_polygon (int center_x, int center_y, int radius, int n_sides = 0);
		};
  }
#endif //_REGULAR_POLYGON_H_
