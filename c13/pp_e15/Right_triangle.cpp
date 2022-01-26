//
// Created by martin on 25/01/2022.
//

#include "Right_triangle.h"

using namespace std;

Right_triangle::Right_triangle (Graph_lib::Point p1, Graph_lib::Point p2, Graph_lib::Point p3)
  {
	int a = int(sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
	int b = int(sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y)));
	int c = int(sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y)));

	if (a*a + b*b != c*c)
	  {
		throw std::runtime_error("Pythagorean theorem");
	  }

	add(p1);
	add(p2);
	add(p3);
	add(p1);
  }
