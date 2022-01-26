//
// Created by martin on 25/01/2022.
//

#ifndef _REGULAR_HEXAGON_H_
#define _REGULAR_HEXAGON_H_

#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

namespace Shapes
  {
	struct Regular_hexagon
		:
			public Graph_lib::Shape
		  {
				Regular_hexagon (int center_x, int center_y, int radius, double angle = 0);
		  };
  }
#endif //_REGULAR_HEXAGON_H_
