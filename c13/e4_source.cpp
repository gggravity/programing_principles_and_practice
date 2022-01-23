//
// Created by martin on 23/01/2022.
//

#include "e4_source.h"

std::ostream &operator<< (std::ostream &os, const Graph_lib::Point &point)
  {
	os << point.x << ", " << point.y;
	return os;
  }

namespace Shapes
  {

	Graph_lib::Point n (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width() / 2, rectangle.point(0).y};
	  }

	Graph_lib::Point s (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width() / 2, rectangle.point(0).y + rectangle.height()};
	  }

	Graph_lib::Point e (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width(), rectangle.point(0).y + rectangle.height() / 2};
	  }

	Graph_lib::Point w (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x, rectangle.point(0).y + rectangle.height() / 2};
	  }

	Graph_lib::Point center (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width() / 2, rectangle.point(0).y + rectangle.height() / 2};
	  }

	Graph_lib::Point ne (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width(), rectangle.point(0).y};
	  }

	Graph_lib::Point se (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x + rectangle.width(), rectangle.point(0).y + +rectangle.height()};
	  }

	Graph_lib::Point sw (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x, rectangle.point(0).y + rectangle.height()};
	  }

	Graph_lib::Point nw (Graph_lib::Rectangle const &rectangle)
	  {
		return {rectangle.point(0).x, rectangle.point(0).y};
	  }

  }