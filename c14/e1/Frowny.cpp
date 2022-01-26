//
// Created by martin on 26/01/2022.
//

#include "Frowny.h"

using namespace std;

Frowny::Frowny (Graph_lib::Point point, int radius) : Graph_lib::Circle(point, radius)
  {
	add(point);
	set_radius(radius);
  }

void Frowny::draw_lines () const
  {
	Circle::draw_lines();

	fl_begin_line();
//	fl_arc(center().x, center().y - radius() / 8.0, radius() * 3.0 / 5.0, 220, 320);
	fl_arc(center().x, center().y + radius() * 0.75, radius() * 3.0 / 5.0, 40, 140);
	fl_end_line();

	fl_circle(center().x - radius() / 2.5, center().y - radius() / 3.5, radius() / 10.0);
	fl_circle(center().x + radius() / 2.5, center().y - radius() / 3.5, radius() / 10.0);
  }
