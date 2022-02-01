//
// Created by martin on 27/01/2022.
//

#include "Octagon.h"

using namespace std;

Octagon::Octagon (Graph_lib::Point center, int radius)
	: m_radius(radius)
  {
	for (int angle = 0 ; angle < 360 ; angle += 45)
	  {
		add(point_on_circle(center, radius, angle));
	  }
	add(point_on_circle(center, radius, 0));

  }

double Octagon::radians (double degrees)
  {
	return degrees * numbers::pi / 180;
  }

int Octagon::radius () const
  {
	return m_radius;
  }

void Octagon::set_radius (int radius)
  {
	m_radius = radius;
  }

Graph_lib::Point Octagon::point_on_circle (Graph_lib::Point center, int radius, int angle)
  {
	int x = int(center.x + radius * cos(radians(angle)));
	int y = int(center.y - radius * sin(radians(angle)));

	return {x, y};
  }
