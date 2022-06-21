//
// Created by martin on 16/01/2022.
//

#include "Point.h"

double Point::get_x () const
  {
	return m_x;
  }
void Point::set_x (double x)
  {
	Point::m_x = x;
  }
double Point::get_y () const
  {
	return m_y;
  }
void Point::set_y (double y)
  {
	Point::m_y = y;
  }

std::ostream &operator<< (std::ostream &os, const Point &point)
  {
	os << "x: " << point.m_x << " y: " << point.m_y;
	return os;
  }

std::istream &operator>> (std::istream &is, Point &point)
  {
	double x;
	double y;
	is >> x >> y;
	point.set_x(x);
	point.set_y(y);

	return is;
  }

Point::Point () : m_x {0},
				  m_y {0}
  { }

Point::Point (double x, double y) : m_x(x),
									m_y(y)
  { }
