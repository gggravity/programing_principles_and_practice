//
// Created by martin on 26/01/2022.
//

#include "Poly.h"

Poly::Poly (std::initializer_list<Graph_lib::Point> points)
  {
	for (auto &point : points)
	  {
		add(point);
	  }
	add(*points.begin());
  }
