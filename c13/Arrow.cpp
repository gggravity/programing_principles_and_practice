//
// Created by martin on 22/01/2022.
//

#include "Arrow.h"

namespace Shapes
  {
	Shapes::Arrow::Arrow (Graph_lib::Point p1, Graph_lib::Point p2, int arrow_head_length)
	  {
		int middle_y = p1.y + abs(p1.y - p2.y) / 2;
		add({p1.x, middle_y}); // change to middle of y
		add({p2.x, middle_y});

		add ({p2.x - arrow_head_length, p1.y});
		add ({p2.x, middle_y});

		add ({p2.x - arrow_head_length, p2.y});
		add ({p2.x, middle_y});
	  }

	void Arrow::draw_lines () const
	  {
		Shape::draw_lines();
	  }
  }